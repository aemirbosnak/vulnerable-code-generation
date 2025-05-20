//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 64
#define FILEPATH_SIZE 256

void generateWatermark(char *watermark) {
  // generate a random string as watermark
  int i;
  for (i = 0; i < WATERMARK_SIZE; i++) {
    watermark[i] = rand() % 127;  // printable ASCII range
  }
}

int main(int argc, char *argv[]) {
  char watermark[WATERMARK_SIZE];
  generateWatermark(watermark);
  printf("Watermark: %s\n", watermark);
  
  char originalFilePath[FILEPATH_SIZE];
  printf("Enter path to original file: ");
  scanf("%s", originalFilePath);

  // add watermark to original file
  FILE *fp = fopen(originalFilePath, "rb+");
  if (fp == NULL) {
    printf("Error: cannot open file %s\n", originalFilePath);
    return 1;
  }

  // get file size
  fseek(fp, 0L, SEEK_END);
  long fileSize = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  // allocate memory for file and watermark data
  char *fileData = (char *) malloc(fileSize);
  fread(fileData, 1, fileSize, fp);

  // write watermark at the end of file
  memcpy(&fileData[fileSize], watermark, WATERMARK_SIZE);

  // write updated data to original file
  fseek(fp, 0L, SEEK_SET);
  fwrite(fileData, 1, fileSize + WATERMARK_SIZE, fp);

  // release resources
  free(fileData);
  fclose(fp);

  // verify watermark
  char verifyFilePath[FILEPATH_SIZE];
  printf("Enter path to file to verify watermark: ");
  scanf("%s", verifyFilePath);

  // read last 64 bytes of file as watermark
  fp = fopen(verifyFilePath, "rb");
  if (fp == NULL) {
    printf("Error: cannot open file %s\n", verifyFilePath);
    return 1;
  }

  fseek(fp, -WATERMARK_SIZE, SEEK_END);
  char verifyWatermark[WATERMARK_SIZE];
  fread(verifyWatermark, 1, WATERMARK_SIZE, fp);

  if (memcmp(verifyWatermark, watermark, WATERMARK_SIZE) == 0) {
    printf("Watermark verified successfully!\n");
  } else {
    printf("Error: watermark verification failed\n");
  }

  fclose(fp);

  return 0;
}