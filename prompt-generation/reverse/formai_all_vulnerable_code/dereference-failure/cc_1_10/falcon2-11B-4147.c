//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Define a structure to store student information
typedef struct {
    char name[50];
    int roll_no;
    int marks;
} Student;

// Define a structure to store question information
typedef struct {
    char question[100];
    char answer[100];
} Question;

// Define a structure to store exam information
typedef struct {
    int num_questions;
    int num_students;
    Question* questions;
    Student* students;
} Exam;

// Function to read student information from the command line
void read_student_info(int argc, char* argv[], Student* student) {
    if (argc!= 4) {
        printf("Usage: %s <name> <roll_no> <marks>\n", argv[0]);
        exit(1);
    }

    strcpy(student->name, argv[1]);
    student->roll_no = atoi(argv[2]);
    student->marks = atoi(argv[3]);
}

// Function to read question information from the command line
void read_question_info(int argc, char* argv[], Question* question) {
    if (argc!= 3) {
        printf("Usage: %s <question> <answer>\n", argv[0]);
        exit(1);
    }

    strcpy(question->question, argv[1]);
    strcpy(question->answer, argv[2]);
}

// Function to read exam information from the command line
void read_exam_info(int argc, char* argv[], Exam* exam) {
    if (argc!= 3) {
        printf("Usage: %s <num_questions> <num_students>\n", argv[0]);
        exit(1);
    }

    exam->num_questions = atoi(argv[1]);
    exam->num_students = atoi(argv[2]);
    exam->questions = malloc(exam->num_questions * sizeof(Question));
    exam->students = malloc(exam->num_students * sizeof(Student));
}

// Function to print student information
void print_student_info(Student student) {
    printf("Name: %s\nRoll No.: %d\nMarks: %d\n", student.name, student.roll_no, student.marks);
}

// Function to print question information
void print_question_info(Question question) {
    printf("Question: %s\nAnswer: %s\n", question.question, question.answer);
}

// Function to print exam information
void print_exam_info(Exam exam) {
    printf("Number of Questions: %d\nNumber of Students: %d\n", exam.num_questions, exam.num_students);
    for (int i = 0; i < exam.num_questions; i++) {
        print_question_info(exam.questions[i]);
    }
    for (int i = 0; i < exam.num_students; i++) {
        print_student_info(exam.students[i]);
    }
}

// Function to run the exam
void run_exam(Exam exam) {
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d: %s\n", i+1, exam.questions[i].question);
        char answer[100];
        printf("Enter your answer: ");
        fgets(answer, sizeof(answer), stdin);
        if (strcmp(answer, exam.questions[i].answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
    }
    printf("Exam complete.\n");
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <num_questions> <num_students>\n", argv[0]);
        exit(1);
    }

    Exam exam;
    read_exam_info(argc, argv, &exam);

    // Create and read student and question information
    for (int i = 0; i < exam.num_students; i++) {
        Student student;
        read_student_info(argc, argv, &student);
        exam.students[i] = student;
    }
    for (int i = 0; i < exam.num_questions; i++) {
        Question question;
        read_question_info(argc, argv, &question);
        exam.questions[i] = question;
    }

    // Run the exam
    run_exam(exam);

    return 0;
}