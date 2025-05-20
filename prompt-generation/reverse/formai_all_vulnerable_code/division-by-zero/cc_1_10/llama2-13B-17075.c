//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define MAX_LINE_LENGTH 256

int main() {
  srand(time(NULL)); // seed random number generator

  // generate a random file name
  char filename[50];
  snprintf(filename, sizeof(filename), "random_%d.txt", rand() % 1000);

  // open the file in random access mode
  FILE *file = fopen(filename, "r+");
  if (!file) {
    fprintf(stderr, "Error: unable to open file %s\n", filename);
    return 1;
  }

  // write some random data to the file
  char buffer[MAX_LINE_LENGTH];
  for (int i = 0; i < 10; i++) {
    snprintf(buffer, sizeof(buffer), "Line %d: This is some random text\n", i);
    fwrite(buffer, 1, strlen(buffer), file);
  }

  // randomize the file size
  long fileSize = rand() % MAX_FILE_SIZE;
  fseek(file, 0, SEEK_SET);
  for (int i = 0; i < fileSize; i++) {
    char randomChar = 'a' + (rand() % 26);
    fputc(randomChar, file);
  }

  // move the file pointer to a random location
  long randomPosition = rand() % (long)ftell(file);
  fseek(file, randomPosition, SEEK_SET);

  // read some data from the file
  char buffer2[MAX_LINE_LENGTH];
  fread(buffer2, 1, MAX_LINE_LENGTH, file);
  printf("Read line: %s\n", buffer2);

  // close the file
  fclose(file);

  return 0;
}