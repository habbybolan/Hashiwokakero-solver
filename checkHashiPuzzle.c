#include "createBoard.h"
#include "checkHashiPuzzle.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "gameBoards.h"

int numIslands = 0;
// heck if each island has at least 1 possibility
int checkIfPossibilityEachIsland(int n) {
	int count;
	for (int i = 0; i < n; i++) {
		struct islands island = allIslands[i];
		count = 0;
		if (island.isIsland == 1) {
			for (int j = 0; j < 81; j++) {
				if (island.allPossibleBridges[j][0] != -1) {
					count++;
				}
			}
			if (count == 0) {
				return 0;
			}
		}
	}
	return 1;
}



void printThings(int n) {
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland) {
			printf("\n------------------------------------\n");
			printf("island %d at (%d, %d) value %d:", i, allIslands[i].x_pos, allIslands[i].y_pos, allIslands[i].value);
			printf("\n TotalPossibilities: %d", allIslands[i].totalPossibilities);
			printf("\n Guaranteed Bridges Up: (%d,%d,%d)", allIslands[i].up_bridge[0], allIslands[i].up_bridge[1], allIslands[i].up_bridge[2]);
			printf("\n Guaranteed Bridges Down: (%d,%d,%d)", allIslands[i].down_bridge[0], allIslands[i].down_bridge[1], allIslands[i].down_bridge[2]);
			printf("\n Guaranteed Bridges Left: (%d,%d,%d)", allIslands[i].left_bridge[0], allIslands[i].left_bridge[1], allIslands[i].left_bridge[2]);
			printf("\n Guaranteed Bridges Right: (%d,%d,%d)", allIslands[i].right_bridge[0], allIslands[i].right_bridge[1], allIslands[i].right_bridge[2]);
		}
		for (int j = 0; j < 81; j++) {
			if (allIslands[i].allPossibleBridges[j][0] != -1) {
				printf("\n");
				printf("%d: (%d %d %d %d)", j
					, allIslands[i].allPossibleBridges[j][0]
					, allIslands[i].allPossibleBridges[j][1]
					, allIslands[i].allPossibleBridges[j][2]
					, allIslands[i].allPossibleBridges[j][3]);
			}
		}
	}
}

// create an island at index i
void createIsland(int i, int s) {
	allIslands[i].isIsland = 1;
	allIslands[i].value = (rand() % 5) + 1;
	// if the index is between 0 to (s-1), then that is the first row 
	if (i < s) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = i;
	}
	// otherwise, the row is 1+, calculated with division and modular
	else {
		allIslands[i].x_pos = i / s;
		allIslands[i].y_pos = i % s;
	}
	allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
	allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
	allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
	allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;

	allIslands[i].finalIsland_Up = NULL;
	allIslands[i].finalIsland_Down = NULL;
	allIslands[i].finalIsland_Left = NULL;
	allIslands[i].finalIsland_Right = NULL;
	allIslands[i].up_islands = NULL;
	allIslands[i].down_islands = NULL;
	allIslands[i].left_islands = NULL;
	allIslands[i].right_islands = NULL;
}

// check if the board is fully conencted  - recursive algorithm
	// holdNeibhors stores the indices of the neighbors to visit later
	// n is the board size
	// maxIndex is the later element of the holdNeighbors array - to act like a stack
	// i is the island i to look at
	// everyIsland is the number of islands on the game board
void checkFullyConnected(int n, int i) {
	// reset visited islands
	
	// look island as visited and store indices of neighbors
		allIslands[i].visited = 1; // visited current island being looked at

		if (allIslands[i].finalIsland_Left != NULL && allIslands[i].finalIsland_Left->visited == 0) { // go into left island neighbor if not NULL
			checkFullyConnected(n, sqrt(n) * allIslands[i].finalIsland_Left->y_pos + allIslands[i].finalIsland_Left->x_pos);
		}
		if (allIslands[i].finalIsland_Down != NULL && allIslands[i].finalIsland_Down->visited == 0) { // go into down island neighbor if not NULL
			checkFullyConnected(n ,sqrt(n) * allIslands[i].finalIsland_Down->y_pos + allIslands[i].finalIsland_Down->x_pos);
		}
		if (allIslands[i].finalIsland_Right != NULL && allIslands[i].finalIsland_Right->visited == 0) { // go into down island neighbor if not NULL
			checkFullyConnected(n, sqrt(n) * allIslands[i].finalIsland_Right->y_pos + allIslands[i].finalIsland_Right->x_pos);
		}
		if (allIslands[i].finalIsland_Up != NULL && allIslands[i].finalIsland_Up->visited == 0) { // go into down island neighbor if not NULL
			checkFullyConnected(n, sqrt(n) * allIslands[i].finalIsland_Up->y_pos + allIslands[i].finalIsland_Up->x_pos);
		}
}

// find the number of islands in the nxn board
int checkNumIslands(int n) {
	int value = 0;
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland)
			value++;
	}
	return value;
}

// store the main struct into a temporary struct to find new information
void createTempStruct(int n) {
	for (int i = 0; i < n; i++)
		store_allIslands[i] = allIslands[i];
}

// take the stored struct and recover it
void reGetStoredStruct(int n) {
	for (int i = 0; i < n; i++)
		allIslands[i] = store_allIslands[i];
}


