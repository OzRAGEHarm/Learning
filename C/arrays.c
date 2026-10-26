/*
  Arrays
  compile with gcc -Wall -Wextra -g -o out/arrays arrays.c

  Warnings this file gives:
  arrays.c: In function 'foo':
  arrays.c:61:28: warning: 'sizeof' on array function parameter 'x' will return size of 'int *' [-Wsizeof-array-argument]
    61 |     printf("%zu\n", sizeof x); // 8
       |                            ^
  arrays.c:60:16: note: declared here
    60 |   void foo(int x[16]) {
       |            ~~~~^~~~~
  arrays.c:63:28: warning: 'sizeof' on array function parameter 'x' will return size of 'int *' [-Wsizeof-array-argument]
    63 |     printf("%zu\n", sizeof x / sizeof(int)); // 2
       |                            ^
  arrays.c:60:16: note: declared here
    60 |   void foo(int x[16]) {
       |            ~~~~^~~~~
  arrays.c: In function 'main':
  arrays.c:113:8: warning: unused variable 'g' [-Wunused-variable]
    113 |   char g[5][4][3];
        |        ^
  arrays.c:112:7: warning: unused variable 'y' [-Wunused-variable]
    112 |   int y[4][8];
        |       ^
  arrays.c:111:7: warning: unused variable 'e' [-Wunused-variable]
    111 |   int e[10];
        |       ^
  arrays.c:82:7: warning: unused variable 'b' [-Wunused-variable]
    82 |   int b[64] = {0}; // make the first index 0, then automatically make the rest 0 as well
       |       ^
*/

#include <stdio.h>

