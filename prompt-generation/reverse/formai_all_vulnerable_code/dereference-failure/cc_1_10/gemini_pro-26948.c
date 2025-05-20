//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* Knuth's shuffling algorithm from "The Art of Computer Programming" */
void shuffle(int *a, int n) {
  for (int i = 0; i < n; i++) {
    int r = rand() % (i + 1);
    int temp = a[i];
    a[i] = a[r];
    a[r] = temp;
  }
}

/* Embed a message in an image */
void embed_message(char *image, char *message, int len) {
  int *pixels = (int *)image;
  int n = len * 8;
  int m = len * 8;
  int *order = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    order[i] = i;
  }
  shuffle(order, n);
  for (int i = 0; i < m; i++) {
    int bit = (message[i / 8] >> (i % 8)) & 1;
    int pixel = pixels[order[i]];
    if (bit) {
      pixel |= 1;
    } else {
      pixel &= ~1;
    }
    pixels[order[i]] = pixel;
  }
  free(order);
}

/* Extract a message from an image */
char *extract_message(char *image, int len) {
  int *pixels = (int *)image;
  int n = len * 8;
  int m = len * 8;
  int *order = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    order[i] = i;
  }
  shuffle(order, n);
  char *message = (char *)malloc(len);
  for (int i = 0; i < m; i++) {
    int pixel = pixels[order[i]];
    int bit = pixel & 1;
    message[i / 8] |= bit << (i % 8);
  }
  free(order);
  return message;
}

int main() {
  char *image = malloc(100000);
  char *message = "Hello, world!";
  embed_message(image, message, strlen(message));
  char *extracted_message = extract_message(image, strlen(message));
  printf("%s\n", extracted_message);
  free(image);
  free(extracted_message);
  return 0;
}