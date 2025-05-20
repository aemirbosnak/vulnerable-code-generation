//FormAI DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *inFile, *outFile;
  int width, height, maxval, r, g, b;
  char *inFileName = "input.ppm";
  char *outFileName = "output.ppm";
  
  printf("Opening input file '%s'\n", inFileName);
  inFile = fopen(inFileName, "r");
  if (!inFile) {
    printf("Error: could not open input file\n");
    return 1;
  }

  printf("Reading image data from input file\n");
  fscanf(inFile, "P3\n%d %d\n%d\n", &width, &height, &maxval);

  printf("Image width: %d, height: %d, maxval: %d\n", width, height, maxval);

  printf("Opening output file '%s'\n", outFileName);
  outFile = fopen(outFileName, "w");
  if (!outFile) {
    printf("Error: could not open output file\n");
    return 1;
  }

  printf("Writing header to output file\n");
  fprintf(outFile, "P3\n%d %d\n%d\n", width, height, maxval);

  printf("Editing image data and writing to output file\n");
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      fscanf(inFile, "%d %d %d", &r, &g, &b);
      r = (r + 255) % maxval;
      g = (g + 255) % maxval;
      b = (b + 255) % maxval;
      fprintf(outFile, "%d %d %d ", r, g, b);
    }
    fprintf(outFile, "\n");
  }
  
  printf("Closing input and output files\n");
  fclose(inFile);
  fclose(outFile);

  printf("Done!\n");

  return 0;
}