//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

void draw_weather(int **rain_map, int **temp_map) {
  for (int y = 0; y < MAX_HEIGHT; y++) {
    for (int x = 0; x < MAX_WIDTH; x++) {
      int rain = rain_map[y][x];
      int temp = temp_map[y][x];

      if (rain > 0) {
        printf("O");
      } else if (temp < 0) {
        printf("C");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  int **rain_map = (int **)malloc(MAX_HEIGHT * sizeof(int *));
  for (int y = 0; y < MAX_HEIGHT; y++) {
    rain_map[y] = (int *)malloc(MAX_WIDTH * sizeof(int));
  }

  int **temp_map = (int **)malloc(MAX_HEIGHT * sizeof(int *));
  for (int y = 0; y < MAX_HEIGHT; y++) {
    temp_map[y] = (int *)malloc(MAX_WIDTH * sizeof(int));
  }

  // Generate random rain and temperature maps
  srand(time(NULL));
  for (int y = 0; y < MAX_HEIGHT; y++) {
    for (int x = 0; x < MAX_WIDTH; x++) {
      rain_map[y][x] = rand() % 10;
      temp_map[y][x] = rand() % 15 - 5;
    }
  }

  draw_weather(rain_map, temp_map);

  free(rain_map);
  free(temp_map);

  return 0;
}