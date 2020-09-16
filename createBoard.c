#include "createBoard.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "checkHashiPuzzle.h"
#include "gameBoards.h"


// create the board of randomly placed islands of size nxn
int createBoard(int n) {
	switch (n) {

	case 0:
		createSpecificBoard_100();
		return 100;
	case 1:
		createSpecificBoardEasy_100();
		return 100;
	case 2:
		createSpecificBoardEasy2_100();
		return 100;
	case 3:
		createSpecificBoardMedium_100();
		return 100;
	case 4:
		createSpecificBoardHard_100();
		return 100;
	case 5:
		createSpecificBoard_49();
		return 49;
	default:
		createSpecificBoardEasy2_625();
		return 625;
	}
}


// print out the hashi board
void printBoard(int n) {
	int s = sqrt(n);
	for (int i = 0; i < n; i++) {
		if (i % s == 0) {
			printf("\n");
		}
		if (allIslands[i].value == -1) {
			printf("     ");
		}
		else {
			printf("%d    ", allIslands[i].value);
		}
	}
}

// find the neighbors of each node that is up, down, left, right
void setNeighbors(int n) {
	int x;
	int y;
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland == 1) {
			x = allIslands[i].x_pos;
			y = allIslands[i].y_pos;
			// go through other islands that may be a neighbor
			for (int j = 0; j < n; j++) {
				// dont look at the same island as islands 'i'
				if (j != i && allIslands[j].isIsland == 1) {
					// find the 'up' islands from islands 'i'
						// if island 'j' is 'up' island, then island 'i' is 'down' island to island 'j'
					if (allIslands[j].x_pos == x && allIslands[j].y_pos < y) {
						// check if up_islands is not NULL
						if (allIslands[i].up_islands != NULL) {
							// if the new island is closer than island already in up_islands
							if (abs(y - allIslands[j].y_pos) < abs(y - allIslands[i].up_islands->y_pos)) {
								allIslands[i].up_islands = &allIslands[j];
								allIslands[j].down_islands = &allIslands[i];
							}
						}
						// up_islands is NULL, so put the island as its neighbor
						else {
							allIslands[i].up_islands = &allIslands[j];
							allIslands[j].down_islands = &allIslands[i];
						}
					}
					// find the 'down' islands from islands 'i'
						// if island 'j' is 'down' island, then island 'i' is 'up' island to island 'j'
					if (allIslands[j].x_pos == x && allIslands[j].y_pos > y) {
						// check if down_islands is not NULL
						if (allIslands[i].down_islands != NULL) {
							// if the new island is closer than island already in down_islands
							if (abs(y - allIslands[j].y_pos) < abs(y - allIslands[i].down_islands->y_pos)) {
								allIslands[i].down_islands = &allIslands[j];
								allIslands[j].up_islands = &allIslands[i];
							}
						}
						// down_islands is NULL, so put the island as its neighbor
						else {
							allIslands[i].down_islands = &allIslands[j];
							allIslands[j].up_islands = &allIslands[i];
						}
					}
					// find the 'left' islands from islands 'i'
						// if island 'j' is 'left' island, then island 'i' is 'right' island to island 'j'
					if (allIslands[j].x_pos < x && allIslands[j].y_pos == y) {
						// check if left_islands is not NULL
						if (allIslands[i].left_islands != NULL) {
							// if the new island is closer than island already in left_islands
							if (abs(x - allIslands[j].x_pos) < abs(x - allIslands[i].left_islands->x_pos)) {
								allIslands[i].left_islands = &allIslands[j];
								allIslands[j].right_islands = &allIslands[i];
							}
						}
						// left_islands is NULL, so put the island as its neighbor
						else {
							allIslands[i].left_islands = &allIslands[j];
							allIslands[j].right_islands = &allIslands[i];
						}
					}
					// find the 'right' islands from islands 'i'
						// if island 'j' is 'right' island, then island 'i' is 'left' island to island 'j'
					if (allIslands[j].x_pos > x && allIslands[j].y_pos == y) {
						// check if right_islands is not NULL
						if (allIslands[i].right_islands != NULL) {
							// if the new island is closer than island already in right_islands
							if (abs(x - allIslands[j].x_pos) < abs(x - allIslands[i].right_islands->x_pos)) {
								allIslands[i].right_islands = &allIslands[j];
								allIslands[j].left_islands = &allIslands[i];
							}
						}
						// right_islands is NULL, so put the island as its neighbor
						else {
							allIslands[i].right_islands = &allIslands[j];
							allIslands[j].left_islands = &allIslands[i];
						}
					}
				}
			}
		}
	}
}


