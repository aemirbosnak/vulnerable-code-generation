//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
} Person;

Person **create_people(int n) {
  Person **people = (Person **)malloc(sizeof(Person *) * n);
  for (int i = 0; i < n; i++) {
    people[i] = (Person *)malloc(sizeof(Person));
    people[i]->name = (char *)malloc(sizeof(char) * 128);
    people[i]->age = rand() % 100;
    sprintf(people[i]->name, "Person %d", i);
  }
  return people;
}

void free_people(Person **people, int n) {
  for (int i = 0; i < n; i++) {
    free(people[i]->name);
    free(people[i]);
  }
  free(people);
}

char *get_fortune(Person *person) {
  char *fortunes[] = {
    "You will have a long and happy life.",
    "You will be rich and successful.",
    "You will find true love.",
    "You will travel the world.",
    "You will make a difference in the world."
  };
  return fortunes[rand() % 5];
}

int main() {
  srand(time(NULL));

  int n = 10;
  Person **people = create_people(n);

  for (int i = 0; i < n; i++) {
    printf("%s (%d): %s\n", people[i]->name, people[i]->age, get_fortune(people[i]));
  }

  free_people(people, n);

  return 0;
}