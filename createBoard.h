#ifndef CREATEBOARD_H
#define CREATEBOARD_H
#define _ALLOW_KEYWORD_MACROS

struct islands {
	int isIsland; // 
	int value; //  value for the bridge (-1 if no value)
	int currValue; // remaining value for the bridge (-1 if no value)
	int x_pos; // x position of bridge
	int y_pos; // y position of bridge
	int visited; // check if the island has been visited to check for connectivity

	struct islands* up_islands; // island directly up
	struct islands* down_islands; // island directly down
	struct islands* left_islands; // island directly left
	struct islands* right_islands; // island directly right
	int total_bridges; // total number of bridges connected

	struct islands* finalIsland_Up; // island up if that connection is guaranteed
	struct islands* finalIsland_Down; // island down if that connection is guaranteed
	struct islands* finalIsland_Left; // island left if that connection is guaranteed
	struct islands* finalIsland_Right; // island right if that connection is guaranteed

		// set any of the indices to -1 if it doesn't have contain a certain number of bridges
			// for example, if there is 2 bridges up, but not 1 or 0 bridges, then up_bridge[0]=-1, up_bridge[1]=-1, up_bridge[2] = 2
	int up_bridge[3]; // island directly up (0, 1, or 2 bridges)
	int down_bridge[3]; // island directly down (0, 1, or 2 bridges)
	int left_bridge[3]; // island directly left (0, 1, or 2 bridges)
	int right_bridge[3]; // island directly right (0, 1, or 2 bridges)
	int allPossibleBridges[81][4];// all possible bridges from island node
		// 80 for 3^4-1 possibilities, while 4 for up, down, left right	
		// [i][0] = up, [i][1] = down, [i][2] = left, [i][3] = right 
		// 0 = 0 bridges, 1 = 1 bridge, 2 = 2 bridges
	int totalPossibilities; // the total number of possibilities left over

	int up_blocked; // if island up is blocked
	int down_blocked; // if island down is blocked
	int left_blocked; // if island left is blocked
	int right_blocked; // if island right is blocked
};  
struct islands allIslands[625];
struct islands store_allIslands[625];

int createBoard(int n);
void setNeighbors(int n);
void setUpAllBridges(int n);
void printBoard(int n);

void printIntersection(int i);

void basicInformation(int n);
void sievingMethods(int n);
void sievingCrossingBridges(int n, int i);
void removeBridges(int dir, int num0, int num1, int num2, int i);
void sievingNumBridges(int n, int i);
void intersection(int n, int i);
void applyGuaranteedBridges(int t);
int noZeroBridges(int dir, int t);
void removePossibilitiesNoNeighbors(int n, int i);
void sievingExcludeImpossibility(int i, int n);


#endif