int main(void) {
  int i;
  float f[4]; // Declare array with 4 floats
  // when declaring an array, the size HAS to be a fixed size

  f[0] = 3.14159; // indexing starts at 0
  f[1] = 2.71828;
  f[2] = 1.61803;
  f[3] = 1.41421;

  // Print each float of the array
  for (i = 0; i < 4; i++) {
    printf("%f\n", f[i]); // 3.141590, 2.718280, 1.618030, 1.414210
  }

  // Getting the length of an array
  // C does not record the length of an array on its own, you have to manage it in a separate variable
  int x[16]; // 16 ints
  printf("%zu total bytes\n", sizeof x); // 64 total bytes
  printf("%zu bytes per int\n", sizeof(int)); // 4 bytes per int
  printf("%zu ints\n", sizeof x / sizeof(int)); // 64/4 = 16 ints

  // if it is an array of chars, then sizeof the array is the number of elements, anything else you need to divide by the size of each element
  // however that only works in the scope that the array is defined in, if you pass the array to a function, it does not work
  void foo(int x[16]) {
    printf("%zu\n", sizeof x); // 8
    printf("%zu\n", sizeof(int)); // 4
    printf("%zu\n", sizeof x / sizeof(int)); // 2
  }
  
  foo(x);
  // This happens because when passing arrays to a function, it only passes the first element in the array instead of the full array
  // another thing you can do with sizeof is get the size of an array of a fixed number of elements without declaring the array
  printf("%zu bytes\n", sizeof(int [32])); // size of an int array of 32 elements, 128 bytes on my pc

  // Array initializers
  int j[5] = {69, 420, 120, 345, 8390}; // declare and initialize, 
  // never have more elements than the array can hold or the compiler will throw an error
  for (i = 0; i < 5; i++) {
    printf("%d\n", j[i]); // 69, 420, 120, 345, 8390 on separate lines
  }

  // you can however have few elements than an array will hold, the remaining elements will be valued at 0 by default
  int a[5] = {22, 37, 3490};
  // the same as: int a[5] = {22, 37, 3490, 0, 0};
  // you can also set every element to 0, a common shortcut
  int b[64] = {0}; // make the first index 0, then automatically make the rest 0 as well
  // you can specify array elements in the initializer as well by specifying an index for the value
  int c[10] = {0, 11, 22, [5]=55, 66, 77};
  for (i = 0; i < 10; i++) {
    printf("c[%d] = %d\n", i, c[i]); // c[0] = 0, c[1] = 11, c[2] = 22, c[3] = 0, c[4] = 0, c[5] = 55, c[6] = 66, c[7] = 77, c[8] = 0, c[9] = 0
  }

  // you can also input a simple constant expression as well
  #define COUNT 5 // THIS IS NEW!
  int d[COUNT] = {[COUNT-3]=3, 2, 1};
  for (i = 0; i < 10; i++) {
    printf("d[%d] = %d\n", i, d[i]); // d[0] = 0, d[1] = 0, d[2] = 3, d[3] = 2, d[4] = 1, d[5] = 7536756, d[6] = 4980828, d[7] = 6357093, d[8] = 0, d[9] = 11
  }

  // you can have C compute the size of the array initializer just by leaving the size off
  // int e[3] = {2542, 453, 575}; // 3
  // is the same as:
  // int e[] = {2542, 453, 575}; // 3

  // Out of Bounds
  // C does not stop you from accessing elements outside the array size
  // printing 10 elements of a 5 element array:
  for (i = 0; i < 10; i++) {
      printf("BAD: %d\n", a[i]); // prints "BAD: 22, 37, 3490, 0, 0, 0, -975493394, 32765, 69, 420" on my pc
      // This is called "undefined behavior", which is bad and should you never do such thing
  }

  // Multidimensional Arrays
  // You can add as many dimensions as you want to an array
  int e[10];
  int y[4][8];
  char g[5][4][3];

  // Dimensions of an array are stored in a row-major order, meaning the first index indicates the row and the second index being the column
  int row, col;
  int h[2][4] = { // Initialize a 2D array
    {0, 1, 2, 3},
    {4, 5, 6, 7}
  };

  for (row = 0; row < 2; row++) {
    for (col = 0; col < 4; col++) {
      printf("(%d,%d) = %d\n", row, col, h[row][col]);
      /*
      (0,0) = 0
      (0,1) = 1
      (0,2) = 2
      (0,3) = 3
      (1,0) = 4
      (1,1) = 5
      (1,2) = 6
      (1,3) = 7
      */
    }
  }

  // you can also initialize with explicit indexes:
  int k[3][3] = {[0][0]=1, [0][2]=1, [1][1]=2, [2][0]=3, [2][2]=3};
  for (int l = 0; l < 3; l++) {
      for (int m = 0; m < 3; m++) {
          printf("%d ", k[l][m]);
      }
      printf("\n");
  }
  // which builds a 2d array like so:
  /*
  1 0 1
  0 2 0
  3 0 3
  */

  // Arrays and Pointers
  // Getting a pointer to an array is actually a pointer to the first element in that array
  int *p; // pointer (uninitialized)
  int l[5] = {22, 453, 2467, 547, 76}; // array with 5 elements
  p = &l[0]; // points to the first element in array l (e.g. 22)
  printf("%d\n", *p); // prints "22"
  // this is so common in C that this also works perfectly fine, it points to the address of the first element in the array:
  // p = l;

  // Passing Single Dimensional Arrays to Functions
  void multiply(int *a, int len) {
    for (int i = 0; i < len; i++) {
      printf("%d * 2 = %d\n", a[i], a[i] * 2);
    }
  }

  // the "mulitply" function declaration is identical to:
  // void multiply(int a[], int len)
  // void multiply(int a[5], int len)
  // but this one is the most common: void multiply(int *a, int len)

  multiply(l, 5);

  // Changing Arrays in Functions
  int m[5] = {1, 2, 3, 4, 5};
  void double_array(int *a, int len); // declare prototype
  double_array(m, 5); // pass array as pointer
  for (int i = 0; i < 5; i++) {
    printf("Doubled: %d\n", m[i]);  // 2, 4, 6, 8, 10
  }

  // Passing Multidimensional Arrays to Functions
  // C needs you to be explicit about all dimensions of an array in order to find out where in memory they are
  int n[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  void print_2D_array(int a[3][2]); // declare prototype, also the same as void print_2D_array(int a[][2]);
  // the compiler only really needs the second dimension so it knows how far in memory to skip for each increment
  // it needs to know all dimensions except the first
  print_2D_array(n);
}

void double_array(int *a, int len)
{
    // Multiply each element in the array by 2 because a and m point to the same array
    for (int i = 0; i < len; i++) {
      a[i] *= 2;
    }
}

void print_2D_array(int a[3][2]) // explicit about dimensions
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 2; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}