//FormAI DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[20];
  int age;
} Person;

typedef struct {
  char index_name[20];
  int num_records;
  Person* records;
} Index;

Index* create_index(char* name, int num_records) {
  Index* index = (Index*) malloc(sizeof(Index));
  strcpy(index->index_name, name);
  index->num_records = num_records;
  index->records = (Person*) malloc(num_records * sizeof(Person));
  return index;
}

int find_record_by_name(Index* index, char* name) {
  for (int i = 0; i < index->num_records; i++) {
    if (strcmp(index->records[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

void print_person(Person p) {
  printf("ID: %d \tName: %s \tAge: %d\n", p.id, p.name, p.age);
}

int main() {
  Index* index = create_index("Name Index", 4);

  index->records[0].id = 1;
  strcpy(index->records[0].name, "John");
  index->records[0].age = 30;

  index->records[1].id = 2;
  strcpy(index->records[1].name, "Sarah");
  index->records[1].age = 25;

  index->records[2].id = 3;
  strcpy(index->records[2].name, "Bob");
  index->records[2].age = 40;

  index->records[3].id = 4;
  strcpy(index->records[3].name, "Alice");
  index->records[3].age = 35;

  printf("Welcome to the Database Indexing System! \n");
  printf("We have an index on the name field for %d records\n", index->num_records);

  char name[20];
  printf("Please enter a name to search: ");
  scanf("%s", name);

  int record_id = find_record_by_name(index, name);
  if (record_id == -1) {
    printf("Sorry, no record found for %s\n", name);
  } else {
    printf("Record found for %s:\n", name);
    print_person(index->records[record_id]);
  }

  free(index->records);
  free(index);

  return 0;
}