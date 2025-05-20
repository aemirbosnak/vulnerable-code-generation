//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student data
typedef struct {
    char name[50];
    float grades[5]; // 5 subjects
    float average;
} Student;

// Function to calculate the average of grades
float calculate_average(float grades[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum / size;
}

// Function to visualize grades of all students
void visualize_grades(Student *students, int num_students) {
    printf("\nGrade Visualization\n");
    printf("---------------------\n");
    
    for (int i = 0; i < num_students; i++) {
        printf("%s: ", students[i].name);
        int grade_count = sizeof(students[i].grades) / sizeof(students[i].grades[0]);
        for (int j = 0; j < grade_count; j++) {
            for (int k = 0; k < (int)(students[i].grades[j] / 10); k++) {
                printf("#");
            }
            printf(" (%.1f) ", students[i].grades[j]);
        }
        printf(" | Average: %.2f\n", students[i].average);
    }
}

int main() {
    int num_students = 3; // Number of students
    Student *students = malloc(num_students * sizeof(Student));

    // Sample data for students
    strcpy(students[0].name, "Alice");
    students[0].grades[0] = 88; // Mathematics
    students[0].grades[1] = 92; // Physics
    students[0].grades[2] = 85; // Chemistry
    students[0].grades[3] = 90; // Biology
    students[0].grades[4] = 95; // English

    strcpy(students[1].name, "Bob");
    students[1].grades[0] = 78; 
    students[1].grades[1] = 82; 
    students[1].grades[2] = 88; 
    students[1].grades[3] = 89; 
    students[1].grades[4] = 91; 

    strcpy(students[2].name, "Charlie");
    students[2].grades[0] = 90; 
    students[2].grades[1] = 94; 
    students[2].grades[2] = 86; 
    students[2].grades[3] = 87; 
    students[2].grades[4] = 93; 

    // Calculate averages
    for (int i = 0; i < num_students; i++) {
        students[i].average = calculate_average(students[i].grades, 5);
    }

    // Visualize grades
    visualize_grades(students, num_students);

    // Cleanup
    free(students);
    return 0;
}