// calculate basic imformation
	// remove bridges not equal to island value and bridges going to no islands
void basicInformation(int n) {
	for (int i = 0; i < n; i++) {
		sievingNumBridges(n, i); // remove possibiltiies where the number of bridges doesn't equal the value is the island
		removePossibilitiesNoNeighbors(n, i); // if there is no neighbors in a certain direction, remove that possibility
	}
}


void printIntersection(int i) {
	if (allIslands[i].isIsland) {
		printf("------------------");
		printf("\nintersection: ");
		printf("\n    Up: (%d,%d,%d)"
			, allIslands[i].up_bridge[0]
			, allIslands[i].up_bridge[1]
			, allIslands[i].up_bridge[2]);
		printf("\nintersection: ");
		printf("\n    down: (%d,%d,%d)"
			, allIslands[i].down_bridge[0]
			, allIslands[i].down_bridge[1]
			, allIslands[i].down_bridge[2]);
		printf("\nintersection: ");
		printf("\n    left: (%d,%d,%d)"
			, allIslands[i].left_bridge[0]
			, allIslands[i].left_bridge[1]
			, allIslands[i].left_bridge[2]);
		printf("\nintersection: ");
		printf("\n    right: (%d,%d,%d)"
			, allIslands[i].right_bridge[0]
			, allIslands[i].right_bridge[1]
			, allIslands[i].right_bridge[2]);
	}
}
// use the three sieveing methods to remove impossible connections before using intersection method
void sievingMethods(int n) {
	for (int i = 0; i < n; i++) {


		intersection(n, i); // intersect the remaining possibilities, finding whether each direction still has 0, 1, or/and 2 bridges
		sievingExcludeImpossibility(i, sqrt(n)); // use the information from intersection to exclude possibilties that don't match up with their neighbor
		applyGuaranteedBridges(i); // if a direction has no zero bridges
		sievingCrossingBridges(n, i); // remove possibilities with bridges crossing others
		intersection(n, i);
	}
}


// if a certain direction has no neighbors for island, remove possiblities that have bridges going that direction
void removePossibilitiesNoNeighbors(int n, int i) {
	if (allIslands[i].up_islands == NULL) {
		removeBridges(0, 0, 1, 1, i);
	}
	if (allIslands[i].down_islands == NULL) {
		removeBridges(1, 0, 1, 1, i);
	}
	if (allIslands[i].left_islands == NULL) {
		removeBridges(2, 0, 1, 1, i);
	}
	if (allIslands[i].right_islands == NULL) {
		removeBridges(3, 0, 1, 1, i);
	}

}

// check if the 0 bridge value is empty
	// Also checks if island bridge going direction up/down/left/right has only a 1 or 2 bridge left
		// if so, then remove the opposite from it's neighbor 
		// (ex) if island has 1 up bridge, then its up neghbor wont have 2 down bridges) // IS THIS STUFF NECESSARY????????!!!!!!
void applyGuaranteedBridges(int i) {
	// iterate through all islands
	if (allIslands[i].isIsland) {
		// check if the up island is a guaranteed connection
		if (noZeroBridges(0, i)) {
			allIslands[i].finalIsland_Up = allIslands[i].up_islands;
			allIslands[i].up_islands->finalIsland_Down = allIslands[i].up_islands->down_islands;
		}
		// check if the down island is a guaranteed connection
		if (noZeroBridges(1, i)) {
			allIslands[i].finalIsland_Down = allIslands[i].down_islands;
			allIslands[i].down_islands->finalIsland_Up = allIslands[i].down_islands->up_islands;
		}
		// check if the left island is a guaranteed connection
		if (noZeroBridges(2, i)) {
			allIslands[i].finalIsland_Left = allIslands[i].left_islands;
			allIslands[i].left_islands->finalIsland_Right = allIslands[i].left_islands->right_islands;
		}
		// check if the right island is a guaranteed connection
		if (noZeroBridges(3, i)) {
			allIslands[i].finalIsland_Right = allIslands[i].right_islands;
			allIslands[i].right_islands->finalIsland_Left = allIslands[i].right_islands->left_islands;
		}
	}
}

