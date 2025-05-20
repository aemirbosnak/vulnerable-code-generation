//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_CHOICES 4

// Define the data structure for each question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    int answer;
} Question;

// Declare the global array of questions
Question questions[MAX_QUESTIONS];

// Function to load the questions from a file
void loadQuestionsFromFile(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // Read each record in the file and store it in the array
    char line[200];
    int questionIndex = 0;
    while (fgets(line, sizeof(line), file)) {
        // Parse the line into question, choices, and answer
        char* token = strtok(line, "|");
        strcpy(questions[questionIndex].question, token);
        for (int i = 0; i < MAX_CHOICES; i++) {
            token = strtok(NULL, "|");
            strcpy(questions[questionIndex].choices[i], token);
        }
        token = strtok(NULL, "|");
        questions[questionIndex].answer = atoi(token);

        questionIndex++;
    }

    // Close the file
    fclose(file);
}

// Function to display a question and its choices
void displayQuestion(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%d. %s\n", i+1, question.choices[i]);
    }
    printf("\n");
}

// Function to check if the user's answer is correct
int isAnswerCorrect(Question question, int userAnswer) {
    return (userAnswer == question.answer);
}

// Function to generate a random number within a range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Main function
int main() {
    // Load the questions from the file
    loadQuestionsFromFile("periodic_table_questions.txt");

    // Set up variables for the quiz
    int score = 0;
    int questionCount = 0;
    int questionsAsked[MAX_QUESTIONS] = {0};
    srand(time(NULL));

    // Loop through the quiz
    while (questionCount < MAX_QUESTIONS) {
        // Choose a random question that hasn't been asked yet
        int questionIndex;
        do {
            questionIndex = generateRandomNumber(0, MAX_QUESTIONS-1);
        } while (questionsAsked[questionIndex]);
        questionsAsked[questionIndex] = 1;

        // Display the question and get the user's answer
        displayQuestion(questions[questionIndex]);
        int userAnswer;
        printf("Enter your answer (1-%d): ", MAX_CHOICES);
        scanf("%d", &userAnswer);

        // Check if the user's answer is correct and increment the score if it is
        if (isAnswerCorrect(questions[questionIndex], userAnswer)) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", questions[questionIndex].answer);
        }

        // Increment the question count
        questionCount++;

        // Check if the quiz is over
        if (questionCount == MAX_QUESTIONS) {
            printf("Quiz over! You scored %d out of %d.\n", score, MAX_QUESTIONS);
            break;
        }

        // Ask the user if they want to continue the quiz
        printf("Do you want to continue? (y/n) ");
        char continueChoice;
        scanf(" %c", &continueChoice);
        if (continueChoice == 'n') {
            printf("Quiz over! You scored %d out of %d.\n", score, questionCount);
            break;
        }
    }

    return 0;
}