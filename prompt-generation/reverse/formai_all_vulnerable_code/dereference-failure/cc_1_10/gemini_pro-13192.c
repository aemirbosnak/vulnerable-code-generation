//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double *data;
  unsigned long length;
  double Hz;
} Sound;

Sound *load_sound(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  unsigned long length;
  fread(&length, sizeof(length), 1, fp);

  double *data = malloc(length * sizeof(double));
  fread(data, sizeof(double), length, fp);

  fclose(fp);

  Sound *sound = malloc(sizeof(Sound));
  sound->data = data;
  sound->length = length;
  sound->Hz = 44100;
  return sound;
}

void free_sound(Sound *sound) {
  free(sound->data);
  free(sound);
}

void play_sound(Sound *sound) {
  for (unsigned long i = 0; i < sound->length; i++) {
    printf("%f\n", sound->data[i]);
  }
}

int main() {
  Sound *sound = load_sound("test.wav");
  if (!sound) return EXIT_FAILURE;

  play_sound(sound);

  free_sound(sound);

  return EXIT_SUCCESS;
}