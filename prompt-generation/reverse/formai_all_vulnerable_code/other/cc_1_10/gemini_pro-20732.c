//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define WIDTH  720
#define HEIGHT 480

#define IMAGE_SIZE (WIDTH * HEIGHT * 4)

static uint8_t* load(const char* path) {
  FILE* f = fopen(path, "rb");
  assert(f);
  uint8_t* data = malloc(IMAGE_SIZE);
  assert(data);
  fread(data, IMAGE_SIZE, 1, f);
  fclose(f);
  return data;
}

static void flip(uint8_t* data) {
  for (int y = 0; y < HEIGHT / 2; y++)
    for (int x = 0; x < WIDTH; x++) {
      int offset = (y * WIDTH + x) * 4;
      uint8_t tmp[4];
      memcpy(tmp, data + offset, 4);
      memcpy(data + offset, data + (IMAGE_SIZE - offset - 4), 4);
      memcpy(data + (IMAGE_SIZE - offset - 4), tmp, 4);
    }
}

static void adjust(uint8_t* data, float bright, float contrast) {
  assert(bright >= 0 && bright <= 1 && contrast >= 0 && contrast <= 1);

  for (int i = 0; i < IMAGE_SIZE; i++)
    data[i] = (data[i] - 128) * contrast + 128 * bright + 128;
}

static void save(uint8_t* data, const char* path) {
  FILE* f = fopen(path, "wb");
  assert(f);
  fwrite(data, IMAGE_SIZE, 1, f);
  fclose(f);
}

static void cleanup(uint8_t* data) {
  free(data);
}

int main() {
  const char* input_path = "./input.png";
  const char* output_path = "./output.png";

  uint8_t* data = load(input_path);

  flip(data);
  adjust(data, 0.5, 1.2);

  save(data, output_path);

  cleanup(data);

  return 0;
}