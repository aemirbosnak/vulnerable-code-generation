//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct dream {
    char* id;
    char* name;
    char* location;
    int happiness_level;
    int nightmare_level;
} Dream;

Dream* createDream(char* id, char* name, char* location, int happiness_level, int nightmare_level) {
    Dream* dream = malloc(sizeof(Dream));
    dream->id = id;
    dream->name = name;
    dream->location = location;
    dream->happiness_level = happiness_level;
    dream->nightmare_level = nightmare_level;
    printf("Your dream has been created. Sweet dreams!\n");
    return dream;
}

void printDream(Dream* dream) {
    printf("\nID: %s\n", dream->id);
    printf("Name: %s\n", dream->name);
    printf("Location: %s\n", dream->location);
    printf("Happiness Level: %d\n", dream->happiness_level);
    printf("Nightmare Level: %d\n\n", dream->nightmare_level);
}

int main() {
    Dream* dream1 = createDream("001", "Flying in the clouds", "Skyland", 10, 0);
    Dream* dream2 = createDream("002", "Fighting zombies", "Apocalypse City", 0, 10);
    Dream* dream3 = createDream("003", "Eating pizza on a pirate ship", "Seaside", 8, 1);
    Dream* dream4 = createDream("004", "Solving a mystery in a haunted mansion", "Mysteryland", 9, 2);
    Dream* dream5 = createDream("005", "Dancing with unicorns", "Magic Forest", 10, 0);

    printf("Welcome to Dream Query!\n\n");
    printf("Enter a dream ID to see dream details: ");
    char* input = malloc(sizeof(char) * 10);
    scanf("%s", input);

    if(strcmp(input, dream1->id) == 0) {
        printDream(dream1);
    } else if(strcmp(input, dream2->id) == 0) {
        printDream(dream2);
    } else if(strcmp(input, dream3->id) == 0) {
        printDream(dream3);
    } else if(strcmp(input, dream4->id) == 0) {
        printDream(dream4);
    } else if(strcmp(input, dream5->id) == 0) {
        printDream(dream5);
    } else {
        printf("\nSorry, we could not find a dream with that ID. Please try again.\n");
    }

    free(input);
    free(dream1);
    free(dream2);
    free(dream3);
    free(dream4);
    free(dream5);
    return 0;
}