//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_option;
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

void grade_student(Question *question, Student *student) {
    int answer = get_student_answer(question);
    if (answer == question->correct_option) {
        student->score++;
    }
}

int main() {
    srand(time(NULL));

    // Create questions
    Question questions[] = {
        {
            "What is the capital of France?",
            {"Paris", "London", "Rome", "Berlin"},
            4,
            1
        },
        {
            "What is the largest ocean in the world?",
            {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
            4,
            1
        },
        {
            "Who is the current President of the United States?",
            {"Donald Trump", "Joe Biden", "Barack Obama", "George W. Bush"},
            4,
            2
        },
        {
            "What is the chemical symbol for gold?",
            {"Au", "Ag", "Cu", "Fe"},
            4,
            1
        },
        {
            "What is the boiling point of water?",
            {"100 degrees Celsius", "212 degrees Fahrenheit", "373 Kelvin", "All of the above"},
            4,
            4
        }
    };

    // Create students
    Student students[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0}
    };

    // Administer exam
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        for (int j = 0; j < sizeof(students) / sizeof(Student); j++) {
            print_question(&questions[i]);
            grade_student(&questions[i], &students[j]);
        }
    }

    // Print results
    for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}