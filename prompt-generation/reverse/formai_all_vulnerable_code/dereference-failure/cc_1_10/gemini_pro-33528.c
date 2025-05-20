//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum { CAT_FOOD, CAT_NIP, CAT_TOY } cat_item_type;

struct cat_item {
  cat_item_type type;
  char *name;
  int quantity;
};

struct cat {
  char *name;
  int health;
  int hunger;
  int happiness;
  struct cat_item *inventory[3];
};

void create_cat(struct cat *cat, char *name) {
  cat->name = name;
  cat->health = 100;
  cat->hunger = 50;
  cat->happiness = 50;
  for (int i = 0; i < 3; i++) {
    cat->inventory[i] = NULL;
  }
}

void destroy_cat(struct cat *cat) {
  free(cat->name);
  for (int i = 0; i < 3; i++) {
    if (cat->inventory[i] != NULL) {
      free(cat->inventory[i]->name);
      free(cat->inventory[i]);
    }
  }
  free(cat);
}

void add_item_to_inventory(struct cat *cat, struct cat_item *item) {
  for (int i = 0; i < 3; i++) {
    if (cat->inventory[i] == NULL) {
      cat->inventory[i] = item;
      return;
    }
  }
  printf("Inventory is full!\n");
}

void remove_item_from_inventory(struct cat *cat, struct cat_item *item) {
  for (int i = 0; i < 3; i++) {
    if (cat->inventory[i] == item) {
      cat->inventory[i] = NULL;
      return;
    }
  }
  printf("Item not found in inventory!\n");
}

void feed_cat(struct cat *cat, struct cat_item *food) {
  if (food->type != CAT_FOOD) {
    printf("That's not food!\n");
    return;
  }
  cat->hunger -= 20;
  if (cat->hunger < 0) {
    cat->hunger = 0;
  }
}

void give_cat_nip(struct cat *cat, struct cat_item *nip) {
  if (nip->type != CAT_NIP) {
    printf("That's not catnip!\n");
    return;
  }
  cat->happiness += 20;
  if (cat->happiness > 100) {
    cat->happiness = 100;
  }
}

void play_with_cat(struct cat *cat, struct cat_item *toy) {
  if (toy->type != CAT_TOY) {
    printf("That's not a toy!\n");
    return;
  }
  cat->happiness += 20;
  if (cat->happiness > 100) {
    cat->happiness = 100;
  }
}

void update_cat(struct cat *cat) {
  cat->hunger += 10;
  if (cat->hunger > 100) {
    cat->hunger = 100;
  }
  cat->happiness -= 10;
  if (cat->happiness < 0) {
    cat->happiness = 0;
  }
  if (cat->hunger == 100 || cat->happiness == 0) {
    cat->health -= 10;
    if (cat->health <= 0) {
      printf("%s has died!\n", cat->name);
      destroy_cat(cat);
    }
  }
}

void print_cat(struct cat *cat) {
  printf("Name: %s\n", cat->name);
  printf("Health: %d\n", cat->health);
  printf("Hunger: %d\n", cat->hunger);
  printf("Happiness: %d\n", cat->happiness);
  printf("Inventory:\n");
  for (int i = 0; i < 3; i++) {
    if (cat->inventory[i] != NULL) {
      printf("  %s\n", cat->inventory[i]->name);
    }
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  struct cat *cat = malloc(sizeof(struct cat));
  create_cat(cat, "Patches");

  struct cat_item *food = malloc(sizeof(struct cat_item));
  food->type = CAT_FOOD;
  food->name = "Cat food";
  food->quantity = 10;

  struct cat_item *nip = malloc(sizeof(struct cat_item));
  nip->type = CAT_NIP;
  nip->name = "Catnip";
  nip->quantity = 10;

  struct cat_item *toy = malloc(sizeof(struct cat_item));
  toy->type = CAT_TOY;
  toy->name = "Mouse toy";
  toy->quantity = 10;

  add_item_to_inventory(cat, food);
  add_item_to_inventory(cat, nip);
  add_item_to_inventory(cat, toy);

  for (int i = 0; i < 100; i++) {
    update_cat(cat);
    if (rand() % 10 == 0) {
      feed_cat(cat, food);
    }
    if (rand() % 10 == 0) {
      give_cat_nip(cat, nip);
    }
    if (rand() % 10 == 0) {
      play_with_cat(cat, toy);
    }
    print_cat(cat);
  }

  destroy_cat(cat);
  free(food);
  free(nip);
  free(toy);
  return 0;
}