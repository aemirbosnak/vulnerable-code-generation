//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ELEMENTS 103
#define NUM_OF_QUESTIONS 7

typedef struct element_info {
    char name[20];
    char symbol[3];
    char group[5];
    char period[5];
    char atomic_mass[8];
    char electron_configuration[20];
} ElementInfo;

ElementInfo elements[] = {
    {"Hydrogen", "H", "1", "1", "1.008", "1s1"},
    {"Helium", "He", "2", "2", "4.0026", "1s2"},
    {"Lithium", "Li", "3", "3", "6.94", "1s22s1"},
    // Add the rest of the elements here...
};

ElementInfo* get_element_info(char* name) {
    int i;
    for (i = 0; i < NUM_OF_ELEMENTS; i++) {
        if (strcmp(elements[i].name, name) == 0) {
            return &elements[i];
        }
    }
    return NULL;
}

int main() {
    int num_of_questions_answered = 0;
    int i;
    int j;
    char* element_name;

    srand(time(NULL));

    printf("Welcome to the Medieval Periodic Table Quiz!\n");

    for (i = 0; i < NUM_OF_QUESTIONS; i++) {
        num_of_questions_answered++;

        printf("\nQuestion %d: What is the name of the element with the symbol '%s'?\n", i+1, elements[i].symbol);
        scanf("%s", &element_name);
        if (strcmp(element_name, elements[i].name) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is '%s'.\n", elements[i].name);
        }
    }

    printf("\nYou answered %d out of %d questions correctly.\n", num_of_questions_answered, NUM_OF_QUESTIONS);

    return 0;
}