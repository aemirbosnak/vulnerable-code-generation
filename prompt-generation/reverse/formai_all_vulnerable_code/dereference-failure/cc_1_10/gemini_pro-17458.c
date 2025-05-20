//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
// Romeo and Juliet: A Tale of Sorting

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our cast of characters
typedef struct {
  char *name;
  int age;
  int height;
  int weight;
} Character;

// The Montagues and Capulets
Character montagues[] = {
  {"Romeo", 16, 175, 65},
  {"Benvolio", 17, 180, 70},
  {"Mercutio", 18, 178, 72},
  {"Tybalt", 19, 185, 75},
  {"Lady Montague", 40, 165, 55},
  {"Lord Montague", 42, 170, 70},
};

Character capulets[] = {
  {"Juliet", 14, 160, 45},
  {"Paris", 17, 175, 68},
  {"Lord Capulet", 50, 180, 80},
  {"Lady Capulet", 48, 168, 60},
  {"Nurse", 55, 155, 75},
};

// The sorting pool
Character *pool[11];

// Comparison functions
int compare_age(const void *a, const void *b) {
  const Character *c1 = a;
  const Character *c2 = b;
  return c1->age - c2->age;
}

int compare_height(const void *a, const void *b) {
  const Character *c1 = a;
  const Character *c2 = b;
  return c1->height - c2->height;
}

int compare_weight(const void *a, const void *b) {
  const Character *c1 = a;
  const Character *c2 = b;
  return c1->weight - c2->weight;
}

// The grand ball
void sort_characters() {
  // Bring all the characters together
  memcpy(pool, montagues, sizeof(montagues));
  memcpy(pool + sizeof(montagues) / sizeof(Character), capulets, sizeof(capulets));

  // Sort by age
  qsort(pool, 11, sizeof(Character), compare_age);
  printf("Sorted by age:\n");
  for (int i = 0; i < 11; i++) {
    printf("%s, %d\n", pool[i]->name, pool[i]->age);
  }

  // Sort by height
  qsort(pool, 11, sizeof(Character), compare_height);
  printf("\nSorted by height:\n");
  for (int i = 0; i < 11; i++) {
    printf("%s, %d\n", pool[i]->name, pool[i]->height);
  }

  // Sort by weight
  qsort(pool, 11, sizeof(Character), compare_weight);
  printf("\nSorted by weight:\n");
  for (int i = 0; i < 11; i++) {
    printf("%s, %d\n", pool[i]->name, pool[i]->weight);
  }
}

int main() {
  // Romeo and Juliet meet
  sort_characters();

  return 0;
}