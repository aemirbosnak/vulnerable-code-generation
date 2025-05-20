//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Declaration of struct for storing the parsed data
struct parsed_data {
  char* id;
  int value;
};

// Function to parse the input string and return parsed_data struct
struct parsed_data parse_input(char* input_string) {

  // Declare struct and initialize variables
  struct parsed_data data;
  data.id = malloc(sizeof(char) * 10); // Assuming max size of id is 10
  data.value = 0;

  // Parse input string
  int i = 0;
  while(input_string[i] != '=') {
    data.id[i] = input_string[i];
    i++;
  }
  data.id[i] = '\0';

  // Skip '=' character
  i++;

  // Parse value
  while(input_string[i] != '\0') {
    data.value = (data.value * 10) + (input_string[i] - '0');
    i++;
  }

  // Return parsed data
  return data;
}

int main() {
  // Sample input string
  char input[] = "foo=123";

  // Call parse_input function to parse input string
  struct parsed_data data = parse_input(input);

  // Print parsed data
  printf("ID: %s\n", data.id);
  printf("Value: %d\n", data.value);

  // Free allocated memory
  free(data.id);

  return 0;
}