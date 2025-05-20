//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  int width;
  int height;
  int channels;
  int samp_rate;
  int bits_per_sample;
  void *data;
} wav;

wav *read_wav(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;
  wav *w = malloc(sizeof(wav));
  if (!w) {
    fclose(fp);
    return NULL;
  }
  fread(w, sizeof(wav), 1, fp);
  if (w->bits_per_sample != 16 || w->channels != 1) {
    fclose(fp);
    free(w);
    return NULL;
  }
  w->data = malloc(w->width * w->height * sizeof(short));
  if (!w->data) {
    fclose(fp);
    free(w);
    return NULL;
  }
  fread(w->data, w->width * w->height * sizeof(short), 1, fp);
  fclose(fp);
  return w;
}

void free_wav(wav *w) {
  free(w->data);
  free(w);
}

wav *apply_filter(wav *w, const float *filter, int filter_size) {
  wav *f = malloc(sizeof(wav));
  if (!f) {
    free_wav(w);
    return NULL;
  }
  *f = *w;
  f->data = malloc(w->width * w->height * sizeof(float));
  if (!f->data) {
    free_wav(f);
    free_wav(w);
    return NULL;
  }
  for (int i = 0; i < w->width * w->height; i++) {
    float sum = 0;
    for (int j = 0; j < filter_size; j++) {
      if (i - j < 0 || i - j >= w->width * w->height) continue;
      sum += filter[j] * ((float*)w->data)[i - j];
    }
    ((float*)f->data)[i] = sum;
  }
  return f;
}

void write_wav(wav *w, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) return;
  fwrite(w, sizeof(wav), 1, fp);
  fwrite(w->data, w->width * w->height * sizeof(short), 1, fp);
  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: %s <input.wav> <filter> <output.wav>\n", argv[0]);
    return 1;
  }
  wav *w = read_wav(argv[1]);
  if (!w) {
    fprintf(stderr, "error: could not read input file\n");
    return 1;
  }
  const float filter[] = {0.1, 0.2, 0.3, 0.4, 0.5};
  int filter_size = sizeof(filter) / sizeof(float);
  wav *f = apply_filter(w, filter, filter_size);
  if (!f) {
    fprintf(stderr, "error: could not apply filter\n");
    free_wav(w);
    return 1;
  }
  write_wav(f, argv[3]);
  free_wav(w);
  free_wav(f);
  return 0;
}