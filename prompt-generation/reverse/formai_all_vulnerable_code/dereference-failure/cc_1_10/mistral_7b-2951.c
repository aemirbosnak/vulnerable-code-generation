//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000
#define NUM_ANIMALS 5

typedef struct {
    char name[20];
    int id;
} Animal;

Animal animals[NUM_ANIMALS] = {
    {"Monkey", 1},
    {"Elephant", 2},
    {"Rhinoceros", 3},
    {"Hippopotamus", 4},
    {"Giraffe", 5}
};

void search(char *haystack, char needle, Animal *team) {
    int index = -1;
    int i, j;

    for (i = 0; i < NUM_ANIMALS; i++) {
        printf("\n%s says: I'll search for the needle in the haystack now!", animals[i].name);
        for (j = 0; j < strlen(haystack) - (int)strlen(&needle) + 1 && index == -1; j++) {
            if (memcmp(&haystack[j], &needle, strlen(&needle)) == 0) {
                index = j;
                printf("\n%s found the needle at position %d!", animals[i].name, index);
                break;
            }
            if (j % 100 == 0) {
                printf("\n%s is getting tired, let's give another animal a turn.", animals[i].name);
                break;
            }
        }
        if (index != -1) break;
    }

    if (index == -1) {
        printf("\nThe needle was not found in the haystack.");
    }
}

int main() {
    char haystack[SIZE] = "This is a haystack with a needle hidden somewhere.";
    char needle = 'e';

    srand(time(NULL));
    Animal *animal = animals + rand() % NUM_ANIMALS;

    printf("\n%s starts the search.\n", animal->name);
    search(haystack, needle, animals);

    return 0;
}