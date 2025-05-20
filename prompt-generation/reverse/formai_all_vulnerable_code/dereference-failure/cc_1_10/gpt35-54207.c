//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 10

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
} Question;

void print_options(char options[][50], int num_options) {
    for (int i = 0; i < num_options; i++) {
        printf("%c) %s\n", 'A' + i, options[i]);
    }
}

void print_question(Question *question) {
    printf("%s?\n", question->question);
    print_options(question->options, MAX_OPTIONS);
    printf("Your answer: ");
}

Question *create_question(char question[], char options[][50], int correct_option) {
    Question *q = (Question *)malloc(sizeof(Question));
    strcpy(q->question, question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        strcpy(q->options[i], options[i]);
    }
    q->correct_option = correct_option;
    return q;
}

int main() {
    Question *questions[MAX_QUESTIONS] = {
            create_question("What is the capital of India?", (char[][50]) {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 0),
            create_question("What is the largest continent?", (char[][50]) {"Asia", "Europe", "Africa", "North America"}, 0),
            create_question("What is the world's longest river?", (char[][50]) {"Nile", "Amazon", "Yangtze", "Mississippi"}, 1),
            create_question("What is the fastest land animal?", (char[][50]) {"Cheetah", "Lion", "Tiger", "Giraffe"}, 0),
            create_question("What is the smallest country in the world?", (char[][50]) {"Vatican City", "Monaco", "Tuvalu", "Nauru"}, 0),
            create_question("What is the most common element in the earth's atmosphere?", (char[][50]) {"Nitrogen", "Oxygen", "Argon", "Carbon dioxide"}, 0),
            create_question("What is the tallest mountain in the world?", (char[][50]) {"Mt. Everest", "K2", "Makalu", "Kanchenjunga"}, 0),
            create_question("What is the only continent that is also a country?", (char[][50]) {"Australia", "Asia", "Africa", "North America"}, 0),
            create_question("What is the smallest ocean in the world?", (char[][50]) {"Arctic Ocean", "Indian Ocean", "Pacific Ocean", "Southern Ocean"}, 3),
            create_question("What is the largest country in the world by area?", (char[][50]) {"Russia", "USA", "China", "India"}, 0)
    };

    int num_questions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    
    printf("Welcome to the Online Examination System!\n\n");
    printf("You have %d questions to answer. Good luck!\n\n", num_questions);
    
    for (int i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);

        if (strlen(answer) != 1 || (answer[0] < 'A' || answer[0] >= 'A' + MAX_OPTIONS)) {
            printf("Invalid answer. Please select an option from A to %c.\n", 'A' + MAX_OPTIONS - 1);
            i--;
            continue;
        }

        int option = answer[0] - 'A';
        if (option == questions[i]->correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c) %s.\n", 'A' + questions[i]->correct_option, questions[i]->options[questions[i]->correct_option]);
        }
        printf("Your score: %d/%d\n\n", score, num_questions);
    }
    
    printf("Congratulations! You have completed the examination. Your final score is %d/%d.\n", score, num_questions);

    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
    }
    
    return 0;
}