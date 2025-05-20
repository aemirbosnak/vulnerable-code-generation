//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for Question and Student
struct Question {
    char* question;
    char* optionA;
    char* optionB;
    char* optionC;
    char* optionD;
};

struct Student {
    char* name;
    int age;
};

// Define function prototypes
void printQuestion(struct Question question);
void printStudent(struct Student student);
void generateRandomQuestion(struct Question* question);
void generateRandomStudent(struct Student* student);
void printRandomQuestion(struct Question question);
void printRandomStudent(struct Student student);
void printScore(int score);

// Main function
int main() {
    struct Question question;
    struct Student student;

    // Generate random question
    generateRandomQuestion(&question);

    // Print random question
    printf("Question: %s\n", question.question);

    // Generate random student
    generateRandomStudent(&student);

    // Print random student
    printf("Student: %s (Age: %d)\n", student.name, student.age);

    // Take exam
    int score = 0;

    // Ask question and get answer
    printf("Answer: ");
    char answer[100];
    scanf("%s", answer);

    if (strcmp(answer, question.optionA) == 0) {
        score++;
    } else if (strcmp(answer, question.optionB) == 0) {
        score++;
    } else if (strcmp(answer, question.optionC) == 0) {
        score++;
    } else if (strcmp(answer, question.optionD) == 0) {
        score++;
    } else {
        printf("Incorrect answer!\n");
    }

    // Print score
    printf("Score: %d\n", score);

    // Print random question again
    printRandomQuestion(question);

    // Print random student again
    printRandomStudent(student);

    return 0;
}

// Function to generate random question
void generateRandomQuestion(struct Question* question) {
    question->question = (char*)malloc(100 * sizeof(char));
    srand(time(NULL));
    sprintf(question->question, "Question %d: %s", rand() % 100, "A random question");
    question->optionA = (char*)malloc(100 * sizeof(char));
    sprintf(question->optionA, "Option A: %s", "Option A");
    question->optionB = (char*)malloc(100 * sizeof(char));
    sprintf(question->optionB, "Option B: %s", "Option B");
    question->optionC = (char*)malloc(100 * sizeof(char));
    sprintf(question->optionC, "Option C: %s", "Option C");
    question->optionD = (char*)malloc(100 * sizeof(char));
    sprintf(question->optionD, "Option D: %s", "Option D");
}

// Function to generate random student
void generateRandomStudent(struct Student* student) {
    student->name = (char*)malloc(100 * sizeof(char));
    srand(time(NULL));
    sprintf(student->name, "Student %d: %s", rand() % 100, "A random name");
    student->age = rand() % 100;
}

// Function to print random question
void printRandomQuestion(struct Question question) {
    printf("Question: %s\n", question.question);
}

// Function to print random student
void printRandomStudent(struct Student student) {
    printf("Student: %s (Age: %d)\n", student.name, student.age);
}

// Function to print score
void printScore(int score) {
    printf("Score: %d\n", score);
}