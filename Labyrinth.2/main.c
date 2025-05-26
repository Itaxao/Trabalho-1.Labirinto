 #pragma region Bibliotecas
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #define LINE 5
  #define COLUMN 10
  #define ENEMIES 15
#pragma endregion

  // Matrix length.
  char matrix[LINE][COLUMN];
  // Positions of enemys and spawn in the matrix.
  void GeneratePositions(int *enemy_randIndexLine, int *enemy_randIndexColumn, int *spawn_randIndexLine, int *spawn_randIndexColumn, int *exit_randIndexLine, int *exit_randIndexColumn){
    // Random number of indexLine and Column in a range from 0 to 6 and 0 to 11, respectivamente.
      *enemy_randIndexLine = rand() % LINE;
      *enemy_randIndexColumn = rand() % COLUMN;
      *exit_randIndexLine = rand() % LINE;
      *exit_randIndexColumn = rand() % COLUMN;

    // Loop for verification if spawn and enemy is equal, case is, do it again.
    do
    {
      *spawn_randIndexLine = rand() % LINE;
      *spawn_randIndexColumn = rand() % COLUMN;
    } while (*enemy_randIndexLine == *spawn_randIndexLine && *enemy_randIndexColumn == *spawn_randIndexColumn);
  }
  // Fill of the matrix.
  void MatrixFill(){
      // Variable declaration
      int enemy_randIndexLine, enemy_randIndexColumn;
      int spawn_randIndexLine, spawn_randIndexColumn;
      int exit_randIndexLine, exit_randIndexColumn;
      int count = 0;

      // Run through matrix and fill each index with '*' character.
      for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN;j++){
          matrix[i][j] = '*';
        }
      }
      // Call the function GeneratePositions for using the enemy and spawn.
      GeneratePositions(&enemy_randIndexLine,&enemy_randIndexColumn,&spawn_randIndexLine,&spawn_randIndexColumn,&exit_randIndexLine,&exit_randIndexColumn);

      // Spawn Index
      matrix[spawn_randIndexLine][spawn_randIndexColumn] = 'H';

      // Enemy Index with a loop for creating more than one enemy
      while(count < ENEMIES)
      {
        enemy_randIndexLine = rand() % LINE;
        enemy_randIndexColumn = rand() % COLUMN;
        if(matrix[enemy_randIndexLine][enemy_randIndexColumn] == '*')
        {
          matrix[enemy_randIndexLine][enemy_randIndexColumn] = 'R';
          count++;
        }
      }
      if(matrix[exit_randIndexLine][exit_randIndexColumn] == '*')
        matrix[exit_randIndexLine][exit_randIndexColumn] = 'E';
  }
  // Print of the matrix.
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
  // Intialize the program.
  int main(){
    // Srand parameter to create a random number based on time from machine
    srand(time(NULL));
    Labyrinth();
    return 0;
  }
