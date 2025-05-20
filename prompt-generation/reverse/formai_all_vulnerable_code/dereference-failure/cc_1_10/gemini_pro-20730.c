//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ALIENS 100
#define MAX_PROBABILITY 100

typedef struct {
  char *name;
  double probability;
} Alien;

Alien aliens[MAX_ALIENS];
int num_aliens = 0;

void add_alien(char *name, double probability) {
  if (num_aliens >= MAX_ALIENS) {
    fprintf(stderr, "Error: too many aliens\n");
    exit(1);
  }
  aliens[num_aliens].name = strdup(name);
  aliens[num_aliens].probability = probability;
  num_aliens++;
}

double calculate_invasion_probability() {
  double probability = 0.0;
  for (int i = 0; i < num_aliens; i++) {
    probability += aliens[i].probability;
  }
  return probability;
}

void print_invasion_probability() {
  double probability = calculate_invasion_probability();
  printf("Invasion probability: %.2f%%\n", probability * 100);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Error: no aliens specified\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    char *alien_name = argv[i];
    double alien_probability = atof(strtok(alien_name, ":"));
    if (alien_probability < 0.0 || alien_probability > 1.0) {
      fprintf(stderr, "Error: invalid alien probability: %s\n", alien_name);
      exit(1);
    }
    add_alien(alien_name, alien_probability);
  }

  print_invasion_probability();

  return 0;
}