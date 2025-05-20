//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ELEMENT_LENGTH 3
#define MAX_SYMBOL_LENGTH 2
#define MAX_NAME_LENGTH 50

// Define structs
typedef struct {
    char element[MAX_ELEMENT_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Element;

typedef struct {
    Element* elements;
    char options[MAX_OPTIONS][MAX_NAME_LENGTH];
    int correct_option;
} Question;

// Define function prototypes
void print_welcome_message();
void read_elements_from_file(Element** elements);
void shuffle_elements(Element* elements);
void generate_question(Question* question, Element* elements);
void print_question(Question* question, int question_number);
void get_user_answer(int* user_answer);
void print_answer_result(int user_answer, Question* question);
void print_final_score(int score, int total_questions);

int main() {
    // Seed random generator
    srand(time(NULL));
    
    // Initialize variables
    int score = 0;
    int total_questions = 0;
    int user_answer;
    Element* elements;
    
    // Print welcome message
    print_welcome_message();
    
    // Read elements from file and shuffle
    read_elements_from_file(&elements);
    shuffle_elements(elements);
    
    // Start asking questions
    for (int i = 1; i <= MAX_QUESTIONS; i++) {
        // Initialize question
        Question question;
        generate_question(&question, elements);
        
        // Print question and get user answer
        print_question(&question, i);
        get_user_answer(&user_answer);
        
        // Print answer result and update score
        print_answer_result(user_answer, &question);
        if (user_answer == question.correct_option) {
            score++;
        }
        
        // Increment total number of questions asked
        total_questions++;
    }
    
    // Print final score
    print_final_score(score, total_questions);
    
    // Free allocated memory
    free(elements);
    
    return 0;
}

void print_welcome_message() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements of the periodic table.\n", MAX_QUESTIONS);
    printf("Please select the correct answer from the options provided.\n\n");
}

void read_elements_from_file(Element** elements) {
    // Open file for reading
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error opening file. Exiting program.\n");
        exit(1);
    }
    
    // Initialize variables
    int num_elements = 0;
    char line[MAX_ELEMENT_LENGTH + MAX_SYMBOL_LENGTH + MAX_NAME_LENGTH + 3];
    
    // Read number of elements from file
    fgets(line, MAX_ELEMENT_LENGTH + MAX_SYMBOL_LENGTH + MAX_NAME_LENGTH + 3, file);
    sscanf(line, "%d", &num_elements);
    
    // Allocate memory for elements
    *elements = (Element*) malloc(num_elements * sizeof(Element));
    
    // Read elements from file
    for (int i = 0; i < num_elements; i++) {
        fgets(line, MAX_ELEMENT_LENGTH + MAX_SYMBOL_LENGTH + MAX_NAME_LENGTH + 3, file);
        sscanf(line, "%s %s %[^\n]", (*elements)[i].element, (*elements)[i].symbol, (*elements)[i].name);
    }
    
    // Close file
    fclose(file);
}

void shuffle_elements(Element* elements) {
    // Shuffle elements using Fisher-Yates algorithm
    for (int i = MAX_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void generate_question(Question* question, Element* elements) {
    // Choose a random element for the question
    int element_index = rand() % MAX_QUESTIONS;
    Element* element = &elements[element_index];
    
    // Set up question
    strcpy(question->options[0], element->name);
    question->correct_option = 0;
    
    // Choose random incorrect options
    for (int i = 1; i < MAX_OPTIONS; i++) {
        int random_index = rand() % MAX_QUESTIONS;
        while (random_index == element_index || strlen(elements[random_index].name) == 0) {
            // Choose a new randomly-indexed element if the element has already been chosen or is empty
            random_index = rand() % MAX_QUESTIONS;
        }
        strcpy(question->options[i], elements[random_index].name);
    }
    
    // Shuffle options
    for (int i = MAX_OPTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_NAME_LENGTH];
        strcpy(temp, question->options[i]);
        strcpy(question->options[i], question->options[j]);
        strcpy(question->options[j], temp);
    }
}

void print_question(Question* question, int question_number) {
    printf("\nQuestion %d:\n", question_number);
    printf("What is the name of the element with symbol %s?\n\n", question->options[0]);
    printf("Options:\n");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d) %s\n", i + 1, question->options[i]);
    }
    printf("\nEnter your answer: ");
}

void get_user_answer(int* user_answer) {
    scanf("%d", user_answer);
    while (*user_answer < 1 || *user_answer > MAX_OPTIONS) {
        printf("Invalid answer. Please enter a number between 1 and %d: ", MAX_OPTIONS);
        scanf("%d", user_answer);
    }
}

void print_answer_result(int user_answer, Question* question) {
    printf("\n");
    if (user_answer == question->correct_option + 1) {
        printf("Correct answer!\n");
    } else {
        printf("Incorrect answer. The correct answer was %s.\n", question->options[question->correct_option]);
    }
}

void print_final_score(int score, int total_questions) {
    printf("\n\nQuiz complete!\n");
    printf("Your final score is %d out of %d.", score, total_questions);
}