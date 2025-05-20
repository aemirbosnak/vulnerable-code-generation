//FormAI DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to hold a student's data
typedef struct Student {
    char name[50];
    int age;
    float gpa;
    char major[50];
} Student;

// Create an index table to store pointers to students
typedef struct IndexTable {
    int numEntries;
    Student **table;
} IndexTable;

// Function to initialize an empty index table
IndexTable *initIndexTable(int n) {
    IndexTable *table = (IndexTable*)malloc(sizeof(IndexTable));
    table->numEntries = 0;
    table->table = (Student**)malloc(n * sizeof(Student*));
    return table;
}

// Function to add a student to the index table
void addToIndexTable(IndexTable *table, Student *student) {
    table->table[table->numEntries] = student;
    table->numEntries++;
}

// Quick sort function
void quickSort(Student **students, int start, int end) {
    if (start < end) {
        // Pick a pivot
        int pivot = (start + end) / 2;
        // Partition the array around the pivot
        int left = start;
        int right = end;
        while (left <= right) {
            while (students[left]->gpa > students[pivot]->gpa) {
                left++;
            }
            while (students[right]->gpa < students[pivot]->gpa) {
                right--;
            }
            if (left <= right) {
                // Swap the two elements
                Student *temp = students[left];
                students[left] = students[right];
                students[right] = temp;
                left++;
                right--;
            }
        }
        // Recursively sort the left and right halves
        quickSort(students, start, right);
        quickSort(students, left, end);
    }
}

int main() {
    // Create some sample students
    Student *s1 = (Student*)malloc(sizeof(Student));
    strcpy(s1->name, "Alice");
    s1->age = 20;
    s1->gpa = 3.5;
    strcpy(s1->major, "Computer Science");

    Student *s2 = (Student*)malloc(sizeof(Student));
    strcpy(s2->name, "Bob");
    s2->age = 21;
    s2->gpa = 3.2;
    strcpy(s2->major, "Biology");

    Student *s3 = (Student*)malloc(sizeof(Student));
    strcpy(s3->name, "Charlie");
    s3->age = 19;
    s3->gpa = 3.8;
    strcpy(s3->major, "Mathematics");

    // Initialize an empty index table
    IndexTable *table = initIndexTable(3);

    // Add the students to the index table
    addToIndexTable(table, s1);
    addToIndexTable(table, s2);
    addToIndexTable(table, s3);

    // Sort the students in the index table by GPA
    quickSort(table->table, 0, table->numEntries - 1);

    // Print out the students in the index table
    printf("Students sorted by GPA:\n");
    for (int i = 0; i < table->numEntries; i++) {
        printf("%s (%s, age %d): %.2f GPA\n", table->table[i]->name, table->table[i]->major, table->table[i]->age, table->table[i]->gpa);
    }

    // Free memory
    free(s1);
    free(s2);
    free(s3);
    free(table->table);
    free(table);

    return 0;
}