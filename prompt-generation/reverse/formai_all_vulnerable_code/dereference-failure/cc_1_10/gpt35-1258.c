//FormAI DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
int readImage(char *filename, unsigned char **image, int *width, int *height, int *depth);
void writeImage(char *filename, unsigned char *image, int width, int height, int depth);
void encodeMessage(unsigned char *image, int width, int height, char *message);
char* decodeMessage(unsigned char *image, int width, int height);

int main(int argc, char *argv[]) {
  /* check for appropriate command-line arguments */
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  unsigned char *image;
  int width, height, depth;
  
  /* read input image */
  if (readImage(argv[1], &image, &width, &height, &depth) == -1) {
    fprintf(stderr, "Error: Unable to read input file <%s>\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  
  /* encode message into image */
  encodeMessage(image, width, height, argv[3]);
  
  /* write encoded image to file */
  writeImage(argv[2], image, width, height, depth);
  
  /* decode message from image */
  char *message = decodeMessage(image, width, height);
  
  /* print decoded message */
  printf("Decoded message: %s\n", message);
  
  /* free allocated memory */
  free(image);
  free(message);
  
  return EXIT_SUCCESS;
}

/* function to read image from file */
int readImage(char *filename, unsigned char **image, int *width, int *height, int *depth) {
  FILE *fp;
  
  /* open file for binary reading */
  if ((fp = fopen(filename, "rb")) == NULL) {
    return -1;
  }
  
  /* read image header */
  fscanf(fp, "P6\n%d %d\n%d\n", width, height, depth);
  
  /* allocate memory for image data */
  *image = (unsigned char*) malloc(sizeof(unsigned char) * (*width) * (*height) * 3);
  
  /* read image data */
  fread(*image, sizeof(unsigned char), (*width) * (*height) * 3, fp);
  
  /* close file */
  fclose(fp);
  
  return 0;
}

/* function to write image to file */
void writeImage(char *filename, unsigned char *image, int width, int height, int depth) {
  FILE *fp;
  
  /* open file for binary writing */
  if ((fp = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "Error: Unable to open output file <%s>\n", filename);
    exit(EXIT_FAILURE);
  }
  
  /* write image header */
  fprintf(fp, "P6\n%d %d\n%d\n", width, height, depth);
  
  /* write image data */
  fwrite(image, sizeof(unsigned char), width * height * 3, fp);
  
  /* close file */
  fclose(fp);
}

/* function to encode message into image */
void encodeMessage(unsigned char *image, int width, int height, char *message) {
  int i, j, bit, index = 0, length = strlen(message);
  
  /* loop through image data */
  for (i = 0; i < width * height * 3 && index < length; i += 3) {
    /* loop through each color channel (RGB) */
    for (j = 0; j < 3 && index < length; j++) {
      /* extract current bit of message */
      bit = (message[index] >> (7 - (i % 8))) & 1;
      
      /* modify least significant bit of current pixel */
      image[i + j] = (image[i + j] & 0xFE) | bit;
      
      /* increment index if current bit of message has been encoded */
      if ((i % 8) == 7) {
        index++;
      }
    }
  }
  
  /* add end-of-message marker */
  for (; index < length + 1; i += 3) {
    image[i] = (image[i] & 0xFE) | 1;
  }
}

/* function to decode message from image */
char* decodeMessage(unsigned char *image, int width, int height) {
  int i, j, bit, index = 0;
  char *message = (char*) malloc(sizeof(char));
  
  /* loop through image data */
  for (i = 0; i < width * height * 3; i += 3) {
    /* loop through each color channel (RGB) */
    for (j = 0; j < 3; j++) {
      /* extract least significant bit of current pixel */
      bit = image[i + j] & 1;
      
      /* append current bit to message */
      message[index] = (message[index] << 1) | bit;
      
      /* increment index if end-of-message marker is encountered */
      if (message[index] == '\0') {
        return message;
      }
      
      /* reset message buffer if current bit of message has been decoded */
      if ((i % 8) == 7) {
        message = (char*) realloc(message, sizeof(char) * (index + 1));
        index++;
      }
    }
  }
  
  return message;
}