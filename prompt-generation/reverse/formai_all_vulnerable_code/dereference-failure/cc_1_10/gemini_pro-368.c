//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question structure
typedef struct Question {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

// Student structure
typedef struct Student {
    char *name;
    int score;
} Student;

// Global variables
Question questions[10];
Student students[100];
int num_questions = 0;
int num_students = 0;

// Function to create a new question
Question *create_question(char *question, char **options, int num_options, int correct_option) {
    Question *new_question = (Question *) malloc(sizeof(Question));
    new_question->question = strdup(question);
    new_question->options = (char **) malloc(sizeof(char *) * num_options);
    for (int i = 0; i < num_options; i++) {
        new_question->options[i] = strdup(options[i]);
    }
    new_question->num_options = num_options;
    new_question->correct_option = correct_option;
    return new_question;
}

// Function to add a new question to the list of questions
void add_question(Question *question) {
    questions[num_questions++] = *question;
}

// Function to create a new student
Student *create_student(char *name) {
    Student *new_student = (Student *) malloc(sizeof(Student));
    new_student->name = strdup(name);
    new_student->score = 0;
    return new_student;
}

// Function to add a new student to the list of students
void add_student(Student *student) {
    students[num_students++] = *student;
}

// Function to print the list of questions
void print_questions() {
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < questions[i].num_options; j++) {
            printf("(%d) %s\n", j + 1, questions[i].options[j]);
        }
    }
}

// Function to take the exam
void take_exam() {
    int student_index = 0;
    int question_index = 0;
    int answer = 0;

    printf("Enter your name: ");
    char name[100];
    scanf("%s", name);

    Student *student = create_student(name);
    add_student(student);

    while (question_index < num_questions) {
        printf("\nQuestion %d: %s\n", question_index + 1, questions[question_index].question);
        for (int j = 0; j < questions[question_index].num_options; j++) {
            printf("(%d) %s\n", j + 1, questions[question_index].options[j]);
        }

        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == questions[question_index].correct_option) {
            student->score++;
        }

        question_index++;
    }
}

// Function to print the results
void print_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

// Main function
int main() {
    // Create questions
    Question *question1 = create_question("What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Berlin"}, 4, 1);
    Question *question2 = create_question("Who is the author of the Harry Potter series?", (char *[]){"J.K. Rowling", "Stephenie Meyer", "Suzanne Collins", "Veronica Roth"}, 4, 1);
    Question *question3 = create_question("What is the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 4, 1);
    Question *question4 = create_question("What is the chemical symbol for gold?", (char *[]){"Au", "Ag", "Cu", "Fe"}, 4, 1);
    Question *question5 = create_question("Who is the current President of the United States?", (char *[]){"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush"}, 4, 1);

    // Add questions to the list of questions
    add_question(question1);
    add_question(question2);
    add_question(question3);
    add_question(question4);
    add_question(question5);

    // Print the list of questions
    print_questions();

    // Take the exam
    take_exam();

    // Print the results
    print_results();

    return 0;
}