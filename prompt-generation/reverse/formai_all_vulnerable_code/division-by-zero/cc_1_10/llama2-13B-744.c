//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: cheerful
// 🐰💡 Happy Arithmetic Land! 🎉

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WELCOME "Welcome to Happy Arithmetic Land! 🎊"
#define GOODBYE "Goodbye! 👋"

// 🤔 Think of a number...
int main() {
  // 🎉 Let's play some arithmetic games!
  srand(time(NULL)); // 🕰 Generate a random number for our games.

  // 📝 Keep track of your score!
  int score = 0;

  // 🔴 Red or Blue? 🔵
  int color = rand() % 2; // 🎨 Randomly choose a color.

  // 📝 Keep track of the correct answers.
  int correct = 0;

  // 📝 Let's start!
  printf("%s\n", WELCOME); // 🎊 Print the welcome message.

  // 📝 Arithmetic Game 1: Addition! 🔢
  int num1 = rand() % 10; // 🔢 Generate a random number 1-10.
  int num2 = rand() % 10; // 🔢 Generate another random number 1-10.
  int sum = num1 + num2; // 🔢 Add the two numbers together.
  printf("Happy Arithmetic Land says: %d + %d = %d\n", num1, num2, sum); // 📝 Print the equation and answer.
  correct++; // 🔝 Increment the correct answer counter.

  // 📝 Arithmetic Game 2: Subtraction! 🔎
  int num3 = rand() % 10; // 🔢 Generate a random number 1-10.
  int num4 = rand() % 10; // 🔢 Generate another random number 1-10.
  int diff = num3 - num4; // 🔢 Subtract the two numbers.
  printf("Happy Arithmetic Land says: %d - %d = %d\n", num3, num4, diff); // 📝 Print the equation and answer.
  correct++; // 🔝 Increment the correct answer counter.

  // 📝 Arithmetic Game 3: Multiplication! 🔠
  int num5 = rand() % 10; // 🔢 Generate a random number 1-10.
  int num6 = rand() % 10; // 🔢 Generate another random number 1-10.
  int product = num5 * num6; // 🔢 Multiply the two numbers.
  printf("Happy Arithmetic Land says: %d x %d = %d\n", num5, num6, product); // 📝 Print the equation and answer.
  correct++; // 🔝 Increment the correct answer counter.

  // 📝 Arithmetic Game 4: Division! 🔢
  int num7 = rand() % 10; // 🔢 Generate a random number 1-10.
  int num8 = rand() % 10; // 🔢 Generate another random number 1-10.
  int quotient = num7 / num8; // 🔢 Divide the two numbers.
  printf("Happy Arithmetic Land says: %d / %d = %d\n", num7, num8, quotient); // 📝 Print the equation and answer.
  correct++; // 🔝 Increment the correct answer counter.

  // 📝 Check your answers! 🤔
  printf("You got %d out of 4 correct! 🎉\n", correct); // 📝 Print the correct answer count.

  // 👋 Goodbye! 👋
  printf("%s\n", GOODBYE); // 🎊 Print the goodbye message.

  return 0; // 👍 End the program.
}