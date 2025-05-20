//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_LENGTH 256

typedef struct {
    char *name;
    char *theory;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];
int conspiracy_count = 0;

void initialize_conspiracies() {
    conspiracies[0].name = "Moon Landing";
    conspiracies[0].theory = "The moon landing was staged by NASA to win the space race.";
    
    conspiracies[1].name = "Flat Earth";
    conspiracies[1].theory = "Scientists and governments are hiding the true flat shape of the Earth.";
    
    conspiracies[2].name = "Lizard People";
    conspiracies[2].theory = "Reptilian aliens have disguised themselves as world leaders.";
    
    conspiracies[3].name = "Chemtrails";
    conspiracies[3].theory = "Airplanes are spraying chemicals to control the population.";
    
    conspiracies[4].name = "Time Travel";
    conspiracies[4].theory = "Time travel is real, but kept secret by a shadow government.";

    conspiracy_count = 5;
}

void generate_random_conspiracy() {
    srand(time(NULL));
    int index = rand() % conspiracy_count;
    printf("Conspiracy: %s\nTheory: %s\n", conspiracies[index].name, conspiracies[index].theory);
}

void add_conspiracy() {
    if (conspiracy_count >= MAX_CONSPIRACIES) {
        printf("Maximum number of conspiracies reached!\n");
        return;
    }

    char name[MAX_LENGTH];
    char theory[MAX_LENGTH];

    printf("Enter the name of the conspiracy: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    printf("Enter the conspiracy theory: ");
    fgets(theory, MAX_LENGTH, stdin);
    theory[strcspn(theory, "\n")] = 0; // remove newline

    conspiracies[conspiracy_count].name = (char *)malloc(strlen(name) + 1);
    conspiracies[conspiracy_count].theory = (char *)malloc(strlen(theory) + 1);
    
    strcpy(conspiracies[conspiracy_count].name, name);
    strcpy(conspiracies[conspiracy_count].theory, theory);
    
    conspiracy_count++;
    printf("Conspiracy added successfully!\n");
}

void list_conspiracies() {
    printf("List of known conspiracies:\n");
    for (int i = 0; i < conspiracy_count; i++) {
        printf("%d: %s\n", i + 1, conspiracies[i].name);
    }
}

void free_memory() {
    for (int i = 0; i < conspiracy_count; i++) {
        free(conspiracies[i].name);
        free(conspiracies[i].theory);
    }
}

int main() {
    int choice;

    initialize_conspiracies();

    do {
        printf("\nConspiracy Theory Generator\n");
        printf("1. Generate random conspiracy theory\n");
        printf("2. Add a new conspiracy theory\n");
        printf("3. List existing conspiracy theories\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                generate_random_conspiracy();
                break;
            case 2:
                add_conspiracy();
                break;
            case 3:
                list_conspiracies();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free_memory();
    return 0;
}