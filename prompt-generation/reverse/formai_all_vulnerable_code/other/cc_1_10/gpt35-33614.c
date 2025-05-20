//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct {
    char question[100];
    char answer[3];
} Question;

const Question questionBank[] = {
    {"What element has the symbol 'H'? ", "1"},
    {"Which element is not a metal: copper, calcium, or cobalt? ", "2"},
    {"What is the atomic symbol for gold? ", "79"},
    {"Which element is a noble gas: helium, lithium, or neon? ", "1"},
    {"What is the most abundant element in the universe? ", "1"},
    {"What element is commonly used to fuel nuclear reactors? ", "92"},
    {"What is the atomic symbol for iron? ", "26"},
    {"What is the chemical symbol for lead? ", "82"},
    {"Which element has the symbol 'O'? ", "8"},
    {"What is the atomic symbol for carbon? ", "6"}
};

void shuffleQuestions(Question *questions, int size);
void displayQuestion(Question question, int questionNumber);
int askQuestion(Question question, int questionNumber);

int main() {
    Question currentQuestion;
    int totalCorrect = 0;
    int questionNumbers[MAX_QUESTIONS] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the question array so we get a random set of questions
    shuffleQuestions(&questionBank[0], sizeof(questionBank) / sizeof(Question));

    // Quiz intro
    printf("Welcome to the Periodic Table quiz!\n\n");
    printf("There will be %d questions.\n", MAX_QUESTIONS); 
    printf("You will have three attempts to answer each question.\n");
    printf("Enter your answer as the atomic number.\n");
    printf("Good luck!\n\n");

    // Ask the user each question and keep a running score
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        currentQuestion = questionBank[i];
        questionNumbers[i] = askQuestion(currentQuestion, i + 1);
        totalCorrect += questionNumbers[i];
    }

    // Quiz results
    printf("\nQuiz Results:\n");
    printf("Total number correct: %d\n", totalCorrect);
    printf("Percentage correct: %.2f%%\n", ((double)totalCorrect / (double)MAX_QUESTIONS) * 100.0);

    return 0;
}

/**
 * Shuffles an array of questions.
 *
 * @param questions The array of questions
 * @param size The size of the array
 */
void shuffleQuestions(Question *questions, int size) {
    int i, j;
    Question temp;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

/**
 * Displays a question to the user with its number.
 *
 * @param question The question to display
 * @param questionNumber The number of the question
 */
void displayQuestion(Question question, int questionNumber) {
    printf("Question #%d: %s\n", questionNumber, question.question);
}

/**
 * Asks the user a question and returns their score for the question.
 *
 * @param question The question to ask
 * @param questionNumber The number of the question
 * @return The number of points earned for the question (1 if correct, 0 if incorrect)
 */
int askQuestion(Question question, int questionNumber) {
    int attempts = 0;
    char input[5];
    int isNumeric;
    int score = 0;
    displayQuestion(question, questionNumber);
    do {
        printf("Attempt #%d: ", attempts + 1);
        fgets(input, 5, stdin);

        // Trim trailing whitespace
        while (isspace(input[strlen(input) - 1])) {
            input[strlen(input) - 1] = '\0';
        }

        // Make all characters uppercase
        for (int i = 0; i < strlen(input); i++) {
            input[i] = toupper(input[i]);
        }

        // Check if the input is numeric and within the valid range
        isNumeric = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isNumeric = 0;
                break;
            }
        }

        if (isNumeric) {
            int answer = atoi(input);
            if (answer == atoi(question.answer)) {
                printf("Correct!\n");
                score = 1;
            } else {
                printf("Incorrect. Try again.\n");
                score = 0;
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
        }

        attempts++;
    } while (attempts < 3 && !score);

    return score;
}