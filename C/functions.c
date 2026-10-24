/*
  Functions
  compile with gcc -Wall -Wextra -g -o out/functions functions.c

  No warnings are emitted when this file is compiled
*/

#include <stdio.h>

// Define a function, argument types must be pre-declared!
int add(int a, int b) {
  return a + b; // return a value from function
}

void function(void) {
  printf("This does not return a value nor take in arguments\n");
}

// Passing a value to a function
void increment(int a) {
  a++;
  printf("a is %d\n", a); // 11
}

// Function prototypes
int foo(void); // prototype function, notifying the compiler that this function has a certain type and parameter list,
// can be defined anywhere including a different file, as long as the function prototype is declared before calling it
// not declaring functions (either prototype or definition) before using them is called implicit declaration
// and was used in C89 but is no longer allowed today and there is no reason to use it today

// Empty Parameter Lists
// C23 allows empty parameter list in a function definition is the same as added 'void' to the parameter list
void bar(); // before C23, empty parentheses in a declaration mean "parameters unspecified," so calls to it aren't type checked (in C23 this means the same as (void))
void bar(void); // Preferred for anything but ESPECIALLY function prototypes because without it,
// it turns off type checking functionality as it omits parameters in both prototypes and declarations,
// therefore it is NOT the same as an empty parameter list so with prototypes,
// ALWAYS use void as the parameter list if you don't need params in the function

int main(void) {
  int a = 10, b = 20, c;
  c = add(a, b); // function call
  printf("a + b = %d\n", c); // a + b = 30
  function();

  // Passing a value to a function
  int i = 10;
  increment(i);
  printf("i is %d\n", i); // prints 10, not 11, reason being is because parameters are copied values, 
  // not the actual value because the parameter is getting incremented, not i in main
  // with the add function, the value was returned, so the main function could see the updated value

  // Function prototypes
  int j;

  j = foo(); // Can be called because the prototype has been declared above

  printf("j is %d\n", j); // j is 1593
}

int foo(void) { // Function defined just like the prototype
  return 1593;
}