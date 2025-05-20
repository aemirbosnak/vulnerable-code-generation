//FormAI DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/* Define a struct that will represent a student's record */
typedef struct {
    int student_id;
    char name[50];
    float grade;
} StudentRecord;

/* Define a function to initialize a student's record */
void initialize_student_record(StudentRecord* record, int id, char* name, float grade) {
    record->student_id = id;
    strcpy(record->name, name);
    record->grade = grade;
}

/* Define the main function */
int main() {
    int num_students = 0;
    
    /* Ask the user how many students they want to enter */
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    
    /* Allocate memory for the array of student records */
    StudentRecord* students = (StudentRecord*)malloc(sizeof(StudentRecord) * num_students);
    
    /* Loop through each student and ask for their information */
    for (int i = 0; i < num_students; i++) {
        int id;
        char name[50];
        float grade;
        
        printf("\nEnter student %d information:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf("%s", name);
        printf("Grade: ");
        scanf("%f", &grade);
        
        initialize_student_record(&students[i], id, name, grade);
    }
    
    /* Print out the records for all the students */
    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d\n", students[i].student_id);
        printf("Name: %s\n", students[i].name);
        printf("Grade: %.2f\n", students[i].grade);
    }
    
    /* Free the memory allocated for the array of student records */
    free(students);
    
    return 0;
}