#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "life.h"

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */


/* If c is alive and has fewer than 2 live neighbors, it dies.
If c is alive and has more than 3 live neighbors, it dies.
If c is alive and has exactly 2 or 3 live neighbors, it remains alive.
If c is dead and has exactly 3 live neighbors, it becomes alive.
*/

char** addborderstogrid(char** grid);
void printgrid(char** grid);
int countliveneighbors(char** grid, int x, int y);
void updategridonegeneration(char** swapgrids[2]);
void updategridntimes(char** swapgrids[2], int n);
char** copygrid(char** grid);

int main(int argc, char *argv[])
{
  if (argc > 3 || argc < 2){
    //printf("%d",argc);
    printf("error");
    return 1;
  }

  char** grid = parse_life(argv[1]);
  char** copy = addborderstogrid(grid);
  //char** copy2 = addborderstogrid(grid);
  char** grids[2] = {copy,copy};
  //printgrid(grids[0]);

  //char*** grids = (char**)calloc(2,sizeof(char**));
  grids[0] = copy;
  grids[1] = copy;

  int n = atoi(argv[2]);

  updategridntimes(grids,n);
  //updategridonegeneration(grids[1]);
  printgrid(grids[1]);

  return 0;
}

char** addborderstogrid(char** grid){
  char** borderedgrid = (char**)calloc(GRIDY+2,sizeof(char*));
  for (int i = 0; i < GRIDY+2; i ++){
    borderedgrid[i] = (char*)calloc(GRIDX+2,sizeof(char));
    for (int j = 0; j < GRIDX+2; j ++){
      if (i == 0 || i == GRIDY+1 || j == 0 || j == GRIDX+1){
        borderedgrid[i][j] = ' ';
      }else{
        borderedgrid[i][j] = grid[i-1][j-1];
      }
    }
  }
  return borderedgrid;
}

void printgrid(char** grid){
  for (int i = 1; i < GRIDY+1; i++){
    for (int j = 1; j < GRIDX+1; j++){
      if (grid[i][j] == LIVE){
        //printf(":");
        //printf("%d", countliveneighbors(grid,j,i));
        //printf(":");
        printf("%c",grid[i][j]);
      }else if (countliveneighbors(grid,j,i) > 0){
        //printf("%c",grid[i][j]);
        //printf(":");
        //printf("%d", countliveneighbors(grid,j,i));
        //rintf(":");
        printf("%c",grid[i][j]);
      }else{
        printf("%c",grid[i][j]);
      }
    }
    printf("\n");
  }
}

int countliveneighbors(char** grid, int x, int y){
  int count = 0;
  if (grid[y][x] == LIVE){
    count = -1;
  }
  for (int i = y-1; i <= y+1; i++){
    for (int j = x-1; j <= x+1; j++){
      if (grid[i][j] == LIVE){
        count ++;
      }
    }
  }
  return count;
}

void updategridonegeneration(char*** swapgrids){
  char** copy = copygrid(swapgrids[0]);
  for (int i = 1; i < GRIDY+1; i++){
    for (int j = 1; j < GRIDX+1; j++){
      char cell = swapgrids[0][i][j];
      int livecellcount = countliveneighbors(swapgrids[0],j,i);
      if (cell == LIVE && livecellcount < 2){
        copy[i][j] = DEAD;
      }else if (cell == LIVE && livecellcount > 3){
        copy[i][j] = DEAD;
      }else if (cell == LIVE && (livecellcount == 2 || livecellcount == 3)){
        copy[i][j] = LIVE;
      }else if (cell == DEAD && livecellcount == 3){
        copy[i][j] = LIVE;
      }
    }
  }
  swapgrids[0] = copy;
  swapgrids[1] = copy;
}

void updategridntimes(char*** swapgrids, int n){
  for (int i = 0; i < n; i++){
    updategridonegeneration(swapgrids);
  }
  //printgrid(swapgrids[1]);
}

char** copygrid(char** grid){
  char** copy = (char**)calloc(GRIDY+2,sizeof(char*));
  for (int i = 0; i < GRIDY+2; i++){
    copy[i] = (char*)calloc(GRIDX+2,sizeof(char));
    for (int j = 0; j < GRIDX+2; j++){
      copy[i][j] = grid[i][j];
    }
  }
  return copy;
}


/* If c is alive and has fewer than 2 live neighbors, it dies.
If c is alive and has more than 3 live neighbors, it dies.
If c is alive and has exactly 2 or 3 live neighbors, it remains alive.
If c is dead and has exactly 3 live neighbors, it becomes alive.
*/













