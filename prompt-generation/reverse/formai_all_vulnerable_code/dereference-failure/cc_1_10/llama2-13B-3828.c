//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MIN_AGE 18
#define MAX_GPA 4.0
#define MIN_GPA 2.0
#define MAX_HEIGHT 2.00
#define MIN_HEIGHT 1.50
#define MAX_WEIGHT 100.0
#define MIN_WEIGHT 40.0

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
    double height;
    double weight;
} Student;

// Function to print a cheerful message
void print_cheerful_message(void) {
    printf("Hello there, young student! I hope you're ready to learn some cool stuff today! 😄\n");
}

// Function to create a new student
Student *create_student(void) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    printf("Welcome to the party, new student! 🎉\n");
    // Ask for the student's name
    printf("What's your name, my dear? 🤔\n");
    fgets(new_student->name, MAX_NAME_LENGTH, stdin);
    // Ask for the student's age
    printf("Ah, I see! How old are you? 🤷‍♀️\n");
    scanf("%d", &new_student->age);
    // Ask for the student's GPA
    printf("Excellent! What's your GPA looking like? 📝\n");
    scanf("%lf", &new_student->gpa);
    // Ask for the student's height and weight
    printf("Great, let's get physical! 🏋️‍♀️ How tall are you? 👩‍🦰\n");
    scanf("%lf", &new_student->height);
    printf("And how much do you weigh? 💪🏼\n");
    scanf("%lf", &new_student->weight);
    return new_student;
}

// Function to print student information in a cheerful way
void print_student_info(Student *student) {
    printf("Hey there, %s! 👋\n", student->name);
    printf("You're %d years young and looking fabulous! 💃\n", student->age);
    printf("Your GPA is looking sharp, %lf! 📝\n", student->gpa);
    printf("You're %lf meters tall and weigh %lf kilograms. 💪🏼\n", student->height, student->weight);
}

// Main function
int main(void) {
    // Create a new student
    Student *student = create_student();
    // Print the student's information in a cheerful way
    print_student_info(student);
    // Free the student's memory
    free(student);
    return 0;
}