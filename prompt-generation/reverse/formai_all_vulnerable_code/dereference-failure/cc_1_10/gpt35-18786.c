//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_FILEPATH_LENGTH 256

void print_banner() {
  printf("=== C Antivirus Scanner ===\n");
  printf("Scanning files for malware...\n");
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filepath>\n", argv[0]);
    return 1;
  }

  char filepath[MAX_FILEPATH_LENGTH];
  strncpy(filepath, argv[1], MAX_FILEPATH_LENGTH);

  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Error: could not open file %s\n", filepath);
    return 1;
  }

  // read file contents into buffer
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char* buffer = (char*) malloc(sizeof(char) * file_size);
  fread(buffer, sizeof(char), file_size, file);
  fclose(file);

  // scan for malware signatures
  char* signature1 = "malware_signature_1";
  char* signature2 = "malware_signature_2";
  char* signature3 = "malware_signature_3";

  int num_matches = 0;
  if (strstr(buffer, signature1)) {
    printf("Found malware signature 1!\n");
    num_matches++;
  }
  if (strstr(buffer, signature2)) {
    printf("Found malware signature 2!\n");
    num_matches++;
  }
  if (strstr(buffer, signature3)) {
    printf("Found malware signature 3!\n");
    num_matches++;
  }

  if (num_matches == 0) {
    printf("No malware signatures found.\n");
  } else {
    printf("Found %d malware signature(s).\n", num_matches);
  }

  free(buffer);
  return 0;
}