//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 118 // Number of elements in periodic table
#define NUM_QUESTIONS 10  // Number of questions for the quiz

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
};

typedef struct element Element;

void initialize_table(Element *table);
void print_table(Element *table);
void shuffle_array(int *array, int size);
int *generate_question_indices();
int ask_question(Element *table, int index);

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // allocate memory for periodic table and initialize it
    Element *table = (Element *) malloc(sizeof(Element) * NUM_ELEMENTS);
    initialize_table(table);
    
    // print periodic table for reference
    printf("Periodic Table:\n");
    print_table(table);
    
    printf("\nWelcome to the Periodic Table Quiz!\n\n");
    
    // generate indices for questions
    int *question_indices = generate_question_indices();
    
    // ask each question and keep track of score
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        score += ask_question(table, question_indices[i]);
    }
    
    // display final score
    printf("\nQuiz complete! Final score: %d/%d\n", score, NUM_QUESTIONS);
    
    free(table);
    free(question_indices);
    
    return 0;
}

void initialize_table(Element *table) {
    FILE *fp;
    fp = fopen("periodictable.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    
    char line[BUFSIZ];
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        
        // set atomic number
        table[i].atomic_number = atoi(token);
        
        // set symbol
        token = strtok(NULL, ",");
        strcpy(table[i].symbol, token);
        
        // set name
        token = strtok(NULL, ",");
        strcpy(table[i].name, token);
        
        i++;
    }
    
    fclose(fp);
}

void print_table(Element *table) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%-3s %-20s %-3d\n", table[i].symbol, table[i].name, table[i].atomic_number);
    }
}

void shuffle_array(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        if (i != j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}

int *generate_question_indices() {
    int *indices = (int *) malloc(sizeof(int) * NUM_QUESTIONS);
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        indices[i] = i % NUM_ELEMENTS;
    }
    shuffle_array(indices, NUM_QUESTIONS);
    return indices;
}

int ask_question(Element *table, int index) {
    printf("What is the name of the element with atomic number %d?\n", table[index].atomic_number);
    char answer[20];
    scanf("%s", answer);
    if (strcmp(answer, table[index].name) == 0) {
        printf("Correct!\n\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer was %s.\n\n", table[index].name);
        return 0;
    }
}