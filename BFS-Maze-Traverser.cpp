/*------------------------------------------*/
/*               Maze2.cpp                  */
/*                                          */
/*  Author: Zwe Phone Shein                 */
/*                                          */
/*  Date: 03/28/2016                        */
/*==========================================*/

#include "Maze2.h"
#include <iostream>
#include <cassert>

using namespace std;

void Maze2::find_exit()
{
   // Use the BFS method to fill the array of predecessors
  Position nbr, current;
  direction d;

  // Mark the start as visited.
  M[start.row][start.col] = VISITED;

  // Initiate the current position, neighbor and direction.
  current = start;
  d = DOWN;
  nbr = current.Neighbor(d);

  // Start searching the exit.
  while (1)
  {
  	while (d != NONE)
  	{
        // If an open neighbor is found, enqueue it and mark it as visited.
        // Also, insert it into the pred array.
	  	if ((M[nbr.row][nbr.col]) == OPEN)
	  	{
	  		Q.push(nbr);
	  		M[nbr.row][nbr.col] = VISITED;
	  		pred[nbr.row][nbr.col] = current;

            // If an exit is found, return.
  			if (nbr == exitpos)
  			{
  				pred[exitpos.row][exitpos.col] = current;
                return;
  			}
	  	}

        // Change next direction.
	  	d = next_direction(d);
	  	nbr = current.Neighbor(d);

  	}

    // Find the neighbors from the queue members.
  	if (!Q.empty())
  	{
  		current = Q.front();
  		d = DOWN;
  		nbr = current.Neighbor(d);
  		Q.pop();
  	}

    // If no exit is found, return.
    if (d == NONE)
    {
      pred[exitpos.row][exitpos.col] = NULLPOS;
      return;
    }

    }

}




