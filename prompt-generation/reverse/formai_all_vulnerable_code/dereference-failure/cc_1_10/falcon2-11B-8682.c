//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/wait.h>

typedef struct joke {
    int id;
    char *joke;
} joke_t;

typedef struct database {
    int count;
    joke_t *jokes;
} database_t;

int main() {
    // Create an empty database
    database_t db = {0, NULL};

    // Open the database file
    FILE *fp = fopen("jokes.db", "w");
    if (fp == NULL) {
        printf("Error opening database file\n");
        return 1;
    }

    // Add jokes to the database
    for (int i = 0; i < 10; i++) {
        // Generate a random joke
        char *joke = malloc(sizeof(char) * 100);
        sprintf(joke, "Why don't scientists trust atoms?\nBecause they make up everything!\n");
        joke_t *j = &(db.jokes[i]);
        j->id = i + 1;
        strcpy(j->joke, joke);

        // Write the joke to the database file
        fprintf(fp, "%d\t%s\n", j->id, joke);
    }

    // Close the database file
    fclose(fp);

    // Display the jokes in the database
    printf("Joke 1: %s\n", db.jokes[1].joke);
    printf("Joke 2: %s\n", db.jokes[2].joke);
    printf("Joke 3: %s\n", db.jokes[3].joke);

    // Search for a joke in the database
    char *query = "Why don't scientists trust atoms?";
    int result = 0;
    for (int i = 0; i < db.count; i++) {
        if (strcmp(db.jokes[i].joke, query) == 0) {
            result = 1;
            printf("Joke %d: %s\n", i + 1, db.jokes[i].joke);
        }
    }

    // Delete a joke from the database
    int joke_to_delete = 4;
    printf("Deleting joke %d...\n", joke_to_delete);
    for (int i = 0; i < db.count; i++) {
        if (db.jokes[i].id == joke_to_delete) {
            printf("Joke %d: %s\n", i + 1, db.jokes[i].joke);
            db.count--;
            break;
        }
    }

    // Close the database file
    fclose(fp);

    return 0;
}