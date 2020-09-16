# HashiwokakeroConsole

Solver for the hashiwokakero problem https://en.wikipedia.org/wiki/Hashiwokakero, programmed in C using an elimination search algorithm
elimination search algorithm: https://ieeexplore.ieee.org/document/6007662


createBoard.c
- chooses a board to use and implements the basic information elimination and sieveing/intersection


gameBoards.c
- holds all the specific game board manually inputted

checkHashiPuzzle.c
- checks if the hashi puzzle is solved and implements part of the elimination search part of the algorithm
  - for the elimination search, the function findSolution calls itself, each time sieving given the new assumption, removing other possibilities within that island that is not the assumption made, and finding a new assumption by random
    - returns 1 if a solution is found, 0 otherwise

main.c
- creates the board, runs the program, and implements the beginning part of the elimination search part
  - for the elimination search, main chooses the first assumption to make for all possibilities, then deterministically goes through all of them after the first sieve/intersect until a solution is found, or all possibilities have been looked at
  
  output: returns each island with it's final possibility (the number of bridges going up/down/left/right) left over if a solution is found.
    otherwise, solution is not found
    
    
