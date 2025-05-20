//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

// Struct for each question and its options
typedef struct Question {
    char prompt[100];
    char options[MAX_OPTIONS][50];
    int correctOption;
} Question;

// Struct for keeping track of score and time
typedef struct Game {
    int score;
    clock_t startTime;
    clock_t endTime;
} Game;

// Function to read questions from a file
Question* readQuestionsFromFile(char* fileName, int* numQuestions) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    Question* questions = malloc(MAX_QUESTIONS * sizeof(Question));
    char line[200];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        if (i >= MAX_QUESTIONS) break; // Maximum questions reached
        char* token = strtok(line, "|"); // Split the line using delimiter
        strcpy(questions[i].prompt, token);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            token = strtok(NULL, "| \n");
            strcpy(questions[i].options[j], token);
        }
        token = strtok(NULL, "| \n");
        questions[i].correctOption = atoi(token);
        i++;
    }
    *numQuestions = i;
    fclose(file);
    return questions;
}

// Function to randomize the order of options for each question
void randomizeOptions(Question* questions, int numQuestions) {
    srand(time(NULL));
    for (int i = 0; i < numQuestions; i++) {
        for (int j = 0; j < MAX_OPTIONS; j++) {
            int index1 = rand() % MAX_OPTIONS;
            int index2 = rand() % MAX_OPTIONS;
            char temp[50];
            strcpy(temp, questions[i].options[index1]);
            strcpy(questions[i].options[index1], questions[i].options[index2]);
            strcpy(questions[i].options[index2], temp);
        }
    }
}

// Function to display a question along with its options
void displayQuestion(Question question) {
    printf("%s\n", question.prompt);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d) %s\n", i+1, question.options[i]);
    }
}

// Function to get the player's answer
int getAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    while (getchar() != '\n'); // Clear input buffer
    return answer;
}

// Function to validate the player's answer
int validateAnswer(int answer, Question question) {
    if (answer < 1 || answer > MAX_OPTIONS) {
        printf("Invalid input.\n");
        return 0;
    }
    return (answer == question.correctOption);
}

// Function to play the game
void playGame(Question* questions, int numQuestions, Game* game) {
    printf("Good luck, let's get started!\n\n");
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
        int answer = getAnswer();
        if (validateAnswer(answer, questions[i])) {
            printf("You got it right!\n");
            game->score++;
        } else {
            printf("Sorry, the correct answer was option %d.\n", questions[i].correctOption);
        }
        printf("Your current score is %d.\n\n", game->score);
    }
    game->endTime = clock();
}

// Function to display the final outcome of the game
void displayOutcome(Game game) {
    double timeTaken = (game.endTime - game.startTime) / (double) CLOCKS_PER_SEC;
    printf("\nCongratulations, you completed the quiz!\n");
    printf("Your final score is %d out of %d.\n", game.score, MAX_QUESTIONS);
    printf("Time taken: %.2f seconds.\n", timeTaken);
}

int main() {
    int numQuestions;
    Question* questions = readQuestionsFromFile("questions.txt", &numQuestions);
    randomizeOptions(questions, numQuestions);

    printf("*** WELCOME TO THE PERIODIC TABLE QUIZ! ***\n\n");
    printf("You will be given %d questions, and 4 answer options for each question.\n", MAX_QUESTIONS);
    printf("Choose the correct option to score points!\n\n");

    Game game = {0, 0, 0};
    game.startTime = clock();

    playGame(questions, numQuestions, &game);
    displayOutcome(game);

    free(questions);
    return 0;
}