//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20 // Maximum number of questions for the quiz
#define MAX_ELEMENTS 118 // Number of elements in the periodic table

// Structure to store element data
typedef struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// Function to parse element data from file
void parse_elements(Element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[30];
    int i = 0;
    while (fgets(line, 30, file) != NULL) {
        sscanf(line, "%s %s %d", elements[i].symbol, elements[i].name, &elements[i].atomic_number);
        i++;
    }
    fclose(file);
}

// Function to generate random question from elements array
void get_random_question(Element elements[], int *answer, char question[]) {
    int random_index = rand() % MAX_ELEMENTS;
    *answer = random_index;
    sprintf(question, "%d. What is the symbol for %s?", random_index+1, elements[random_index].name);
}

// Function to check user's answer
int check_answer(Element elements[], int answer, char user_answer[]) {
    return strcmp(elements[answer].symbol, user_answer) == 0;
}

// Function to print quiz results
void print_results(int correct_answers, int total_questions) {
    printf("\nQuiz Results:\n");
    printf("Correct Answers: %d/%d\n", correct_answers, total_questions);
    double percent_correct = ((double)correct_answers / (double)total_questions) * 100.0;
    printf("Percent Correct: %.2f%%\n", percent_correct);
}

int main() {
    srand(time(NULL));  // Seed random number generator
    
    // Allocate memory for elements array
    Element *elements = (Element*) malloc(MAX_ELEMENTS * sizeof(Element));
    
    // Parse element data from file
    parse_elements(elements);
    
    // Initialize quiz variables
    int correct_answers = 0;
    char user_answer[3];
    
    // Print welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d multiple choice questions\n", MAX_QUESTIONS);
    printf("Enter the symbol for the element corresponding to the given name\n");
    printf("Type 'quit' at any time to quit the quiz\n\n");
    
    // Ask questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int answer_index;
        char question[50];
        get_random_question(elements, &answer_index, question);
        printf("%s\n", question);
        scanf("%s", user_answer);
        if (strcmp(user_answer, "quit") == 0) {
            printf("\nQuitting the quiz...\n");
            break;
        }
        if (check_answer(elements, answer_index, user_answer)) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s\n", elements[answer_index].symbol);
        }
    }
    
    // Print quiz results
    print_results(correct_answers, MAX_QUESTIONS);
    
    // Free memory allocated for elements array
    free(elements);
    return 0;
}