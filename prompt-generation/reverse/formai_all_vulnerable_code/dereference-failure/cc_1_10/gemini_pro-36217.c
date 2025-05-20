//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question
typedef struct Question {
    char question[100];
    char options[4][50];
    int correctOption;
} Question;

// Function to create a new question
Question* createQuestion(char *question, char *option1, char *option2, char *option3, char *option4, int correctOption) {
    Question *newQuestion = (Question*) malloc(sizeof(Question));
    strcpy(newQuestion->question, question);
    strcpy(newQuestion->options[0], option1);
    strcpy(newQuestion->options[1], option2);
    strcpy(newQuestion->options[2], option3);
    strcpy(newQuestion->options[3], option4);
    newQuestion->correctOption = correctOption;
    return newQuestion;
}

// Function to display a question
void displayQuestion(Question *question) {
    printf("\n%s\n", question->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

// Function to get the user's answer
int getAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int isCorrectAnswer(Question *question, int answer) {
    return answer == question->correctOption;
}

// Main function
int main() {
    // Create a set of questions
    Question *questions[] = {
        createQuestion("What is the capital of India?", "New Delhi", "Mumbai", "Chennai", "Kolkata", 1),
        createQuestion("Who is the current Prime Minister of India?", "Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee", 1),
        createQuestion("What is the national animal of India?", "Tiger", "Lion", "Elephant", "Rhinoceros", 1),
        createQuestion("What is the national bird of India?", "Peacock", "Sparrow", "Eagle", "Owl", 1),
        createQuestion("What is the national anthem of India?", "Jana Gana Mana", "Vande Mataram", "Saare Jahan Se Accha", "Jana Mana Gana", 1)
    };

    // Display the questions and get the user's answers
    int score = 0;
    for (int i = 0; i < 5; i++) {
        displayQuestion(questions[i]);
        int answer = getAnswer();
        if (isCorrectAnswer(questions[i], answer)) {
            score++;
        }
    }

    // Display the score
    printf("\nYour score is %d out of 5\n", score);

    return 0;
}