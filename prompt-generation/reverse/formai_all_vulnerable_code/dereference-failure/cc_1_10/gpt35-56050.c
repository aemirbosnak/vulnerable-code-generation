//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  char *address;
} Person;

void free_person(Person *p){
  free(p->name);
  free(p->address);
  free(p);
}

int main(int argc, char* argv[]){
  if (argc != 2){
    printf("Usage: %s <csv_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *csv_file = fopen(argv[1], "r");
  if (csv_file == NULL){
    printf("Failed to open csv file.\n");
    exit(EXIT_FAILURE);
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t num_read;

  Person *people[100]; // Assume no more than 100 people in the csv file

  int i = 0;

  while ((num_read = getline(&line, &len, csv_file)) != -1) {
    line[strcspn(line, "\r\n")] = 0; // Strip newline characters from the line

    char *name;
    int age;
    char *address;

    name = strtok(line, ",");
    if (name == NULL){
      printf("Invalid csv format.\n");
      exit(EXIT_FAILURE);
    }

    char *age_str = strtok(NULL, ",");
    if (age_str == NULL){
      printf("Invalid csv format.\n");
      exit(EXIT_FAILURE);
    }

    age = atoi(age_str);

    address = strtok(NULL, ",");
    if (address == NULL){
      printf("Invalid csv format.\n");
      exit(EXIT_FAILURE);
    }

    Person *p = malloc(sizeof(Person));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->age = age;
    p->address = malloc(strlen(address) + 1);
    strcpy(p->address, address);

    people[i] = p;

    i++;
  }

  for (int j = 0; j < i; j++){
    printf("%s, %d, %s\n", people[j]->name, people[j]->age, people[j]->address);
    free_person(people[j]);
  }

  free(line);
  fclose(csv_file);

  return 0;
}