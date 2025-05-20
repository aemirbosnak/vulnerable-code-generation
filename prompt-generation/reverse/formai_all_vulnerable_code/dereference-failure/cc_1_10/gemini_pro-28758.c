//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: creative
// Welcome to the Enchanted Forest of Data Mining!

#include <stdio.h>
#include <stdlib.h>

// Our Mystical Data Forest
typedef struct {
  char name[20];       // Every tree has a unique name
  int height;          // How tall they stand
  float canopy;       // How lush their leaves
} Tree;

// Our Wise Old Wizard of Data
void analyze(Tree forest[], int n) {
  // Step 1: Gather Wisdom from the Forest
  int tallest = -1;     // No tree is initially the tallest
  int shortest = 2147483647;  // No tree is initially the shortest
  int averageHeight = 0;
  int denseCanopyCount = 0;

  for (int i = 0; i < n; i++) {
    if (forest[i].height > forest[tallest].height) {
      tallest = i;
    }
    if (forest[i].height < forest[shortest].height) {
      shortest = i;
    }
    averageHeight += forest[i].height;
    if (forest[i].canopy > 0.75) {
      denseCanopyCount++;
    }
  }

  averageHeight /= n;

  // Step 2: Reveal the Forest's Secrets
  printf("Behold the Secrets of the Enchanted Forest!\n");
  printf("The Tallest Tree: %s, reaching %d feet into the sky!\n", forest[tallest].name, forest[tallest].height);
  printf("The Humblest Tree: %s, standing at a modest %d feet.\n", forest[shortest].name, forest[shortest].height);
  printf("Average Tree Height: %d feet, a balanced beauty.\n", averageHeight);
  printf("Dense Canopy Trees: %d, their leaves a verdant tapestry.\n", denseCanopyCount);
}

int main() {
  // Let's Meet the Forest's Residents
  Tree forest[] = {
    {"Oak", 80, 0.8},
    {"Pine", 60, 0.6},
    {"Birch", 40, 0.5},
    {"Maple", 50, 0.7},
    {"Willow", 30, 0.9}
  };
  int n = sizeof(forest) / sizeof(Tree);

  // Step 3: Consult the Wizard of Data
  analyze(forest, n);

  return 0;
}