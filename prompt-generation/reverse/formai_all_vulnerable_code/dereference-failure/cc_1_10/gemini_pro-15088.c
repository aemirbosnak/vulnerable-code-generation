//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct {
  char *name;
  char *signature;
  int size;
} Virus;

Virus viruses[] = {
  {"Virus A", "0x12345678", 1024},
  {"Virus B", "0x87654321", 2048},
  {"Virus C", "0x98765432", 4096},
};

int num_viruses = sizeof(viruses) / sizeof(Virus);

int scan_file(char *filename) {
  FILE *fp;
  char *buffer;
  int i;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  if (file_size > MAX_FILE_SIZE) {
    fclose(fp);
    return -1;
  }

  fseek(fp, 0, SEEK_SET);
  buffer = malloc(file_size);
  if (buffer == NULL) {
    fclose(fp);
    return -1;
  }

  fread(buffer, 1, file_size, fp);
  fclose(fp);

  for (i = 0; i < num_viruses; i++) {
    if (memcmp(buffer, viruses[i].signature, viruses[i].size) == 0) {
      free(buffer);
      return viruses[i].name;
    }
  }

  free(buffer);
  return NULL;
}

int main(int argc, char **argv) {
  int i;

  for (i = 1; i < argc; i++) {
    char *filename = argv[i];
    char *virus_name = scan_file(filename);
    if (virus_name != NULL) {
      printf("File %s is infected with virus %s\n", filename, virus_name);
    } else {
      printf("File %s is clean\n", filename);
    }
  }

  return 0;
}