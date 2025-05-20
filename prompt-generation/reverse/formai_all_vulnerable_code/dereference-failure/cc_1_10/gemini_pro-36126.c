//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: immersive
// Immerse yourself in the world of database indexing!

#include <stdio.h>
#include <stdlib.h>

// Our adventurous database explorer
struct Explorer {
    int id;
    char *name;
    int *adventure_ids;
    int num_adventures;
};

// The mystical land of adventures
struct Adventure {
    int id;
    char *name;
    char *location;
};

// Our trusty index, a guide to the unexplored lands
struct Index {
    int *explorer_ids;
    int num_explorers;
};

// The gateway to our database, a portal to knowledge
struct Database {
    struct Explorer **explorers;
    int num_explorers;
    struct Adventure **adventures;
    int num_adventures;
    struct Index *explorer_index;
    struct Index *adventure_index;
};

// Begin our journey by creating the database
struct Database *create_database() {
    struct Database *database = malloc(sizeof(struct Database));
    database->explorers = malloc(sizeof(struct Explorer *) * 10);
    database->num_explorers = 0;
    database->adventures = malloc(sizeof(struct Adventure *) * 10);
    database->num_adventures = 0;
    database->explorer_index = malloc(sizeof(struct Index));
    database->explorer_index->explorer_ids = malloc(sizeof(int) * 10);
    database->explorer_index->num_explorers = 0;
    database->adventure_index = malloc(sizeof(struct Index));
    database->adventure_index->explorer_ids = malloc(sizeof(int) * 10);
    database->adventure_index->num_explorers = 0;
    return database;
}

// Forge an explorer, ready to embark on adventures
struct Explorer *create_explorer(int id, char *name, int num_adventures) {
    struct Explorer *explorer = malloc(sizeof(struct Explorer));
    explorer->id = id;
    explorer->name = strdup(name);
    explorer->adventure_ids = malloc(sizeof(int) * num_adventures);
    explorer->num_adventures = num_adventures;
    return explorer;
}

// Conjure an adventure, a thrilling experience for our explorers
struct Adventure *create_adventure(int id, char *name, char *location) {
    struct Adventure *adventure = malloc(sizeof(struct Adventure));
    adventure->id = id;
    adventure->name = strdup(name);
    adventure->location = strdup(location);
    return adventure;
}

// Embark on an adventure, adding it to our explorer's logbook
void add_adventure_to_explorer(struct Database *database, struct Explorer *explorer, struct Adventure *adventure) {
    explorer->adventure_ids[explorer->num_adventures++] = adventure->id;
    database->explorer_index->explorer_ids[database->explorer_index->num_explorers++] = explorer->id;
    database->adventure_index->explorer_ids[database->adventure_index->num_explorers++] = explorer->id;
}

// Unlock the secrets of an adventure by exploring it
void explore_adventure(struct Database *database, struct Explorer *explorer, struct Adventure *adventure) {
    printf("Explorer %s embarked on adventure %s in %s\n", explorer->name, adventure->name, adventure->location);
}

// Delve into the database, discovering hidden connections
void explore_database(struct Database *database) {
    for (int i = 0; i < database->num_explorers; i++) {
        struct Explorer *explorer = database->explorers[i];
        printf("Explorer %s has %d adventures:\n", explorer->name, explorer->num_adventures);
        for (int j = 0; j < explorer->num_adventures; j++) {
            int adventure_id = explorer->adventure_ids[j];
            struct Adventure *adventure = database->adventures[adventure_id];
            explore_adventure(database, explorer, adventure);
        }
    }
}

// Farewell, brave explorers!
void free_database(struct Database *database) {
    for (int i = 0; i < database->num_explorers; i++) {
        free(database->explorers[i]->name);
        free(database->explorers[i]->adventure_ids);
        free(database->explorers[i]);
    }
    free(database->explorers);
    for (int i = 0; i < database->num_adventures; i++) {
        free(database->adventures[i]->name);
        free(database->adventures[i]->location);
        free(database->adventures[i]);
    }
    free(database->adventures);
    free(database->explorer_index->explorer_ids);
    free(database->explorer_index);
    free(database->adventure_index->explorer_ids);
    free(database->adventure_index);
    free(database);
}

// Let our journey begin!
int main() {
    struct Database *database = create_database();

    struct Explorer *explorer1 = create_explorer(1, "Indiana Jones", 3);
    struct Explorer *explorer2 = create_explorer(2, "Lara Croft", 5);
    struct Explorer *explorer3 = create_explorer(3, "Nathan Drake", 4);

    struct Adventure *adventure1 = create_adventure(1, "Raiders of the Lost Ark", "Egypt");
    struct Adventure *adventure2 = create_adventure(2, "Tomb Raider", "Peru");
    struct Adventure *adventure3 = create_adventure(3, "Uncharted Waters", "Madagascar");
    struct Adventure *adventure4 = create_adventure(4, "The Last Crusade", "Austria");
    struct Adventure *adventure5 = create_adventure(5, "The Cradle of Life", "China");

    add_adventure_to_explorer(database, explorer1, adventure1);
    add_adventure_to_explorer(database, explorer1, adventure4);
    add_adventure_to_explorer(database, explorer1, adventure5);
    add_adventure_to_explorer(database, explorer2, adventure2);
    add_adventure_to_explorer(database, explorer2, adventure3);
    add_adventure_to_explorer(database, explorer3, adventure1);
    add_adventure_to_explorer(database, explorer3, adventure2);
    add_adventure_to_explorer(database, explorer3, adventure3);
    add_adventure_to_explorer(database, explorer3, adventure5);

    explore_database(database);

    free_database(database);

    return 0;
}