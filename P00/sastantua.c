#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char a) {
  write(1, &a, 1);
}

int ft_atoi(char *str) {
  int i = 0;
  int number = 0;
  int sign = 1;
  while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')) {
    i++;
  }
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  if (str[i] == '+') {
    i++;
  }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
    number = (number * 10) + str[i] - 48;
    i++;
  }
  return number * sign;
}

int ft_GetHeight(int size) {
  int height = 0;
  int counter = 1;
  while (counter <= size) {
    height = counter + height + 2;
    counter++;
  }
  return height;
}

int ft_GetWidth(int size) {
  int width = 7;
  int counter = 1;
  int difference = 12;
  if (size == 0) {
    return (0);
  }
  while (counter < size) {
    width += difference;
    if (counter % 2 == 1) {
      difference += 2;
    }
    else {
      difference += (counter + 2);
    }
    counter++;
  }
  printf("%d\n", width);
  printf("%d\n", difference);
  return width;
}

void sastantua(int size) {
  int height = ft_GetHeight(size);
  int width = ft_GetWidth(size);
  int y = 0;
  int x = 0;
  while (y < height) {
    x = 0;
    //ft_putchar('/');
    while (x < width) {
      ft_putchar('*');
      x++;
    }
    //ft_putchar(92);
    ft_putchar('\n');
    y++;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    sastantua(ft_atoi(argv[1]));
  }
  else {
    return 0;
  }
}
