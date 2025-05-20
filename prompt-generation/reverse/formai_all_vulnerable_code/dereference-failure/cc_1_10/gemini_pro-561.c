//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
   char *name;
   int age;
   char *hobby;
} person_t;

person_t *create_person(char *name, int age, char *hobby) {
   person_t *person = malloc(sizeof(person_t));
   person->name = strdup(name);
   person->age = age;
   person->hobby = strdup(hobby);
   return person;
}

void destroy_person(person_t *person) {
   free(person->name);
   free(person->hobby);
   free(person);
}

typedef struct {
   int count;
   person_t **people;
} people_t;

people_t *create_people() {
   people_t *people = malloc(sizeof(people_t));
   people->count = 0;
   people->people = NULL;
   return people;
}

void destroy_people(people_t *people) {
   for (int i = 0; i < people->count; i++) {
      destroy_person(people->people[i]);
   }
   free(people->people);
   free(people);
}

void add_person(people_t *people, person_t *person) {
   people->count++;
   people->people = realloc(people->people, sizeof(person_t *) * people->count);
   people->people[people->count - 1] = person;
}

person_t *find_person_by_name(people_t *people, char *name) {
   for (int i = 0; i < people->count; i++) {
      if (strcmp(people->people[i]->name, name) == 0) {
         return people->people[i];
      }
   }
   return NULL;
}

int main() {
   people_t *people = create_people();
   add_person(people, create_person("John", 30, "coding"));
   add_person(people, create_person("Jane", 25, "reading"));
   add_person(people, create_person("Joe", 40, "fishing"));

   person_t *person = find_person_by_name(people, "John");
   if (person != NULL) {
      printf("%s is %d years old and likes %s.\n", person->name, person->age, person->hobby);
   } else {
      printf("Person not found.\n");
   }

   destroy_people(people);
   return 0;
}