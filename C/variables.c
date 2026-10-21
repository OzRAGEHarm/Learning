/*
  Variables and Types

  Rules:
    You can’t start a variable with a digit 0-9.
    You can’t start a variable name with two underscores.
    You can’t start a variable name with an underscore followed by a capital A-Z.
*/

// preprocessor before compiler even touches code
#include <stdio.h> // standard I/O header file

int main(void) {
  int i;                     // holds signed integers (-1, 0, 1, etc.)
  float f;                   // holds signed floating-point numbers/decimals (3.14, -0.5, etc.) a.k.a. a real number

  i = 3;                     // assign i to 3
  f = 2.5;                   // assign f to 2.5
  char *s = "Hello, World!"; // char *<name> (char pointer) is string type

  // format strings have special sequences that start with %,
  // %s means to print as a string
  // %d means to print as an integer
  // %f means to print as a float
  // each go in order based on parameter order, s is a string, i is an integer, and f is a float so %s, %d, and %f
  printf("%s | i = %d | f = %f\n", s, i, f); // print variables with format string

  // C can use integers as bool types
  // 0 = false, 1 = true, negative numbers are also true (-20 = true), only 0 is false
  int x = 0; // False
  if (x) {
    printf("x is true\n");
  } else {
    printf("x is false\n");
  }

  // bool, true, and false comes with the compiler in C23, in older versions you can use 
  // #include <stdbool.h> which is not needed in C23 (I currently am using C23)
  bool y = true;
  if (y) {
    printf("y is true\n");
  } else {
    printf("y is false\n");
  }

  // true = 1 and false = 0, therefore the following prints 0, because 1 is not equal to 12
  printf("%d\n", true == 12);
}