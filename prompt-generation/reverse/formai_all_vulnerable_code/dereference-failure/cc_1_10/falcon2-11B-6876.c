//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_OF_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_ELEMENT_VALUE 30

struct element {
    char name[MAX_NAME_LENGTH];
    int atomic_number;
    char symbol[MAX_ELEMENT_VALUE];
    int electron_configuration;
};

int main() {
    struct element elements[NUM_OF_ELEMENTS];
    int num_elements = 0;
    int num_correct = 0;
    int num_incorrect = 0;
    int element_num;
    int element_value;
    char element_symbol[MAX_ELEMENT_VALUE];
    char element_name[MAX_ELEMENT_VALUE];
    char user_answer[MAX_ELEMENT_VALUE];

    printf("Welcome to the C Periodic Table Quiz!\n\n");

    for (int i = 1; i <= NUM_OF_ELEMENTS; i++) {
        element_num = i;
        strcpy(element_name, elements[i - 1].name);
        strcpy(element_symbol, elements[i - 1].symbol);
        printf("%d) %s (%s)\n", element_num, element_name, element_symbol);
        num_elements++;
    }

    printf("How many elements would you like to test? ");
    scanf("%d", &element_num);

    if (element_num <= 0 || element_num > num_elements) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", num_elements);
        return 0;
    }

    for (int i = 0; i < element_num; i++) {
        printf("Enter the atomic number: ");
        scanf("%d", &element_value);

        for (int j = 1; j <= NUM_OF_ELEMENTS; j++) {
            if (elements[j - 1].atomic_number == element_value) {
                strcpy(element_name, elements[j - 1].name);
                strcpy(element_symbol, elements[j - 1].symbol);
                break;
            }
        }

        printf("Enter the element name: ");
        scanf("%s", user_answer);

        if (strcmp(user_answer, element_name) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element_name);
            num_incorrect++;
        }

        printf("Enter the element symbol: ");
        scanf("%s", element_symbol);

        if (strcmp(element_symbol, element_name) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element_symbol);
            num_incorrect++;
        }
    }

    printf("\nYou got %d out of %d questions correct (%.2f%%).\n\n", num_correct, num_elements, ((float)num_correct / (float)num_elements) * 100);
    printf("You got %d out of %d questions incorrect (%.2f%%).\n\n", num_incorrect, num_elements, ((float)num_incorrect / (float)num_elements) * 100);

    return 0;
}