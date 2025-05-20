//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a struct for storing data
struct data {
    int id;
    char name[20];
};

// Define a struct for storing index
struct index {
    int id;
    int offset;
};

// Function for creating index from data
void createIndexFromFile(FILE* fp, struct index** indexArray, int* count) {
    // Define buffer and variables
    char buffer[100];
    struct data d;
    int i = 0;
    int j = 0;
    
    // Get the size of file
    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);
    *count = fileSize / sizeof(struct data);
    
    // Allocate memory for index
    *indexArray = (struct index*) malloc((*count) * sizeof(struct index));
    fseek(fp, 0L, SEEK_SET);
    
    // Loop through file and create index
    while (fgets(buffer, 100, fp)) {
        sscanf(buffer, "%d %s", &(d.id), d.name);
        (*indexArray)[i].id = d.id;
        (*indexArray)[i].offset = j;
        i++;
        j += sizeof(struct data);
    }
}

// Function for searching data using index
void searchDataFromIndex(FILE* fp, struct index* indexArray, int count, int searchId) {
    // Define buffer and variables
    char buffer[100];
    struct data d;
    int i = 0;
    int found = 0;
    int start = 0;
    int end = count - 1;
    int middle;
    
    // Perform binary search in index
    while (start <= end) {
        middle = (start + end) / 2;
        if (indexArray[middle].id == searchId) {
            found = 1;
            fseek(fp, indexArray[middle].offset, SEEK_SET);
            fgets(buffer, 100, fp);
            sscanf(buffer, "%d %s", &(d.id), d.name);
            printf("Data found: %d %s\n", d.id, d.name);
            break;
        }
        else if (indexArray[middle].id > searchId) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    
    if (!found) {
        printf("Data not found.\n");
    }
}

int main() {
    // Open data file
    FILE* data_file;
    data_file = fopen("data.txt", "r");
    
    if (data_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Create index from data
    struct index* indexArray;
    int count;
    createIndexFromFile(data_file, &indexArray, &count);
    
    // Search data using index
    searchDataFromIndex(data_file, indexArray, count, 3);

    // Close file and free memory
    fclose(data_file);
    free(indexArray);

    return 0;
}