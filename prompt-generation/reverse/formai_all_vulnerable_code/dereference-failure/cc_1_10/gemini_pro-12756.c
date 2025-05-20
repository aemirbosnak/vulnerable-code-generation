//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char *answer;
    int weight;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

// Function to create a new question
Question *create_question(char *question, char *answer, int weight) {
    Question *new_question = malloc(sizeof(Question));
    new_question->question = strdup(question);
    new_question->answer = strdup(answer);
    new_question->weight = weight;
    return new_question;
}

// Function to create a new student
Student *create_student(char *name) {
    Student *new_student = malloc(sizeof(Student));
    new_student->name = strdup(name);
    new_student->score = 0;
    return new_student;
}

// Function to add a question to an exam
void add_question(Question *question, Student **students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i]->score += question->weight;
    }
}

// Function to grade an exam
void grade_exam(Student **students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i]->name, students[i]->score);
    }
}

int main() {
    // Create some questions
    Question *question1 = create_question("What is the capital of France?", "Paris", 1);
    Question *question2 = create_question("Who is the author of Hamlet?", "William Shakespeare", 1);
    Question *question3 = create_question("What is the chemical symbol of gold?", "Au", 1);

    // Create some students
    Student *student1 = create_student("John");
    Student *student2 = create_student("Mary");

    // Add the questions to the exam
    add_question(question1, &student1, 1);
    add_question(question2, &student1, 1);
    add_question(question3, &student1, 1);
    add_question(question1, &student2, 1);
    add_question(question2, &student2, 1);
    add_question(question3, &student2, 1);

    // Grade the exam
    grade_exam(&student1, 1);
    grade_exam(&student2, 1);

    // Free the memory allocated for the questions and students
    free(question1);
    free(question2);
    free(question3);
    free(student1);
    free(student2);

    return 0;
}