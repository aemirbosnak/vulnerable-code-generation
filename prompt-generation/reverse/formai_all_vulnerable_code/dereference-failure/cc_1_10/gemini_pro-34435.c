//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define ROMEO 1
#define JULIET 2

struct Virus {
  char* name;
  int family;
  int severity;
};

struct ScanResult {
  int num_viruses_found;
  struct Virus* viruses_found[];
};

struct Virus Viruses[] = {
  { "I Love You", ROMEO, 10 },
  { "Melissa", ROMEO, 7 },
  { "Code Red", JULIET, 10 },
  { "Nimda", JULIET, 8 },
  { "Conficker", ROMEO, 9 },
  { "Stuxnet", JULIET, 10 },
  { "Flame", ROMEO, 9 },
  { "Duqu", JULIET, 8 }
};

int num_viruses = sizeof(Viruses) / sizeof(Viruses[0]);

struct ScanResult ScanFile(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  struct ScanResult result;
  result.num_viruses_found = 0;

  char* line = NULL;
  size_t len = 0;
  while (getline(&line, &len, fp) != -1) {
    for (int i = 0; i < num_viruses; i++) {
      if (strstr(line, Viruses[i].name) != NULL) {
        result.viruses_found[result.num_viruses_found++] = &Viruses[i];
        break;
      }
    }
  }

  fclose(fp);
  return result;
}

int main() {
  printf("Romeo and Juliet Antivirus Scanner\n");

  char* filename = "test.txt";
  struct ScanResult result = ScanFile(filename);

  if (result.num_viruses_found == 0) {
    printf("No viruses found in file %s\n", filename);
  } else {
    printf("Found %d viruses in file %s\n", result.num_viruses_found, filename);
    for (int i = 0; i < result.num_viruses_found; i++) {
      printf("  %s (severity: %d)\n", result.viruses_found[i]->name, result.viruses_found[i]->severity);
    }
  }

  return 0;
}