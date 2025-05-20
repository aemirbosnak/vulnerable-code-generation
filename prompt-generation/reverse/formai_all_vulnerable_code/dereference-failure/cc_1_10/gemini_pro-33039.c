//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string
char *generate_string(int length)
{
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++)
  {
    string[i] = (char)((rand() % 26) + 97);
  }
  string[length] = '\0';
  return string;
}

// Function to test the typing speed
void test_typing_speed()
{
  // Generate a random string
  int length = 100;
  char *string = generate_string(length);
  int i = 0;
  int start_time = time(NULL);
  int end_time;
  char input[length + 1];

  // Get the input from the user
  printf("Type the following string: %s\n", string);
  scanf("%s", input);

  // Calculate the time taken
  end_time = time(NULL);
  int time_taken = end_time - start_time;

  // Calculate the typing speed
  int typing_speed = length / time_taken;
  float wpm = typing_speed / 5;

  // Display the results
  printf("Your typing speed is: %d characters per second\n", typing_speed);
  printf("Your typing speed is: %.2f words per minute\n", wpm);

  // Free the allocated memory
  free(string);
}

int main()
{
  // Test the typing speed
  test_typing_speed();

  return 0;
}