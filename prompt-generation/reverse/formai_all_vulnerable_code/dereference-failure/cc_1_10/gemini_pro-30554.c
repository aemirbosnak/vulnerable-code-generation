//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

typedef struct {
  float *data;
  int length;
} Signal;

Signal *createSignal(int length) {
  Signal *signal = malloc(sizeof(Signal));
  signal->data = malloc(length * sizeof(float));
  signal->length = length;
  return signal;
}

void freeSignal(Signal *signal) {
  free(signal->data);
  free(signal);
}

Signal *loadSignal(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Could not open file");
    exit(1);
  }

  int length;
  fscanf(file, "%d", &length);

  Signal *signal = createSignal(length);
  for (int i = 0; i < length; i++) {
    fscanf(file, "%f", &signal->data[i]);
  }

  fclose(file);
  return signal;
}

void saveSignal(const char *filename, Signal *signal) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Could not open file");
    exit(1);
  }

  fprintf(file, "%d\n", signal->length);
  for (int i = 0; i < signal->length; i++) {
    fprintf(file, "%f\n", signal->data[i]);
  }

  fclose(file);
}

void printSignal(Signal *signal) {
  for (int i = 0; i < signal->length; i++) {
    printf("%f\n", signal->data[i]);
  }
}

Signal *fft(Signal *signal) {
  Signal *fftSignal = createSignal(signal->length);

  for (int i = 0; i < signal->length; i++) {
    fftSignal->data[i] = 0.0;
    for (int j = 0; j < signal->length; j++) {
      fftSignal->data[i] += signal->data[j] * cos(2 * PI * i * j / signal->length);
    }
  }

  return fftSignal;
}

Signal *ifft(Signal *fftSignal) {
  Signal *signal = createSignal(fftSignal->length);

  for (int i = 0; i < fftSignal->length; i++) {
    signal->data[i] = 0.0;
    for (int j = 0; j < fftSignal->length; j++) {
      signal->data[i] += fftSignal->data[j] * cos(2 * PI * i * j / fftSignal->length);
    }
  }

  return signal;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  Signal *signal = loadSignal(argv[1]);

  Signal *fftSignal = fft(signal);

  Signal *ifftSignal = ifft(fftSignal);

  freeSignal(signal);
  freeSignal(fftSignal);
  freeSignal(ifftSignal);

  return 0;
}