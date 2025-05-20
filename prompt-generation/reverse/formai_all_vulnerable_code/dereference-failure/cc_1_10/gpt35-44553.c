//FormAI DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold database values
typedef struct{
  int id;
  char name[20];
  char gender[10];
  int age;
} Person;

// function to recursively search for a person's age in the database by name
int find_age_by_name(Person* people, char* name, int start, int end){
  if(start > end) return -1;
  int mid = (start + end) / 2;
  if(strcmp(people[mid].name, name) == 0) return people[mid].age;
  else if(strcmp(people[mid].name, name) < 0) return find_age_by_name(people, name, mid + 1, end);
  else return find_age_by_name(people, name, start, mid - 1);
}

int main(){
  // database initialization
  int num_people = 5;
  Person* people = (Person*) malloc(num_people * sizeof(Person));
  people[0].id = 1;
  strcpy(people[0].name, "Alice");
  strcpy(people[0].gender, "Female");
  people[0].age = 21;
  people[1].id = 2;
  strcpy(people[1].name, "Bob");
  strcpy(people[1].gender, "Male");
  people[1].age = 25;
  people[2].id = 3;
  strcpy(people[2].name, "Charlie");
  strcpy(people[2].gender, "Non-binary");
  people[2].age = 30;
  people[3].id = 4;
  strcpy(people[3].name, "David");
  strcpy(people[3].gender, "Male");
  people[3].age = 28;
  people[4].id = 5;
  strcpy(people[4].name, "Eva");
  strcpy(people[4].gender, "Female");
  people[4].age = 23;

  // recursive search for Alice's age
  int alice_age = find_age_by_name(people, "Alice", 0, num_people - 1);
  printf("Alice is %d years old\n", alice_age);

  // recursive search for David's age
  int david_age = find_age_by_name(people, "David", 0, num_people - 1);
  printf("David is %d years old\n", david_age);

  // recursive search for Frank's age (not in database)
  int frank_age = find_age_by_name(people, "Frank", 0, num_people - 1);
  if(frank_age == -1) printf("Frank is not in the database\n");

  free(people);
  return 0;
}