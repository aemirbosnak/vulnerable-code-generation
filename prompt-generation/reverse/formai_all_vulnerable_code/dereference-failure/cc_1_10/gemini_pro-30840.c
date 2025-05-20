//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
  char *name;
  int age;
  char *gender;
  char *education;
  int salary;
} Person;

typedef struct {
  int num_people;
  Person *people;
} Dataset;

Dataset load_dataset(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  Dataset dataset;
  dataset.num_people = 0;
  dataset.people = NULL;

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *name = strtok(line, ",");
    int age = atoi(strtok(NULL, ","));
    char *gender = strtok(NULL, ",");
    char *education = strtok(NULL, ",");
    int salary = atoi(strtok(NULL, ","));

    Person person;
    person.name = strdup(name);
    person.age = age;
    person.gender = strdup(gender);
    person.education = strdup(education);
    person.salary = salary;

    dataset.num_people++;
    dataset.people = realloc(dataset.people, dataset.num_people * sizeof(Person));
    dataset.people[dataset.num_people - 1] = person;
  }

  fclose(fp);

  return dataset;
}

void print_dataset(Dataset dataset) {
  for (int i = 0; i < dataset.num_people; i++) {
    Person person = dataset.people[i];
    printf("%s, %d, %s, %s, %d\n", person.name, person.age, person.gender, person.education, person.salary);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  Dataset dataset = load_dataset(argv[1]);
  print_dataset(dataset);

  return 0;
}