// return 1 if the zero bridge is false (must have a bridge in dir)
	// dir = up/down/left/right = (0/1/2/3)
	// also makes sure not all possiblities are -1
int noZeroBridges(int dir, int i) {
	int countNoPoss = 0; // counts number of no possibilities
		for (int j = 0; j < 81; j++) { // go through all possibilities
			// iterate through each possiblity of dir
				// if any of the dir index at a possibility is 0, then return 0
			if (allIslands[i].allPossibleBridges[j][dir] == 0) {
				return 0;
			} else if (allIslands[i].allPossibleBridges[j][dir] == -1) {
				countNoPoss++;
			}
		}
		// otherwise return 1
			// every possibility in dir has a bridge of 1 or 2
		if (countNoPoss < 81) {
			return 1;
		}
		else {
			return 0;
		}
}

	
// if the remaining node value doesn't match the outgoing bridges, remove that possibility (too many bridges for that node value)
void sievingNumBridges(int n, int i) {
	int valueBridges = 0;

	for (int j = 0; j < 81; j++) {
		if (allIslands[i].allPossibleBridges[j][0] != -1) {
			// if the possibility is not empty (not -1), then add up the number of bridges in the possibility
			valueBridges = allIslands[i].allPossibleBridges[j][0]
				+ allIslands[i].allPossibleBridges[j][1]
				+ allIslands[i].allPossibleBridges[j][2]
				+ allIslands[i].allPossibleBridges[j][3];

			// check if the number of bridges doesn't equal the value of the node
				// if not, then remove the possibility.
			if (valueBridges != allIslands[i].value) {
				allIslands[i].allPossibleBridges[j][0] = -1;
				allIslands[i].allPossibleBridges[j][1] = -1;
				allIslands[i].allPossibleBridges[j][2] = -1;
				allIslands[i].allPossibleBridges[j][3] = -1;
				allIslands[i].totalPossibilities--;
			}
		}
	}
}

