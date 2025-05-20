//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// The Montagues and Capulets
struct Montague {
  char *name;
  int age;
};

struct Capulet {
  char *name;
  int age;
};

// The play's data
struct Play {
  struct Montague Montagues[MAX_SIZE];
  struct Capulet Capulets[MAX_SIZE];
  int num_Montagues;
  int num_Capulets;
};

// Create a new play
struct Play *new_play() {
  struct Play *play = malloc(sizeof(struct Play));
  play->num_Montagues = 0;
  play->num_Capulets = 0;
  return play;
}

// Add a Montague to the play
void add_Montague(struct Play *play, char *name, int age) {
  play->Montagues[play->num_Montagues].name = strdup(name);
  play->Montagues[play->num_Montagues].age = age;
  play->num_Montagues++;
}

// Add a Capulet to the play
void add_Capulet(struct Play *play, char *name, int age) {
  play->Capulets[play->num_Capulets].name = strdup(name);
  play->Capulets[play->num_Capulets].age = age;
  play->num_Capulets++;
}

// Print the play's data
void print_play(struct Play *play) {
  printf("The Montagues:\n");
  for (int i = 0; i < play->num_Montagues; i++) {
    printf("  %s (%d)\n", play->Montagues[i].name, play->Montagues[i].age);
  }

  printf("The Capulets:\n");
  for (int i = 0; i < play->num_Capulets; i++) {
    printf("  %s (%d)\n", play->Capulets[i].name, play->Capulets[i].age);
  }
}

// Free the play's memory
void free_play(struct Play *play) {
  for (int i = 0; i < play->num_Montagues; i++) {
    free(play->Montagues[i].name);
  }

  for (int i = 0; i < play->num_Capulets; i++) {
    free(play->Capulets[i].name);
  }

  free(play);
}

int main() {
  // Create a new play
  struct Play *play = new_play();

  // Add the Montagues
  add_Montague(play, "Romeo", 16);
  add_Montague(play, "Benvolio", 17);
  add_Montague(play, "Tybalt", 18);

  // Add the Capulets
  add_Capulet(play, "Juliet", 14);
  add_Capulet(play, "Paris", 18);
  add_Capulet(play, "Mercutio", 19);

  // Print the play's data
  print_play(play);

  // Free the play's memory
  free_play(play);

  return 0;
}