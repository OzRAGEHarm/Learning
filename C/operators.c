/*
  Operators and Expressions
*/

#include <stdio.h>

int main(void) {
  // Arithmetic Operators (Math)
  int x = 2;

  x = x + 3; // Addition, adding 2 numbers together and assigning the value back to x
  x = x - 8; // Subtraction
  x = x * 9; // Multiplication
  x = x / 2; // Division
  x = x % 5; // Modulo (division with remainer)

  printf("%d\n", x);

  // Shorthand variation for above
  int y = 1;
  y += 8;
  y -= 4;
  y *= 2; 
  y /= 2;
  y %= 6;

  printf("%d\n", y);

  // No exponentiation, you have to use pow() from math.h

  // Ternary Operator
  int i = 5;
  int j = 12;

  // if j is less than 15 add 10 to i, otherwise add 20 to i
  i += j < 15 ? 10 : 20;
  printf("%d\n", i);

  // the above ternary operator expression is equivalent to this if statement:
  if (j < 15)
    i += 10;
  else
    i += 20;

  printf("The number %d is %s.\n", x, x % 2 == 0? "even": "odd"); // prints odd since -3 is odd

  // Pre and Post Increment and Decrement (used frequently with array and pointer access/manipulation, but also common in for-loops)

  i++; // Post increment, adds after an expression, equivalent/shorthand to i += 1;
  i--; // Post decrement, subtracts after an expression, equivalent/shorthand to i -= 1;
  ++i; // Pre increment, adds before an expression, incremented value used in expressions
  --i; // Pre decrement, subtracts before an expression, decremented value used in expressions

  // embedded into expression
  i = 15;
  j = 5 + i++; // Post increment, computes 5 + i then increments i
  printf("%d, %d\n", i, j); // 16, 20

  i = 15;
  j = 5 + ++i; // Pre increment, increments i then computes 5 + i
  printf("%d, %d\n", i, j); // 16, 21

  for (i = 0; i < 10; i++)
    printf("i is %d\n", i);

  // Comma Operator (uncommonly used to separate expressions that run left to right)
  x = 10, y = 20; // single expression
  x = 10; y = 20; // multiple expressions

  // with the comma operator, the value of comma expression is the value of the rightmost expression
  x = (1, 2, 3);
  printf("x is %d\n", x); // prints 3 because it is the rightmost in the expression

  // a common place for the comma operator is within for-loops to do multiple things
  for (i = 0, j = 10; i < 100; i++, j++)
    printf("%d, %d\n", i, j);

  // Conditional Operators
  int a = 10, b = 20;
  a == b;  // True if a is equivalent to b, comparison is double equals (==) and assignment is single equals (=)
  a != b;  // True if a is not equivalent to b
  a < b;   // True if a is less than b
  a > b;   // True if a is greater than b
  a <= b;  // True if a is less than or equal to b
  a >= b;  // True if a is greater than or equal to b
  printf("%d, %d\n", a, b);

  // comparison expression with if statement:
  if (a <= 10)
    printf("a is less than or equal to 10\n");

  // Boolean Operators
  // && is the AND operator
  // || is the OR operator
  // ! is the NOT operator

  if (x < 10 && y == b)
    printf("Something 1\n");

  if (x > 5 || y != a)
    printf("Something 2\n");

  if (!(x > 15)) // expression surrounded by parentheses because ! has higher precedence than other boolean operators
    printf("x is not greater than 15\n");

  // above is equivalent to:
  if (x <= 15)
    printf("x is greater than 15\n");

  // The sizeof Operator, used to know the size in bytes of a variable or data type in memory
  // different data types can be different sizes on different machines, except char, char is always 1 byte
  // C has a special type called size_t specifically for the return type from sizeof

  // %zu is the format specifier for size_t, some compilers reject the z part, mine also allows just %u
  printf("%zu\n", sizeof(char)); // 1
  printf("%u\n", sizeof(int));   // 4 on my pc
  printf("%u\n", sizeof(3.14));  // 8 on my pc

  // the reason for the newline character (\n) after each print statement is because if there were not one, it would print everything onto a singular line
  // which would be hard to read what was printed to the terminal
}