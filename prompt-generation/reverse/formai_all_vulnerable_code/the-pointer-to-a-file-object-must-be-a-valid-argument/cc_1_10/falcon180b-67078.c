//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int atomic_weight;
    char category[20];
};

void initialize_elements(struct element *elements) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("elements.txt", "r");

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %s %d %d %s", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].atomic_weight, elements[i].category);
        i++;
    }

    fclose(fp);
}

void print_element(struct element element) {
    printf("Symbol: %s\n", element.symbol);
    printf("Name: %s\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Atomic Weight: %d\n", element.atomic_weight);
    printf("Category: %s\n\n", element.category);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    int i, j, correct_answers = 0;
    char user_answer[4];

    initialize_elements(elements);

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        j = rand() % MAX_ELEMENTS;
        print_element(elements[j]);
        printf("Enter the symbol of the element: ");
        scanf("%s", user_answer);

        if (strcmp(user_answer, elements[j].symbol) == 0) {
            correct_answers++;
        }
    }

    printf("You got %d out of 10 correct.\n", correct_answers);

    return 0;
}