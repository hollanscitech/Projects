#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* 
F1 (ft_putchar) //writes characters
F2 (formatArgv) //formats argv inputs
F3 (makeSudoku) // 
F4 (printSudoku) //writes every character of a 2D array onto the standard output 
*/

//F1
void ft_putchar(char c) {
  write(1, &c, 1);
}

//F2
char **formatArgv(int argc, char *argv) {
  char **formArr;
  formArr = (char**) malloc(sizeof(char*) * (argc));
  int i	= 0;
  int argvLength = strlen(argv[i]);
  char *argvStr;
  argvStr = (char*) malloc(sizeof(char) * (argvLength + 1));

  return formArr;
}
  
/*
//F3
char **makeSudoku(int argc, char *argv) {
  char **sudoku;
  sudoku = (char**) malloc(sizeof(char*) * (argc));
  int i = 0;
  int argvLength = argv[i];
  char *str;
  str = (char*) malloc(sizeof(char) * (argvLength + 1));
  int y = 0;
  while (argv) {
    str[i] = argv[i];
    i++;
  }
  str[i] = '\0';
  sudoku[y] = str;
  return sudoku;
}
*/

//F4
void printSudoku(char **sudoku) {
  int x = 0;
  int y = 0;
  while(sudoku[y] != NULL) {
    x = 0;
    while(sudoku[y][x] != '\0') {
      ft_putchar(sudoku[y][x]);
      x++;
    }
    ft_putchar('\n');
    y++;
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1 && argc <= 10) {
    int y = 1;
    while (argv[y] != NULL) {
      formatArgv(argc, argv[y]);
      y++;
    }
  }
  return 0;
}

  
