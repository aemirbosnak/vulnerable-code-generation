//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char **options;
    int correct_option;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

int main() {
    // Initialize the questions
    Question questions[] = {
        {
            .question = "What is the capital of India?",
            .options = {"Mumbai", "Delhi", "Kolkata", "Chennai"},
            .correct_option = 1
        },
        {
            .question = "Who is the current Prime Minister of India?",
            .options = {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"},
            .correct_option = 0
        },
        {
            .question = "What is the national animal of India?",
            .options = {"Lion", "Tiger", "Elephant", "Peacock"},
            .correct_option = 0
        },
        {
            .question = "What is the national bird of India?",
            .options = {"Peacock", "Sparrow", "Kite", "Myna"},
            .correct_option = 0
        },
        {
            .question = "What is the national flower of India?",
            .options = {"Lotus", "Rose", "Jasmine", "Marigold"},
            .correct_option = 0
        }
    };

    // Initialize the students
    Student students[] = {
        {
            .name = "John Doe",
            .score = 0
        },
        {
            .name = "Jane Doe",
            .score = 0
        }
    };

    // Conduct the examination
    for (int i = 0; i < 5; i++) {
        print_question(questions[i]);
        int answer;
        scanf("%d", &answer);
        if (answer == questions[i].correct_option) {
            students[0].score++;
        }
    }

    // Print the results
    for (int i = 0; i < 2; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}