//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    char category[20];
    float atomic_mass;
};

char* prompt_user(char* prompt) {
    char* buffer = malloc(100*sizeof(char));
    printf("%s\n", prompt);
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}

int check_answer(char* user_answer, char* correct_answer) {
    if (strcmp(user_answer, correct_answer) == 0) {
        printf("Correct!\n");
        return 1;
    }
    else {
        printf("Incorrect, the correct answer is %s\n", correct_answer);
        return 0;
    }
}

void shuffle(struct element* arr, int n) {
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        struct element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    struct element periodic_table[118];
    FILE* fp = fopen("periodic_table.txt", "r");
    char line[100];
    int counter = 0;
    while (fgets(line, sizeof(line), fp)) {
        char* symbol = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* atomic_number_str = strtok(NULL, ",");
        int atomic_number = atoi(atomic_number_str);
        char* category = strtok(NULL, ",");
        char* atomic_mass_str = strtok(NULL, ",");
        float atomic_mass = atof(atomic_mass_str);

        strcpy(periodic_table[counter].symbol, symbol);
        strcpy(periodic_table[counter].name, name);
        periodic_table[counter].atomic_number = atomic_number;
        strcpy(periodic_table[counter].category, category);
        periodic_table[counter].atomic_mass = atomic_mass;

        counter++;
    }
    fclose(fp);

    printf("Welcome to the Surrealist Periodic Table Quiz!\n");
    printf("In this quiz, you will be shown 5 elements at random and be asked to guess their symbols.\n");
    printf("Please enter your answer in all caps.\n");
    printf("Press enter to begin...\n");
    getchar();

    shuffle(periodic_table, 118);

    int score = 0;
    for (int i = 0; i < 5; i++) {
        printf("Element %d:\n", i+1);
        printf("%s\n", periodic_table[i].name);
        char* user_answer = prompt_user("Guess the symbol:");
        score += check_answer(user_answer, periodic_table[i].symbol);
        free(user_answer);
    }

    printf("You scored %d/5\n", score);

    return 0;
}