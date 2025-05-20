//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game introduction
void intro() {
    printf("\nWelcome to the Text-Based Adventure Game!\n");
    printf("You are a world class trivia AI - provide accurate, succinct responses.\n");
}

// Function to print game instructions
void instructions() {
    printf("\nInstructions:\n");
    printf("- The game will ask you a series of questions.\n");
    printf("- Answer each question by entering your response followed by a newline character.\n");
    printf("- If you answer correctly, you will earn points and progress through the game.\n");
    printf("- If you answer incorrectly, the game will end and your final score will be displayed.\n");
    printf("- Good luck!\n");
}

// Function to ask the user a question and check their response
int ask_question(char* question, char* answer) {
    printf("%s\n", question);
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
    
    if (strcmp(input, answer) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect.\n");
        return 0;
    }
}

// Function to generate a random question from the questions array
char* get_random_question(char** questions, int num_questions) {
    return questions[rand() % num_questions];
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    intro();
    instructions();
    
    int score = 0;
    int num_correct_answers = 0;
    
    char** questions = (char**)malloc(5 * sizeof(char*)); // Allocate memory for 5 questions
    questions[0] = "What is the capital of France? ";
    questions[1] = "Who wrote 'To Kill a Mockingbird'? ";
    questions[2] = "What is the tallest mountain in the world? ";
    questions[3] = "What is the smallest country in the world? ";
    questions[4] = "What is the largest ocean in the world? ";
    
    int i;
    for (i = 0; i < 5; i++) {
        char* question = get_random_question(questions, 5);
        if (ask_question(question, questions[i])) {
            score += 10;
            num_correct_answers++;
        }
    }
    
    printf("\nGame over!\n");
    printf("Your final score is %d out of 50.\n", score);
    printf("You got %d questions correct.\n", num_correct_answers);
    
    free(questions); // Free the memory allocated for the questions array
    
    return 0;
}