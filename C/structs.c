/*
  Structs
  compile with gcc -Wall -Wextra -g -o out/structs structs.c

  No warnings are emitted when this file is compiled

  Warnings this file gives:
*/

#include <stdio.h>

int main(void) {
  // A Struct is a user-definable type that holds multiple pieces of data of potentially different types
  // Declaring a Struct (often declared in global scope so all things have access to it)
  struct user {
    char *name;
    int age;
    char *skills[2];
  };
  
  struct user user_1; // variable "user_1" of type "struct user" (uninitialized)

  // Initializing struct variable fields using dot (.) operator
  user_1.name = "Oz RAGE Harm";
  user_1.age = 19;
  user_1.skills[0] = "Programming";
  user_1.skills[1] = "C";

  // printing struct fields
  printf("Name: %s\n", user_1.name); // Oz RAGE Harm
  printf("Age:  %d\n", user_1.age);  // 19
  for (int i = 0; i < 2; i++) {
    printf("Skills: %s\n", user_1.skills[i]); // Programming, C
  }

  // Struct Initializers
  // Instead of initializing each struct field individually, you can initialize it as you declare the variable
  struct user user_2 = {"Oz RAGE Harm", 19, .skills[0]="Programming", .skills[1]="C"}; // values need to be in order!
  // Unless you do this, which is independent of the order as well as safer code:
  // struct user user_2 = {.age=19, .name="Oz RAGE Harm"};
  // Any missing field designators are initialized to 0, just like arrays!

  // printing struct fields
  printf("Name: %s\n", user_2.name); // Oz RAGE Harm
  printf("Age:  %d\n", user_2.age);  // 19
  for (int i = 0; i < 2; i++) {
    printf("Skills: %s\n", user_2.skills[i]); // Programming, C
  }

  // Passing Structs to Functions
  // It is best to pass a pointer of a struct to a function, but it perfectly fine to just pass the struct itself
  void set_skills(struct user *s, char *skills[2]) {
    // dot (.) operator does not work on pointers to structs
    // s.skills[0] = skills[0]; // ERROR
    // Dereferencing the struct pointer will work
    printf("Before: %s\n", (*s).skills[0]); // works, but (*s) is non-idiomatic
    printf("Before: %s\n", (*s).skills[1]); // works, but (*s) is non-idiomatic

    // C has syntactic sugar called the arrow (->) operator that helps with the clunkiness of (*s):
    s->skills[0] = skills[0];
    s->skills[1] = skills[1];

    // Much cleaner than (*s)
    printf("After: %s\n", s->skills[0]);
    printf("After: %s\n", s->skills[1]);
  }

  char *new_skills[2] = {"Coding", "C++"};

  set_skills(&user_2, new_skills);

  // Copying Structs are as simple as assigning one to another:
  struct user user_3;
  user_3 = user_2; // that's it
  printf("Name: %s\n", user_3.name); // Oz RAGE Harm
  printf("Age:  %d\n", user_3.age);  // 19
  for (int i = 0; i < 2; i++) {
    printf("Skills: %s\n", user_3.skills[i]); // Coding, C++
  }
}