//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold information about a student */
typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

/* Define a struct to hold information about an index record */
typedef struct {
    int key;
    long offset;
} IndexRecord;

/* Define a struct to hold information about an index */
typedef struct {
    int num_records;
    IndexRecord *records;
} Index;

/* Function to compare two IndexRecords by key */
int compare_index_records(const void *a, const void *b) {
    const IndexRecord *ra = (const IndexRecord *) a;
    const IndexRecord *rb = (const IndexRecord *) b;
    if (ra->key < rb->key)
        return -1;
    else if (ra->key > rb->key)
        return 1;
    else
        return 0;
}

/* Function to create an index from a file containing student records */
Index *create_index(char *filename) {
    FILE *fp;
    Student student;
    Index *index = malloc(sizeof(Index));
    int num_records = 0;
    long offset = 0;

    /* Open the file for reading */
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    /* Count the number of records in the file */
    while (fread(&student, sizeof(Student), 1, fp) == 1)
        num_records++;

    /* Allocate memory for the index records */
    index->num_records = num_records;
    index->records = malloc(num_records * sizeof(IndexRecord));

    /* Reset the file pointer */
    fseek(fp, 0L, SEEK_SET);

    /* Read each student record and add it to the index */
    while (fread(&student, sizeof(Student), 1, fp) == 1) {
        index->records[offset].key = student.id;
        index->records[offset].offset = offset * sizeof(Student);
        offset++;
    }

    /* Sort the index records by key */
    qsort(index->records, num_records, sizeof(IndexRecord),
          compare_index_records);

    /* Close the file */
    fclose(fp);

    return index;
}

/* Function to retrieve a student record using an index */
Student *get_student(Index *index, int id, char *filename) {
    FILE *fp;
    Student *student = malloc(sizeof(Student));
    long offset;
    int low, high, mid, found;

    /* Open the file for reading */
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    /* Perform binary search to find the index record with the key */
    low = 0;
    high = index->num_records - 1;
    found = 0;
    while (low <= high && !found) {
        mid = (low + high) / 2;
        if (index->records[mid].key == id) {
            offset = index->records[mid].offset;
            found = 1;
        } else if (index->records[mid].key < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    /* If the key was found, seek to the offset in the file and read the record */
    if (found) {
        fseek(fp, offset, SEEK_SET);
        fread(student, sizeof(Student), 1, fp);
    } else {
        printf("Could not find student with ID %d\n", id);
        student = NULL;
    }

    /* Close the file */
    fclose(fp);

    return student;
}

int main(int argc, char **argv) {
    Index *index;
    Student *student;

    /* Create an index from the student data file */
    index = create_index("students.bin");

    /* Get a student record by ID using the index */
    student = get_student(index, 12345, "students.bin");
    if (student != NULL)
        printf("Student name: %s\nStudent GPA: %.2f\n", student->name, student->gpa);

    free(student);
    free(index);

    return 0;
}