//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
  char *occupation;
} person_t;

person_t *load_data(char *filename, int *num_people) {
  FILE *fp;
  char line[1024];
  person_t *people = NULL;
  int i = 0;

  *num_people = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    char *name, *age, *occupation;

    name = strtok(line, ",");
    age = strtok(NULL, ",");
    occupation = strtok(NULL, "\n");

    people = realloc(people, sizeof(person_t) * (i + 1));
    people[i].name = strdup(name);
    people[i].age = atoi(age);
    people[i].occupation = strdup(occupation);

    i++;
  }

  fclose(fp);

  *num_people = i;

  return people;
}

void print_data(person_t *people, int num_people) {
  int i;

  for (i = 0; i < num_people; i++) {
    printf("%s, %d, %s\n", people[i].name, people[i].age, people[i].occupation);
  }
}

int main(int argc, char **argv) {
  int num_people;
  person_t *people;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  people = load_data(argv[1], &num_people);
  if (people == NULL) {
    return EXIT_FAILURE;
  }

  print_data(people, num_people);

  return EXIT_SUCCESS;
}