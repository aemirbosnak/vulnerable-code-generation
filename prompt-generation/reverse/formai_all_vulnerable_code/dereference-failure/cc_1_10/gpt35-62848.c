//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    int id;
    char name[50];
    float cgpa;
} Student;

int main(){

    //Open database file
    FILE *fp = fopen("students.db", "rb");
    if(fp == NULL){
        printf("Error: could not open database.\n");
        exit(1);
    }

    //Calculate number of records in the database
    fseek(fp, 0, SEEK_END);
    int num_records = ftell(fp) / sizeof(Student);
    rewind(fp);

    //Allocate memory for all records
    Student *students = malloc(num_records * sizeof(Student));

    //Read all records into memory
    fread(students, sizeof(Student), num_records, fp);

    //Find the student with the highest CGPA
    float max_cgpa = -1;
    int max_cgpa_index = -1;
    for(int i=0; i<num_records; i++){
        if(students[i].cgpa > max_cgpa){
            max_cgpa = students[i].cgpa;
            max_cgpa_index = i;
        }
    }

    //Print details of the student with the highest CGPA
    printf("Student with highest CGPA:\n");
    printf("ID: %d\n", students[max_cgpa_index].id);
    printf("Name: %s\n", students[max_cgpa_index].name);
    printf("CGPA: %f\n", students[max_cgpa_index].cgpa);

    //Find all students with a CGPA greater than 3.5
    printf("\nStudents with CGPA greater than 3.5:\n");
    for(int i=0; i<num_records; i++){
        if(students[i].cgpa > 3.5){
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("CGPA: %f\n", students[i].cgpa);
            printf("\n");
        }
    }

    //Free memory and close file
    free(students);
    fclose(fp);

    return 0;
}