//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_CONSPIRACIES 1000
#define MAX_WORDS 20
#define MAX_SENTENCE_LENGTH 50

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
char words[MAX_WORDS][MAX_SENTENCE_LENGTH];

void generate_conspiracy(int index) {
    char sentence[MAX_SENTENCE_LENGTH];
    int length = rand() % MAX_SENTENCE_LENGTH + 1;
    sprintf(sentence, "The %s is actually %s.", conspiracies[index].name, conspiracies[index].description);
    printf("%s\n", sentence);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        char input[MAX_SENTENCE_LENGTH];
        printf("Enter a new conspiracy theory: ");
        scanf("%s", input);

        strcpy(conspiracies[i].name, input);
        strcpy(conspiracies[i].description, "unknown");
    }

    int choice;
    while (1) {
        printf("Enter 1 to generate a random conspiracy theory\n");
        printf("Enter 2 to exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int index = rand() % MAX_CONSPIRACIES;
            generate_conspiracy(index);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}