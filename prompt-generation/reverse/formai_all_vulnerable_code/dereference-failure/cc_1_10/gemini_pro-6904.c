//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} color_t;

typedef struct {
  color_t color;
  char *hex_code;
} color_conversion_t;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int color_conversion_complete = 0;

void *color_converter(void *arg) {
  color_conversion_t *conversion = (color_conversion_t *)arg;

  pthread_mutex_lock(&mutex);

  char hex_code[7];
  snprintf(hex_code, sizeof(hex_code), "#%02x%02x%02x", conversion->color.r, conversion->color.g, conversion->color.b);

  conversion->hex_code = malloc(sizeof(hex_code));
  strcpy(conversion->hex_code, hex_code);

  color_conversion_complete = 1;
  pthread_cond_signal(&cond);

  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  color_t color = { .r = 255, .g = 0, .b = 0 };
  color_conversion_t conversion = { .color = color };

  pthread_t thread;
  pthread_create(&thread, NULL, color_converter, &conversion);

  pthread_mutex_lock(&mutex);
  while (!color_conversion_complete) {
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  printf("Hex code: %s\n", conversion.hex_code);

  free(conversion.hex_code);

  pthread_join(thread, NULL);

  return 0;
}