// remove connection that are overlapping on crossing bridges
void sievingCrossingBridges(int n, int i) {
	//struct islands* island_;
	int s = sqrt(n);
	int leave = 0;
	int temp_j;
	// if there is a crossing bridge over the up bridge from island, remove its possibilities
	if (allIslands[i].up_islands != NULL) {
		// go through all points above island
		for (int k = allIslands[i].y_pos-1; k > allIslands[i].up_islands->y_pos; k--) {
			// look to the right of island to find an island possibly creating a conflicting bridge
			for (int j = allIslands[i].x_pos; j < sqrt(n); j++) {
				//printf("\n CrossingBridges: (%d, %d) for island %d:", j, i, island->value);
				if (allIslands[s * k + j].isIsland) {
					temp_j = j; 
					j = s;  // makes sure that once the loop hits an island, it wont keep going past it
					if (allIslands[s * k + temp_j].finalIsland_Left != NULL) {
						// check if there is a bridge crossing above the island
						if (allIslands[s * k + temp_j].finalIsland_Left->x_pos < temp_j) {
							// remove the bridges going up from island
								// remove possibiltiies with 1 or 2 bridges going up
							removeBridges(0, 0, 1, 1, i); // remove if there is a guaranteed bridge blocking path
						}
					}
				}
			}
		}
	}
	// if there is a crossing bridge over the down bridge from island, remove its possibilities
	if (allIslands[i].down_islands != NULL) {
		// go through all points below island
		for (int k = allIslands[i].y_pos+1; k < allIslands[i].down_islands->y_pos; k++) {
			// look to the right of island to find an island possibly creating a conflicting bridge
			for (int j = allIslands[i].x_pos; j < sqrt(n); j++) {
				//printf("\n CrossingBridges: (%d, %d) for island %d:", j, i, island->value);
				if (allIslands[s * k + j].isIsland) {
					temp_j = j;
					j = s;  // makes sure that once the loop hits an island, it wont keep going past it
					if (allIslands[s * k + temp_j].finalIsland_Left != NULL) {
						//printf("\n value of left crossing: %d", allIslands[s * i + j].finalIsland_Left->value);
						// check if there is a bridge crossing above the island
						if (allIslands[s * k + temp_j].finalIsland_Left->x_pos < temp_j) {
							// remove the bridges going down from island
								// remove possibiltiies with 1 or 2 bridges going down
							removeBridges(1, 0, 1, 1, i); // remove if there is a guaranteed bridge blocking path
							
						}
					}
				}
			}
		}
	}
	// if there is a crossing bridge over the left bridge from island, remove its possibilities
	if (allIslands[i].left_islands != NULL) {
		// go through all points right of the island
		for (int k = allIslands[i].x_pos-1; k > allIslands[i].left_islands->x_pos; k--) {
			// look to down of island to find an island possibly creating a conflicting bridge
			for (int j = allIslands[i].y_pos; j < sqrt(n); j++) {
				if (allIslands[s * j + k].isIsland) {
					temp_j = j;
					j = s;  // makes sure that once the loop hits an island, it wont keep going past it
					if (allIslands[s * temp_j + k].finalIsland_Up != NULL) {
						// check if there is a bridge crossing above the island
						if (allIslands[s * temp_j + k].finalIsland_Up->y_pos < temp_j) {
							// remove the bridges going left from island
								// remove possibiltiies with 1 or 2 bridges going left.
							removeBridges(2, 0, 1, 1, i); // remove if there is a guaranteed bridge blocking path
						}
					}
				}
			}
		}
	}
	// if there is a crossing bridge over the right bridge from island, remove its possibilities
	if (allIslands[i].right_islands != NULL) {
		// go through all points right of the island
		for (int k = allIslands[i].x_pos+1; k < allIslands[i].right_islands->x_pos; k++) {
			// look to down of island to find an island possibly creating a conflicting bridge
			for (int j = allIslands[i].y_pos; j < sqrt(n); j++) {
				if (allIslands[s * j + k].isIsland) {
					temp_j = j;
					j = s;  // makes sure that once the loop hits an island, it wont keep going past it
					if (allIslands[s * temp_j + k].finalIsland_Up != NULL) {
						// check if there is a bridge crossing above the island
						if (allIslands[s * temp_j + k].finalIsland_Up->y_pos < temp_j) {
							// remove the bridges going to the left from island
								// remove possibiltiies with 1 or 2 bridges going right
							removeBridges(3, 0, 1, 1, i); // remove if there is a guaranteed bridge blocking path
						}
					}
				}
			}
		}
	}
}

// remove the bridge from island corresponding to dir (dir: 0 = up, 1 = down, 2 = left, 3 = right)
// island is the node island, dir is the direction of the impossible bridge
// num0 = 1 if 0 bridges impossible, 0 otherwise (num1 for 1 bridge, num2 for 2 bridges)
void removeBridges(int dir, int num0, int num1, int num2, int i) {
	// remove any impossible bridges
	if (allIslands[i].isIsland) {
		for (int j = 0; j < 81; j++) {
			// look for a possible bridge combination with an specified impossible combination
			if (allIslands[i].allPossibleBridges[j][0] != -1) {
				// removing 0 bridge possibility
				if (num0) {
					// check if the this is a bridge possibility with 0 bridges at dir
					if (allIslands[i].allPossibleBridges[j][dir] == 0) {
						allIslands[i].allPossibleBridges[j][0] = -1;
						allIslands[i].allPossibleBridges[j][1] = -1;
						allIslands[i].allPossibleBridges[j][2] = -1;
						allIslands[i].allPossibleBridges[j][3] = -1;
						allIslands[i].totalPossibilities--;
						if (allIslands[i].totalPossibilities < 0) {
							printf("removeBridges");
						}
					}
				}
				// removing 1 bridge possibility
				if (num1) {
					// check if the this is a bridge possibility with 1 bridge at dir
					if (allIslands[i].allPossibleBridges[j][dir] == 1) {
						allIslands[i].allPossibleBridges[j][0] = -1;
						allIslands[i].allPossibleBridges[j][1] = -1;
						allIslands[i].allPossibleBridges[j][2] = -1;
						allIslands[i].allPossibleBridges[j][3] = -1;
						allIslands[i].totalPossibilities--;
						if (allIslands[i].totalPossibilities < 0) {
							printf("removeBridges");
						}
					}
				}
				// removing 2 bridge possibilty
				if (num2) {
					// check if the this is a bridge possibility with 2 bridges at dir
					if (allIslands[i].allPossibleBridges[j][dir] == 2) {
						allIslands[i].allPossibleBridges[j][0] = -1;
						allIslands[i].allPossibleBridges[j][1] = -1;
						allIslands[i].allPossibleBridges[j][2] = -1;
						allIslands[i].allPossibleBridges[j][3] = -1;
						allIslands[i].totalPossibilities--;
						if (allIslands[i].totalPossibilities < 0) {
							printf("removeBridges");
						}
					}
				}
			}
		}
	}
}


