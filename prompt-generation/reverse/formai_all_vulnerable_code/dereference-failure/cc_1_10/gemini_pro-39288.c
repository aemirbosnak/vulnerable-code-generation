//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 32

typedef struct {
    int atomic_number;
    char name[MAX_NAME_LEN];
    char symbol[3];
    double atomic_weight;
    char category[16];
    int group;
    int period;
} Element;

Element periodic_table[MAX_ELEMENTS];

void load_periodic_table() {
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening periodic table file\n");
        exit(1);
    }

    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *fields[7];
        int num_fields = 0;
        char *field = strtok(line, ",");
        while (field) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        if (num_fields != 7) {
            fprintf(stderr, "Invalid line in periodic table file: %s\n", line);
            exit(1);
        }

        periodic_table[i].atomic_number = atoi(fields[0]);
        strcpy(periodic_table[i].name, fields[1]);
        strcpy(periodic_table[i].symbol, fields[2]);
        periodic_table[i].atomic_weight = atof(fields[3]);
        strcpy(periodic_table[i].category, fields[4]);
        periodic_table[i].group = atoi(fields[5]);
        periodic_table[i].period = atoi(fields[6]);

        i++;
    }

    fclose(fp);
}

void print_periodic_table() {
    printf("╔════════╤══════════════════════════════════════╤════════════╤═════════════╤═══════════╤═════════╤══════════╗\n");
    printf("║   #    │            Name            │  Symbol  │ Atomic Weight │   Category   │  Group  │  Period  ║\n");
    printf("╠════════╪══════════════════════════════════════╪════════════╪═════════════╪═══════════╪═════════╪══════════╣\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("║ %6d │ %-32s │ %-8s │ %12.3f │ %-12s │ %7d │ %8d │║\n",
               periodic_table[i].atomic_number,
               periodic_table[i].name,
               periodic_table[i].symbol,
               periodic_table[i].atomic_weight,
               periodic_table[i].category,
               periodic_table[i].group,
               periodic_table[i].period);
    }
    printf("╚════════╧══════════════════════════════════════╧════════════╧═════════════╧═══════════╧═════════╧══════════╝\n");
}

void quiz_periodic_table() {
    int score = 0;
    int num_questions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a series of questions about the elements in the periodic table.\n");
    printf("For each question, you will be given a clue and you must answer with the correct element.\n");
    printf("Good luck!\n\n");

    while (1) {
        int random_element = rand() % MAX_ELEMENTS;

        char clue[1024];
        switch (rand() % 5) {
            case 0:
                snprintf(clue, sizeof(clue), "What is the element with the atomic number %d?", periodic_table[random_element].atomic_number);
                break;
            case 1:
                snprintf(clue, sizeof(clue), "What is the element with the symbol %s?", periodic_table[random_element].symbol);
                break;
            case 2:
                snprintf(clue, sizeof(clue), "What is the element with the name %s?", periodic_table[random_element].name);
                break;
            case 3:
                snprintf(clue, sizeof(clue), "What is the element in group %d and period %d?", periodic_table[random_element].group, periodic_table[random_element].period);
                break;
            case 4:
                snprintf(clue, sizeof(clue), "What is the element in the %s category?", periodic_table[random_element].category);
                break;
        }

        char answer[MAX_NAME_LEN];
        printf("%s: ", clue);
        scanf("%s", answer);

        if (strcmp(tolower(answer), tolower(periodic_table[random_element].name)) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[random_element].name);
        }

        num_questions++;

        printf("Your score is %d out of %d.\n\n", score, num_questions);

        char cont[10];
        printf("Do you want to continue? (y/n): ");
        scanf("%s", cont);
        if (strcmp(tolower(cont), "n") == 0) {
            break;
        }
    }

    printf("Thanks for playing!\n");
}

int main() {
    load_periodic_table();

    int choice;
    while (1) {
        printf("╔════════════╤══════════════════════════╗\n");
        printf("║  1. Print  │  2. Quiz  │  3. Exit  ║\n");
        printf("╚════════════╧══════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_periodic_table();
                break;
            case 2:
                quiz_periodic_table();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number from 1 to 3.\n");
        }
    }

    return 0;
}