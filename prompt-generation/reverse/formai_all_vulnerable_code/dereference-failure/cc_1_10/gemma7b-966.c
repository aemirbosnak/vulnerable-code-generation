//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void watermark(int **img, int w, int h, int **wm, int wm_w, int wm_h) {
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      int sum = 0;
      for (int i = 0; i < wm_h; i++) {
        for (int j = 0; j < wm_w; j++) {
          sum += img[r + i][c + j] * wm[i][j];
        }
      }
      img[r][c] += (sum / MAX_SIZE) % 255;
    }
  }
}

int main() {
  int w = 1024;
  int h = 1024;
  int **img = (int **)malloc(h * sizeof(int *));
  for (int r = 0; r < h; r++) {
    img[r] = (int *)malloc(w * sizeof(int));
  }

  int wm_w = 64;
  int wm_h = 64;
  int **wm = (int **)malloc(wm_h * sizeof(int *));
  for (int i = 0; i < wm_h; i++) {
    wm[i] = (int *)malloc(wm_w * sizeof(int));
  }

  // Generate watermark
  for (int i = 0; i < wm_h; i++) {
    for (int j = 0; j < wm_w; j++) {
      wm[i][j] = rand() % 255;
    }
  }

  // Watermark image
  watermark(img, w, h, wm, wm_w, wm_h);

  // Save watermarked image
  FILE *fp = fopen("watermarked.jpg", "wb");
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      fprintf(fp, "%d ", img[r][c]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  return 0;
}