// return 1 if board is solved, otherwise return 0
int onePossibilityEachIsland(int n) {
	for (int i = 0; i < n; i++) {
		// add up all island's possibiltiies to see if it equals numIslands (1 possibility for each island)
		if (allIslands[i].isIsland) {
			if (allIslands[i].totalPossibilities != 1) { // finds if an island doesn't have 0 possibilities
				return 0;
			}
		}
	}
	return 1;
}

// return true if there is an island with 0 possibilities
int zeroPossibilities(int n) {
	for (int i = 0; i < n; i++) {
		// add up all island's possibiltiies to see if it equals numIslands (1 possibility for each island)
		if (allIslands[i].isIsland) {
			if (allIslands[i].totalPossibilities <= 0) { // make sure an island doesn't have 0 possibilities
				return 1;
			}
		}
	}
	return 0;
}

int countNumPossibilities(int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		// add up all island's possibiltiies to see if it equals numIslands (1 possibility for each island)
		count += allIslands[i].totalPossibilities;
	}
	return count;
}

// find the island where it has 
int* findIslandWithCurrPossibility(int n, int curr) {
	int possFound = 0; // the current real possibility found while searching
	int returnArray[2]; // the return array, where [0]=island index, [1]=possibility index in island
	for (int i = 0; i < n; i++) { // go thorugh all islands
		if (allIslands[i].isIsland) {
			for (int j = 0; j < 81; j++) { // go through all possibilities for island i
				if (allIslands[i].allPossibleBridges[j][0] != -1) { // if this possibility is not empty
					if (possFound == curr) { // if the proper possibility is found
						returnArray[0] = i;
						returnArray[1] = j;
					}
					possFound++;
				}
			}
		}
	}
	return returnArray;
}

// reutrn 1 if all nodes have been visited
int checkAllVisited(int n) {
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland)
			if (allIslands[i].visited == 0)
				return 0;
	}
	return 1;
}

void resetVisited(int n) {
	for (int i = 0; i < n; i++)
		if (allIslands[i].isIsland)
			allIslands[i].visited = 0;
}

// return the number of islands that have multiple possibilties (>1)
int numIslandsWithMultPossibilities(int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland && allIslands[i].totalPossibilities > 1)
			count++;
	}
	return count;
}

int checkIfPossDontMatch(int i) {
	int count = 0;

			for (int j = 0; j < 81; j++) {
				if (allIslands[i].allPossibleBridges[j][0] != -1) {
					count++; // count number of acutal possibilities
				}
			}
			printf("\n totalPossibilities: %d", allIslands[i].totalPossibilities);
			printf("\n counted Number: %d", count);
		if (count != allIslands[i].totalPossibilities) {
			return 1;
		}
		else {
			return 0;
		}
}

// using possibility assumption, ratiocination, and mistake testing
	// n is the size of board, currPoss is the current possiblity, and i is the current island being assumed
	// j is the possibility in the island chosen for assumption
int findSolution(int n, int i, int j) {
	sievingMethods(n);
	if (onePossibilityEachIsland(n)) { // return 1 if there is 1 possibility for each island
		int p = 0;
		// find an island to start at
		while (allIslands[p].isIsland == 0) {
			p++;
		}

		resetVisited(n); // makes all visited variables  = 0

		checkFullyConnected(n, p); // using dfs, check if fully connected
		if (checkAllVisited(n)) { //  check if all islands visited (fully connected)
			return 1; // return 1 if all islands have 1 possiblity and are fully connected
		}
		else {
			return 0;
		}
	}
	// return 0 if there is an island with 0 possibilities
	else if (zeroPossibilities(n)) {
		return 0;
	}
	else {
		
		for (int k = 0; k < 81; k++) { // remove not assumption possibilities
			if (k != j) {
				// delete all other possibilities in i that are not the asumption
				if (allIslands[i].allPossibleBridges[k][0] != -1) {
					allIslands[i].allPossibleBridges[k][0] = -1;
					allIslands[i].allPossibleBridges[k][1] = -1;
					allIslands[i].allPossibleBridges[k][2] = -1;
					allIslands[i].allPossibleBridges[k][3] = -1;
					allIslands[i].totalPossibilities--;
				}
			}
		}
	


		// running sieving methods to check if this findsa solution
		// find the next island with more than 1 possibility
			// if one doesn't exist, then recurse over then same values as before
				// this will either return no solution, or a solution is found
		int new_i = 0;
		int new_j = 0;
		int randVar;
		int i = 0;
		int multPoss = numIslandsWithMultPossibilities(n); // counts # of islands with mult possiblities
		
		srand(time(0));
		if (multPoss > 0) { // if there is at least 1 island with multiple possiblities
			while (1) {
				if (allIslands[i].totalPossibilities > 1) { // check if island i has mult possibilities
					if ((rand() % multPoss) == 0) { // each islands with mult possibilities have equal cahnce
						randVar = 0;
						j = 0;
						new_i = i;
						// make a new assumption about a new island that has more than 1 possibility
						while (1) {
							// choose a RANDOM possibility to assume
							if (allIslands[i].allPossibleBridges[j][0] != -1) {
								randVar = rand() % allIslands[i].totalPossibilities; // all possibilities equal prob
								if (randVar == 0) {
									new_j = j; // pick this possibility randomly - new assumption
									break; // leave while loop
								}
							}
							j++;
							if (j == 81)
								j = 0; // reset j
						}
						break;	// leave for loop
					}
				}
				i++;
				if (i == n)
					i = 0; // reset island i
			}
		}
		return findSolution(n, new_i, new_j);
	}
}