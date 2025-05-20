//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_NAME_LEN 20  // maximum length of an element's name
#define MAX_SYM_LEN  3   // maximum length of an element's symbol

// define the element struct
typedef struct Element {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYM_LEN];
    int atomic_number;
    double atomic_mass;
} Element;

// define a global array to hold the elements
Element elements[MAX_ELEMENTS];

// function prototypes
void load_elements();
void display_element_info(int atomic_number);
void take_quiz();

int main() {
    load_elements();

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be shown the name or symbol of an element and asked for its atomic number and atomic mass.\n");
    printf("Enter -1 for the atomic number or atomic mass if you do not know the answer.\n\n");

    take_quiz();

    return 0;
}

// load the elements from a file into the global elements array
void load_elements() {
    FILE *f = fopen("elements.txt", "r");
    if (f == NULL) {
        perror("Error reading elements.txt");
        exit(1);
    }

    int i = 0;
    char line[50];
    while (fgets(line, sizeof(line), f)) {
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        double atomic_mass = atof(strtok(NULL, ","));

        strcpy(elements[i].name, name);
        strcpy(elements[i].symbol, symbol);
        elements[i].atomic_number = atomic_number;
        elements[i].atomic_mass = atomic_mass;

        i++;
    }

    fclose(f);
}

// display information about the element with the given atomic number
void display_element_info(int atomic_number) {
    Element *element = NULL;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].atomic_number == atomic_number) {
            element = &elements[i];
            break;
        }
    }

    if (element == NULL) {
        printf("Sorry, element with atomic number %d not found.\n", atomic_number);
    } else {
        printf("Name: %s\n", element->name);
        printf("Symbol: %s\n", element->symbol);
        printf("Atomic number: %d\n", element->atomic_number);
        printf("Atomic mass: %f\n", element->atomic_mass);
    }
}

// take the quiz
void take_quiz() {
    int num_correct = 0;
    int num_total = 0;

    // ask for atomic number
    printf("What is the atomic number of Oxygen? ");
    int user_atomic_number;
    scanf("%d", &user_atomic_number);
    if (user_atomic_number == 8) {
        printf("Correct! Oxygen's atomic number is 8.\n");
        num_correct++;
    } else if (user_atomic_number == -1) {
        printf("The atomic number of Oxygen is 8.\n");
    } else {
        printf("Incorrect. Oxygen's atomic number is 8.\n");
    }
    num_total++;

    // ask for atomic mass
    printf("What is the atomic mass of Carbon? ");
    double user_atomic_mass;
    scanf("%lf", &user_atomic_mass);
    if (user_atomic_mass == 12.011) {
        printf("Correct! Carbon's atomic mass is 12.011.\n");
        num_correct++;
    } else if (user_atomic_mass == -1) {
        printf("The atomic mass of Carbon is 12.011.\n");
    } else {
        printf("Incorrect. Carbon's atomic mass is 12.011.\n");
    }
    num_total++;

    printf("\n");

    // show a random element and ask for atomic number and mass
    srand(time(NULL));
    int random_index = rand() % MAX_ELEMENTS;
    Element random_element = elements[random_index];
    printf("What is the atomic number and atomic mass of %s?\n", random_element.name);
    printf("Enter the atomic number: ");
    scanf("%d", &user_atomic_number);
    printf("Enter the atomic mass: ");
    scanf("%lf", &user_atomic_mass);
    if (user_atomic_number == random_element.atomic_number && user_atomic_mass == random_element.atomic_mass) {
        printf("Correct! %s's atomic number is %d and its atomic mass is %f\n", random_element.name, random_element.atomic_number, random_element.atomic_mass);
        num_correct++;
    } else {
        printf("Incorrect. %s's atomic number is %d and its atomic mass is %f\n", random_element.name, random_element.atomic_number, random_element.atomic_mass);
    }
    num_total++;

    printf("\n");

    // show a random element symbol and ask for atomic number and mass
    random_index = rand() % MAX_ELEMENTS;
    random_element = elements[random_index];
    printf("What is the atomic number and atomic mass of %s?\n", random_element.symbol);
    printf("Enter the atomic number: ");
    scanf("%d", &user_atomic_number);
    printf("Enter the atomic mass: ");
    scanf("%lf", &user_atomic_mass);
    if (user_atomic_number == random_element.atomic_number && user_atomic_mass == random_element.atomic_mass) {
        printf("Correct! %s's atomic number is %d and its atomic mass is %f\n", random_element.symbol, random_element.atomic_number, random_element.atomic_mass);
        num_correct++;
    } else {
        printf("Incorrect. %s's atomic number is %d and its atomic mass is %f\n", random_element.symbol, random_element.atomic_number, random_element.atomic_mass);
    }
    num_total++;

    printf("\n");

    // calculate and display the score
    double percentage = (double) num_correct / num_total * 100;
    printf("Quiz complete! You got %d out of %d correct (%0.2f%%).\n", num_correct, num_total, percentage);
}