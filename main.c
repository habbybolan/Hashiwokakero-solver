#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "createBoard.h"
#include "checkHashiPuzzle.h"
#include "main.h"
#include <stdbool.h>

int main() {
	int boardNum = userInputBoard();
	// sets the size of allIslands. (sqrt(n) x sqrt(n) size board)
	int n = createBoard(boardNum); 
		setNeighbors(n);
		setUpAllBridges(n);

		basicInformation(n);
		sievingMethods(n);
		
		// stuff calculated for calling checkFullyConnectd 
			// uses dfs to find if every island is fully connected
		int everyIsland = checkNumIslands(n);
		
		createTempStruct(n); // store current struct into storage
		printThings(n);
		
		int allPossibilities = countNumPossibilities(n); // all possibilities found so far
		int currPossibility = 0; // keeps track of the current possibility being assumed
		int* array;
		array = malloc(2 * sizeof(int));
		int end = 0;
		while (end < 1000) {
			int i = 0; // holds island to make assumption on
			int j = 0; // holds possiblity to make assumption on
			// make assumptions, and use ratiocinationa and mistake testing - FIND THE SOLUTION
			currPossibility = 0;
			while (currPossibility != allPossibilities) {
				reGetStoredStruct(n);

				array = findIslandWithCurrPossibility(n, currPossibility);
				i = array[0];
				j = array[1];
				if (findSolution(n, i, j)) {

					for (int j = 0; j < n; j++) {
						if (allIslands[j].isIsland)
							printf("\nIsland (%d,%d) with value %d: visited = %d"
								, allIslands[j].x_pos, allIslands[j].y_pos, allIslands[j].value, allIslands[j].visited);
					}

					printThings(n);

					printf("\nSOLUTION IS FOUND!!!!!!!!!!!!!!!!!!!!!");
					end = 1000;
					break;
				}
				else { // otherwise make assumptions about new possibilities.
					currPossibility++;
				}
			}
			end++;
		}
		system("pause");
}

// ask user to input the board to sovle and check if value is valid
int userInputBoard() {
	int boardNum;
	char r[10];
	printf("%s", "enter a board to solve: \n");
	printAllBoard();
	int len;
	while (1) {
		scanf("%2s", r);
		len = strlen(r);
		if (isValidDigit(r, len)) {
			boardNum = atoi(r);
			if (0 >= boardNum <= 6) {
				break;
			}
		}
		else {
			printf("%s\n", "please enter a number from 0-6: ");
		}
	}
	return boardNum;
}

// check if each character is a valid digit
bool isValidDigit(char* f, int len) {
	int isValidDigit;
	for (int i = 0; i < len; i++) {
		isValidDigit = isdigit(f[i]);
		if (isValidDigit == 0) {
			return false;
		}
	}
	return true;
}

void printAllBoard() {
	printf("%s", "0: 100x100 board \n");
	printf("%s", "1: 100x100 easy board \n");
	printf("%s", "2: 100x100 easy2 board \n");
	printf("%s", "3: 100x100 medium board \n");
	printf("%s", "4: 100x100 hard board \n");
	printf("%s", "5: 7x7 board \n");
	printf("%s", "6: 625x625 board \n");
}
