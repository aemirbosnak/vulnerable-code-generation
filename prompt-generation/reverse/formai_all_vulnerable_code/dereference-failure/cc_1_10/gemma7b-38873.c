//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the futuristic examination system
typedef struct ExamSystem {
    char student_name[50];
    int student_id;
    float marks[5];
    struct ExamSystem* next;
} ExamSystem;

// Function to create a new examination system node
ExamSystem* createExamSystem(char* student_name, int student_id, float marks[]) {
    ExamSystem* new_exam_system = (ExamSystem*)malloc(sizeof(ExamSystem));
    strcpy(new_exam_system->student_name, student_name);
    new_exam_system->student_id = student_id;
    memcpy(new_exam_system->marks, marks, 5 * sizeof(float));
    new_exam_system->next = NULL;
    return new_exam_system;
}

// Function to insert a new examination system node at the end
void insertExamSystem(ExamSystem* exam_system, char* student_name, int student_id, float marks[]) {
    ExamSystem* new_exam_system = createExamSystem(student_name, student_id, marks);
    if (exam_system == NULL) {
        exam_system = new_exam_system;
    } else {
        exam_system->next = new_exam_system;
        exam_system = new_exam_system;
    }
}

// Function to print the examination system
void printExamSystem(ExamSystem* exam_system) {
    while (exam_system) {
        printf("Student Name: %s\n", exam_system->student_name);
        printf("Student ID: %d\n", exam_system->student_id);
        printf("Marks:\n");
        for (int i = 0; i < 5; i++) {
            printf("  %f\n", exam_system->marks[i]);
        }
        printf("\n");
        exam_system = exam_system->next;
    }
}

int main() {
    ExamSystem* exam_system = NULL;

    // Insert some examination system nodes
    insertExamSystem(exam_system, "John Doe", 1234, (float[]){90, 80, 70, 95, 85});
    insertExamSystem(exam_system, "Jane Doe", 5678, (float[]){80, 90, 85, 90, 80});
    insertExamSystem(exam_system, "Peter Pan", 2468, (float[]){70, 80, 90, 85, 90});

    // Print the examination system
    printExamSystem(exam_system);

    return 0;
}