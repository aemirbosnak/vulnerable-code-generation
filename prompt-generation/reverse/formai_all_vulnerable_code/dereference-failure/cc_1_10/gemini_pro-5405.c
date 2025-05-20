//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// I'm a very serious image processing program.

int main() {
  // Let's load an image.
  FILE *f = fopen("image.bmp", "rb");
  if (!f) {
    printf("Oops! I can't find your image. Did you hide it on me? :(\n");
    return 1;
  }

  // Let's read the header.
  uint16_t type;
  fread(&type, sizeof(type), 1, f);
  if (type != 0x4D42) {
    printf("Hmm... this doesn't look like a BMP image. Are you trying to trick me? :P\n");
    fclose(f);
    return 1;
  }

  // Let's skip the rest of the header.
  fseek(f, 10, SEEK_CUR);

  // Let's read the image dimensions.
  uint32_t width, height;
  fread(&width, sizeof(width), 1, f);
  fread(&height, sizeof(height), 1, f);

  // Let's read the image data.
  uint8_t *data = malloc(width * height * 3);
  fread(data, width * height * 3, 1, f);
  fclose(f);

  // Let's flip the image horizontally.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      uint8_t tmp = data[y * width * 3 + x * 3];
      data[y * width * 3 + x * 3] = data[y * width * 3 + (width - x - 1) * 3];
      data[y * width * 3 + (width - x - 1) * 3] = tmp;
      tmp = data[y * width * 3 + x * 3 + 1];
      data[y * width * 3 + x * 3 + 1] = data[y * width * 3 + (width - x - 1) * 3 + 1];
      data[y * width * 3 + (width - x - 1) * 3 + 1] = tmp;
      tmp = data[y * width * 3 + x * 3 + 2];
      data[y * width * 3 + x * 3 + 2] = data[y * width * 3 + (width - x - 1) * 3 + 2];
      data[y * width * 3 + (width - x - 1) * 3 + 2] = tmp;
    }
  }

  // Let's make the image brighter and more contrasty.
  for (int i = 0; i < width * height * 3; i++) {
    data[i] = (data[i] * 1.2) + 10;
    if (data[i] > 255) {
      data[i] = 255;
    }
  }

  // Let's save the image.
  f = fopen("flipped_brightened_contrasted_image.bmp", "wb");
  fwrite(&type, sizeof(type), 1, f);
  fseek(f, 10, SEEK_CUR);
  fwrite(&width, sizeof(width), 1, f);
  fwrite(&height, sizeof(height), 1, f);
  fwrite(data, width * height * 3, 1, f);
  fclose(f);

  // Let's show off our masterpiece!
  printf("Ta-da! I've flipped, brightened, and contrasted your image. Check it out: flipped_brightened_contrasted_image.bmp\n");

  free(data);
  return 0;
}