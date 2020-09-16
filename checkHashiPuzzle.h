#ifndef CHECKHASHIPUZZLE_H
#define CHECKHASHIPUZZLE_H
#define _ALLOW_KEYWORD_MACROS


int checkIfPossibilityEachIsland(int n);
void createSpecificBoard_9();
void createSpecificBoard_100();
void createSpecificBoardHard_100();
void createSpecificBoardMedium_100();
void createSpecificBoardEasy_100();
void createSpecificBoardEasy2_625();
void createSpecificBoardEasy2_100();

void createIsland(int i, int s);

void createTempStruct(int n);
void reGetStoredStruct(int n);

void printThings(int n);
int numIslandsWithMultPossibilities(int n);
void checkFullyConnected(int n, int i);
int checkAllVisited(int n);
void resetVisited(int n);

int* findIslandWithCurrPossibility(int n, int curr);
int onePossibilityEachIsland(int n);
int countNumPossibilities(int n);
int findSolution(int n, int i, int j);


int checkIfPossDontMatch(n);

#endif
