//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of guards
#define MAX_GUARDS 10

// Define the maximum number of attacks
#define MAX_ATTACKS 10

// Define the maximum length of a guard's name
#define MAX_GUARD_NAME_LENGTH 20

// Define the maximum length of an attack's name
#define MAX_ATTACK_NAME_LENGTH 20

// Define the types of attacks
typedef enum {
  ATTACK_TYPE_NONE,
  ATTACK_TYPE_PHYSICAL,
  ATTACK_TYPE_MAGICAL,
  ATTACK_TYPE_SIEGE
} attack_type_t;

// Define the structure of a guard
typedef struct {
  char name[MAX_GUARD_NAME_LENGTH];
  int strength;
  int agility;
  int intelligence;
  int endurance;
  attack_type_t attack_type;
} guard_t;

// Define the structure of an attack
typedef struct {
  char name[MAX_ATTACK_NAME_LENGTH];
  int damage;
  attack_type_t attack_type;
} attack_t;

// Define the structure of the intrusion detection system
typedef struct {
  guard_t guards[MAX_GUARDS];
  attack_t attacks[MAX_ATTACKS];
  int num_guards;
  int num_attacks;
} intrusion_detection_system_t;

// Create a new intrusion detection system
intrusion_detection_system_t *new_intrusion_detection_system() {
  intrusion_detection_system_t *ids = malloc(sizeof(intrusion_detection_system_t));
  if (ids == NULL) {
    return NULL;
  }
  ids->num_guards = 0;
  ids->num_attacks = 0;
  return ids;
}

// Destroy an intrusion detection system
void destroy_intrusion_detection_system(intrusion_detection_system_t *ids) {
  free(ids);
}

// Add a guard to the intrusion detection system
int add_guard(intrusion_detection_system_t *ids, guard_t *guard) {
  if (ids->num_guards >= MAX_GUARDS) {
    return -1;
  }
  ids->guards[ids->num_guards++] = *guard;
  return 0;
}

// Add an attack to the intrusion detection system
int add_attack(intrusion_detection_system_t *ids, attack_t *attack) {
  if (ids->num_attacks >= MAX_ATTACKS) {
    return -1;
  }
  ids->attacks[ids->num_attacks++] = *attack;
  return 0;
}

// Detect an intrusion
int detect_intrusion(intrusion_detection_system_t *ids, attack_t *attack) {
  for (int i = 0; i < ids->num_guards; i++) {
    guard_t *guard = &ids->guards[i];
    if (guard->attack_type == attack->attack_type &&
        guard->strength >= attack->damage) {
      return 0;
    }
  }
  return -1;
}

// Print the intrusion detection system
void print_intrusion_detection_system(intrusion_detection_system_t *ids) {
  printf("Guards:\n");
  for (int i = 0; i < ids->num_guards; i++) {
    guard_t *guard = &ids->guards[i];
    printf("  %s (%d, %d, %d, %d)\n",
           guard->name,
           guard->strength,
           guard->agility,
           guard->intelligence,
           guard->endurance);
  }
  printf("Attacks:\n");
  for (int i = 0; i < ids->num_attacks; i++) {
    attack_t *attack = &ids->attacks[i];
    printf("  %s (%d)\n",
           attack->name,
           attack->damage);
  }
}

// Main function
int main() {
  // Create a new intrusion detection system
  intrusion_detection_system_t *ids = new_intrusion_detection_system();

  // Add some guards to the intrusion detection system
  guard_t guard1 = {"Sir Reginald", 10, 8, 6, 8, ATTACK_TYPE_PHYSICAL};
  add_guard(ids, &guard1);
  guard_t guard2 = {"Lady Marian", 8, 10, 8, 6, ATTACK_TYPE_MAGICAL};
  add_guard(ids, &guard2);
  guard_t guard3 = {"Sir Tristan", 9, 9, 7, 7, ATTACK_TYPE_SIEGE};
  add_guard(ids, &guard3);

  // Add some attacks to the intrusion detection system
  attack_t attack1 = {"Orcish Horde", 10, ATTACK_TYPE_PHYSICAL};
  add_attack(ids, &attack1);
  attack_t attack2 = {"Goblin Raid", 8, ATTACK_TYPE_MAGICAL};
  add_attack(ids, &attack2);
  attack_t attack3 = {"Dragon Attack", 12, ATTACK_TYPE_SIEGE};
  add_attack(ids, &attack3);

  // Print the intrusion detection system
  print_intrusion_detection_system(ids);

  // Detect an intrusion
  int result = detect_intrusion(ids, &attack3);
  if (result == 0) {
    printf("Intrusion detected and repelled!\n");
  } else {
    printf("Intrusion detected but not repelled!\n");
  }

  // Destroy the intrusion detection system
  destroy_intrusion_detection_system(ids);

  return 0;
}