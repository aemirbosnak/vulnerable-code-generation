//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100
#define MAX_LENGTH 20
#define SEED (unsigned int) time(NULL)

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

void init() {
    FILE *file;
    char line[MAX_LENGTH];
    int count = 0;

    file = fopen("conspiracies.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open conspiracies.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, file)!= NULL) {
        if (count >= MAX_CONSPIRACIES) {
            printf("Warning: Maximum number of conspiracies reached\n");
            break;
        }

        char *name = strtok(line, ",");
        char *description = strtok(NULL, ",");

        conspiracies[count].name = strdup(name);
        conspiracies[count].description = strdup(description);

        count++;
    }

    fclose(file);
}

void generate() {
    srand(SEED);

    int length = rand() % MAX_LENGTH + 1;
    char *words[MAX_WORDS];
    int num_words = 0;

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        if (conspiracies[i].name!= NULL) {
            words[num_words++] = conspiracies[i].name;
        }
    }

    while (num_words < length) {
        int index = rand() % MAX_CONSPIRACIES;
        if (conspiracies[index].name!= NULL) {
            words[num_words++] = conspiracies[index].name;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%s ", words[i]);
    }

    printf("\n");
}

int main() {
    init();
    generate();

    return 0;
}