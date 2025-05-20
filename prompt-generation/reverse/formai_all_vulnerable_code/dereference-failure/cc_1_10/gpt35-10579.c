//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk virus definitions
char virus1[] = "deadc0de";
char virus2[] = "brainstormvirus";
char virus3[] = "ghostinthemachine";
char virus4[] = "neonworm";
char virus5[] = "cyperpunksrulez";

int scan_files(const char* filename);

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Please specify file to scan!\n");
    return 0;
  }

  if(scan_files(argv[1]) == 0) {
    printf("File is clean!\n");
  }

  return 0;
}

int scan_files(const char* filename) {
  FILE* file = fopen(filename, "r");

  if(file == NULL) {
    printf("Cannot open file!\n");
    return -1;
  }

  char* buffer = (char*)malloc(sizeof(char) * 1024);
  int infected = 0;

  while(fgets(buffer, 1024, file) != NULL) {
    if(strstr(buffer, virus1) != NULL || strstr(buffer, virus2) != NULL || strstr(buffer, virus3) != NULL || strstr(buffer, virus4) != NULL || strstr(buffer, virus5) != NULL) {
      printf("Virus detected!\n");
      infected = 1;
      break;
    }
  }

  free(buffer);
  fclose(file);

  return infected;
}