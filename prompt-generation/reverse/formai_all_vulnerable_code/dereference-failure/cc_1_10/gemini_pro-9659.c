//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question
typedef struct Question {
    char *question;
    char *options[4];
    char *correctAnswer;
} Question;

// Structure to store a student
typedef struct Student {
    char *name;
    int score;
} Student;

// Function to create a new question
Question *createQuestion(char *question, char *option1, char *option2, char *option3, char *option4, char *correctAnswer) {
    Question *newQuestion = (Question *) malloc(sizeof(Question));
    newQuestion->question = strdup(question);
    newQuestion->options[0] = strdup(option1);
    newQuestion->options[1] = strdup(option2);
    newQuestion->options[2] = strdup(option3);
    newQuestion->options[3] = strdup(option4);
    newQuestion->correctAnswer = strdup(correctAnswer);
    return newQuestion;
}

// Function to create a new student
Student *createStudent(char *name) {
    Student *newStudent = (Student *) malloc(sizeof(Student));
    newStudent->name = strdup(name);
    newStudent->score = 0;
    return newStudent;
}

// Function to add a question to the exam
void addQuestion(Question *question, Question **questions, int *numQuestions) {
    questions[*numQuestions] = question;
    (*numQuestions)++;
}

// Function to add a student to the exam
void addStudent(Student *student, Student **students, int *numStudents) {
    students[*numStudents] = student;
    (*numStudents)++;
}

// Function to administer the exam
void administerExam(Question **questions, int numQuestions, Student **students, int numStudents) {
    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i]->question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i]->options[j]);
        }
        printf("Enter your answer: ");
        int answer;
        scanf("%d", &answer);
        if (strcmp(questions[i]->correctAnswer, questions[i]->options[answer - 1]) == 0) {
            students[0]->score++;
        }
    }
}

// Function to print the results of the exam
void printResults(Student **students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i]->name, students[i]->score);
    }
}

int main() {
    // Create the questions
    Question *questions[] = {
        createQuestion("What is the capital of France?", "Paris", "London", "Rome", "Madrid", "Paris"),
        createQuestion("What is the largest ocean in the world?", "Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"),
        createQuestion("What is the highest mountain in the world?", "Mount Everest", "K2", "Kangchenjunga", "Lhotse", "Mount Everest"),
        createQuestion("What is the longest river in the world?", "Nile River", "Amazon River", "Mississippi River", "Yangtze River", "Nile River"),
        createQuestion("What is the largest desert in the world?", "Sahara Desert", "Gobi Desert", "Atacama Desert", "Antarctic Polar Desert", "Sahara Desert")
    };
    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    // Create the students
    Student *students[] = {
        createStudent("John Smith"),
        createStudent("Jane Doe")
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    // Add the questions and students to the exam
    for (int i = 0; i < numQuestions; i++) {
        addQuestion(questions[i], questions, &numQuestions);
    }
    for (int i = 0; i < numStudents; i++) {
        addStudent(students[i], students, &numStudents);
    }

    // Administer the exam
    administerExam(questions, numQuestions, students, numStudents);

    // Print the results of the exam
    printResults(students, numStudents);

    return 0;
}