#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* 
F1 (ft_putchar) //writes characters
F2 (formatArgv) //formats argv inputs
F3 (putFormStr) //writes every value from a 2D character array onto the standard output
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
void printSudoku(char **sudoku) {
  int x = 0;
  int y = 0;
  while(sudoku[y] != '\0') {
    x = 0;
    while(sudoku[y][x] != '\0') {
      ft_putchar(sudoku[y][x]);
      ft_putchar(' ');
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
    printSudoku(sudoku);
  }
  return 0;
}

/*
//F3
void putFormStr(char *argv) {
  int i = 0;
  int argvLength = strlen(argv);
  char *formStr;
  formStr = formatArgv(argv);
  while (i < argvLength) {
    ft_putchar(formStr[i]);
    if (i < (argvLength - 1)) {
        ft_putchar(' ');
      }
    i++;
  }
  ft_putchar('\n');
}
*/

