//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: retro
// **Retro Digital Signal Processing Adventure**

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// **Function Prototypes**

// Input: raw signal data
// Output: filtered signal data
int16_t *filter(int16_t *input, int16_t N);

// **Main Function**

int main() {
  // **Signal Generation**

  int16_t signal[] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39
  };

  int16_t N = sizeof(signal) / sizeof(signal[0]);

  // **Filtering**

  int16_t *filtered_signal = filter(signal, N);

  // **Output**

  printf("Original Signal:\n");
  for (int16_t i = 0; i < N; i++) {
    printf("%3d ", signal[i]);
  }

  printf("\n\nFiltered Signal:\n");
  for (int16_t i = 0; i < N; i++) {
    printf("%3d ", filtered_signal[i]);
  }

  printf("\n");

  return 0;
}

// **Filter Function**

int16_t *filter(int16_t *input, int16_t N) {
  // **Create Filtered Signal**

  int16_t *filtered_signal = malloc(N * sizeof(int16_t));

  // **Apply Filter**

  for (int16_t i = 0; i < N; i++) {
    filtered_signal[i] = (int16_t) (input[i] * 0.5 + input[i+1] * 0.5);
  }

  return filtered_signal;
}