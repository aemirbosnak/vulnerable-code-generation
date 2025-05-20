//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int number;
} Element;

int main(int argc, char *argv[]) {
    int n_elements = 118;
    Element *elements = (Element*) malloc(n_elements * sizeof(Element));

    // Fill the array with elements
    for (int i = 0; i < n_elements; i++) {
        elements[i].name[0] = 'X';
        elements[i].name[1] = '\0';
        elements[i].number = i + 1;
    }

    // Quiz
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many elements are there in the periodic table?\n");
    scanf("%d", &n_elements);
    if (n_elements!= 118) {
        printf("Incorrect! The correct answer is 118.\n");
    }

    // Display the elements
    printf("Now let's see some elements!\n");
    for (int i = 0; i < n_elements; i++) {
        printf("%s (%d)\n", elements[i].name, elements[i].number);
    }

    // Test the user's knowledge
    printf("Let's test your knowledge of the elements!\n");
    printf("What element has the symbol 'He'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 2) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("What element has the symbol 'H'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 1) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("What element has the symbol 'Li'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 3) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("What element has the symbol 'N'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 7) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("What element has the symbol 'P'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 15) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("What element has the symbol 'U'?\n");
    scanf("%d", &n_elements);
    if (elements[n_elements - 1].number == 92) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    printf("Congratulations, you passed the quiz!\n");

    // Free the memory
    free(elements);

    return 0;
}