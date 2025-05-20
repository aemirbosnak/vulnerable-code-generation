//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
struct Question {
    char question[256];
    char answer[256];
};

// Array of questions
struct Question questions[] = {
    {"What is the capital of France?", "Paris"},
    {"Who is the author of 'The Lord of the Rings'?", "J.R.R. Tolkien"},
    {"What is the chemical symbol for gold?", "Au"},
    {"What is the largest ocean in the world?", "Pacific Ocean"},
    {"Who is the current President of the United States?", "Joe Biden"}
};

// Function to print a question and get the user's answer
char *get_answer(struct Question question) {
    printf("%s\n", question.question);
    char *answer = malloc(256);
    scanf("%s", answer);
    return answer;
}

// Function to check if the user's answer is correct
int is_correct(char *answer, char *correct_answer) {
    return strcmp(answer, correct_answer) == 0;
}

// Function to print the results of the exam
void print_results(int score, int total) {
    printf("Your score is %d out of %d.\n", score, total);
    if (score >= total / 2) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
}

int main() {
    // Get the number of questions
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Initialize the score to 0
    int score = 0;

    // Loop through the questions and get the user's answers
    for (int i = 0; i < num_questions; i++) {
        char *answer = get_answer(questions[i]);

        // Check if the answer is correct
        if (is_correct(answer, questions[i].answer)) {
            score++;
        }

        // Free the memory allocated for the answer
        free(answer);
    }

    // Print the results of the exam
    print_results(score, num_questions);

    return 0;
}