//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the data 
typedef struct {
    int id;
    char name[50];
} Record;

// Function prototypes
void initializeRecords(Record *records, int size);
void displayRecords(Record *records, int size);
int linearSearch(Record *records, int size, int id);
int binarySearch(Record *records, int left, int right, int id);
int compareRecords(const void *a, const void *b);

int main() {
    int size = 10;
    Record *records = malloc(size * sizeof(Record));

    // Initialize records with some values
    initializeRecords(records, size);
    printf("All Records:\n");
    displayRecords(records, size);

    // Perform a linear search
    int searchId = 5;
    int linearResult = linearSearch(records, size, searchId);
    if (linearResult != -1) {
        printf("Linear Search: Record with ID %d found: %s\n", records[linearResult].id, records[linearResult].name);
    } else {
        printf("Linear Search: Record with ID %d not found.\n", searchId);
    }

    // Sort records for binary search
    qsort(records, size, sizeof(Record), compareRecords);
    printf("\nRecords sorted for binary search:\n");
    displayRecords(records, size);

    // Perform a binary search
    int binaryResult = binarySearch(records, 0, size - 1, searchId);
    if (binaryResult != -1) {
        printf("Binary Search: Record with ID %d found: %s\n", records[binaryResult].id, records[binaryResult].name);
    } else {
        printf("Binary Search: Record with ID %d not found.\n", searchId);
    }

    // Clean up
    free(records);
    return 0;
}

// Function to initialize the records with sample data
void initializeRecords(Record *records, int size) {
    for (int i = 0; i < size; i++) {
        records[i].id = i;
        snprintf(records[i].name, sizeof(records[i].name), "Record %d", i);
    }
}

// Function to display the records
void displayRecords(Record *records, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", records[i].id, records[i].name);
    }
}

// Linear search function
int linearSearch(Record *records, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (records[i].id == id) {
            return i; // return the index
        }
    }
    return -1; // Not found
}

// Binary search function
int binarySearch(Record *records, int left, int right, int id) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the element at mid is the id
        if (records[mid].id == id) {
            return mid;
        }
        // If id is greater, ignore the left half
        if (records[mid].id < id) {
            left = mid + 1;
        }
        // If id is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

// Comparison function for qsort
int compareRecords(const void *a, const void *b) {
    return ((Record *)a)->id - ((Record *)b)->id;
}