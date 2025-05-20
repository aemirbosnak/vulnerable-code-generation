//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Virus {
  char name[256];
  char description[512];
  int severity;
  struct Virus* next;
} Virus;

Virus* scan_for_virus(char* file_path) {
  FILE* file = fopen(file_path, "r");
  if (file == NULL) {
    return NULL;
  }

  Virus* virus_list = NULL;
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;

  while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
    char* virus_name = strstr(buffer, "Virus Name:");
    char* virus_description = strstr(buffer, "Virus Description:");
    int virus_severity = atoi(strstr(buffer, "Virus Severity:"));

    if (virus_name && virus_description && virus_severity) {
      Virus* new_virus = malloc(sizeof(Virus));
      strcpy(new_virus->name, virus_name);
      strcpy(new_virus->description, virus_description);
      new_virus->severity = virus_severity;
      new_virus->next = virus_list;
      virus_list = new_virus;
    }
  }

  fclose(file);
  return virus_list;
}

int main() {
  char* file_path = "virus_list.txt";
  Virus* virus_list = scan_for_virus(file_path);

  if (virus_list) {
    for (Virus* virus = virus_list; virus; virus = virus->next) {
      printf("Virus Name: %s\n", virus->name);
      printf("Virus Description: %s\n", virus->description);
      printf("Virus Severity: %d\n", virus->severity);
      printf("\n");
    }
  } else {
    printf("No viruses found.\n");
  }

  return 0;
}