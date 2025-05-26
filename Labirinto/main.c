  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #define LINE 5
  #define COLUMN 10

  // Matrix length.
  char matrix[LINE][COLUMN];

  // Positions of enemys and spawn in the matrix.
  void GeneratePositions(int *enemy_randIndexLine, int *enemy_randIndexColumn, int *spawn_randIndexLine, int *spawn_randIndexColumn){
    // Random number of indexLine in a range from 0 to 6.
    *enemy_randIndexLine = rand() % LINE;
    *enemy_randIndexColumn = rand() % COLUMN;
    
    // Loop for verification if spawn and enemy is equal, case is, do it again.
    do
    {
      *spawn_randIndexLine = rand() % LINE;
      *spawn_randIndexColumn = rand() % COLUMN;
    }while (*enemy_randIndexLine == *spawn_randIndexLine && *enemy_randIndexColumn == *spawn_randIndexColumn);
    
  // END
  }

  // Run through matrix and fill each index with '*' character.
  void MatrixFill(){
      // Variable declaration
      int enemy_randIndexLine, enemy_randIndexColumn;
      int spawn_randIndexLine, spawn_randIndexColumn;

      for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN;j++){
          matrix[i][j] = '*';
        }
      }
      GeneratePositions(&enemy_randIndexLine,&enemy_randIndexColumn,&spawn_randIndexLine,&spawn_randIndexColumn);
      // Enemy INDEX
      for(int i = 0; i < 11; i++){
        matrix[enemy_randIndexLine][enemy_randIndexColumn] = 'R';
      }
  }


  // Print of labyrinth with for under for.
  void Labyrinth() {

    // Call the function matrixFill.
    MatrixFill();
    for(int i = 0; i < LINE ; i++){
      for(int j = 0; j < COLUMN; j++){
        printf("%c", matrix[i][j]);                                                      
      }
      printf("\n");
    }
  }

  // Intialize the program
  int main(){
    // Srand parameter to create a random number based on time from machine
    srand(time(NULL));
    Labyrinth();
    return 0;
  }
