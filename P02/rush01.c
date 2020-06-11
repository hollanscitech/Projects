#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* 
F1 (ft_putchar)//writes characters
F2 (formatArgv)//formats argv inputs
F3 (checkRow)//determines if the character placement will break Sudoku rules for rows
F4 (checkColumn)//determines if the character placement will break Sudoku rules for columns
F5 (checkSubGrid)//determines if the character placement will break Sudoku rules for subgrids
F6 (solveSudoku)//solves the sudoku 2D array
F7 (putFormStr)//writes every value from a 2D character array onto the standard output
*/

//F1
void ft_putchar(char c) {
  write(1, &c, 1);
}

//F2
char *formatArgv(char *argv) {
  int i = 0;
  int argvLength = strlen(argv);
  char *formStr;
  formStr = (char*) malloc(sizeof(char) * (argvLength + 1));
  while (argv[i] != '\0') {
    formStr[i] = argv[i];
    if (argv[i] == '.') {
      formStr[i] = '0';
    }
    i++;
  }
  formStr[i] = '\0';
  return formStr;
}

//F3
//F4
//F5
//F6

//F7
void printSudoku(char **sudoku) {
  int x = 0;
  int y = 0;
  int length = strlen(sudoku[y]);
  while(sudoku[y] != '\0') {
    x = 0;
    while(sudoku[y][x] != '\0') {
      ft_putchar(sudoku[y][x]);
      if (x < (length - 1)) {
	ft_putchar(' ');
      }
      x++;
    }
    ft_putchar('\n');
    y++;
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1 && argc <= 10) {
    int z = 1;
    char **sudoku;
    sudoku = (char**) malloc(sizeof(char*) * (argc));
    int y = 0;
    while (argv[z] != NULL) {
      sudoku[y] = formatArgv(argv[z]);
      y++;
      z++;
    }
    sudoku[y] = NULL;
    ft_putchar('\n');
    printSudoku(sudoku);
    ft_putchar('\n');
  }
  return 0;
}
