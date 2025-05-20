//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who creates and manages a business", "b. A person who is good at math", "c. A person who is a teacher", "d. A person who is a lawyer"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Thunder", "d. A drum"}, 3},
    {"Which scientist invented the theory of relativity?", {"a. Einstein", "b. Newton", "c. Galileo", "d. Hawking"}, 4},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who creates and manages a business", "b. A person who is good at math", "c. A person who is a teacher", "d. A person who is a lawyer"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Thunder", "d. A drum"}, 3},
    {"Which scientist invented the theory of relativity?", {"a. Einstein", "b. Newton", "c. Galileo", "d. Hawking"}, 4},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who creates and manages a business", "b. A person who is good at math", "c. A person who is a teacher", "d. A person who is a lawyer"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2}
};

int main() {
    int i, score = 0, currentQuestion = 0;

    system("cls");

    // Display questions
    printf("Welcome to the C Online Examination System!\n\n");
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        // Display answers
        printf("Answers:");
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf(" %s", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer;
        printf("\nEnter your answer (a-d): ");
        scanf("%c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer is %c.\n", questions[i].correctAnswer);
        }

        // Move to the next question
        currentQuestion++;
    }

    // Display the results
    printf("\nYour score: %d out of %d", score, MAX_QUESTIONS);
    printf("\nThank you for taking the C Online Examination System!");

    return 0;
}