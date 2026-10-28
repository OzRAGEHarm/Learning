/*
  Strings
  compile with gcc -Wall -Wextra -g -o out/strings strings.c

  No warnings are emitted when this file is compiled
*/

#include <stdio.h>
#include <string.h> // new header file!

int main(void) {
  // Strings in C aren't actually strings, they are pointers, like arrays
  // String Literals examples:
  /*
    "Hello, World!\n" newline escaped character at the end
    "Test string."
    "Does this string has a quote in it, \"yes\"" \" is the escape code for a double quote inside a string literal
  */

  // String Variables
  char *s = "Hello, World!"; // char pointer to the value of the first letter in the string, in this case, "H"
  printf("%s\n", s); // prints "Hello, World!"

  // String Variables as Arrays
  char t[20] = "Hello again, World!"; // Same as char t[] = "Hello again, World!"; 20, 19 for the actual string, and 1 for the NUL character (\0)
  // because you let the compiler do the work of finding out how many characters there are in the string
  // Printing each character one by one on the same line using array notation
  // the same can be done with char pointer, since arrays and pointers are essentially the same
  for (int i = 0; i < 20; i++) {
    // %d for integer value "72" (ascii value) for index 0, %c for actual character "H" for index 0
    printf("%c", t[i]); 
  }
  printf("\n");

  // String Initializers
  // char *s = "Hello, World!" is a string literal and cannot be mutated (changed)
  // s[0] = "D"; results in a crash because it tried to change read-only memory, also this is undefined behavior
  // char t[] = "Hello, World!"; is an array copy of the string, meaning it can in fact be changed
  // t[0] = "D"; is perfectly fine and will in fact change the first element (H) into D
  // pointers to string literals should NEVER be changed but array copies are mutable, so it is ok to change them

  // Getting String Length
  // C does not track the length of strings for you,
  // but there is a function from string.h called strlen that gives you the length of a string in bytes
  printf("The string s is %zu bytes long.\n", strlen(s)); // 13 bytes long

  // String Termination
  // There are essentially 2 ways to store a string in memory:
  // 1. Store the bytes of the string along with the length of said string
  // 2. Store the bytes of the string and mark the end with a special byte called the "terminator"
  // for a string longer than 255 characters, option 1 needs at least 2 bytes to store the length,
  // whereas option 2 only needs 1 byte to terminate the string
  // C uses option 2 for its strings, C strings are defined by 2 characteristics:
  // 1. A pointer to the first character in the string
  // 2. A zero-valued byte at the end of the string that is somewhere in memory
  // The NUL character (\0) is appended at the end of a string automatically behind the scenes
  
  // This function counts each character in a char pointer until it reaches the NUL character
  // this is essentially what strlen() does form string.h
  int string_length(char *s) {
    int count = 0;

    while (s[count] != '\0') { // Single quotes for single characters
      count++;
    }

    return count;
  }

  printf("%d\n", string_length(s)); // Pass the char pointer from earlier, prints 13

  // Copying a String
  // You can't just copy a string from the assignment operator (=), that only makes a copy of the pointer to the first character
  char a[] = "Hello, world!";
  char *b;

  // This makes a copy of the pointer
  b = a;
  b[0] = 'D'; // modify it

  printf("%s\n", a);  // prints the modified b string, even though t was the one modified,
  // since it is just a pointer, it modified the original, not a copy

  // If you want to copy a string, you need to copy each individual byte and place them somewhere else in memory,
  // but if you use the strcpy() function from string.h, it is much easier
  char *c = "Hello, World!";
  char d[20]; // make sure to have plenty of space in order to copy the string!

  strcpy(d, c); // actually copy the string

  d[0] = 'B'; // modify the copy, since only modifying 1 character, make sure to use single quotes!

  printf("%s\n", c); // Hello, World!
  printf("%s\n", d); // Bello, World!
} 