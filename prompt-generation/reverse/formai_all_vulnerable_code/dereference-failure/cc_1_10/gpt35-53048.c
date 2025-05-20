//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the indexed data
typedef struct {
    int key;
    char value[20];
} IndexedData;

// Create the structure for the database index
typedef struct {
    int size;
    IndexedData* data;
} DatabaseIndex;

// Function to initialize the database index
DatabaseIndex* initializeIndex(int size) {
    DatabaseIndex* index = malloc(sizeof(DatabaseIndex));
    index->size = size;
    index->data = malloc(size * sizeof(IndexedData));
    return index;
}

// Function to insert data into the database index
void insertData(DatabaseIndex* index, int key, char* value) {
    // Find the appropriate index for the new data based on its key
    int i = 0;
    while (i < index->size && index->data[i].key < key) {
        i++;
    }
    // Shift all of the data with greater keys than the new data to the right
    for (int j = index->size - 1; j > i; j--) {
        index->data[j] = index->data[j - 1];
    }
    // Insert the new data at the appropriate index
    index->data[i].key = key;
    sprintf(index->data[i].value, "%s", value);
}

// Function to search for data in the database index based on its key
char* searchData(DatabaseIndex* index, int key) {
    // Use binary search to find the data with the specified key
    int low = 0;
    int high = index->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (index->data[mid].key == key) {
            return index->data[mid].value;
        }
        else if (index->data[mid].key < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return "Not found";
}

// Function to print the contents of the database index
void printIndex(DatabaseIndex* index) {
    for (int i = 0; i < index->size; i++) {
        printf("%d: %s\n", index->data[i].key, index->data[i].value);
    }
}

int main() {
    // Initialize the database index with a size of 10
    DatabaseIndex* index = initializeIndex(10);

    // Insert some data into the index
    insertData(index, 5, "value1");
    insertData(index, 2, "value2");
    insertData(index, 7, "value3");
    insertData(index, 3, "value4");
    insertData(index, 8, "value5");

    // Print the contents of the index
    printf("Index contents:\n");
    printIndex(index);

    // Search for some data in the index
    printf("Searching for key 7: %s\n", searchData(index, 7));
    printf("Searching for key 4: %s\n", searchData(index, 4));

    return 0;
}