//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NBITS 8
#define NBLOCKS 1024
#define BLOCKSIZE 1024

unsigned char *embedWaterMark(unsigned char *image, unsigned char *waterMark, int n, int m){
  unsigned char *newImage = malloc(n * m);

  int i, j, k = 0;
  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      newImage[i * m + j] = image[i * m + j] & 0xFE | (waterMark[k >> 3] >> (k & 7)) & 1;
      k++;
    }
  }
  return newImage;
}
unsigned char *extractWaterMark(unsigned char *image, int n, int m){
  unsigned char *waterMark = calloc(n * m / 8, sizeof(unsigned char));

  int i, j, k = 0;
  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      waterMark[k >> 3] |= (image[i * m + j] & 1) << (k & 7);
      k++;
    }
  }
  return waterMark;
}
int main(){
  unsigned char image[NBLOCKS * BLOCKSIZE], waterMark[NBLOCKS * BLOCKSIZE / NBITS];

  FILE *fImage = fopen("image.bmp", "rb");
  if (fImage == NULL) fprintf(stderr, "Error opening image file.\n"), exit(1);
  fread(image, BLOCKSIZE, NBLOCKS, fImage);
  fclose(fImage);

  FILE *fWaterMark = fopen("waterMark.txt", "rb");
  if (fWaterMark == NULL) fprintf(stderr, "Error opening waterMark file.\n"), exit(1);
  fread(waterMark, NBLOCKS * BLOCKSIZE / NBITS, 1, fWaterMark);
  fclose(fWaterMark);

  unsigned char *newImage = embedWaterMark(image, waterMark, NBLOCKS, BLOCKSIZE);
  FILE *fNewImage = fopen("newImage.bmp", "wb");
  fwrite(newImage, BLOCKSIZE, NBLOCKS, fNewImage);
  fclose(fNewImage);

  unsigned char *extractedWaterMark = extractWaterMark(newImage, NBLOCKS, BLOCKSIZE);
  FILE *fExtractedWaterMark = fopen("extractedWaterMark.txt", "wb");
  fwrite(extractedWaterMark, NBLOCKS * BLOCKSIZE / NBITS, 1, fExtractedWaterMark);
  fclose(fExtractedWaterMark);

  return 0;
}