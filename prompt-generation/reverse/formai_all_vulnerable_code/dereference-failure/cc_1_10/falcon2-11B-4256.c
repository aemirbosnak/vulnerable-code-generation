//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a file
struct File {
    char* name;
    char* content;
};

// Function to open a file
struct File* openFile(char* filename) {
    struct File* f = (struct File*)malloc(sizeof(struct File));
    f->name = strdup(filename);
    f->content = NULL;
    return f;
}

// Function to read from a file
void readFromFile(struct File* f) {
    printf("Reading from file %s...\n", f->name);
    // Read the content of the file and store it in the variable 'content'
    f->content = (char*)malloc(sizeof(char) * 100);
    FILE* fp = fopen(f->name, "r");
    fscanf(fp, "%s", f->content);
    fclose(fp);
}

// Function to write to a file
void writeToFile(struct File* f, char* content) {
    printf("Writing to file %s...\n", f->name);
    // Write the content to the file using the variable 'content'
    FILE* fp = fopen(f->name, "w");
    fprintf(fp, "%s", content);
    fclose(fp);
}

// Function to delete a file
void deleteFile(struct File* f) {
    printf("Deleting file %s...\n", f->name);
    // Delete the file using the variable 'f'
    remove(f->name);
}

// Function to close a file
void closeFile(struct File* f) {
    printf("Closing file %s...\n", f->name);
    // Free the memory allocated for the content of the file
    free(f->content);
    // Free the memory allocated for the name of the file
    free(f->name);
    // Free the memory allocated for the file structure
    free(f);
}

int main() {
    // Create a file named 'a'
    struct File* fileA = openFile("a");

    // Read from the file
    readFromFile(fileA);

    // Write to the file
    char content[] = "Hello, world!";
    writeToFile(fileA, content);

    // Close the file
    closeFile(fileA);

    // Delete the file
    deleteFile(fileA);

    return 0;
}