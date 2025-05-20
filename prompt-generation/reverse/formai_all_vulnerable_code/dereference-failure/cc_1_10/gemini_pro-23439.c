//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// The RAM Goblin, a mythical creature that haunts your computer's memory
struct RAMGoblin {
  size_t gobbledRAM; // The amount of RAM the goblin has consumed
  char *name;       // The goblin's mischievous name
};

// Create a new RAM Goblin
struct RAMGoblin *createRAMGoblin(char *name) {
  struct RAMGoblin *goblin = malloc(sizeof(struct RAMGoblin));
  goblin->gobbledRAM = 0;
  goblin->name = name;
  return goblin;
}

// Feed the RAM Goblin more RAM
void feedRAMGoblin(struct RAMGoblin *goblin, size_t amount) {
  goblin->gobbledRAM += amount;
}

// Get the total amount of RAM consumed by all RAM Goblins
size_t getTotalRAMConsumed() {
  struct sysinfo info;
  sysinfo(&info);
  return info.totalram - info.freeram;
}

// Print a report on the RAM Goblins and their consumption habits
void printRAMGoblinReport() {
  struct RAMGoblin *goblins[] = {
      createRAMGoblin("Greedius Maximus"), createRAMGoblin("Slackius Maximus"),
      createRAMGoblin("Leakius Maximus"), createRAMGoblin("Balloonius Maximus"),
      createRAMGoblin("Hoggius Maximus"),
  };

  // Feed the goblins some RAM
  for (int i = 0; i < 5; i++) {
    feedRAMGoblin(goblins[i], rand() % 1000000000);
  }

  // Print the report
  printf("**RAM Goblin Report**\n");
  printf("Total RAM consumed: %ld bytes\n", getTotalRAMConsumed());
  for (int i = 0; i < 5; i++) {
    printf("Goblin %s: %ld bytes\n", goblins[i]->name, goblins[i]->gobbledRAM);
  }
}

int main() {
  printRAMGoblinReport();
  return 0;
}