//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 200
#define MAX_WORDS 1000
#define MAX_CONSPIRACIES 100

typedef struct {
    char* name;
    char* description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
int num_conspiracies;

void generate_conspiracy(char* name, char* description) {
    if (num_conspiracies >= MAX_CONSPIRACIES) {
        return;
    }

    conspiracies[num_conspiracies].name = malloc(strlen(name) + 1);
    strcpy(conspiracies[num_conspiracies].name, name);

    conspiracies[num_conspiracies].description = malloc(strlen(description) + 1);
    strcpy(conspiracies[num_conspiracies].description, description);

    num_conspiracies++;
}

void print_conspiracy(int index) {
    printf("Name: %s\n", conspiracies[index].name);
    printf("Description: %s\n", conspiracies[index].description);
}

int main() {
    srand(time(NULL));

    generate_conspiracy("Flat Earth", "The theory that the Earth is flat instead of a sphere.");
    generate_conspiracy("Moon Landing Hoax", "The belief that the Apollo moon landings were faked.");
    generate_conspiracy("9/11 Inside Job", "The conspiracy theory that the September 11 attacks were orchestrated by the US government.");
    generate_conspiracy("Lizard People", "The belief that shape-shifting reptilian aliens control world politics.");
    generate_conspiracy("Chemtrails", "The theory that the trails left by aircraft are chemical or biological agents deliberately sprayed for sinister purposes.");

    num_conspiracies = 5;

    char input[MAX_LENGTH];
    while (1) {
        printf("Enter a keyword or phrase related to a conspiracy theory: ");
        scanf("%s", input);

        int match = 0;
        for (int i = 0; i < num_conspiracies; i++) {
            if (strstr(conspiracies[i].name, input) || strstr(conspiracies[i].description, input)) {
                print_conspiracy(i);
                match = 1;
            }
        }

        if (!match) {
            printf("No conspiracy theories found.\n");
        }
    }

    return 0;
}