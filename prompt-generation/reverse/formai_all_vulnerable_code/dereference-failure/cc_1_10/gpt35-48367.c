//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int id;
    char name[50];
    char major[50];
    double gpa;
} Student;

// Index struct to map ID to position in db file
typedef struct index {
    int id;
    long position;
} Index;

// Function to compare two indexes for sorting
int compare_indexes(const void* a, const void* b) {
    Index* index_a = (Index*) a;
    Index* index_b = (Index*) b;
    return index_a->id - index_b->id;
}

int main() {
    int num_students = 0;
    char filename[50];
    
    // Get user input for number of students and filename
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    printf("Enter filename: ");
    scanf("%s", filename);
    
    // Create db file and index file
    FILE* db_file = fopen(filename, "w+b");
    FILE* index_file = fopen("index.bin", "w+b");
    
    // Allocate memory for students and indexes
    Student* students = malloc(num_students * sizeof(Student));
    Index* indexes = malloc(num_students * sizeof(Index));
    
    // Initialize students and indexes arrays with user input
    for(int i = 0; i < num_students; i++) {
        printf("Enter student ID: ");
        scanf("%d", &students[i].id);
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        printf("Enter student major: ");
        scanf("%s", students[i].major);
        printf("Enter student GPA: ");
        scanf("%lf", &students[i].gpa);
        
        // Save student record to db file
        long position = ftell(db_file);
        fwrite(&students[i], sizeof(Student), 1, db_file);
        
        // Save index record to index file
        Index index = {students[i].id, position};
        fwrite(&index, sizeof(Index), 1, index_file);
    }
    
    // Sort indexes by ID for efficient searching
    qsort(indexes, num_students, sizeof(Index), compare_indexes);
    
    // Search for a student record by ID
    int search_id;
    printf("Enter student ID to search for: ");
    scanf("%d", &search_id);
    
    int found_index = -1;
    int left = 0, right = num_students - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(indexes[mid].id == search_id) {
            found_index = mid;
            break;
        } else if(indexes[mid].id < search_id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if(found_index == -1) {
        printf("Student record not found\n");
    } else {
        // Seek to position of student record in db file
        fseek(db_file, indexes[found_index].position, SEEK_SET);
        
        // Read the student record from db file
        Student found_student;
        fread(&found_student, sizeof(Student), 1, db_file);
        
        // Print the student record
        printf("Found student record:\n");
        printf("ID: %d\n", found_student.id);
        printf("Name: %s\n", found_student.name);
        printf("Major: %s\n", found_student.major);
        printf("GPA: %.2f\n", found_student.gpa);
    }
    
    // Close files and free memory
    fclose(db_file);
    fclose(index_file);
    free(students);
    free(indexes);
    
    return 0;
}