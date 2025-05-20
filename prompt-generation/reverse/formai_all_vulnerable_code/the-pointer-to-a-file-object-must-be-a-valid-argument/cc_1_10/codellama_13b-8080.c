//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1000
#define MAX_FILES 100

typedef struct {
  char name[100];
  char extension[10];
  char data[MAX_BUFFER];
} file_t;

void print_files(file_t files[], int num_files) {
  int i;
  for (i = 0; i < num_files; i++) {
    printf("%s.%s\n", files[i].name, files[i].extension);
  }
}

void save_files(file_t files[], int num_files) {
  int i;
  for (i = 0; i < num_files; i++) {
    char filename[100];
    sprintf(filename, "%s.%s", files[i].name, files[i].extension);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s", files[i].data);
    fclose(fp);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file1> <file2> ...\n", argv[0]);
    return 1;
  }

  int num_files = argc - 1;
  file_t files[num_files];

  int i;
  for (i = 0; i < num_files; i++) {
    FILE *fp = fopen(argv[i + 1], "r");
    char buffer[MAX_BUFFER];
    char *name = strtok(argv[i + 1], ".");
    char *extension = strtok(NULL, ".");
    int size = 0;
    while (fgets(buffer, MAX_BUFFER, fp)) {
      size += strlen(buffer);
      strcat(files[i].data, buffer);
    }
    fclose(fp);
    strcpy(files[i].name, name);
    strcpy(files[i].extension, extension);
  }

  print_files(files, num_files);
  save_files(files, num_files);

  return 0;
}