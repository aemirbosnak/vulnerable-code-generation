//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Question structure
typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

// Student structure
typedef struct {
    char *name;
    int score;
} Student;

// Function to create a new question
Question *create_question(char *question, char **options, int num_options, int correct_option) {
    Question *new_question = malloc(sizeof(Question));
    new_question->question = question;
    new_question->options = options;
    new_question->num_options = num_options;
    new_question->correct_option = correct_option;
    return new_question;
}

// Function to create a new student
Student *create_student(char *name) {
    Student *new_student = malloc(sizeof(Student));
    new_student->name = name;
    new_student->score = 0;
    return new_student;
}

// Function to print a question
void print_question(Question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < question->num_options; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

// Function to get the student's answer to a question
int get_student_answer(Question *question) {
    int answer;
    printf("Enter your answer (1-%d): ", question->num_options);
    scanf("%d", &answer);
    return answer;
}

// Function to grade a question
int grade_question(Question *question, int student_answer) {
    return student_answer == question->correct_option;
}

// Function to administer a quiz
void administer_quiz(Question **questions, int num_questions, Student *student) {
    for (int i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        int student_answer = get_student_answer(questions[i]);
        int score = grade_question(questions[i], student_answer);
        student->score += score;
    }
}

// Function to print the results of a quiz
void print_results(Student *student, int num_questions) {
    printf("Results for %s:\n", student->name);
    printf("Score: %d/%d\n", student->score, num_questions);
}

// Main function
int main() {
    // Create a set of questions
    Question *questions[] = {
        create_question("What is the capital of France?", (char *[]) {"Paris", "London", "Rome", "Berlin"}, 4, 1),
        create_question("What is the largest ocean in the world?", (char *[]) {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 4, 1),
        create_question("What is the most populous country in the world?", (char *[]) {"China", "India", "United States", "Indonesia"}, 4, 1),
    };
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Create a student
    Student *student = create_student("John Doe");

    // Administer the quiz
    administer_quiz(questions, num_questions, student);

    // Print the results
    print_results(student, num_questions);

    return 0;
}