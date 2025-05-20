//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

#define WATERMARK "This image is digitally watermarked."

void embed_watermark(const char* img_file) {
  FILE* fp = fopen(img_file, "rb+");
  if(fp == NULL) {
    printf("Error: Unable to open file.\n");
    return;
  }

  fseek(fp, 0, SEEK_END);
  long int file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  byte* buf = (byte*) malloc(sizeof(byte) * file_size);
  fread(buf, sizeof(byte), file_size, fp);

  fseek(fp, 0, SEEK_SET);

  const char* watermark = WATERMARK;
  long int watermark_len = strlen(watermark);
  byte byte_mask = 0x80;
  byte mask = byte_mask;
  int bit_index = 0;

  for(long int i = 0; i < watermark_len; i++) {
    char c = watermark[i];

    for(int j = 0; j < 8; j++) {
      byte b = c & mask;
      b >>= bit_index;
      buf[i * 8 + j] |= b;
      mask >>= 1;

      if(mask == 0) {
        byte_mask >>= 1;
        mask = byte_mask;
        bit_index++;

        if(bit_index == 8) {
          bit_index = 0;
        }
      }
    }
  }

  fseek(fp, 0, SEEK_SET);
  fwrite(buf, sizeof(byte), file_size, fp);
  fclose(fp);
  free(buf);
  printf("Watermark successfully embedded.\n");
}

int check_watermark(const char* img_file) {
  FILE* fp = fopen(img_file, "rb");
  if(fp == NULL) {
    printf("Error: Unable to open file.\n");
    return -1;
  }

  fseek(fp, 0, SEEK_END);
  long int file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  byte* buf = (byte*) malloc(sizeof(byte) * file_size);
  fread(buf, sizeof(byte), file_size, fp);

  const char* watermark = WATERMARK;
  long int watermark_len = strlen(watermark);
  byte byte_mask = 0x80;
  byte mask = byte_mask;
  int bit_index = 0;
  int match = 0;

  for(long int i = 0; i < watermark_len; i++) {
    char c = watermark[i];

    for(int j = 0; j < 8; j++) {
      byte b = c & mask;
      b >>= bit_index;

      if((buf[i * 8 + j] & 0x01) == b) {
        match++;
      }

      mask >>= 1;

      if(mask == 0) {
        byte_mask >>= 1;
        mask = byte_mask;
        bit_index++;

        if(bit_index == 8) {
          bit_index = 0;
        }
      }
    }
  }

  fclose(fp);
  free(buf);

  if(match == watermark_len * 8) {
    printf("Watermark detected.\n");
    return 1;
  }
  else {
    printf("Watermark not detected.\n");
    return 0;
  }
}

int main() {
  printf("Embedding watermark...\n");
  embed_watermark("myimage.jpg");
  printf("Checking watermark...\n");
  int result = check_watermark("myimage.jpg");

  if(result == -1) {
    printf("Error: Unable to check watermark.\n");
  }

  return 0;
}