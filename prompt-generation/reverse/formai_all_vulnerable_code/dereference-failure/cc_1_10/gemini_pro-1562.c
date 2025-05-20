//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_answer;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

void print_question(Question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < question->num_options; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

int get_student_answer(Question *question) {
    int answer;
    printf("Enter your answer (1-%d): ", question->num_options);
    scanf("%d", &answer);
    return answer;
}

void check_answer(Question *question, int answer, Student *student) {
    if (answer == question->correct_answer) {
        student->score++;
    }
}

int main() {
    // Create a new exam
    Question questions[] = {
        {
            "What is the capital of France?",
            {"Paris", "London", "Rome", "Madrid"},
            4,
            1
        },
        {
            "What is the largest ocean in the world?",
            {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"},
            4,
            2
        },
        {
            "Who is the current president of the United States?",
            {"Donald Trump", "Joe Biden", "Barack Obama", "George W. Bush"},
            4,
            2
        }
    };

    // Get the student's name
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    // Create a new student
    Student student = {
        .name = name,
        .score = 0
    };

    // Administer the exam
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        print_question(&questions[i]);
        int answer = get_student_answer(&questions[i]);
        check_answer(&questions[i], answer, &student);
    }

    // Print the student's score
    printf("Your score is %d out of %d\n", student.score, sizeof(questions) / sizeof(Question));

    return 0;
}