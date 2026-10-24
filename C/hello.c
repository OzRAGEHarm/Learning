/*
  Basic Hello World
  compile with gcc -Wall -Wextra -g -o out/hello hello.c
  '-o out/hello' means what is the output file's name going to be and hello.c is the source file that is compiled,
  it is located in the 'out' directory and is named 'hello', so to run it, do './out/hello'

  No warnings are emitted when this file is compiled
*/


// preprocessor before compiler even touches code
#include <stdio.h> // standard I/O header file

int main(void) {
  printf("Hello, World!\n"); // printf won't work unless stdio.h is included, otherwise compiler throws error, also requires semicolon (;)
}