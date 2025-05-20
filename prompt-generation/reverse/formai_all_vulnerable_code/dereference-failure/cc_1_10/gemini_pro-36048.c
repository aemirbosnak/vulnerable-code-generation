//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

// Function to read the input file
unsigned char *read_file(char *filename, long *file_size) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  *file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  unsigned char *data = (unsigned char *)malloc(*file_size);
  if (data == NULL) {
    printf("Error allocating memory for file data\n");
    fclose(fp);
    return NULL;
  }

  fread(data, 1, *file_size, fp);
  fclose(fp);

  return data;
}

// Function to write the output file
int write_file(char *filename, unsigned char *data, long file_size) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  fwrite(data, 1, file_size, fp);
  fclose(fp);

  return 0;
}

// Function to embed the watermark into the input file
int embed_watermark(unsigned char *data, long file_size, char *watermark) {
  // Check if the watermark is too long
  if (strlen(watermark) > file_size) {
    printf("Watermark is too long\n");
    return -1;
  }

  // Embed the watermark into the input file
  for (int i = 0; i < strlen(watermark); i++) {
    data[i] = data[i] ^ watermark[i];
  }

  return 0;
}

// Function to extract the watermark from the input file
char *extract_watermark(unsigned char *data, long file_size) {
  // Allocate memory for the extracted watermark
  char *watermark = (char *)malloc(file_size);
  if (watermark == NULL) {
    printf("Error allocating memory for watermark\n");
    return NULL;
  }

  // Extract the watermark from the input file
  for (int i = 0; i < file_size; i++) {
    watermark[i] = data[i] ^ data[i];
  }

  // Return the extracted watermark
  return watermark;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <input_file> <output_file> <watermark>\n", argv[0]);
    return -1;
  }

  // Read the input file
  long file_size;
  unsigned char *data = read_file(argv[1], &file_size);
  if (data == NULL) {
    return -1;
  }

  // Embed the watermark into the input file
  if (embed_watermark(data, file_size, argv[3]) != 0) {
    free(data);
    return -1;
  }

  // Write the watermarked file to disk
  if (write_file(argv[2], data, file_size) != 0) {
    free(data);
    return -1;
  }

  // Extract the watermark from the watermarked file
  char *watermark = extract_watermark(data, file_size);
  if (watermark == NULL) {
    free(data);
    return -1;
  }

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", watermark);

  // Free the allocated memory
  free(data);
  free(watermark);

  return 0;
}