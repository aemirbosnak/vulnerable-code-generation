//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

struct question {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correct_option;
};

struct exam {
    struct question questions[MAX_QUESTIONS];
    int num_questions;
};

void print_question(struct question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

int get_user_input(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }
    }
}

int take_exam(struct exam *exam, int current_question, int score) {
    if (current_question == exam->num_questions) {
        return score;
    } else {
        struct question *question = &exam->questions[current_question];
        print_question(question);
        int user_input = get_user_input(1, MAX_OPTIONS);
        if (user_input == question->correct_option) {
            score++;
        }
        return take_exam(exam, current_question + 1, score);
    }
}

int main() {
    struct exam exam;

    // Read the exam questions from a file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[256];
    int current_question = 0;
    while (fgets(line, sizeof(line), fp)) {
        struct question *question = &exam.questions[current_question];

        // Parse the question
        char *question_text = strtok(line, "|");
        strcpy(question->question, question_text);

        // Parse the options
        for (int i = 0; i < MAX_OPTIONS; i++) {
            char *option = strtok(NULL, "|");
            if (option == NULL) {
                break;
            }
            strcpy(question->options[i], option);
        }

        // Parse the correct option
        char *correct_option = strtok(NULL, "|");
        question->correct_option = atoi(correct_option) - 1;

        current_question++;
    }

    fclose(fp);

    exam.num_questions = current_question;

    // Take the exam
    int score = take_exam(&exam, 0, 0);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam.num_questions);

    return EXIT_SUCCESS;
}