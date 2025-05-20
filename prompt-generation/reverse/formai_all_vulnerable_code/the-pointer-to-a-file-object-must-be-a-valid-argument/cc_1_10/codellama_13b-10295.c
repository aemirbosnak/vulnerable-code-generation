//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
// Apocalypse C Reader - A CSV Reader in a post-apocalyptic style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store the data read from the CSV file
typedef struct {
  char *name;
  int age;
  char *gender;
} Person;

// Function to read a CSV file and return a Person struct
Person read_person(FILE *file) {
  char line[256];
  Person person;

  // Read a line from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    // Split the line into fields
    char *fields[3];
    fields[0] = strtok(line, ",");
    fields[1] = strtok(NULL, ",");
    fields[2] = strtok(NULL, "\n");

    // Store the fields in the Person struct
    person.name = fields[0];
    person.age = atoi(fields[1]);
    person.gender = fields[2];
  }

  return person;
}

// Function to print a Person struct
void print_person(Person person) {
  printf("Name: %s\n", person.name);
  printf("Age: %d\n", person.age);
  printf("Gender: %s\n", person.gender);
}

int main(void) {
  // Open the CSV file
  FILE *file = fopen("people.csv", "r");

  // Read the first line of the file
  Person person = read_person(file);

  // Print the first line of the file
  print_person(person);

  // Close the file
  fclose(file);

  return 0;
}