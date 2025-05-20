//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char symbol[3];
    char name[20];
    int group;
    int period;
} Element;

Element elements[118];

void load_data() {
    FILE *file = fopen("elements.txt", "r");
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%s%d%d", elements[i].symbol, elements[i].name, &elements[i].group, &elements[i].period);
        elements[i].symbol[2] = '\0';
        i++;
    }

    fclose(file);
}

void shuffle_array(Element arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_element(Element e) {
    printf("%-3s %-20s Group %-2 Period %-2\n", e.symbol, e.name, e.group, e.period);
}

void quiz(int num_questions) {
    int score = 0;
    shuffle_array(elements, 118);

    for (int i = 0; i < num_questions; i++) {
        int r = rand() % 118;
        Element e = elements[r];
        printf("Question %d:\nWhat is the name of the element with the symbol '%s'?\n", i + 1, e.symbol);
        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, elements[r].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is '%s'.\n", elements[r].name);
        }
    }

    printf("\nYour score is %d out of %d.\n", score, num_questions);
}

int main() {
    load_data();
    int num_questions;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like in the quiz?\n");
    scanf("%d", &num_questions);

    quiz(num_questions);

    return 0;
}