// remove the possibilities from island neighbors to island that are impossible
void sievingExcludeImpossibility(int i, int n) {
	int x = 0;
	int y = 0;
	int new_i = 0;

	for (int j = 0; j < 3; j++) {
		// check if up_island has proper bridge value to island
		if (allIslands[i].up_bridge[j] == -1 && allIslands[i].up_islands != NULL) {
			if (allIslands[i].up_islands->down_bridge[j] == j) {
				allIslands[i].up_islands->down_bridge[j] = -1;
				x = allIslands[i].up_islands->x_pos;
				y = allIslands[i].up_islands->y_pos;
				new_i = y * n + x;
				if (j == 0) {
					// remove 0 bridge possibilities
					removeBridges(1, 1, 0, 0, new_i);
				}
				else if (j == 1) {
					// remove 1 bridge possibilities
					removeBridges(1, 0, 1, 0, new_i);
				}
				else {
					// remove 2 bridge possibilities
					removeBridges(1, 0, 0, 1, new_i);
				}
			}
		}
		// check if down_island has proper bridge value to island
		if (allIslands[i].down_bridge[j] == -1 && allIslands[i].down_islands != NULL) {
			if (allIslands[i].down_islands->up_bridge[j] == j) {
				allIslands[i].down_islands->up_bridge[j] = -1;
				x = allIslands[i].down_islands->x_pos;
				y = allIslands[i].down_islands->y_pos;
				new_i = y * n + x;
				if (j == 0) {
					// remove 0 bridge possibilities
					removeBridges(0, 1, 0, 0, new_i);
				}
				else if (j == 1) {
					// remove 1 bridge possibilities
					removeBridges(0, 0, 1, 0, new_i);
				}
				else {
					// remove 2 bridge possibilities
					removeBridges(0, 0, 0, 1, new_i);
				}
			}
		}
		// check if left_island has proper bridge value to island
		if (allIslands[i].left_bridge[j] == -1 && allIslands[i].left_islands != NULL) {
			if (allIslands[i].left_islands->right_bridge[j] == j) {
				allIslands[i].left_islands->right_bridge[j] = -1;
				x = allIslands[i].left_islands->x_pos;
				y = allIslands[i].left_islands->y_pos;
				new_i = y * n + x;
				if (j == 0) {
					// remove 0 bridge possibilities
					removeBridges(3, 1, 0, 0, new_i);
				}
				else if (j == 1) {
					// remove 1 bridge possibilities
					removeBridges(3, 0, 1, 0, new_i);
				}
				else {
					// remove 2 bridge possibilities
					removeBridges(3, 0, 0, 1, new_i);
				}
			}
		}
		// check if right_island has proper bridge value to island
		if (allIslands[i].right_bridge[j] == -1 && allIslands[i].right_islands != NULL) {
			if (allIslands[i].right_islands->left_bridge[j] == j) {
				allIslands[i].right_islands->left_bridge[j] = -1;
				x = allIslands[i].right_islands->x_pos;
				y = allIslands[i].right_islands->y_pos;
				new_i = y * n + x;
				if (j == 0) {
					// remove 0 bridge possibilities
					removeBridges(2, 1, 0, 0, new_i);
				}
				else if (j == 1) {
					// remove 1 bridge possibilities
					removeBridges(2, 0, 1, 0, new_i);
				}
				else {
					// remove 2 bridge possibilities
					removeBridges(2, 0, 0, 1, new_i);
				}
			}
		}
	}
}

