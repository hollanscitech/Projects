#include <stdio.h>

int nmatch(char *s1, char *s2) {
  //deals with "example" "" == 0 || "" "" == 1
  if (*s2 == '\0') {
    if(*s1 != '\0') {
      return 0;
    }
    else {
      return 1;
    }
  }
  //deals with a star char
  if (*s2 == '*') {
    char *rest = s1;
    int count = 0;
    while (*rest != '\0') {
      count = count + nmatch(rest, s2 + 1);
      rest++;
    }
    count = count + nmatch(rest, s2 + 1);
    return count;
  }
  //deals with s1 being empty && *s2 not being a star && s2 not being empty
  if (*s1 == '\0') {
    return 0;
  }
  //iterates through both strings as long as the pointers are equal each time
  if (*s2 == *s1) {
    return nmatch(s1 + 1, s2 + 1);
  }
  else {
    return 0;
  }
}

void test(void) {
  //Test 1
  if (nmatch("hello", "hello") == 1) {
    int count = nmatch("hello", "hello");
    printf("Test 1 Passed\nS1: hello\nS2: hello\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 2
  if (nmatch("hello", "h") == 0) {
    int count = nmatch("hello", "h");
    printf("Test 2 Passed\nS1: hello\nS2: h\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 3
  if (nmatch("hello", "hell") == 0) {
    int count = nmatch("hello", "hell");
    printf("Test 3 Passed\nS1: hello\nS2: hell\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 4
  if (nmatch("", " ") == 0) {
    int count = nmatch("", " ");
    printf("Test 4 Passed\nS1: ''\nS2: ' '\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 5
  if (nmatch("", "") == 1) {
    int count = nmatch("", "");
    printf("Test 5 Passed\nS1: ''\nS2: ''\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 6
  if (nmatch(" ", "*") == 1) {
    int count = nmatch(" ", "*");
    printf("Test 6 Passed\nS1: ' '\nS2: *\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 7
  if (nmatch("hello", "*") == 1) {
    int count = nmatch("hello", "*");
    printf("Test 7 Passed\nS1: hello\nS2: *\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 8
  if (nmatch("hello", "h") == 0) {
    int count = nmatch("hello", "h");
    printf("Test 8 Passed\nS1: hello\nS2: h\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 9
  if (nmatch("hello", "he") == 0) {
    int count = nmatch("hello", "he");
    printf("Test 9 Passed\nS1: hello\nS2: he\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 10
  if (nmatch("hello", "h*") == 1) {
    int count = nmatch("hello", "h*");
    printf("Test 10 Passed\nS1: hello\nS2: h*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 11
  if (nmatch("hello", "hlo") == 0) {
    int count = nmatch("hello", "hlo");
    printf("Test 11 Passed\nS1: hello\nS2: hlo\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 12
  if (nmatch("hello", "hell*") == 1) {
    int count = nmatch("hello", "hell*");
    printf("Test 12 Passed\nS1: hello\nS2: hell*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 13
  if (nmatch("hello", "hello*") == 1) {
    int count = nmatch("hello", "hello*");
    printf("Test 13 Passed\nS1: hello\nS2: hello*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 14
  if (nmatch("hello", "he*") == 1) {
    int count = nmatch("hello", "he*");
    printf("Test 14 Passed\nS1: hello\nS2: he*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 15
  if (nmatch("hello", "lo") == 0) {
    int count = nmatch("hello", "lo");
    printf("Test 15 Passed\nS1: hello\nS2: lo\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 16
  if (nmatch("abcbd", "*b*") == 2) {
    int count = nmatch("abcbd", "*b*");
    printf("Test 16 Passed\nS1: abcbd\nS2: *b*\nExpected Output: 2\nOutput Received: %d\n\n", count);
  }
  //Test 17
  if (nmatch("abc", "a**") == 3) {
    int count = nmatch("abc", "a**");
    printf("Test 17 Passed\nS1: abc\nS2: a**\nExpected Output: 3\nOutput Received: %d\n\n", count);
  }
  //Test 18
  if (nmatch("abc", "abc") == 1) {
    int count = nmatch("abc", "abc");
    printf("Test 18 Passed\nS1: abc\nS2: abc\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 19
  if (nmatch("abc", "ab*") == 1) {
    int count = nmatch("abc", "ab*");
    printf("Test 19 Passed\nS1: abc\nS2: ab*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 20
  if (nmatch("abc", "abc*") == 1) {
    int count = nmatch("abc", "abc*");
    printf("Test 20 Passed\nS1: abc\nS2: abc*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 21
  if (nmatch("abc", "*") == 1) {
    int count = nmatch("abc", "*");
    printf("Test 21 Passed\nS1: abc\nS2: *\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 22
  if (nmatch("abc", "**") == 4) {
    int count = nmatch("abc", "**");
    printf("Test 22 Passed\nS1: abc\nS2: **\nExpected Output: 4\nOutput Received: %d\n\n", count);
  }
  //Test 23
  if (nmatch("abc", "***") == 10) {
    int count = nmatch("abc", "***");
    printf("Test 23 Passed\nS1: abc\nS2: ***\nExpected Output: 10\nOutput Received: %d\n\n", count);
  }
  //Test 24
  if (nmatch("abc", "**a") == 0) {
    int count = nmatch("abc", "**a");
    printf("Test 24 Passed\nS1: abc\nS2: **a\nExpected Output: 0\nOutput Received: %d\n\n", count);
  }
  //Test 25
  if (nmatch("abc", "*a*") == 1) {
    int count = nmatch("abc", "*a*");
    printf("Test 25 Passed\nS1: abc\nS2: *a*\nExpected Output: 1\nOutput Received: %d\n\n", count);
  }
  //Test 26
  if (nmatch("abc", "cba") == 0) {
    int count = nmatch("abc", "cba");
    printf("Test 26 Passed\nS1: abc\nS2: cba\nExpected Output: 0\nOutput Received: %d\n", count);
  }
}

int main(int argc, char *argv[]) {
  test();
  if (argc == 3) {
    char *s1 = argv[1];
    char *s2 = argv[2];
    int output = nmatch(s1, s2);
    printf("%d\n", output);
  }
}
