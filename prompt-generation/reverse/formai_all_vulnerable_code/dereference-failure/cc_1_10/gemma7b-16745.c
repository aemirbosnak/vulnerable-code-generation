//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECOVERY_SIZE 1024

typedef struct Record
{
  char name[MAX_RECOVERY_SIZE];
  int age;
  struct Record* next;
} Record;

Record* recover_data(char* filename)
{
  FILE* file = fopen(filename, "r");
  if (!file)
  {
    return NULL;
  }

  Record* head = NULL;
  char line[MAX_RECOVERY_SIZE];
  while (fgets(line, MAX_RECOVERY_SIZE, file) != NULL)
  {
    char* name = strtok(line, ",");
    int age = atoi(strtok(NULL, ","));

    Record* new_record = malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->next = head;
    head = new_record;
  }

  fclose(file);
  return head;
}

int main()
{
  Record* recovered_data = recover_data("data.txt");

  for (Record* current = recovered_data; current; current = current->next)
  {
    printf("Name: %s, Age: %d\n", current->name, current->age);
  }

  return 0;
}