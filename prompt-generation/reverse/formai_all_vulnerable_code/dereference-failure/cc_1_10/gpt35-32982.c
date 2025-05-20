//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MB 1048576  // 1 megabyte in bytes

/* Function to test internet speed */
void internetSpeedTest() {
  clock_t start, end;
  double totalTime;
  int fileSize = 50 * MB;  // 50 MB file
  char* buffer = (char*)malloc(fileSize);
  int i;

  // Generate random data
  for (i = 0; i < fileSize; i++)
    buffer[i] = rand() % 256;

  // Start timer
  printf("\nStarting test...\n");
  start = clock();

  // Simulate download/upload
  printf("Downloading %d MB file...\n", fileSize / MB);
  end = clock();
  while ((end - start) / (double)CLOCKS_PER_SEC < 5.0) {  // simulate 5 seconds download time
    end = clock();
  }
  printf("Download completed.\n");

  printf("Uploading %d MB file...\n", fileSize / MB);
  end = clock();
  while ((end - start) / (double)CLOCKS_PER_SEC < 10.0) {  // simulate 10 seconds upload time
    end = clock();
  }
  printf("Upload completed.\n");

  // Calculate time taken
  end = clock();
  totalTime = (end - start) / (double)CLOCKS_PER_SEC;

  // Print result
  printf("\nTest completed in %f seconds.\n", totalTime);

  // Free buffer memory
  free(buffer);
}

/* Main function to test internet speed */
int main() {
  internetSpeedTest();
  return 0;
}