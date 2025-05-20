//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question structure
typedef struct {
    int id;
    char *question;
    char **options;
    int num_options;
} Question;

// Student structure
typedef struct {
    int id;
    char *name;
    int score;
} Student;

// Exam structure
typedef struct {
    int id;
    char *name;
    Question *questions;
    int num_questions;
} Exam;

// Create a new question
Question *create_question(int id, char *question, char **options, int num_options) {
    Question *q = (Question *)malloc(sizeof(Question));
    q->id = id;
    q->question = strdup(question);
    q->options = (char **)malloc(num_options * sizeof(char *));
    for (int i = 0; i < num_options; i++) {
        q->options[i] = strdup(options[i]);
    }
    q->num_options = num_options;
    return q;
}

// Create a new student
Student *create_student(int id, char *name) {
    Student *s = (Student *)malloc(sizeof(Student));
    s->id = id;
    s->name = strdup(name);
    s->score = 0;
    return s;
}

// Create a new exam
Exam *create_exam(int id, char *name, Question *questions, int num_questions) {
    Exam *e = (Exam *)malloc(sizeof(Exam));
    e->id = id;
    e->name = strdup(name);
    e->questions = questions;
    e->num_questions = num_questions;
    return e;
}

// Print the question
void print_question(Question *q) {
    printf("%d. %s\n", q->id, q->question);
    for (int i = 0; i < q->num_options; i++) {
        printf("    %c. %s\n", 'A' + i, q->options[i]);
    }
}

// Print the student
void print_student(Student *s) {
    printf("%d. %s (score: %d)\n", s->id, s->name, s->score);
}

// Print the exam
void print_exam(Exam *e) {
    printf("Exam: %s\n", e->name);
    for (int i = 0; i < e->num_questions; i++) {
        print_question(&e->questions[i]);
    }
}

// Free the question
void free_question(Question *q) {
    free(q->question);
    for (int i = 0; i < q->num_options; i++) {
        free(q->options[i]);
    }
    free(q->options);
    free(q);
}

// Free the student
void free_student(Student *s) {
    free(s->name);
    free(s);
}

// Free the exam
void free_exam(Exam *e) {
    free(e->name);
    for (int i = 0; i < e->num_questions; i++) {
        free_question(&e->questions[i]);
    }
    free(e->questions);
    free(e);
}

// Main function
int main() {
    // Create some questions
    Question *q1 = create_question(1, "What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Berlin"}, 4);
    Question *q2 = create_question(2, "What is the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 4);
    Question *q3 = create_question(3, "Who is the author of the Harry Potter series?", (char *[]){"J.K. Rowling", "Stephen King", "George R.R. Martin", "Suzanne Collins"}, 4);

    // Create an exam
    Exam *e1 = create_exam(1, "General Knowledge Exam", (Question *[]){q1, q2, q3}, 3);

    // Create some students
    Student *s1 = create_student(1, "John Doe");
    Student *s2 = create_student(2, "Jane Doe");

    // Print the exam
    print_exam(e1);

    // Take the exam
    for (int i = 0; i < e1->num_questions; i++) {
        print_question(&e1->questions[i]);
        char answer;
        scanf(" %c", &answer);
        if (answer == 'A') {
            s1->score++;
        }
        if (answer == 'B') {
            s2->score++;
        }
    }

    // Print the students
    print_student(s1);
    print_student(s2);

    // Free the memory
    free_exam(e1);
    free_student(s1);
    free_student(s2);

    return 0;
}