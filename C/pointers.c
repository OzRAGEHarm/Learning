/*
  Pointers
  compile with gcc -Wall -Wextra -g -o out/pointers pointers.c

  Warnings this file gives:
  pointers.c: In function 'main':
  pointers.c:64:8: warning: variable 'c' set but not used [-Wunused-but-set-variable=]
    64 |   int *c;
       |        ^
*/

#include <stdio.h>
#include <stdbool.h>

// Passing pointers as Arguments
void increment(int *p) { // accepts pointer to int
  *p = *p + 1;
}

int main(void) {
  // Pointers are like references but more in-depth and more explicit in C
  // Memory and Variables
  // you can use sizeof to determine the amount of bytes a data type has
  printf("a boolean value uses %zu byte(s) in memory\n", sizeof(bool)); // 1 on my pc
  // A pointer is a address in memory, a pointer holds the address number, just like an int can hold 12
  int i = 10;

  // Ampersand (&) gives you the address of data, %p prints the pointer
  printf("The value of i is %d\n", i); // 10
  printf("And its address is %p\n", (void *)&i); // hexadecimal, memory index data is stored at, typically the first index of multi-byte data,
  // this is a pointer because it lets you know where i is stored in memory

  // Pointer types
  int j;  // j is type of "int"
  int *p; // p is type of "int-pointer" and is uninitiallized, therefore points to garbage, not a dereference

  p = &j; // p is assigned j's address, p now "points to" j
  // left is an expression of type "pointer-to-int" because j is int and address-of "int" gives you the pointer of int

  // Dereferencing
  // A pointer could be thought of as referring to another variable by pointing to it,
  // when you have a pointer (reference) to a variable, you can get to the original variable by dereferencing the pointer
  j = 10;   // j is now 10
  *p = 20;  // the thing p points to (j), is now 20, dereference (indirection) operator is asterisk (*), p holds address to j

  printf("j is %d\n", j);   // j is 20
  printf("j is %d\n", *p);  // j is 20, dereferenced p is the same as j

  // Passing pointers as Arguments

  int a = 10;
  int *b = &a; // address-of, turns into pointer to a

  printf("a is %d\n", a);        // prints "10"
  printf("a is also %d\n", *b);  // prints "10"

  increment(b); // int* to a

  printf("a is %d\n", a); // prints "11"

  // the above is more concisely written with the address-of right in the argument list
  /*
  printf("i is %d\n", i); // 10
  increment(&i);
  printf("i is %d\n", i); // 11
  */

  // The NULL pointer
  // Any pointer variable of any pointer type can be set to NULL which means the pointer does not point to anything
  int *c;
  c = NULL;

  // Since the pointer does not point to anything, dereferencing it is undefined behavior and could result in a crash
  // int *c = NULL;
  // c = 12; // CRASH
  // pointer points to garbage unless explicitly assigning it to point to an address or NULL

  // Note on Declaring pointers
  // pointer syntax when declaring is asterisk (*) in front of the variable name: 
  // int i, *p; // declare i and *p
  // int *p, i; // *p is the pointer, while i is just an integer
  // int* p, i; // p is still the pointer, while i is just an integer,
  // this is bad though since it makes it a little confusing on what is the pointer and what it not

  // sizeof and Pointers
  int *d;

  // Prints size of an 'int'
  printf("size of int: %zu\n", sizeof(int)); // 4 on my pc

  // d is type 'int*' (int-pointer), so prints size of 'int*' (int-pointer)
  printf("size of d: %zu\n", sizeof d); // 8 on my pc

  // *d is type 'int', so prints size of 'int' (dereferenced)
  printf("size of *d: %zu\n", sizeof *d); // 4 on my pc
}