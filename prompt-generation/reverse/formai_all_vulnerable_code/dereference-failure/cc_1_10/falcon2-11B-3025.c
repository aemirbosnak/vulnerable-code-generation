//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int i, j, k, n;
  FILE *infile, *outfile;
  unsigned char *inptr, *outptr;
  int height, width, ncolors, maxvalue, maxindex;
  int red, green, blue, maxcolor;
  float ratio;

  infile = fopen("input.ppm", "r");
  if (infile == NULL) {
    printf("Unable to open input.ppm\n");
    return 1;
  }

  fscanf(infile, "%d %d %d ", &height, &width, &ncolors);
  maxvalue = (unsigned char)0;
  maxindex = 0;
  for (i = 0; i < ncolors; i++) {
    fscanf(infile, "%d %d %d ", &red, &green, &blue);
    if (maxvalue < red) {
      maxvalue = red;
      maxindex = i;
    }
  }
  ratio = (float)maxvalue / 255.0;

  outfile = fopen("output.ppm", "w");
  if (outfile == NULL) {
    printf("Unable to open output.ppm\n");
    return 1;
  }

  fprintf(outfile, "P3\n%d %d %d\n", width, height, ncolors);
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      fscanf(infile, "%d %d %d ", &red, &green, &blue);
      red = 255 - red;
      green = 255 - green;
      blue = 255 - blue;
      red = (unsigned char)(red * ratio);
      green = (unsigned char)(green * ratio);
      blue = (unsigned char)(blue * ratio);
      fprintf(outfile, "%d %d %d\n", red, green, blue);
    }
  }

  fclose(infile);
  fclose(outfile);

  return 0;
}