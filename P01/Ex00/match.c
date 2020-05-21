#include <stdio.h>

int match(char *s1, char *s2) {
  //deals with "example" "" == 0 || "" "" == 1
  if (*s2 == '\0') {
    if(*s1 != '\0') {
      return 0;
    }
    else {
      return 1;
    }
  }
  //deals with star char
  if (*s2 == '*') {
    char *rest = s1;
    int count = 0;
    while (*rest != '\0') {
      count = count + match(rest, s2 + 1);
      rest++;
    }
    count = count + match(rest, s2 + 1);
    return count;
  }
  //deals with s1 being empty && *s2 not being a star && s2 not being empty
  if (*s1 == '\0') {
    return 0;
  }
  //iterates through both strings as long as the pointers are equal each time
  if (*s2 == *s1) {
    return match(s1 + 1, s2 + 1);
  }
  else {
    return 0;
  }
}

void test(void) {
  //Test 1
  if(match("hello", "hello") > 0) {
    printf("Test 1 Passed\nS1: hello\nS2: hello\nOutput: 1\n\n");
  }
  //Test 2
  if(match("match.c", "**.c") > 0) {
    printf("Test 2 Passed\nS1: hello\nS2: hello\nOutput: 1\n\n");
  }
  //Test 3
  if(match("match.c", "mat*ch.c") > 0) {
    printf("Test 3 Passed\nS1: match.c\nS2: mat*ch.c\nOutput: 1\n\n");
  }
  //Test 4
  if(match("match.c", "***adsads***") == 0) {
    printf("Test 4 Passed\nS1: match.c\nS2: ***adsads***\nOutput: 0\n\n");
  }
  //Test 5
  if(match("match.c", "*") > 0) {
    printf("Test 5 Passed\nS1: match.c\nS2: *\nOutput: 1\n\n");
  }
  //Test 6
  if(match("match.c", "*atch.c") > 0) {
    printf("Test 6 Passed\nS1: match.c\nS2: *atch.c\nOutput: 1\n\n");
  }
  //Test 7
  if(match("match.c", "*********c") > 0) {
    printf("Test 7 Passed\nS1: match.c\nS2: *********c\nOutput: 1\n\n");
  }
  //Test 8
  if(match("match.c", "*********") > 0) {
    printf("Test 8 Passed\nS1: match.c\nS2: *********\nOutput: 1\n\n");
  }
  //Test 9
  if(match("abcbd", "*b*") > 0) {
    printf("Test 9 Passed\nS1: abcbd\nS2: *b*\nOutput: 1\n\n");
  }
  //Test 10
  if(match("abc", "a**") > 0) {
    printf("Test 10 Passed\nS1: abc\nS2: a**\nOutput: 1\n\n");
  }
  //Test 11
  if(match("bonjour.c", "********c") > 0) {
    printf("Test 11 Passed\nS1: bonjour.c\nS2: ********c\nOutput: 1\n\n");
  }
  //Test 12
  if(match("bonjour.c", "***") > 0) {
    printf("Test 12 Passed\nS1: bonjour.c\nS2: ***\nOutput: 1\n\n");
  }
  //Test 13
  if(match("bonjour.c", "*.c") > 0) {
    printf("Test 13 Passed\nS1: bonjour.c\nS2: *.c\nOutput: 1\n\n");
  }
  //Test 14
  if(match("match.c", "*m*a****c*.c") > 0) {
    printf("Test 14 Passed\nS1: match.c\nS2: *m*a****c*.c\nOutput: 1\n\n");
  }
  //Test 15
  if(match("match.c", "m*atc*.c") > 0) {
    printf("Test 15 Passed\nS1: match.c\nS2: m*atc*.c\nOutput: 1\n\n");
  }
  //Test 16
  if(match("match.c", "l*h.c") == 0) {
    printf("Test 16 Passed\nS1: match.c\nS2: l*h.c\nOutput: 0\n\n");
  }
  //Test 17
  if(match("match.c", "*h.c") > 0) {
    printf("Test 17 Passed\nS1: match.c\nS2: *h.c\nOutput: 1\n\n");
  }
  //Test 18
  if(match("match.c", "***.c*") > 0) {
    printf("Test 18 Passed\nS1: match.c\nS2: ***.c*\nOutput: 1\n\n");
  }
  //Test 19
  if(match("match.c", "ma*.c") > 0) {
    printf("Test 19 Passed\nS1: match.c\nS2: ma*.c\nOutput: 1\n\n");
  }
  //Test 20
  if(match("match.c", "ma**c****.c") > 0) {
    printf("Test 20 Passed\nS1: match.c\nS2: ma**c****.c\nOutput: 1\n\n");
  }
  //Test 21
  if(match("match.c", "*match.c") > 0) {
    printf("Test 21 Passed\nS1: match.c\nS2: *match.c\nOutput: 1\n");
  }
}

int main(int argc, char *argv[]) {
  test();
  if (argc == 3) {
    int returned = match(argv[1], argv[2]);
    if (returned >= 1) {
      printf("Output: 1\nStrings Match\n");
    }
    if (returned == 0) {
      printf("Output: 0\nStrings Do Not Match\n");
    }
  }
  return 0;
}
