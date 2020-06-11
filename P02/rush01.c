#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* 
F1 (ft_putchar)//writes characters
F2 (formatArgv)//formats argv inputs
F3 (sameRow)//determines if the character placement will break Sudoku rules for rows
F4 (sameColumn)//determines if the character placement will break Sudoku rules for columns
F5 (sameSubGrid)//determines if the character placement will break Sudoku rules for subgrids
F6 (solveSudoku)//solves the sudoku 2D array
F7 (printSudoku)//writes every value from a 2D character array onto the standard output
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
int sameRow(int y, int x, char num, char **sudoku) {
  x = 0;
  while (x < 9) {
    if (sudoku[y][x] == num) {
      return 1;
    }
    x++;
  }
  return 0;
}

//F4
int sameColumn(int y, int x, char num, char **sudoku) {
   y = 0;
  while	(y < 9) {
    if (sudoku[y][x] == num) {
      return 1;
    }
    y++;
  }
  return 0;
}

//F5
int sameSubGrid(int y, int x, char num, char **sudoku) {
  if (x < 3) {
    x = 0;
  } else if (x < 6) {
    x = 3;
  } else {
    x = 6;
  }
  if (y < 3) {
    y = 0;
  } else if (y < 6) {
    y = 3;
  } else {
    y = 6;
  }
  int a = y + 3;
  int b = x + 3;
  while (y < a) {
    while (x < b) {
      if (sudoku[y][x] == num) {
	return 1;
      }
      x++;
    }
    y++;
    x = x - 2;
  }
  return 0;
}

//F6
char **solveSudoku(char **sudoku) {
  int x = 0;
  int y = 0;
  char num = '1';
  while (num <= '9') {
    x = 0;
    while (x < 9) {
      if (sudoku[y][x] == '0') {
	if (!sameRow(y, x, num, sudoku) && !sameColumn(y, x, num, sudoku) && !sameSubGrid(y, x, num, sudoku)) {
	  sudoku[y][x] = num;
	}
      }
      x++;
    }
    y++;
    num++;
  }
  return sudoku;
}

//F7
void printSudoku(char **sudoku) {
  int x = 0;
  int y = 0;
  int length = strlen(sudoku[y]);
  while (sudoku[y] != '\0') {
    x = 0;
    while (sudoku[y][x] != '\0') {
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
  if (argc == 10) {
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
    printSudoku(solveSudoku(sudoku));
  }
  return 0;
}
