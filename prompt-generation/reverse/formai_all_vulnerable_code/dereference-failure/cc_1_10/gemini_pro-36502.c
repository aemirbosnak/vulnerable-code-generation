//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define BUFFsize 1024
#define NUMtests 10

int main(int argc, char *argv[]) {
  struct timeval start, end;
  int i, j, k;
  char *buff;
  double elapsed;

  if (argc != 2) {
    printf("Usage: %s server_address\n", argv[0]);
    exit(1);
  }

  buff = malloc(BUFFsize);
  if (buff == NULL) {
    printf("Error: Unable to allocate memory for buffer.\n");
    exit(1);
  }

  for (i = 0; i < NUMtests; i++) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("Error: Unable to open file.\n");
      exit(1);
    }

    gettimeofday(&start, NULL);
    for (j = 0; j < BUFFsize; j++) {
      k = fread(buff, 1, BUFFsize, fp);
      if (k < BUFFsize) {
        printf("Error: Unexpected end of file.\n");
        exit(1);
      }
    }
    gettimeofday(&end, NULL);
    fclose(fp);

    elapsed = (double)(end.tv_sec - start.tv_sec) +
              (double)(end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Test %d: %.3f seconds\n", i + 1, elapsed);
  }

  free(buff);
  return 0;
}