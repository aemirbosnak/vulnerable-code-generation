//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the question and answer bank
const char* questionBank[10] = {"What is the capital of India?", "What is the meaning of life?", "What is the best programming language?", "What is the square root of 9?", "What is the length of a day on Jupiter?", "What is the speed of light in a vacuum?", "What is the number of moons in our solar system?", "What is the boiling point of water?", "What is the sum of the first 10 natural numbers?", "What is the maximum number of questions in an examination?"};
const char* answerBank[10] = {"Delhi", "42", "C++", "3", "9.54 hours", "299,792,458 meters per second", "8", "100 degrees Celsius", "55", "100"};

// Define the student and test taker class
struct Student {
    int id;
    int score;
};

struct TestTaker {
    struct Student* students;
    int numStudents;
    int numQuestions;
};

// Define the main function
int main() {
    // Initialize the test taker object
    struct TestTaker* testTaker = (struct TestTaker*)malloc(sizeof(struct TestTaker));
    testTaker->students = NULL;
    testTaker->numStudents = 0;
    testTaker->numQuestions = 10;

    // Randomly select questions and answers
    srand(time(NULL));
    int questionIndex = rand() % testTaker->numQuestions;
    int answerIndex = rand() % testTaker->numQuestions;

    // Print the selected question and answer
    printf("Question: %s\nAnswer: %s\n\n", questionBank[questionIndex], answerBank[answerIndex]);

    // Create a new student object
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    student->id = 0;
    student->score = 0;
    testTaker->students = (struct Student*)realloc(testTaker->students, testTaker->numStudents + 1 * sizeof(struct Student));
    testTaker->students[testTaker->numStudents++] = *student;

    // Grade the student's answer
    if (strcmp(answerBank[answerIndex], student->score) == 0) {
        student->score = 10;
        printf("Correct! Your score is now %d.\n", student->score);
    } else {
        printf("Incorrect! Your score is now %d.\n", student->score);
    }

    // Free the allocated memory
    free(student);
    free(testTaker);

    return 0;
}