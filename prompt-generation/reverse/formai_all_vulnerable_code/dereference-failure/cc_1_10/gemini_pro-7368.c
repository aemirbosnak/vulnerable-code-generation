//GEMINI-pro DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student record
typedef struct {
    char name[50];
    int roll_number;
    float marks;
} student_record;

// Define a function to read student records from a file
int read_student_records(char *filename, student_record *records, int *num_records) {
    // Open the file for reading in binary mode
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the number of records from the file
    fread(num_records, sizeof(int), 1, fp);

    // Allocate memory to store the records
    records = malloc(*num_records * sizeof(student_record));

    // Read the records from the file
    fread(records, sizeof(student_record), *num_records, fp);

    // Close the file
    fclose(fp);

    return 0;
}

// Define a function to write student records to a file
int write_student_records(char *filename, student_record *records, int num_records) {
    // Open the file for writing in binary mode
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the number of records to the file
    fwrite(&num_records, sizeof(int), 1, fp);

    // Write the records to the file
    fwrite(records, sizeof(student_record), num_records, fp);

    // Close the file
    fclose(fp);

    return 0;
}

int main() {
    // Define an array of student records
    student_record records[100];

    // Read the student records from a file
    int num_records;
    if (read_student_records("students.dat", records, &num_records) == -1) {
        return -1;
    }

    // Print the student records
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Roll number: %d\n", records[i].roll_number);
        printf("Marks: %.2f\n\n", records[i].marks);
    }

    // Add a new student record
    student_record new_record;
    strcpy(new_record.name, "John Doe");
    new_record.roll_number = 101;
    new_record.marks = 85.5;

    // Append the new record to the array
    records[num_records] = new_record;
    num_records++;

    // Write the updated student records to a file
    if (write_student_records("students.dat", records, num_records) == -1) {
        return -1;
    }

    return 0;
}