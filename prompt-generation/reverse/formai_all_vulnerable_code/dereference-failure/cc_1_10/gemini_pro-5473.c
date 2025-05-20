//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// A humble serf, for managing memory tasks
typedef struct Serf {
    void *keep;           // A chest to store our treasures
    size_t weight;         // The weight of the treasures
    struct Serf *next;     // The next serf in our chain of command
} Serf;

// The Master, who oversees the serfs and their memory management
typedef struct Master {
    Serf *head;        // The first serf in our serfdom
} Master;

// A function to create a new serf, with a chest of a certain weight
Serf* serf_create(size_t weight) {
    Serf *serf = malloc(sizeof(Serf));
    serf->keep = malloc(weight);
    serf->weight = weight;
    serf->next = NULL;
    return serf;
}

// A function to free a serf and his chest of treasures
void serf_free(Serf *serf) {
    free(serf->keep);
    free(serf);
}

// A function to create a new Master, who oversees a serfdom
Master* master_create() {
    Master *master = malloc(sizeof(Master));
    master->head = NULL;
    return master;
}

// A function to free a Master and his serfdom
void master_free(Master *master) {
    Serf *serf = master->head;
    while (serf) {
        Serf *next = serf->next;
        serf_free(serf);
        serf = next;
    }
    free(master);
}

// A function to add a serf to the Master's serfdom
void master_add(Master *master, Serf *serf) {
    serf->next = master->head;
    master->head = serf;
}

// A function to remove a serf from the Master's serfdom
void master_remove(Master *master, Serf *serf) {
    if (serf == master->head) {
        master->head = serf->next;
    } else {
        Serf *prev = master->head;
        while (prev->next != serf) {
            prev = prev->next;
        }
        prev->next = serf->next;
    }
    serf_free(serf);
}

// A function to print the contents of a serf's chest
void serf_print(Serf *serf) {
    printf("Serf has ");
    for (size_t i = 0; i < serf->weight; i++) {
        printf("%c", ((char*)serf->keep)[i]);
    }
    printf(" in his chest.\n");
}

// A function to print the contents of a Master's serfdom
void master_print(Master *master) {
    Serf *serf = master->head;
    while (serf) {
        serf_print(serf);
        serf = serf->next;
    }
}

int main() {
    // A Master overseeing a serfdom of memory managers
    Master *master = master_create();

    // A serf with a chest of gold
    Serf *gold_serf = serf_create(10);
    char *gold = "Gold";
    for (int i = 0; i < 10; i++) {
        ((char*)gold_serf->keep)[i] = gold[i];
    }

    // A serf with a chest of silver
    Serf *silver_serf = serf_create(10);
    char *silver = "Silver";
    for (int i = 0; i < 10; i++) {
        ((char*)silver_serf->keep)[i] = silver[i];
    }

    // A serf with a chest of copper
    Serf *copper_serf = serf_create(10);
    char *copper = "Copper";
    for (int i = 0; i < 10; i++) {
        ((char*)copper_serf->keep)[i] = copper[i];
    }

    // The Master assigns the serfs to their duties
    master_add(master, gold_serf);
    master_add(master, silver_serf);
    master_add(master, copper_serf);

    // The Master inspects the contents of his serfdom
    master_print(master);

    // The Master frees the serfs and their chests of treasures
    master_free(master);

    return 0;
}