// interect the remaining possibilities, removing the minimum/maximum number of bridges that can be chosen
	// this is used on up_bridges, down_bridges, left_bridges, right_bridges (all array of ints)
		// once there is only 1 value that isn't -1 in each array of ints, then that bridge is the final number
		// game is finished when every array of ints for each struct for each island is only 1 value left
void intersection(int n, int i) {
	int oneUp = -1; int zeroUp = -1; int twoUp = -1;
	int oneDown = -1; int zeroDown = -1; int twoDown = -1;
	int oneLeft = -1; int zeroLeft = -1; int twoLeft = -1;
	int oneRight = -1; int zeroRight = -1; int twoRight = -1;
	
	for (int j = 0; j < 81; j++) {
			if (allIslands[i].allPossibleBridges[j][0] == 1)
				oneUp = 1;
			if (allIslands[i].allPossibleBridges[j][1] == 1)
				oneDown = 1;
			if (allIslands[i].allPossibleBridges[j][2] == 1)
				oneLeft = 1;
			if (allIslands[i].allPossibleBridges[j][3] == 1)
				oneRight = 1;

			if (allIslands[i].allPossibleBridges[j][0] == 2)
				twoUp = 1;
			if (allIslands[i].allPossibleBridges[j][1] == 2)
				twoDown = 1;
			if (allIslands[i].allPossibleBridges[j][2] == 2)
				twoLeft = 1;
			if (allIslands[i].allPossibleBridges[j][3] == 2)
				twoRight = 1;

			if (allIslands[i].allPossibleBridges[j][0] == 0)
				zeroUp = 1;
			if (allIslands[i].allPossibleBridges[j][1] == 0)
				zeroDown = 1;
			if (allIslands[i].allPossibleBridges[j][2] == 0)
				zeroLeft = 1;
			if (allIslands[i].allPossibleBridges[j][3] == 0)
				zeroRight = 1;
		}

		if (zeroUp == -1)
			allIslands[i].up_bridge[0] = -1;
		if (zeroDown == -1)
			allIslands[i].down_bridge[0] = -1;
		if (zeroLeft == -1)
			allIslands[i].left_bridge[0] = -1;
		if (zeroRight == -1)
			allIslands[i].right_bridge[0] = -1;

		if (oneUp == -1)
			allIslands[i].up_bridge[1] = -1;
		if (oneDown == -1)
			allIslands[i].down_bridge[1] = -1;
		if (oneLeft == -1)
			allIslands[i].left_bridge[1] = -1;
		if (oneRight == -1)
			allIslands[i].right_bridge[1] = -1;

		if (twoUp == -1)
			allIslands[i].up_bridge[2] = -1;
		if (twoDown == -1)
			allIslands[i].down_bridge[2] = -1;
		if (twoLeft == -1)
			allIslands[i].left_bridge[2] = -1;
		if (twoRight == -1)
			allIslands[i].right_bridge[2] = -1;
	
}

// sets up each island allPossibleBridges array with every possible one
void setUpAllBridges(int n) {
	int e;
	for (int i = 0; i < n; i++) {
		if (allIslands[i].isIsland) {
			e = 0;
			// number if bridges going up
			for (int a = 0; a <= 2; a++) {
				// number of bridges going down
				for (int b = 0; b <= 2; b++) {
					// number of bridges going left
					for (int c = 0; c <= 2; c++) {
						// number of bridges going right
						for (int d = 0; d <= 2; d++) {
							// otherwise set up the bridge possibities
								allIslands[i].allPossibleBridges[e][0] = a; // up bridge
								allIslands[i].allPossibleBridges[e][1] = b; // down bridge
								allIslands[i].allPossibleBridges[e][2] = c; // left bridge
								allIslands[i].allPossibleBridges[e][3] = d; // right bridge
								e++;
						}
					}
				}
			}
		}
	}
}

