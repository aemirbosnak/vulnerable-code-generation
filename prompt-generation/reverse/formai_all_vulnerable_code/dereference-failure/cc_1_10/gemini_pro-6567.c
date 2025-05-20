//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the guards of the castle
char *guards[] = {"Sir Reginald", "Lady Beatrice", "Master Bowman"};

// Declare the intruders
char *intruders[] = {"Orc", "Goblin", "Troll"};

// Declare the weapons
char *weapons[] = {"Sword", "Bow and Arrow", "Axe"};

// Declare the spells
char *spells[] = {"Fireball", "Lightning Bolt", "Ice Storm"};

// Function to detect intruders
int detect_intruders(char *name) {
  for (int i = 0; i < sizeof(intruders) / sizeof(char *); i++) {
    if (strcmp(name, intruders[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

// Function to equip guards with weapons
void equip_guards() {
  for (int i = 0; i < sizeof(guards) / sizeof(char *); i++) {
    guards[i] = strcat(guards[i], " armed with ");
    guards[i] = strcat(guards[i], weapons[i]);
  }
}

// Function to cast spells on intruders
void cast_spells(char *name) {
  for (int i = 0; i < sizeof(spells) / sizeof(char *); i++) {
    printf("The guards cast %s on %s!\n", spells[i], name);
  }
}

// Main function
int main() {
  // Detect intruders
  char *name = "Orc";
  int is_intruder = detect_intruders(name);

  // Equip guards with weapons
  equip_guards();

  // Cast spells on intruders
  if (is_intruder) {
    cast_spells(name);
  } else {
    printf("No intruders detected.\n");
  }

  return 0;
}