//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct galaxy {
  int size;
  int num_stars;
  struct star *stars;
};

struct star {
  int x;
  int y;
  int size;
  int num_planets;
  struct planet *planets;
};

struct planet {
  int x;
  int y;
  int size;
};

struct galaxy *generate_galaxy(int size) {
  struct galaxy *galaxy = malloc(sizeof(struct galaxy));
  galaxy->size = size;
  galaxy->num_stars = rand() % 100;
  galaxy->stars = malloc(sizeof(struct star) * galaxy->num_stars);
  for (int i = 0; i < galaxy->num_stars; i++) {
    galaxy->stars[i].x = rand() % galaxy->size;
    galaxy->stars[i].y = rand() % galaxy->size;
    galaxy->stars[i].size = rand() % 10;
    galaxy->stars[i].num_planets = rand() % 10;
    galaxy->stars[i].planets = malloc(sizeof(struct planet) * galaxy->stars[i].num_planets);
    for (int j = 0; j < galaxy->stars[i].num_planets; j++) {
      galaxy->stars[i].planets[j].x = rand() % galaxy->stars[i].size;
      galaxy->stars[i].planets[j].y = rand() % galaxy->stars[i].size;
      galaxy->stars[i].planets[j].size = rand() % 5;
    }
  }
  return galaxy;
}

void print_galaxy(struct galaxy *galaxy) {
  for (int i = 0; i < galaxy->num_stars; i++) {
    printf("Star %d:\n", i + 1);
    printf("  Location: (%d, %d)\n", galaxy->stars[i].x, galaxy->stars[i].y);
    printf("  Size: %d\n", galaxy->stars[i].size);
    printf("  Planets:\n");
    for (int j = 0; j < galaxy->stars[i].num_planets; j++) {
      printf("    Planet %d:\n", j + 1);
      printf("      Location: (%d, %d)\n", galaxy->stars[i].planets[j].x, galaxy->stars[i].planets[j].y);
      printf("      Size: %d\n", galaxy->stars[i].planets[j].size);
    }
  }
}

int main() {
  srand(time(NULL));
  struct galaxy *galaxy = generate_galaxy(100);
  print_galaxy(galaxy);
  return 0;
}