//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void recover_data(const char* filename);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please specify a filename as a command-line argument.\n");
    return 1;
  }

  const char* filename = argv[1];
  recover_data(filename);

  return 0;
}

void recover_data(const char* filename) {
  int file_size = 0;
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("File not found or inaccessible\n");
    return;
  }

  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  char* file_data = calloc(file_size, sizeof(char));
  if (file_data == NULL) {
    fclose(fp);
    printf("Memory allocation error\n");
    return;
  }

  fread(file_data, sizeof(char), file_size, fp);
  fclose(fp);

  // Data recovery code goes here
  char* recovered_data = calloc(file_size, sizeof(char));
  int recovered_data_index = 0;

  for (int i = 0; i < file_size; i++) {
    char c = file_data[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      // Add letters as is to recovered data
      recovered_data[recovered_data_index++] = c;
    } else if (c == '\n' || c == '\r') {
      // Add line breaks as is to recovered data
      recovered_data[recovered_data_index++] = c;
    } else if (c >= '0' && c <= '9') {
      // Add digits as is to recovered data
      recovered_data[recovered_data_index++] = c;
    } else {
      // Replace all other characters with spaces in recovered data
      recovered_data[recovered_data_index++] = ' ';
    }
  }

  // Save recovered data to a new file
  char* output_filename = calloc(strlen(filename) + 5, sizeof(char));
  strcpy(output_filename, filename);
  strcat(output_filename, ".rec");
  FILE* output_fp = fopen(output_filename, "w");
  if (output_fp == NULL) {
    printf("Unable to create output file\n");
    free(file_data);
    free(recovered_data);
    free(output_filename);
    return;
  }

  int offset = 0;
  while (offset < recovered_data_index) {
    int bytes_to_write = BUFFER_SIZE;
    if (offset + bytes_to_write >= recovered_data_index) {
      bytes_to_write = recovered_data_index - offset;
    }

    fwrite(recovered_data + offset, sizeof(char), bytes_to_write, output_fp);
    offset += bytes_to_write;
  }

  fclose(output_fp);

  printf("Data recovery successful! Recovered data saved to %s\n", output_filename);

  free(file_data);
  free(recovered_data);
  free(output_filename);
}