/*
  Basic Hello World
  compile with gcc -o hello hello.c
  '-o hello' means what is the output file's name going to be and hello.c is the compiled file
*/


// preprocessor before compiler even touches code
#include <stdio.h> // standard I/O header file

int main(void) {
  printf("Hello, World!\n"); // printf won't work unless stdio.h is included, otherwise compiler throws error, also requires semicolon (;)
}