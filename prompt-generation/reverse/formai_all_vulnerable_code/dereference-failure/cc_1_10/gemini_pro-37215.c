//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 1024

// Define the maximum number of strings
#define MAX_NUM_STRINGS 100

// Define the structure of a string
typedef struct {
  char *str;
  int length;
} string;

// Define the structure of a list of strings
typedef struct {
  string *strings;
  int num_strings;
} list_of_strings;

// Create a new string
string *create_string(char *str) {
  string *new_string = malloc(sizeof(string));
  new_string->str = strdup(str);
  new_string->length = strlen(str);
  return new_string;
}

// Create a new list of strings
list_of_strings *create_list_of_strings() {
  list_of_strings *new_list = malloc(sizeof(list_of_strings));
  new_list->strings = malloc(MAX_NUM_STRINGS * sizeof(string));
  new_list->num_strings = 0;
  return new_list;
}

// Add a string to a list of strings
void add_string_to_list(list_of_strings *list, string *str) {
  list->strings[list->num_strings++] = *str;
}

// Print a list of strings
void print_list_of_strings(list_of_strings *list) {
  for (int i = 0; i < list->num_strings; i++) {
    printf("%s\n", list->strings[i].str);
  }
}

// Free a string
void free_string(string *str) {
  free(str->str);
  free(str);
}

// Free a list of strings
void free_list_of_strings(list_of_strings *list) {
  for (int i = 0; i < list->num_strings; i++) {
    free_string(&list->strings[i]);
  }
  free(list->strings);
  free(list);
}

// Main function
int main() {
  // Create a list of strings
  list_of_strings *list = create_list_of_strings();

  // Add some strings to the list
  add_string_to_list(list, create_string("Hello"));
  add_string_to_list(list, create_string("World"));
  add_string_to_list(list, create_string("!"));

  // Print the list of strings
  print_list_of_strings(list);

  // Free the list of strings
  free_list_of_strings(list);

  return 0;
}