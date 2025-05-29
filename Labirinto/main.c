  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #define LINE 7
  #define COLUMN 9
  #define ENEMIES 13
    struct Coordinates
    {
      int line;
      int column;
    };
    
  // Matrix length.
  char matrix[LINE][COLUMN];
  // Positions of enemys and spawn in the matrix.
  void GeneratePositions(struct Coordinates *enemy, struct Coordinates *spawn, struct Coordinates *exit){
    // Loop for verification if spawn and enemy and exit is equal, case is, do it again.
    do{
      spawn->line = rand() % LINE;
      spawn->column = rand() % COLUMN;
    } while (enemy->line == spawn->line && enemy->column == spawn->column);
    
    do{
      exit->line = rand() % LINE;
      exit->column = rand() % COLUMN;
    }while((exit->line == enemy->line && exit->column == enemy->column) ||
           (exit->line == spawn->line && exit->column == spawn->column));
  }
  // Fill of the matrix.
  void MatrixFill(){
      // Variable declaration
      struct Coordinates enemy,spawn,exit;
      int count = 0;
      // Run through matrix and fill each index with 'space' character.
      for(int i = 0; i < LINE; i++){
        for(int j = 0; j < COLUMN;j++){
          matrix[i][j] = ' ';
        }
      }
      GeneratePositions(&enemy,&spawn,&exit);
      // Spawn Index
      matrix[spawn.line][spawn.column] = 'H';

      // Enemy Index with a loop for creating more than one enemy.
      while(count < ENEMIES){
        enemy.line = rand() % LINE;
        enemy.column = rand() % COLUMN;
        if(matrix[enemy.line][enemy.column] == ' '){
          matrix[enemy.line][enemy.column] = 'R';
          count++;
        }
      }
      // Index of the exit and verification if is open or not
      if(matrix[exit.line][exit.column] == ' ')
        matrix[exit.line][exit.column] = 'Z';
  }
  // Print of the matrix.
  void Labyrinth() {
    printf("--------------------------LABYRINTH WITH A MATRIX------------------------------------\n");
    for(int i = 0; i < LINE ; i++){
      for(int j = 0; j < COLUMN; j++){
        printf("[%c]", matrix[i][j]);                                                      
      }
      printf("\n");
    }
    printf("------------------------------------------------------------------------------------\n");
  }
  // Find the better way from 'H' to 'Z'.
  int Human_Escape(int x, int y){
    char temp;

    // Verify the limits of the matrix, doing that the program will not be out of bounds.
    if(x < 0 || x>= LINE || y < 0 || y >= COLUMN)
      return 0;

    // Verify the correct path, using the 'R' for enemies or '*' for a path that already has pass
    if (matrix[x][y] == 'R' || matrix[x][y] == '*')
      return 0;

    // Find the exit
    if (matrix[x][y] == 'Z')
      return 1;

    // Temporary variable in case the correct path was not found
    temp = matrix[x][y];
    // Verify if the path is open or is 'H' or 'Z' to keep the H and Z
    if (matrix[x][y] != 'H' && matrix[x][y] != 'Z')
      matrix[x][y] = '*';

    // Array for directions, down, up, right, left, respectively
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < 4 ; i++){
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (Human_Escape(newX,newY))
          return 1;
    }

    matrix[x][y] = temp;
    return 0;
  }
  void PathDFS(){
    // Find the inicial position from human.
    int startX, startY;
    for (int i = 0; i < LINE; i++){
      for (int j = 0; j < COLUMN; j++){
        if (matrix[i][j] == 'H'){
            startX = i;
            startY = j;
            break;
        }
      }
    }
    // End of the game
    if (Human_Escape(startX, startY)){
      printf("PATH FOUND!!!.\n");
      Labyrinth();
    }    
    else{
    printf("PATH WAS NOT FOUND!!.\n");
    }
  }
  int main(){
    // Srand parameter to create a random number based on time from machine.
    srand(time(NULL));
    MatrixFill();
    Labyrinth();
    PathDFS();
    return 0;
  }
