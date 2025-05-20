//FormAI DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for storing questions
typedef struct {
    int question_id;
    char question_text[200];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_answer;
} question_t;

int main() {
    // Initialize variables
    char student_name[50];
    int num_questions, question_choice, user_answer, num_correct = 0;
    bool answered = false;
    
    // Get student name and number of questions
    printf("Welcome to the Online Exam System!\n");
    printf("Please enter your name: ");
    scanf("%s", student_name);
    printf("Hello %s, how many questions do you want to answer? ", student_name);
    scanf("%d", &num_questions);
    
    // Initialize array of questions
    question_t questions[num_questions];
    
    // Get questions from user
    for (int i = 0; i < num_questions; i++) {
        // Get question text
        printf("Please enter the text for question %d: ", i+1);
        getchar(); // Consume newline character from scanf
        fgets(questions[i].question_text, 200, stdin);
        
        // Get options
        printf("Please enter option 1: ");
        scanf("%s", questions[i].option1);
        printf("Please enter option 2: ");
        scanf("%s", questions[i].option2);
        printf("Please enter option 3: ");
        scanf("%s", questions[i].option3);
        printf("Please enter option 4: ");
        scanf("%s", questions[i].option4);
        
        // Get correct answer
        printf("Which option is the correct answer? ");
        scanf("%d", &questions[i].correct_answer);
        
        // Set question id
        questions[i].question_id = i+1;
    }
    
    // Loop through each question
    for (int i = 0; i < num_questions; i++) {
        // Display question text and options
        printf("\nQuestion %d:\n", questions[i].question_id);
        printf("%s\n", questions[i].question_text);
        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);
        
        // Get user answer and validate input
        do {
            printf("Please enter your answer (1-4): ");
            scanf("%d", &user_answer);
            
            if (user_answer < 1 || user_answer > 4) {
                printf("Invalid input. Please try again.\n");
            } else {
                answered = true;
            }
        } while (!answered);
        
        // Check if user answer is correct
        if (user_answer == questions[i].correct_answer) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is option %d.\n", questions[i].correct_answer);
        }
        
        answered = false; // Reset answered variable
    }
    
    // Calculate and display score
    float score = (float)num_correct / num_questions * 100;
    printf("\nCongratulations %s! You scored %d out of %d (%.2f%%).\n", student_name, num_correct, num_questions, score);
    
    return 0;
}