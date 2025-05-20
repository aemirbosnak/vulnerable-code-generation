//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_answer;
} Question;

typedef struct {
    char name[50];
    int score;
} Student;

void generate_question(Question *question) {
    int i;
    for (i = 0; i < MAX_OPTIONS; i++) {
        sprintf(question->options[i], "Option %d", i + 1);
    }
    question->correct_answer = rand() % MAX_OPTIONS;
}

void generate_exam(Question *exam, int num_questions) {
    int i;
    for (i = 0; i < num_questions; i++) {
        generate_question(&exam[i]);
    }
}

void take_exam(Student *student, Question *exam, int num_questions) {
    int i, correct_answers = 0;
    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam[i].question);
        int choice;
        scanf("%d", &choice);
        if (choice == exam[i].correct_answer) {
            correct_answers++;
        }
    }
    student->score = correct_answers;
}

void print_results(Student *students, int num_students) {
    int i;
    for (i = 0; i < num_students; i++) {
        printf("Student %s: Score %d\n", students[i].name, students[i].score);
    }
}

int main() {
    srand(time(NULL));

    int num_questions, num_students;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    Question exam[num_questions];
    generate_exam(exam, num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student students[num_students];
    int i;
    for (i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    int j;
    for (j = 0; j < num_students; j++) {
        take_exam(&students[j], exam, num_questions);
    }

    print_results(students, num_students);

    return 0;
}