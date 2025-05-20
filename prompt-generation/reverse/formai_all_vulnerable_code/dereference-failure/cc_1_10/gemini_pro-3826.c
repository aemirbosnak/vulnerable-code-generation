//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the question and its options
typedef struct {
    char question[256];
    char options[4][64];
    int correct_answer;
} Question;

// Function to load the questions from a file
void load_questions(Question *questions, int *num_questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("Error opening questions file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line into question, options, and correct answer
        char *question_start = line;
        char *option_start = strstr(line, "|");
        char *option_end = strstr(option_start + 1, "|");
        char *correct_answer_start = strstr(option_end + 1, "|");

        strncpy(questions[i].question, question_start, option_start - question_start);
        questions[i].question[option_start - question_start] = '\0';

        for (int j = 0; j < 4; j++) {
            strncpy(questions[i].options[j], option_start + j, option_end - option_start);
            questions[i].options[j][option_end - option_start] = '\0';
            option_start = option_end + 1;
            option_end = strstr(option_start, "|");
        }

        questions[i].correct_answer = atoi(correct_answer_start);

        i++;
    }

    fclose(fp);
    *num_questions = i;
}

// Function to print the question and its options
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int is_correct(Question question, int answer) {
    return question.correct_answer == answer;
}

int main() {
    // Load the questions from the file
    Question questions[10];
    int num_questions;
    load_questions(questions, &num_questions);

    // Print the questions and get the user's answers
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        int answer = get_answer();
        if (is_correct(questions[i], answer)) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d/%d\n", score, num_questions);

    return 0;
}