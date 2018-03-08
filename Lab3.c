#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_LEN 256
#define GRID_DIM 9

//void *rows(int puzzleGrid[GRID_DIM][GRID_DIM]);

/*int cmp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}*/

int main() {
  //Defined Variables, Arrays and Pointers
  char buffer[MAX_LEN];//malloc
  int puzzleGrid[GRID_DIM][GRID_DIM];
  int countRow = 0;
  int countCol = 0;
  int index = 0;
  void *rowPointer;

/*
  //Create threads
  pthread_t thread_rows;
  pthread_create(&thread_rows, NULL, rows, puzzleGrid);
  
  //Join threads for row
  pthread_join(thread_rows, &rowPointer);
*/
  // Read contents from puzzle.txt and stores values in puzzleGrid
  FILE *puzzleFP = fopen("puzzle.txt","r");
  if (puzzleFP == NULL)
  {
    printf("Error:");
    exit(0);
  }

  while (fgets(buffer, MAX_LEN, puzzleFP) != NULL && countRow < GRID_DIM)
  {

    for (int i = 0; i < GRID_DIM*2; i+=2)
    {
      puzzleGrid[countRow][countCol] = buffer[i] - '0';
      countCol++;
    }
    countCol = 0;
    countRow++;
  }
  //printf("%d\n", puzzleGrid[GRID_DIM][GRID_DIM]);
  return 0;
 // printf("\n");
}



//Checks each row 
/*void *rows(int puzzleGrid[GRID_DIM][GRID_DIM]) {
  int i, j;
  int temp = 0;
  int values[9];
  int validArray[GRID_DIM] = {0};

  for (int i = 0; i < GRID_DIM; i++) {
    for(int j = 0; j < GRID_DIM; j++) {
      values[j] = puzzleGrid[j][i];
      
    }
    qsort(values,9,sizeof(int),cmp);
  
  for(int k = 0; k < GRID_DIM; k++) {
    if(values[k] == values[k+1]) {
      validArray[k] = 1;
    } else{
      validArray[k] = 0;
    }
  }
  }
}*/
