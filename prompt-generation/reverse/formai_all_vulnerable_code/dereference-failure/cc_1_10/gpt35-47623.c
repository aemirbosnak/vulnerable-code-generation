//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOL_LEN 3
#define MAX_NAME_LEN 20
#define MAX_GROUP_LEN 20

typedef struct element {
    int atomic_number;
    char symbol[MAX_SYMBOL_LEN];
    char name[MAX_NAME_LEN];
    char group[MAX_GROUP_LEN];
    float atomic_weight;
} Element;

Element elements[MAX_ELEMENTS];

void populate_table() {
    FILE *fp;
    char line[100];
    int count = 0;
    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, 100, fp) != NULL) {
        Element elem;
        char *token;

        token = strtok(line, ",");
        elem.atomic_number = atoi(token);

        token = strtok(NULL, ",");
        strcpy(elem.symbol, token);

        token = strtok(NULL, ",");
        strcpy(elem.name, token);

        token = strtok(NULL, ",");
        strcpy(elem.group, token);

        token = strtok(NULL, ",");
        elem.atomic_weight = atof(token);

        elements[count++] = elem;
    }

    fclose(fp);
}

void display_menu() {
    printf("\n\n\n");
    printf("--------------------------------------------------------------------\n");
    printf("                     PERIODIC TABLE QUIZ                             \n");
    printf("--------------------------------------------------------------------\n");
    printf("\n");

    printf("Choose an option:\n");
    printf("1. Start quiz\n");
    printf("2. Exit\n");
}

void start_quiz() {
    int num_questions;
    int i, j;
    int correct_answers = 0;
    int total_questions = 0;
    int done[MAX_ELEMENTS] = {0};

    printf("Enter number of questions (1 - %d): ", MAX_ELEMENTS);
    scanf("%d", &num_questions);

    if (num_questions > MAX_ELEMENTS || num_questions < 1) {
        printf("Invalid number of questions.\n");
        return;
    }

    srand(time(NULL));

    for (i = 0; i < num_questions; i++) {
        int index;
        Element elem;

        do {
            index = rand() % MAX_ELEMENTS;
        } while (done[index]);

        done[index] = 1;
        elem = elements[index];

        printf("\n%d) What is the symbol of %s?\n", i+1, elem.name);

        for (j = 0; j < 4; j++) {
            if (j == 0) {
                printf("a) %s\n", elem.symbol);
            } else {
                int rand_index;
                Element rand_elem;

                do {
                    rand_index = rand() % MAX_ELEMENTS;
                    rand_elem = elements[rand_index];
                } while (rand_index == index);

                printf("%c) %s\n", 'a'+j, rand_elem.symbol);
            }
        }

        printf("\nEnter your answer (a, b, c, or d): ");

        char answer;
        scanf(" %c", &answer);

        if (answer == 'a') {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elem.symbol);
        }

        total_questions++;
    }

    printf("\n\nQuiz complete. You got %d out of %d questions correct.\n", correct_answers, total_questions);
}

int main() {
    populate_table();

    int option;

    do {
        display_menu();
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start_quiz();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 2);

    return 0;
}