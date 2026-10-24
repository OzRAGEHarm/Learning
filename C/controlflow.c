/*
  Control Flow
  compile with gcc -Wall -Wextra -g -o out/controlflow controlflow.c

  Warnings this file gives:
  controlflow.c: In function 'main':
  controlflow.c:13:3: warning: this 'if' clause does not guard... [-Wmisleading-indentation]
    13 |   if (x < 10)
       |   ^~
  controlflow.c:15:5: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'if'
    15 |     printf("unconditional print message because yes\n"); // Unconditional, will print no matter what
       |     ^~~~~~
  controlflow.c:99:7: warning: this statement may fall through [-Wimplicit-fallthrough=]
    99 |       printf("a 0\n");
       |       ^~~~~~~~~~~~~~~
  controlflow.c:103:5: note: here
    103 |     case 1:
        |     ^~~~
*/

#include <stdio.h>

int main(void) {
  // If Statements

  int x = 10;
  if (x != 10) printf("x does not equal 10\n");
  // also written on separate line like python:
  if (x < 10)
    printf("x is less than 10\n"); // Conditional, only will print if x is less than 10
    printf("unconditional print message because yes\n"); // Unconditional, will print no matter what

  // cascading if-else (with python style syntax)
  if (x < 10)
    printf("X is less than 10\n");
  else if (x > 10)
    printf("X is greater than 10\n");
  else if (x == 10)
    printf("X is equal to 10\n");
  else
    printf("idk what X is\n");

  // While Statements
  int y = 1;
  while (y <= 10) {
    printf("Y is %d\n", y);
    y++;
  }

  /*
  while (1) {
    printf("Repeats forever until manually stopped\n");
  }
  */

  // Do-while Statements
  int i = 10;
  while(i < 10) { // not executed because i is not less than 10
    printf("while: i is %d\n", i);
    i++;
  }

  do { // executed because condition is checked after the block of code, if you want a loop to execute once even if the conditional is false, use do while
    printf("do while: i is %d\n", i);
    i++;
  } while (i < 10);

  // For Statements

  // printing a sequence of 0 to 9 with a while loop:
  i = 0;
  while (i < 10) {
    printf("i: %d | ", i);
    i++;
  }
  printf("\n");

  // printing a sequence of 0 to 9 with a for loop:
  for (i = 0; i < 10; i++) {
    printf("i: %d | ", i);
  }

  // exactly what a for loop has: for (initialize variable(s); loop if condition is true; after each loop, do this)
  // you can also intialize multiple things with the comma operator:
  int j = 0;
  for (i = 0, j = 100; i <= 10; i++, j--) {
    printf("i is %d and j is %d\n", i, j); // "i is 10 and j is 90" is the last line printed
  }

  /* empty for loops forever
  for (;;) {
    printf("loop forever\n");
  }
  */

  // Switch Statements
  int money = 0;

  switch (money) {
    case 0:
      printf("no moneys :(\n");
      break;
    case 1:
      printf("yay 1 moneys :)\n");
      break;
    default:
      printf("i dunno how much moneys you got\n");
      break; // if case hits break, go out of switch and continue other stuffs
  }

  // if no break in case, fall through to next case, meaning execute that block until break
  int a = 0;
  switch (a) {
    case 0:
      printf("a 0\n");
      // fall through (always put comment if fall through so you know why there isn't a break here)
      // __attribute__((fallthrough)); can also be used, gcc and clang recognizes it
      // C23 has [[fallthrough]]; which is the standard for fall throughs
    case 1:
      printf("a 1\n");
      break;
    // default is optional
  }
}