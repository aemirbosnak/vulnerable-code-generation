//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLK_SZ 512

int main() {
  FILE *fp;
  char *buf;
  int i, j, k;
  long long int sz;

  // Open the C drive
  fp = fopen("C:\\", "rb");
  if (fp == NULL) {
    perror("Error opening C drive");
    return EXIT_FAILURE;
  }

  // Get the size of the C drive
  fseek(fp, 0, SEEK_END);
  sz = ftell(fp);

  // Allocate a buffer to hold the data
  buf = (char *)malloc(BLK_SZ);
  if (buf == NULL) {
    perror("Error allocating buffer");
    return EXIT_FAILURE;
  }

  // Read the data from the C drive
  fseek(fp, 0, SEEK_SET);
  for (i = 0; i < sz; i += BLK_SZ) {
    if (fread(buf, BLK_SZ, 1, fp) != 1) {
      perror("Error reading C drive");
      return EXIT_FAILURE;
    }

    // Process the data
    for (j = 0; j < BLK_SZ; j++) {
      for (k = 0; k < 8; k++) {
        if (buf[j] & (1 << k)) {
          printf("%d ", k);
        }
      }
    }
  }

  // Free the buffer
  free(buf);

  // Close the C drive
  fclose(fp);

  return EXIT_SUCCESS;
}