//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>

void embed_watermark(FILE *infile, FILE *outfile, char watermark[]) {
  unsigned char byte;
  int i = 0, wm_length = strlen(watermark);

  while (fread(&byte, 1, 1, infile) == 1) {
    if (i < wm_length) {
      byte = byte | watermark[i];
      i++;
    }
    fwrite(&byte, 1, 1, outfile);
  }

  if (i == wm_length) {
    int j;
    for (j = 0; j < 8; j++) {
      byte = byte & ~(1 << j);
    }
    fwrite(&byte, 1, 1, outfile);
  }
}

void extract_watermark(FILE *infile) {
  unsigned char byte;
  int i = 0;

  while (fread(&byte, 1, 1, infile) == 1) {
    if (i < 8) {
      printf("%d", byte & 1);
      i++;
    } else {
      break;
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  char *mode = argv[1];
  char *infile_name = argv[2];
  char *outfile_name = argv[3];
  char *watermark = argv[4];

  FILE *infile = fopen(infile_name, "rb");
  FILE *outfile = fopen(outfile_name, mode);

  if (!infile) {
    perror("Could not open input file");
    return 1;
  } else if (!outfile) {
    perror("Could not open output file");
    fclose(infile);
    return 1;
  }

  if (mode[0] == 'e') {
    embed_watermark(infile, outfile, watermark);
    printf("Watermark embedded successfully\n");
  } else if (mode[0] == 'x') {
    printf("Extracted watermark: ");
    extract_watermark(infile);
  } else {
    printf("Invalid mode specified\n");
  }

  fclose(infile);
  fclose(outfile);
  
  return 0;
}