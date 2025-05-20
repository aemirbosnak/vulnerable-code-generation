//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record {
  char name[20];
  int age;
  struct Record* next;
} Record;

Record* recoverRecords(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  Record* head = NULL;
  Record* current = NULL;

  char line[1024];
  while (fgets(line, 1024, file) != NULL) {
    char* name = strtok(line, ",");
    int age = atoi(strtok(NULL, ","));

    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
      head = newRecord;
    } else {
      current->next = newRecord;
    }

    current = newRecord;
  }

  fclose(file);
  return head;
}

int main() {
  Record* records = recoverRecords("records.txt");

  for (Record* record = records; record != NULL; record = record->next) {
    printf("Name: %s, Age: %d\n", record->name, record->age);
  }

  return 0;
}