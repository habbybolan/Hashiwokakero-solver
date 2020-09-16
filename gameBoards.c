#include "createBoard.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "checkHashiPuzzle.h"
#include "gameBoards.h"

void createSpecificBoard_100() {
	for (int i = 0; i < 100; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 19;

	allIslands[0].x_pos = 0;
	allIslands[0].y_pos = 0;
	allIslands[0].isIsland = 1;
	allIslands[0].value = 3;

	allIslands[8].x_pos = 8;
	allIslands[8].y_pos = 0;
	allIslands[8].isIsland = 1;
	allIslands[8].value = 2;

	allIslands[12].x_pos = 2;
	allIslands[12].y_pos = 1;
	allIslands[12].isIsland = 1;
	allIslands[12].value = 4;

	allIslands[14].x_pos = 4;
	allIslands[14].y_pos = 1;
	allIslands[14].isIsland = 1;
	allIslands[14].value = 4;

	allIslands[17].x_pos = 7;
	allIslands[17].y_pos = 1;
	allIslands[17].isIsland = 1;
	allIslands[17].value = 3;

	allIslands[19].x_pos = 9;
	allIslands[19].y_pos = 1;
	allIslands[19].isIsland = 1;
	allIslands[19].value = 3;

	allIslands[32].x_pos = 2;
	allIslands[32].y_pos = 3;
	allIslands[32].isIsland = 1;
	allIslands[32].value = 5;

	allIslands[38].x_pos = 8;
	allIslands[38].y_pos = 3;
	allIslands[38].isIsland = 1;
	allIslands[38].value = 3;

	allIslands[50].x_pos = 0;
	allIslands[50].y_pos = 5;
	allIslands[50].isIsland = 1;
	allIslands[50].value = 4;

	allIslands[52].x_pos = 2;
	allIslands[52].y_pos = 5;
	allIslands[52].isIsland = 1;
	allIslands[52].value = 7;

	allIslands[58].x_pos = 8;
	allIslands[58].y_pos = 5;
	allIslands[58].isIsland = 1;
	allIslands[58].value = 6;

	allIslands[69].x_pos = 9;
	allIslands[69].y_pos = 6;
	allIslands[69].isIsland = 1;
	allIslands[69].value = 2;

	allIslands[70].x_pos = 0;
	allIslands[70].y_pos = 7;
	allIslands[70].isIsland = 1;
	allIslands[70].value = 2;

	allIslands[73].x_pos = 3;
	allIslands[73].y_pos = 7;
	allIslands[73].isIsland = 1;
	allIslands[73].value = 2;

	allIslands[78].x_pos = 8;
	allIslands[78].y_pos = 7;
	allIslands[78].isIsland = 1;
	allIslands[78].value = 4;

	allIslands[90].x_pos = 0;
	allIslands[90].y_pos = 9;
	allIslands[90].isIsland = 1;
	allIslands[90].value = 1;

	allIslands[92].x_pos = 2;
	allIslands[92].y_pos = 9;
	allIslands[92].isIsland = 1;
	allIslands[92].value = 2;

	allIslands[97].x_pos = 7;
	allIslands[97].y_pos = 9;
	allIslands[97].isIsland = 1;
	allIslands[97].value = 3;

	allIslands[99].x_pos = 9;
	allIslands[99].y_pos = 9;
	allIslands[99].isIsland = 1;
	allIslands[99].value = 2;

}

void createSpecificBoardHard_100() {
	for (int i = 0; i < 100; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 20;

	allIslands[0].x_pos = 0;
	allIslands[0].y_pos = 0;
	allIslands[0].isIsland = 1;
	allIslands[0].value = 2;

	allIslands[2].x_pos = 2;
	allIslands[2].y_pos = 0;
	allIslands[2].isIsland = 1;
	allIslands[2].value = 2;

	allIslands[7].x_pos = 7;
	allIslands[7].y_pos = 0;
	allIslands[7].isIsland = 1;
	allIslands[7].value = 1;

	allIslands[9].x_pos = 9;
	allIslands[9].y_pos = 0;
	allIslands[9].isIsland = 1;
	allIslands[9].value = 1;

	allIslands[20].x_pos = 0;
	allIslands[20].y_pos = 2;
	allIslands[20].isIsland = 1;
	allIslands[20].value = 2;

	allIslands[29].x_pos = 9;
	allIslands[29].y_pos = 2;
	allIslands[29].isIsland = 1;
	allIslands[29].value = 3;

	allIslands[31].x_pos = 1;
	allIslands[31].y_pos = 3;
	allIslands[31].isIsland = 1;
	allIslands[31].value = 3;

	allIslands[38].x_pos = 8;
	allIslands[38].y_pos = 3;
	allIslands[38].isIsland = 1;
	allIslands[38].value = 2;

	allIslands[47].x_pos = 7;
	allIslands[47].y_pos = 4;
	allIslands[47].isIsland = 1;
	allIslands[47].value = 1;

	allIslands[52].x_pos = 2;
	allIslands[52].y_pos = 5;
	allIslands[52].isIsland = 1;
	allIslands[52].value = 2;

	allIslands[54].x_pos = 4;
	allIslands[54].y_pos = 5;
	allIslands[54].isIsland = 1;
	allIslands[54].value = 4;

	allIslands[56].x_pos = 6;
	allIslands[56].y_pos = 5;
	allIslands[56].isIsland = 1;
	allIslands[56].value = 2;

	allIslands[72].x_pos = 2;
	allIslands[72].y_pos = 7;
	allIslands[72].isIsland = 1;
	allIslands[72].value = 2;

	allIslands[74].x_pos = 4;
	allIslands[74].y_pos = 7;
	allIslands[74].isIsland = 1;
	allIslands[74].value = 3;

	allIslands[77].x_pos = 7;
	allIslands[77].y_pos = 7;
	allIslands[77].isIsland = 1;
	allIslands[77].value = 5;

	allIslands[79].x_pos = 9;
	allIslands[79].y_pos = 7;
	allIslands[79].isIsland = 1;
	allIslands[79].value = 2;

	allIslands[91].x_pos = 1;
	allIslands[91].y_pos = 9;
	allIslands[91].isIsland = 1;
	allIslands[91].value = 3;

	allIslands[95].x_pos = 5;
	allIslands[95].y_pos = 9;
	allIslands[95].isIsland = 1;
	allIslands[95].value = 3;

	allIslands[97].x_pos = 7;
	allIslands[97].y_pos = 9;
	allIslands[97].isIsland = 1;
	allIslands[97].value = 5;

	allIslands[99].x_pos = 9;
	allIslands[99].y_pos = 9;
	allIslands[99].isIsland = 1;
	allIslands[99].value = 2;




}

void createSpecificBoardMedium_100() {
	for (int i = 0; i < 100; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 34;

	allIslands[2].x_pos = 2;
	allIslands[2].y_pos = 0;
	allIslands[2].isIsland = 1;
	allIslands[2].value = 2;

	allIslands[4].x_pos = 4;
	allIslands[4].y_pos = 0;
	allIslands[4].isIsland = 1;
	allIslands[4].value = 2;

	allIslands[6].x_pos = 6;
	allIslands[6].y_pos = 0;
	allIslands[6].isIsland = 1;
	allIslands[6].value = 2;

	allIslands[8].x_pos = 8;
	allIslands[8].y_pos = 0;
	allIslands[8].isIsland = 1;
	allIslands[8].value = 2;

	allIslands[10].x_pos = 0;
	allIslands[10].y_pos = 1;
	allIslands[10].isIsland = 1;
	allIslands[10].value = 1;

	allIslands[13].x_pos = 3;
	allIslands[13].y_pos = 1;
	allIslands[13].isIsland = 1;
	allIslands[13].value = 3;

	allIslands[17].x_pos = 7;
	allIslands[17].y_pos = 1;
	allIslands[17].isIsland = 1;
	allIslands[17].value = 1;

	allIslands[19].x_pos = 9;
	allIslands[19].y_pos = 1;
	allIslands[19].isIsland = 1;
	allIslands[19].value = 1;

	allIslands[22].x_pos = 2;
	allIslands[22].y_pos = 2;
	allIslands[22].isIsland = 1;
	allIslands[22].value = 1;

	allIslands[25].x_pos = 5;
	allIslands[25].y_pos = 2;
	allIslands[25].isIsland = 1;
	allIslands[25].value = 1;

	allIslands[28].x_pos = 8;
	allIslands[28].y_pos = 2;
	allIslands[28].isIsland = 1;
	allIslands[28].value = 3;

	allIslands[30].x_pos = 0;
	allIslands[30].y_pos = 3;
	allIslands[30].isIsland = 1;
	allIslands[30].value = 5;

	allIslands[33].x_pos = 3;
	allIslands[33].y_pos = 3;
	allIslands[33].isIsland = 1;
	allIslands[33].value = 6;

	allIslands[37].x_pos = 7;
	allIslands[37].y_pos = 3;
	allIslands[37].isIsland = 1;
	allIslands[37].value = 1;

	allIslands[49].x_pos = 9;
	allIslands[49].y_pos = 4;
	allIslands[49].isIsland = 1;
	allIslands[49].value = 2;

	allIslands[50].x_pos = 0;
	allIslands[50].y_pos = 5;
	allIslands[50].isIsland = 1;
	allIslands[50].value = 4;

	allIslands[53].x_pos = 3;
	allIslands[53].y_pos = 5;
	allIslands[53].isIsland = 1;
	allIslands[53].value = 3;

	allIslands[55].x_pos = 5;
	allIslands[55].y_pos = 5;
	allIslands[55].isIsland = 1;
	allIslands[55].value = 3;

	allIslands[58].x_pos = 8;
	allIslands[58].y_pos = 5;
	allIslands[58].isIsland = 1;
	allIslands[58].value = 3;

	allIslands[61].x_pos = 1;
	allIslands[61].y_pos = 6;
	allIslands[61].isIsland = 1;
	allIslands[61].value = 3;

	allIslands[64].x_pos = 4;
	allIslands[64].y_pos = 6;
	allIslands[64].isIsland = 1;
	allIslands[64].value = 3;

	allIslands[66].x_pos = 6;
	allIslands[66].y_pos = 6;
	allIslands[66].isIsland = 1;
	allIslands[66].value = 1;

	allIslands[70].x_pos = 0;
	allIslands[70].y_pos = 7;
	allIslands[70].isIsland = 1;
	allIslands[70].value = 1;

	allIslands[75].x_pos = 5;
	allIslands[75].y_pos = 7;
	allIslands[75].isIsland = 1;
	allIslands[75].value = 1;

	allIslands[79].x_pos = 9;
	allIslands[79].y_pos = 7;
	allIslands[79].isIsland = 1;
	allIslands[79].value = 3;

	allIslands[82].x_pos = 2;
	allIslands[82].y_pos = 8;
	allIslands[82].isIsland = 1;
	allIslands[82].value = 1;

	allIslands[84].x_pos = 4;
	allIslands[84].y_pos = 8;
	allIslands[84].isIsland = 1;
	allIslands[84].value = 3;

	allIslands[86].x_pos = 6;
	allIslands[86].y_pos = 8;
	allIslands[86].isIsland = 1;
	allIslands[86].value = 3;

	allIslands[88].x_pos = 8;
	allIslands[88].y_pos = 8;
	allIslands[88].isIsland = 1;
	allIslands[88].value = 2;

	allIslands[91].x_pos = 1;
	allIslands[91].y_pos = 9;
	allIslands[91].isIsland = 1;
	allIslands[91].value = 2;

	allIslands[93].x_pos = 3;
	allIslands[93].y_pos = 9;
	allIslands[93].isIsland = 1;
	allIslands[93].value = 2;

	allIslands[95].x_pos = 5;
	allIslands[95].y_pos = 9;
	allIslands[95].isIsland = 1;
	allIslands[95].value = 3;

	allIslands[97].x_pos = 7;
	allIslands[97].y_pos = 9;
	allIslands[97].isIsland = 1;
	allIslands[97].value = 3;

	allIslands[99].x_pos = 9;
	allIslands[99].y_pos = 9;
	allIslands[99].isIsland = 1;
	allIslands[99].value = 3;
}

void createSpecificBoardEasy_100() {
	for (int i = 0; i < 100; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 28;

	allIslands[1].x_pos = 1;
	allIslands[1].y_pos = 0;
	allIslands[1].isIsland = 1;
	allIslands[1].value = 2;

	allIslands[3].x_pos = 3;
	allIslands[3].y_pos = 0;
	allIslands[3].isIsland = 1;
	allIslands[3].value = 3;

	allIslands[5].x_pos = 5;
	allIslands[5].y_pos = 0;
	allIslands[5].isIsland = 1;
	allIslands[5].value = 3;

	allIslands[7].x_pos = 7;
	allIslands[7].y_pos = 0;
	allIslands[7].isIsland = 1;
	allIslands[7].value = 3;

	allIslands[10].x_pos = 0;
	allIslands[10].y_pos = 1;
	allIslands[10].isIsland = 1;
	allIslands[10].value = 2;

	allIslands[19].x_pos = 9;
	allIslands[19].y_pos = 1;
	allIslands[19].isIsland = 1;
	allIslands[19].value = 1;

	allIslands[21].x_pos = 1;
	allIslands[21].y_pos = 2;
	allIslands[21].isIsland = 1;
	allIslands[21].value = 1;

	allIslands[24].x_pos = 4;
	allIslands[24].y_pos = 2;
	allIslands[24].isIsland = 1;
	allIslands[24].value = 2;

	allIslands[27].x_pos = 7;
	allIslands[27].y_pos = 2;
	allIslands[27].isIsland = 1;
	allIslands[27].value = 6;

	allIslands[30].x_pos = 0;
	allIslands[30].y_pos = 3;
	allIslands[30].isIsland = 1;
	allIslands[30].value = 5;

	allIslands[33].x_pos = 3;
	allIslands[33].y_pos = 3;
	allIslands[33].isIsland = 1;
	allIslands[33].value = 4;

	allIslands[36].x_pos = 6;
	allIslands[36].y_pos = 3;
	allIslands[36].isIsland = 1;
	allIslands[36].value = 2;

	allIslands[49].x_pos = 9;
	allIslands[49].y_pos = 4;
	allIslands[49].isIsland = 1;
	allIslands[49].value = 2;

	allIslands[52].x_pos = 2;
	allIslands[52].y_pos = 5;
	allIslands[52].isIsland = 1;
	allIslands[52].value = 3;

	allIslands[54].x_pos = 4;
	allIslands[54].y_pos = 5;
	allIslands[54].isIsland = 1;
	allIslands[54].value = 3;

	allIslands[57].x_pos = 7;
	allIslands[57].y_pos = 5;
	allIslands[57].isIsland = 1;
	allIslands[57].value = 3;

	allIslands[60].x_pos = 0;
	allIslands[60].y_pos = 6;
	allIslands[60].isIsland = 1;
	allIslands[60].value = 2;

	allIslands[65].x_pos = 5;
	allIslands[65].y_pos = 6;
	allIslands[65].isIsland = 1;
	allIslands[65].value = 3;

	allIslands[69].x_pos = 9;
	allIslands[69].y_pos = 6;
	allIslands[69].isIsland = 1;
	allIslands[69].value = 5;

	allIslands[74].x_pos = 4;
	allIslands[74].y_pos = 7;
	allIslands[74].isIsland = 1;
	allIslands[74].value = 1;

	allIslands[80].x_pos = 0;
	allIslands[80].y_pos = 8;
	allIslands[80].isIsland = 1;
	allIslands[80].value = 3;

	allIslands[82].x_pos = 2;
	allIslands[82].y_pos = 8;
	allIslands[82].isIsland = 1;
	allIslands[82].value = 5;

	allIslands[85].x_pos = 5;
	allIslands[85].y_pos = 8;
	allIslands[85].isIsland = 1;
	allIslands[85].value = 3;

	allIslands[88].x_pos = 8;
	allIslands[88].y_pos = 8;
	allIslands[88].isIsland = 1;
	allIslands[88].value = 1;

	allIslands[91].x_pos = 1;
	allIslands[91].y_pos = 9;
	allIslands[91].isIsland = 1;
	allIslands[91].value = 2;

	allIslands[93].x_pos = 3;
	allIslands[93].y_pos = 9;
	allIslands[93].isIsland = 1;
	allIslands[93].value = 3;

	allIslands[96].x_pos = 6;
	allIslands[96].y_pos = 9;
	allIslands[96].isIsland = 1;
	allIslands[96].value = 3;

	allIslands[99].x_pos = 9;
	allIslands[99].y_pos = 9;
	allIslands[99].isIsland = 1;
	allIslands[99].value = 4;
}

void createSpecificBoardEasy2_625() {
	for (int i = 0; i < 625; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 101;

	allIslands[0].x_pos = 0;
	allIslands[0].y_pos = 0;
	allIslands[0].isIsland = 1;
	allIslands[0].value = 3;

	allIslands[2].x_pos = 2;
	allIslands[2].y_pos = 0;
	allIslands[2].isIsland = 1;
	allIslands[2].value = 6;

	allIslands[4].x_pos = 4;
	allIslands[4].y_pos = 0;
	allIslands[4].isIsland = 1;
	allIslands[4].value = 5;

	allIslands[14].x_pos = 14;
	allIslands[14].y_pos = 0;
	allIslands[14].isIsland = 1;
	allIslands[14].value = 3;

	allIslands[16].x_pos = 16;
	allIslands[16].y_pos = 0;
	allIslands[16].isIsland = 1;
	allIslands[16].value = 3;

	allIslands[18].x_pos = 18;
	allIslands[18].y_pos = 0;
	allIslands[18].isIsland = 1;
	allIslands[18].value = 4;

	allIslands[20].x_pos = 20;
	allIslands[20].y_pos = 0;
	allIslands[20].isIsland = 1;
	allIslands[20].value = 3;

	allIslands[22].x_pos = 22;
	allIslands[22].y_pos = 0;
	allIslands[22].isIsland = 1;
	allIslands[22].value = 5;

	allIslands[24].x_pos = 24;
	allIslands[24].y_pos = 0;
	allIslands[24].isIsland = 1;
	allIslands[24].value = 3;

	allIslands[42].x_pos = 17;
	allIslands[42].y_pos = 1;
	allIslands[42].isIsland = 1;
	allIslands[42].value = 1;

	allIslands[56].x_pos = 6;
	allIslands[56].y_pos = 2;
	allIslands[56].isIsland = 1;
	allIslands[56].value = 3;

	allIslands[63].x_pos = 13;
	allIslands[63].y_pos = 2;
	allIslands[63].isIsland = 1;
	allIslands[63].value = 2;

	allIslands[66].x_pos = 16;
	allIslands[66].y_pos = 2;
	allIslands[66].isIsland = 1;
	allIslands[66].value = 1;

	allIslands[74].x_pos = 24;
	allIslands[74].y_pos = 2;
	allIslands[74].isIsland = 1;
	allIslands[74].value = 3;

	allIslands[75].x_pos = 0;
	allIslands[75].y_pos = 3;
	allIslands[75].isIsland = 1;
	allIslands[75].value = 3;

	allIslands[97].x_pos = 22;
	allIslands[97].y_pos = 3;
	allIslands[97].isIsland = 1;
	allIslands[97].value = 2;

	allIslands[106].x_pos = 6;
	allIslands[106].y_pos = 4;
	allIslands[106].isIsland = 1;
	allIslands[106].value = 3;

	allIslands[111].x_pos = 11;
	allIslands[111].y_pos = 4;
	allIslands[111].isIsland = 1;
	allIslands[111].value = 5;

	allIslands[114].x_pos = 14;
	allIslands[114].y_pos = 4;
	allIslands[114].isIsland = 1;
	allIslands[114].value = 5;

	allIslands[117].x_pos = 17;
	allIslands[117].y_pos = 4;
	allIslands[117].isIsland = 1;
	allIslands[117].value = 4;

	allIslands[132].x_pos = 7;
	allIslands[132].y_pos = 5;
	allIslands[132].isIsland = 1;
	allIslands[132].value = 2;

	allIslands[134].x_pos = 9;
	allIslands[134].y_pos = 5;
	allIslands[134].isIsland = 1;
	allIslands[134].value = 3;

	allIslands[147].x_pos = 22;
	allIslands[147].y_pos = 5;
	allIslands[147].isIsland = 1;
	allIslands[147].value = 2;

	allIslands[149].x_pos = 24;
	allIslands[149].y_pos = 5;
	allIslands[149].isIsland = 1;
	allIslands[149].value = 5;

	allIslands[150].x_pos = 0;
	allIslands[150].y_pos = 6;
	allIslands[150].isIsland = 1;
	allIslands[150].value = 3;

	allIslands[156].x_pos = 6;
	allIslands[156].y_pos = 6;
	allIslands[156].isIsland = 1;
	allIslands[156].value = 3;

	allIslands[158].x_pos = 8;
	allIslands[158].y_pos = 6;
	allIslands[158].isIsland = 1;
	allIslands[158].value = 2;

	allIslands[162].x_pos = 12;
	allIslands[162].y_pos = 6;
	allIslands[162].isIsland = 1;
	allIslands[162].value = 4;

	allIslands[164].x_pos = 14;
	allIslands[164].y_pos = 6;
	allIslands[164].isIsland = 1;
	allIslands[164].value = 2;

	allIslands[167].x_pos = 17;
	allIslands[167].y_pos = 6;
	allIslands[167].isIsland = 1;
	allIslands[167].value = 2;

	allIslands[198].x_pos = 23;
	allIslands[198].y_pos = 7;
	allIslands[198].isIsland = 1;
	allIslands[198].value = 1;

	allIslands[204].x_pos = 4;
	allIslands[204].y_pos = 8;
	allIslands[204].isIsland = 1;
	allIslands[204].value = 4;

	allIslands[209].x_pos = 9;
	allIslands[209].y_pos = 8;
	allIslands[209].isIsland = 1;
	allIslands[209].value = 4;

	allIslands[253].x_pos = 3;
	allIslands[253].y_pos = 10;
	allIslands[253].isIsland = 1;
	allIslands[253].value = 2;

	allIslands[257].x_pos = 7;
	allIslands[257].y_pos = 10;
	allIslands[257].isIsland = 1;
	allIslands[257].value = 3;

	allIslands[259].x_pos = 9;
	allIslands[259].y_pos = 10;
	allIslands[259].isIsland = 1;
	allIslands[259].value = 2;

	allIslands[262].x_pos = 12;
	allIslands[262].y_pos = 10;
	allIslands[262].isIsland = 1;
	allIslands[262].value = 3;

	allIslands[268].x_pos = 18;
	allIslands[268].y_pos = 10;
	allIslands[268].isIsland = 1;
	allIslands[268].value = 2;

	allIslands[275].x_pos = 0;
	allIslands[275].y_pos = 11;
	allIslands[275].isIsland = 1;
	allIslands[275].value = 5;

	allIslands[277].x_pos = 2;
	allIslands[277].y_pos = 11;
	allIslands[277].isIsland = 1;
	allIslands[277].value = 8;

	allIslands[279].x_pos = 4;
	allIslands[279].y_pos = 11;
	allIslands[279].isIsland = 1;
	allIslands[279].value = 5;

	allIslands[286].x_pos = 11;
	allIslands[286].y_pos = 11;
	allIslands[286].isIsland = 1;
	allIslands[286].value = 7;

	allIslands[295].x_pos = 20;
	allIslands[295].y_pos = 11;
	allIslands[295].isIsland = 1;
	allIslands[295].value = 7;

	allIslands[297].x_pos = 22;
	allIslands[297].y_pos = 11;
	allIslands[297].isIsland = 1;
	allIslands[297].value = 4;

	allIslands[299].x_pos = 24;
	allIslands[299].y_pos = 11;
	allIslands[299].isIsland = 1;
	allIslands[299].value = 3;

	allIslands[301].x_pos = 1;
	allIslands[301].y_pos = 12;
	allIslands[301].isIsland = 1;
	allIslands[301].value = 2;

	allIslands[312].x_pos = 12;
	allIslands[312].y_pos = 12;
	allIslands[312].isIsland = 1;
	allIslands[312].value = 2;

	allIslands[317].x_pos = 17;
	allIslands[317].y_pos = 12;
	allIslands[317].isIsland = 1;
	allIslands[317].value = 4;

	allIslands[327].x_pos = 2;
	allIslands[327].y_pos = 13;
	allIslands[327].isIsland = 1;
	allIslands[327].value = 2;

	allIslands[331].x_pos = 6;
	allIslands[331].y_pos = 13;
	allIslands[331].isIsland = 1;
	allIslands[331].value = 2;

	allIslands[336].x_pos = 11;
	allIslands[336].y_pos = 13;
	allIslands[336].isIsland = 1;
	allIslands[336].value = 5;

	allIslands[340].x_pos = 15;
	allIslands[340].y_pos = 13;
	allIslands[340].isIsland = 1;
	allIslands[340].value = 1;

	allIslands[351].x_pos = 1;
	allIslands[351].y_pos = 14;
	allIslands[351].isIsland = 1;
	allIslands[351].value = 5;

	allIslands[354].x_pos = 4;
	allIslands[354].y_pos = 14;
	allIslands[354].isIsland = 1;
	allIslands[354].value = 5;

	allIslands[367].x_pos = 17;
	allIslands[367].y_pos = 14;
	allIslands[367].isIsland = 1;
	allIslands[367].value = 7;

	allIslands[369].x_pos = 19;
	allIslands[369].y_pos = 14;
	allIslands[369].isIsland = 1;
	allIslands[369].value = 3;

	allIslands[372].x_pos = 22;
	allIslands[372].y_pos = 14;
	allIslands[372].isIsland = 1;
	allIslands[372].value = 1;

	allIslands[377].x_pos = 2;
	allIslands[377].y_pos = 15;
	allIslands[377].isIsland = 1;
	allIslands[377].value = 2;

	allIslands[380].x_pos = 5;
	allIslands[380].y_pos = 15;
	allIslands[380].isIsland = 1;
	allIslands[380].value = 2;

	allIslands[385].x_pos = 10;
	allIslands[385].y_pos = 15;
	allIslands[385].isIsland = 1;
	allIslands[385].value = 2;

	allIslands[387].x_pos = 12;
	allIslands[387].y_pos = 15;
	allIslands[387].isIsland = 1;
	allIslands[387].value = 6;

	allIslands[389].x_pos = 14;
	allIslands[389].y_pos = 15;
	allIslands[389].isIsland = 1;
	allIslands[389].value = 2;

	allIslands[404].x_pos = 4;
	allIslands[404].y_pos = 16;
	allIslands[404].isIsland = 1;
	allIslands[404].value = 2;

	allIslands[413].x_pos = 13;
	allIslands[413].y_pos = 16;
	allIslands[413].isIsland = 1;
	allIslands[413].value = 1;

	allIslands[415].x_pos = 15;
	allIslands[415].y_pos = 16;
	allIslands[415].isIsland = 1;
	allIslands[415].value = 2;

	allIslands[417].x_pos = 17;
	allIslands[417].y_pos = 16;
	allIslands[417].isIsland = 1;
	allIslands[417].value = 3;

	allIslands[419].x_pos = 19;
	allIslands[419].y_pos = 16;
	allIslands[419].isIsland = 1;
	allIslands[419].value = 2;

	allIslands[424].x_pos = 24;
	allIslands[424].y_pos = 16;
	allIslands[424].isIsland = 1;
	allIslands[424].value = 1;

	allIslands[430].x_pos = 5;
	allIslands[430].y_pos = 17;
	allIslands[430].isIsland = 1;
	allIslands[430].value = 6;

	allIslands[433].x_pos = 8;
	allIslands[433].y_pos = 17;
	allIslands[433].isIsland = 1;
	allIslands[433].value = 6;

	allIslands[437].x_pos = 12;
	allIslands[437].y_pos = 17;
	allIslands[437].isIsland = 1;
	allIslands[437].value = 7;

	allIslands[443].x_pos = 18;
	allIslands[443].y_pos = 17;
	allIslands[443].isIsland = 1;
	allIslands[443].value = 2;

	allIslands[452].x_pos = 2;
	allIslands[452].y_pos = 18;
	allIslands[452].isIsland = 1;
	allIslands[452].value = 4;

	allIslands[454].x_pos = 4;
	allIslands[454].y_pos = 18;
	allIslands[454].isIsland = 1;
	allIslands[454].value = 5;

	allIslands[459].x_pos = 9;
	allIslands[459].y_pos = 18;
	allIslands[459].isIsland = 1;
	allIslands[459].value = 3;

	allIslands[461].x_pos = 11;
	allIslands[461].y_pos = 18;
	allIslands[461].isIsland = 1;
	allIslands[461].value = 2;

	allIslands[465].x_pos = 15;
	allIslands[465].y_pos = 18;
	allIslands[465].isIsland = 1;
	allIslands[465].value = 2;

	allIslands[469].x_pos = 19;
	allIslands[469].y_pos = 18;
	allIslands[469].isIsland = 1;
	allIslands[469].value = 3;

	allIslands[475].x_pos = 0;
	allIslands[475].y_pos = 19;
	allIslands[475].isIsland = 1;
	allIslands[475].value = 2;

	allIslands[488].x_pos = 13;
	allIslands[488].y_pos = 19;
	allIslands[488].isIsland = 1;
	allIslands[488].value = 4;

	allIslands[491].x_pos = 16;
	allIslands[491].y_pos = 19;
	allIslands[491].isIsland = 1;
	allIslands[491].value = 5;

	allIslands[495].x_pos = 20;
	allIslands[495].y_pos = 19;
	allIslands[495].isIsland = 1;
	allIslands[495].value = 8;

	allIslands[498].x_pos = 23;
	allIslands[498].y_pos = 19;
	allIslands[498].isIsland = 1;
	allIslands[498].value = 4;

	allIslands[503].x_pos = 3;
	allIslands[503].y_pos = 20;
	allIslands[503].isIsland = 1;
	allIslands[503].value = 1;

	allIslands[518].x_pos = 18;
	allIslands[518].y_pos = 20;
	allIslands[518].isIsland = 1;
	allIslands[518].value = 2;

	allIslands[525].x_pos = 0;
	allIslands[525].y_pos = 21;
	allIslands[525].isIsland = 1;
	allIslands[525].value = 2;

	allIslands[529].x_pos = 4;
	allIslands[529].y_pos = 21;
	allIslands[529].isIsland = 1;
	allIslands[529].value = 2;

	allIslands[551].x_pos = 1;
	allIslands[551].y_pos = 22;
	allIslands[551].isIsland = 1;
	allIslands[551].value = 1;

	allIslands[578].x_pos = 3;
	allIslands[578].y_pos = 23;
	allIslands[578].isIsland = 1;
	allIslands[578].value = 3;

	allIslands[580].x_pos = 5;
	allIslands[580].y_pos = 23;
	allIslands[580].isIsland = 1;
	allIslands[580].value = 5;

	allIslands[583].x_pos = 8;
	allIslands[583].y_pos = 23;
	allIslands[583].isIsland = 1;
	allIslands[583].value = 3;

	allIslands[588].x_pos = 13;
	allIslands[588].y_pos = 23;
	allIslands[588].isIsland = 1;
	allIslands[588].value = 2;

	allIslands[591].x_pos = 16;
	allIslands[591].y_pos = 23;
	allIslands[591].isIsland = 1;
	allIslands[591].value = 2;

	allIslands[593].x_pos = 18;
	allIslands[593].y_pos = 23;
	allIslands[593].isIsland = 1;
	allIslands[593].value = 3;

	allIslands[600].x_pos = 0;
	allIslands[600].y_pos = 24;
	allIslands[600].isIsland = 1;
	allIslands[600].value = 3;

	allIslands[602].x_pos = 2;
	allIslands[602].y_pos = 24;
	allIslands[602].isIsland = 1;
	allIslands[602].value = 3;

	allIslands[606].x_pos = 6;
	allIslands[606].y_pos = 24;
	allIslands[606].isIsland = 1;
	allIslands[606].value = 3;

	allIslands[609].x_pos = 9;
	allIslands[609].y_pos = 24;
	allIslands[609].isIsland = 1;
	allIslands[609].value = 5;

	allIslands[612].x_pos = 12;
	allIslands[612].y_pos = 24;
	allIslands[612].isIsland = 1;
	allIslands[612].value = 4;

	allIslands[620].x_pos = 20;
	allIslands[620].y_pos = 24;
	allIslands[620].isIsland = 1;
	allIslands[620].value = 5;

	allIslands[623].x_pos = 23;
	allIslands[623].y_pos = 24;
	allIslands[623].isIsland = 1;
	allIslands[623].value = 3;

}

void createSpecificBoard_49() {
	for (int i = 0; i < 49; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}

	numIslands = 10;

	allIslands[0].x_pos = 0;
	allIslands[0].y_pos = 0;
	allIslands[0].isIsland = 1;
	allIslands[0].value = 4;

	allIslands[2].x_pos = 2;
	allIslands[2].y_pos = 0;
	allIslands[2].isIsland = 1;
	allIslands[2].value = 6;

	allIslands[4].x_pos = 4;
	allIslands[4].y_pos = 0;
	allIslands[4].isIsland = 1;
	allIslands[4].value = 4;

	allIslands[6].x_pos = 6;
	allIslands[6].y_pos = 0;
	allIslands[6].isIsland = 1;
	allIslands[6].value = 2;

	allIslands[20].x_pos = 6;
	allIslands[20].y_pos = 2;
	allIslands[20].isIsland = 1;
	allIslands[20].value = 4;

	allIslands[23].x_pos = 2;
	allIslands[23].y_pos = 3;
	allIslands[23].isIsland = 1;
	allIslands[23].value = 2;

	allIslands[42].x_pos = 0;
	allIslands[42].y_pos = 6;
	allIslands[42].isIsland = 1;
	allIslands[42].value = 4;

	allIslands[44].x_pos = 2;
	allIslands[44].y_pos = 6;
	allIslands[44].isIsland = 1;
	allIslands[44].value = 4;

	allIslands[46].x_pos = 4;
	allIslands[46].y_pos = 6;
	allIslands[46].isIsland = 1;
	allIslands[46].value = 6;

	allIslands[48].x_pos = 6;
	allIslands[48].y_pos = 6;
	allIslands[48].isIsland = 1;
	allIslands[48].value = 4;
}

void createSpecificBoardEasy2_100() {
	for (int i = 0; i < 100; i++) {
		allIslands[i].x_pos = 0;
		allIslands[i].y_pos = 0;
		allIslands[i].value = -1;
		allIslands[i].isIsland = 0;
		allIslands[i].visited = 0;
		allIslands[i].totalPossibilities = 81;
		allIslands[i].up_bridge[0] = 0; allIslands[i].up_bridge[1] = 1; allIslands[i].up_bridge[2] = 2;
		allIslands[i].down_bridge[0] = 0; allIslands[i].down_bridge[1] = 1; allIslands[i].down_bridge[2] = 2;
		allIslands[i].left_bridge[0] = 0; allIslands[i].left_bridge[1] = 1; allIslands[i].left_bridge[2] = 2;
		allIslands[i].right_bridge[0] = 0; allIslands[i].right_bridge[1] = 1; allIslands[i].right_bridge[2] = 2;
	}
	numIslands = 22;

	allIslands[1].x_pos = 1;
	allIslands[1].y_pos = 0;
	allIslands[1].isIsland = 1;
	allIslands[1].value = 3;

	allIslands[3].x_pos = 3;
	allIslands[3].y_pos = 0;
	allIslands[3].isIsland = 1;
	allIslands[3].value = 4;

	allIslands[7].x_pos = 7;
	allIslands[7].y_pos = 0;
	allIslands[7].isIsland = 1;
	allIslands[7].value = 4;

	allIslands[9].x_pos = 9;
	allIslands[9].y_pos = 0;
	allIslands[9].isIsland = 1;
	allIslands[9].value = 3;

	allIslands[10].x_pos = 0;
	allIslands[10].y_pos = 1;
	allIslands[10].isIsland = 1;
	allIslands[10].value = 1;

	allIslands[28].x_pos = 8;
	allIslands[28].y_pos = 2;
	allIslands[28].isIsland = 1;
	allIslands[28].value = 1;

	allIslands[31].x_pos = 1;
	allIslands[31].y_pos = 3;
	allIslands[31].isIsland = 1;
	allIslands[31].value = 2;

	allIslands[35].x_pos = 5;
	allIslands[35].y_pos = 3;
	allIslands[35].isIsland = 1;
	allIslands[35].value = 1;

	allIslands[37].x_pos = 7;
	allIslands[37].y_pos = 3;
	allIslands[37].isIsland = 1;
	allIslands[37].value = 2;

	allIslands[40].x_pos = 0;
	allIslands[40].y_pos = 4;
	allIslands[40].isIsland = 1;
	allIslands[40].value = 4;

	allIslands[43].x_pos = 3;
	allIslands[43].y_pos = 4;
	allIslands[43].isIsland = 1;
	allIslands[43].value = 7;

	allIslands[48].x_pos = 8;
	allIslands[48].y_pos = 4;
	allIslands[48].isIsland = 1;
	allIslands[48].value = 5;

	allIslands[59].x_pos = 9;
	allIslands[59].y_pos = 5;
	allIslands[59].isIsland = 1;
	allIslands[59].value = 3;

	allIslands[64].x_pos = 4;
	allIslands[64].y_pos = 6;
	allIslands[64].isIsland = 1;
	allIslands[64].value = 2;

	allIslands[68].x_pos = 8;
	allIslands[68].y_pos = 6;
	allIslands[68].isIsland = 1;
	allIslands[68].value = 4;

	allIslands[70].x_pos = 0;
	allIslands[70].y_pos = 7;
	allIslands[70].isIsland = 1;
	allIslands[70].value = 1;

	allIslands[84].x_pos = 4;
	allIslands[84].y_pos = 8;
	allIslands[84].isIsland = 1;
	allIslands[84].value = 1;

	allIslands[87].x_pos = 7;
	allIslands[87].y_pos = 8;
	allIslands[87].isIsland = 1;
	allIslands[87].value = 2;

	allIslands[89].x_pos = 9;
	allIslands[89].y_pos = 8;
	allIslands[89].isIsland = 1;
	allIslands[89].value = 2;

	allIslands[90].x_pos = 0;
	allIslands[90].y_pos = 9;
	allIslands[90].isIsland = 1;
	allIslands[90].value = 2;

	allIslands[93].x_pos = 3;
	allIslands[93].y_pos = 9;
	allIslands[93].isIsland = 1;
	allIslands[93].value = 5;

	allIslands[98].x_pos = 8;
	allIslands[98].y_pos = 9;
	allIslands[98].isIsland = 1;
	allIslands[98].value = 1;
}