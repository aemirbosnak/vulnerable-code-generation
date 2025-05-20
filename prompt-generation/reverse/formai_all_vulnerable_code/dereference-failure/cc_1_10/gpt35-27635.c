//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int virus_detected = 0;

void file_scan(char *filename);
void search_for_virus(char *content);
void quarantine(char *filename);
void delete_file(char *filename);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: Please provide a file path for scanning.\n");
    exit(1);
  }

  char *filename = argv[1];
  printf("Scanning file %s...\n", filename);

  file_scan(filename);

  if (virus_detected) {
    printf("\nVirus detected in file %s\n", filename);
    quarantine(filename);
    printf("Virus successfully quarantined!\n");
    delete_file(filename);
    printf("Virus file deleted!\n");
  } else {
    printf("\nNo virus found in file %s\n", filename);
  }

  return 0;
}

void file_scan(char *filename) {
  FILE *fileptr;
  long file_size;
  char *file_content;

  fileptr = fopen(filename, "rb");

  if (fileptr == NULL) {
    printf("ERROR: File %s could not be opened.\n", filename);
    exit(1);
  }

  fseek(fileptr, 0L, SEEK_END);
  file_size = ftell(fileptr);
  rewind(fileptr);

  file_content = (char *) malloc(file_size * sizeof(char));
  if (file_content == NULL) {
    printf("ERROR: Could not allocate memory for file content.\n");
    exit(1);
  }

  fread(file_content, sizeof(char), file_size, fileptr);
  fclose(fileptr);

  search_for_virus(file_content);
}

void search_for_virus(char *content) {
  char *virus_signature = "invasive_antispyware";
  int signature_len = strlen(virus_signature);

  for (int i = 0; i < strlen(content) - signature_len; i++) {
    if (strncmp(&content[i], virus_signature, signature_len) == 0) {
      virus_detected = 1;
      break;
    }
  }
}

void quarantine(char *filename) {
  char *quarantine_dir = "/quarantine";
  char *new_filepath = (char *) malloc(strlen(filename) + strlen(quarantine_dir) + 1);

  if (new_filepath == NULL) {
    printf("ERROR: Could not allocate memory for new file path.\n");
    exit(1);
  }

  strcpy(new_filepath, quarantine_dir);
  strcat(new_filepath, "/");
  strcat(new_filepath, filename);

  FILE *orig_file, *new_file;
  long file_size;
  char *file_content;

  orig_file = fopen(filename, "rb");
  new_file = fopen(new_filepath, "wb");

  if (orig_file == NULL || new_file == NULL) {
    printf("ERROR: Could not open files for quarantine.\n");
    exit(1);
  }

  fseek(orig_file, 0L, SEEK_END);
  file_size = ftell(orig_file);
  rewind(orig_file);

  file_content = (char *) malloc(file_size * sizeof(char));
  if (file_content == NULL) {
    printf("ERROR: Could not allocate memory for file content.\n");
    exit(1);
  }

  fread(file_content, sizeof(char), file_size, orig_file);
  fwrite(file_content, sizeof(char), file_size, new_file);

  fclose(orig_file);
  fclose(new_file);
}

void delete_file(char *filename) {
  if (remove(filename) != 0) {
    printf("ERROR: Could not delete file %s\n", filename);
    exit(1);
  }
}