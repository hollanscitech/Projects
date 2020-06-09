#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* 
F1 (ft_putchar) //writes characters
F2 (formatArgv) //formats argv inputs
F3 (putFormStr) //writes every character from formStr onto the standard output 
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

int main(int argc, char* argv[]) {
  if (argc > 1 && argc <= 10) {
    int y = 1;
    while (argv[y] != NULL) {
      formatArgv(argv[y]);
      putFormStr(argv[y]);
      y++;
    }
  }
  return 0;
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
/*
//F4
void printSudoku(char **formArr) {
  int x = 0;
  int y = 0;
  while(formArr[y] != NULL) {
    x = 0;
    while(formArr[y][x] != '\0') {
      ft_putchar(formArr[y][x]);
      x++;
    }
    ft_putchar('\n');
    y++;
  }
}
*/
