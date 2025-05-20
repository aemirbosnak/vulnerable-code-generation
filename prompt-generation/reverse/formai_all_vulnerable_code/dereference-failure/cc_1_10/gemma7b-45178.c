//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Virus {
  char name[256];
  char description[256];
  int severity;
  struct Virus *next;
} Virus;

Virus *virus_list = NULL;

void scan_system() {
  FILE *file = fopen("virus_list.txt", "r");
  char line[256];
  Virus *new_virus = NULL;

  if (file) {
    while (fgets(line, 256, file) != NULL) {
      char *name = strtok(line, ",");
      char *description = strtok(NULL, ",");
      int severity = atoi(strtok(NULL, ","));

      new_virus = malloc(sizeof(Virus));
      strcpy(new_virus->name, name);
      strcpy(new_virus->description, description);
      new_virus->severity = severity;
      new_virus->next = virus_list;
      virus_list = new_virus;
    }
    fclose(file);
  }
}

void scan_files() {
  FILE *file = fopen("files.txt", "r");
  char line[256];
  Virus *virus = virus_list;

  if (file) {
    while (fgets(line, 256, file) != NULL) {
      char *filename = strtok(line, ",");

      for (virus = virus_list; virus; virus = virus->next) {
        if (strstr(filename, virus->name)) {
          printf("WARNING: Virus %s found in file %s!\n", virus->name, filename);
        }
      }
    }
    fclose(file);
  }
}

int main() {
  scan_system();
  scan_files();

  return 0;
}