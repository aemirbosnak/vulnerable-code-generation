//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

struct Ghost {
  char name[20];
  int room_num;
  int spirit_level;
  int actions_taken;
  int is_active;
};

void initialize_ghost(struct Ghost *ghost) {
  ghost->name[0] = '\0';
  ghost->room_num = 0;
  ghost->spirit_level = 0;
  ghost->actions_taken = 0;
  ghost->is_active = 0;
}

void spawn_ghosts(struct Ghost **ghosts, int num_ghosts) {
  for (int i = 0; i < num_ghosts; i++) {
    ghosts[i] = malloc(sizeof(struct Ghost));
    initialize_ghost(ghosts[i]);
  }
}

void simulate_haunted_house(struct Ghost **ghosts, int num_ghosts) {
  time_t t = time(NULL);
  for (int i = 0; i < num_ghosts; i++) {
    ghosts[i]->is_active = 1;
    switch (ghosts[i]->spirit_level) {
      case 0:
        ghosts[i]->actions_taken++;
        printf("Ghost %s is wandering the halls...\n", ghosts[i]->name);
        break;
      case 1:
        ghosts[i]->actions_taken++;
        printf("Ghost %s is whispering secrets...\n", ghosts[i]->name);
        break;
      case 2:
        ghosts[i]->actions_taken++;
        printf("Ghost %s is attacking...\n", ghosts[i]->name);
        break;
    }
  }

  t = time(NULL) - t;
  printf("Total time spent in the haunted house: %d seconds\n", t);
}

int main() {
  struct Ghost **ghosts = NULL;
  int num_ghosts = 3;

  spawn_ghosts(ghosts, num_ghosts);
  simulate_haunted_house(ghosts, num_ghosts);

  for (int i = 0; i < num_ghosts; i++) {
    free(ghosts[i]);
  }

  return 0;
}