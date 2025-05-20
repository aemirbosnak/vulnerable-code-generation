//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  unsigned int width, height, channels;
  unsigned char *data;
} Image;

Image *read_image(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Unable to open file");
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    perror("Unable to allocate memory for image");
    fclose(file);
    return NULL;
  }

  fread(&image->width, sizeof(unsigned int), 1, file);
  fread(&image->height, sizeof(unsigned int), 1, file);
  fread(&image->channels, sizeof(unsigned int), 1, file);

  image->data = malloc(image->width * image->height * image->channels);
  if (image->data == NULL) {
    perror("Unable to allocate memory for image data");
    free(image);
    fclose(file);
    return NULL;
  }

  fread(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);

  return image;
}

void write_image(const char *filename, const Image *image) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Unable to open file");
    return;
  }

  fwrite(&image->width, sizeof(unsigned int), 1, file);
  fwrite(&image->height, sizeof(unsigned int), 1, file);
  fwrite(&image->channels, sizeof(unsigned int), 1, file);
  fwrite(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);
}

void embed_message(Image *image, const char *message) {
  int message_length = strlen(message);
  if (message_length > image->width * image->height * image->channels / 8) {
    fprintf(stderr, "Message too long\n");
    return;
  }

  int bit_index = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if (bit_index < message_length * 8) {
      image->data[i] = (image->data[i] & ~1) | ((message[bit_index / 8] >> (bit_index % 8)) & 1);
      bit_index++;
    }
  }
}

char *extract_message(const Image *image) {
  int message_length = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if (image->data[i] & 1) {
      message_length++;
    }
  }
  if (message_length % 8 != 0) {
    fprintf(stderr, "Invalid message length\n");
    return NULL;
  }

  char *message = malloc(message_length / 8 + 1);
  if (message == NULL) {
    perror("Unable to allocate memory for message");
    return NULL;
  }

  int bit_index = 0;
  for (int i = 0; i < image->width * image->height * image->channels; i++) {
    if (bit_index < message_length * 8) {
      message[bit_index / 8] |= (image->data[i] & 1) << (bit_index % 8);
      bit_index++;
    }
  }
  message[message_length / 8] = '\0';

  return message;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
    return 1;
  }

  Image *image = read_image(argv[1]);
  if (image == NULL) {
    return 1;
  }

  embed_message(image, argv[3]);

  write_image(argv[2], image);

  free(image->data);
  free(image);

  return 0;
}