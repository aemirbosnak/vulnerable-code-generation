//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Example JSON string to parse
char json[] = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";

// Struct to store the parsed data
typedef struct {
  char *name;
  int age;
  char *city;
} Person;

// Function to parse the JSON string and return a Person struct
Person parse_json(char *json) {
  Person person;
  char *token, *endptr;

  // Get name
  token = strtok(json, ":\"");
  token = strtok(NULL, "\"");
  person.name = (char*) malloc(strlen(token) + 1);
  strcpy(person.name, token);

  // Get age
  token = strtok(NULL, ":,");
  person.age = strtol(token, &endptr, 10);

  // Get city
  token = strtok(NULL, ":\"");
  token = strtok(NULL, "\"}");
  person.city = (char*) malloc(strlen(token) + 1);
  strcpy(person.city, token);

  return person;
}

int main() {
  // Parse JSON string and print result
  Person person = parse_json(json);
  printf("Name: %s\n", person.name);
  printf("Age: %d\n", person.age);
  printf("City: %s\n", person.city);

  // Free memory
  free(person.name);
  free(person.city);

  return 0;
}