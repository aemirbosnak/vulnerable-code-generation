//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

typedef struct {
  int key;
  char name[20];
  int age;
} Record;

typedef struct {
  int* keys;
  int size;
} Index;

Index* create_index(int* arr, int size) {
  Index* index = (Index*)malloc(sizeof(Index));
  index->keys = arr;
  index->size = size;
  return index;
}

void display_records(Record* records, int count) {
  printf("\n=================================================================================");
  printf("\n| %-10s | %-20s | %-10s |", "Key", "Name", "Age");
  printf("\n=================================================================================");
  for(int i = 0; i < count; i++) {
    printf("\n| %10d | %-20s | %10d |", records[i].key, records[i].name, records[i].age);
  }
  printf("\n=================================================================================");
}

void display_index(Index* index) {
  printf("\n------------------------ Index ------------------------------");
  for(int i = 0; i < index->size; i++) {
    printf("\n%d", index->keys[i]);
  }
  printf("\n-------------------------------------------------------------");
}

int main() {

  Record records[MAX_RECORDS];
  int record_count = 0;

  int keys[MAX_RECORDS];
  int index_count = 0;

  while(1) {
    int choice;
    printf("\n------------------------ Menu -------------------------------");
    printf("\n1. Insert record");
    printf("\n2. Search record");
    printf("\n3. Display records");
    printf("\n4. Display index");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
      if(record_count < MAX_RECORDS) {
        Record record;

        printf("\nEnter key: ");
        scanf("%d", &record.key);

        printf("\nEnter name: ");
        scanf("%s", record.name);

        printf("\nEnter age: ");
        scanf("%d", &record.age);

        records[record_count] = record;

        int i = 0;
        while(i < index_count && keys[i] < record.key) {
          i++;
        }
        for(int j = index_count; j > i; j--) {
          keys[j] = keys[j-1];
        }
        keys[i] = record.key;
        index_count++;

        printf("\nRecord successfully inserted!");
        record_count++;
      } else {
        printf("\nMax records reached! Cannot insert anymore.");
      }
    } else if(choice == 2) {
      int key;
      printf("\nEnter key: ");
      scanf("%d", &key);

      int i = 0;
      while(i < index_count && keys[i] < key) {
        i++;
      }
      if(i < index_count && keys[i] == key) {
        printf("\nRecord found:");
        printf("\n| %-10s | %-20s | %-10s |", "Key", "Name", "Age");
        printf("\n| %10d | %-20s | %10d |", records[i].key, records[i].name, records[i].age);
      } else {
        printf("\nRecord not found!");
      }

    } else if(choice == 3) {
      display_records(records, record_count);

    } else if(choice == 4) {
      Index* index = create_index(keys, index_count);
      display_index(index);

    } else if(choice == 5) {
      printf("\nExiting...");
      break;

    } else {
      printf("\nInvalid choice! Please try again.");
    }
  }

  return 0;
}