//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_NAME_LENGTH 100
#define MAX_SURVIVORS 50

struct survivor {
    char name[MAX_NAME_LENGTH];
    int health;
};

void readSurvivorsFromFile(char *filename, struct survivor survivors[], int *numSurvivors) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening survivors file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_NAME_LENGTH + 10];
    int i = 0;

    while (fgets(line, sizeof(line), fd) != NULL) {
        if (sscanf(line, "%s%d", survivors[i].name, &survivors[i].health) != 2) {
            perror("Error parsing survivor line");
            exit(EXIT_FAILURE);
        }
        i++;
        if (i == MAX_SURVIVORS) {
            fprintf(stderr, "Too many survivors in file\n");
            exit(EXIT_FAILURE);
        }
    }

    close(fd);
    *numSurvivors = i;
}

void printSurvivors(struct survivor survivors[], int numSurvivors) {
    for (int i = 0; i < numSurvivors; i++) {
        printf("%s: %d\n", survivors[i].name, survivors[i].health);
    }
}

int main() {
    char filename[] = "survivors.txt";
    struct survivor survivors[MAX_SURVIVORS];
    int numSurvivors;

    readSurvivorsFromFile(filename, survivors, &numSurvivors);

    printf("Post-Apocalyptic Survivors:\n");
    printSurvivors(survivors, numSurvivors);

    // Now let's sort the survivors based on their health
    for (int i = 0; i < numSurvivors - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numSurvivors; j++) {
            if (survivors[j].health < survivors[minIndex].health) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct survivor temp = survivors[i];
            survivors[i] = survivors[minIndex];
            survivors[minIndex] = temp;
        }
    }

    printf("\nSurvivors sorted by health:\n");
    printSurvivors(survivors, numSurvivors);

    return EXIT_SUCCESS;
}