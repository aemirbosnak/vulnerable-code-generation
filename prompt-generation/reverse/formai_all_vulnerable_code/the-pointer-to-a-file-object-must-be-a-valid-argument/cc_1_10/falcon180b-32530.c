//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATOMS 118
#define MAX_ELEMENTS 118

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *fp = fopen("elements.txt", "r");
    char line[100];
    int count = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_ELEMENTS) {
            break;
        }

        char *token = strtok(line, " ");
        strcpy(elements[count].symbol, token);

        token = strtok(NULL, " ");
        strcpy(elements[count].name, token);

        elements[count].atomic_number = atoi(token);
        count++;
    }

    fclose(fp);
}

void quiz() {
    int score = 0;
    int random_index;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        random_index = rand() % MAX_ELEMENTS;

        printf("Question %d: What is the symbol of the element with atomic number %d?\n", i + 1, elements[random_index].atomic_number);

        char input[4];
        scanf("%s", input);

        if (strcmp(input, elements[random_index].symbol) == 0) {
            score++;
        }
    }

    printf("\nYour final score is %d out of 10.\n", score);
}

int main() {
    load_elements();
    quiz();

    return 0;
}