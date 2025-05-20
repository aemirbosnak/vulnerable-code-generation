//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 50

// Student structure
typedef struct Student
{
    char name[50];
    int rollNo;
    float marks[MAX_QUESTIONS];
} Student;

// Question structure
typedef struct Question
{
    char question[255];
    int marks;
} Question;

// Function to create a student
Student* createStudent()
{
    Student* student = (Student*)malloc(sizeof(Student));

    // Get the student's name and roll number
    printf("Enter student's name: ");
    scanf("%s", student->name);

    printf("Enter student's roll number: ");
    scanf("%d", &student->rollNo);

    return student;
}

// Function to create a question
Question* createQuestion()
{
    Question* question = (Question*)malloc(sizeof(Question));

    // Get the question's text and marks
    printf("Enter question text: ");
    scanf("%[^\n]%*c", question->question);

    printf("Enter marks for the question: ");
    scanf("%d", &question->marks);

    return question;
}

// Function to calculate student's total marks
float calculateTotalMarks(Student* student)
{
    float totalMarks = 0;

    // Calculate the total marks for each question
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        totalMarks += student->marks[i];
    }

    return totalMarks;
}

// Function to print student's marks
void printMarks(Student* student)
{
    // Print the student's name and roll number
    printf("Student's name: %s\n", student->name);
    printf("Student's roll number: %d\n", student->rollNo);

    // Print the student's marks for each question
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Question %d: %f\n", i + 1, student->marks[i]);
    }

    // Print the student's total marks
    printf("Total marks: %f\n", calculateTotalMarks(student));
}

int main()
{
    // Create a student
    Student* student = createStudent();

    // Create a question
    Question* question = createQuestion();

    // Print the student's marks
    printMarks(student);

    return 0;
}