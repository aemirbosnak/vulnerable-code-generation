//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //seed the random number generator
  int width, height; //dimensions of the pixel art canvas
  printf("Enter width of canvas: ");
  scanf("%d", &width);
  printf("Enter height of canvas: ");
  scanf("%d", &height);

  int pixelArt[height][width]; //2D array to store the pixel art
  int pixelColors[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //color palette for the pixel art
  
  //generate random pixel art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixelArt[i][j] = pixelColors[rand() % 8]; //pick a random color from the palette
    }
  }
  
  //print the pixel art canvas
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      switch(pixelArt[i][j]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf(":");
          break;
        case 3:
          printf("-");
          break;
        case 4:
          printf("=");
          break;
        case 5:
          printf("+");
          break;
        case 6:
          printf("*");
          break;
        case 7:
          printf("#");
          break;
        default:
          printf("?");
      }
    }
    printf("\n"); //move to next line after every row
  }
  
  return 0;
}