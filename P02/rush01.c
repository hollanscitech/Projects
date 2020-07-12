#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* 
F1 (ft_putchar) writes characters
F2 (formatArgv) formats argv inputs
F3 (sameRow) determines if the character placement will break Sudoku rules for rows
F4 (sameColumn) determines if the character placement will break Sudoku rules for columns
F5 (sameSubGrid) determines if the character placement will break Sudoku rules for subgrids
F6 (printSudoku) writes every value from a 2D character array onto the standard output
F7 (solveSudoku) solves the sudoku 2D array with recursion and backtracking
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
  x -= x % 3;
  y -= y % 3;
  int xTemp = 0;
  int yTemp = 0;
  while (yTemp < 3) {
    xTemp = 0;
    while (xTemp < 3) {
      if (sudoku[y + yTemp][x + xTemp] == num) {
	return 1;
      }
      xTemp++;
    }
    yTemp++;
  }
  return 0;
}

//F6
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

//F7
int solveSudoku(char **sudoku, int y, int x) {
  int tempX = 0;
  int tempY = 0;
  char num = '1';
  if (sudoku[y][x] != '0') {
    if (y == 8 && x == 8) {
      printSudoku(sudoku);
      return 1;
    }
    if (x < 8) {
      x++;
    } else {
      if (y < 8) {
	x = 0;
	y++;
      }
    }
    if (solveSudoku(sudoku, y, x)) {
      return 1;
    } else {
      return 0;
    }
  }

  if (sudoku[y][x] == '0') {
    while (num <= '9') {
      if (!sameRow(y, x, num, sudoku) && !sameColumn(y, x, num, sudoku) && !sameSubGrid(y, x, num, sudoku)) {
	sudoku[y][x] = num;
	if (y == 8 && x == 8) {
          printSudoku(sudoku);
          return 1;
	}
	if (x < 8) {
	  tempX = x + 1;
	} else {
	  if (y < 8) {
	    tempX = 0;
	    tempY = y + 1;
	  }
	}
	if (solveSudoku(sudoku, tempY, tempX)) {
	  return 1;
	}
      }
      num++;
    }
  }
  sudoku[y][x] = '0';
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc == 10) {
    int y = 0;
    char **sudoku;
    sudoku = (char**) malloc(sizeof(char*) * (argc));
    while (argv[y + 1] != NULL) {
      sudoku[y] = formatArgv(argv[y + 1]);
      y++;
    }
    sudoku[y] = NULL;
    
    ft_putchar('\n');
    printSudoku(sudoku);
    ft_putchar('\n');
    
    y = 0;
    int x = 0;
    solveSudoku(sudoku, y, x);
  }
  return 0;
}
