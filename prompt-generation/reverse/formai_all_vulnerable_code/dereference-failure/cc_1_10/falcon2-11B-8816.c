//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a directory
void create_directory(char *dir_path) {
    FILE *fp;
    char buffer[256];

    // Check if the directory already exists
    if ((fp = fopen(dir_path, "r"))!= NULL) {
        printf("Directory %s already exists.\n", dir_path);
        return;
    }

    // Create the directory
    sprintf(buffer, "mkdir %s", dir_path);
    system(buffer);

    // Check if the directory was created successfully
    if ((fp = fopen(dir_path, "r")) == NULL) {
        printf("Failed to create directory %s.\n", dir_path);
        return;
    }
    printf("Directory %s created successfully.\n", dir_path);

    fclose(fp);
}

// Function to list files in a directory
void list_files(char *dir_path) {
    FILE *fp;
    char buffer[256];

    // Check if the directory exists
    if ((fp = fopen(dir_path, "r")) == NULL) {
        printf("Directory %s does not exist.\n", dir_path);
        return;
    }

    // List the files in the directory
    sprintf(buffer, "ls -l %s", dir_path);
    system(buffer);

    fclose(fp);
}

// Function to delete a file
void delete_file(char *file_path) {
    FILE *fp;
    char buffer[256];

    // Check if the file exists
    if ((fp = fopen(file_path, "r")) == NULL) {
        printf("File %s does not exist.\n", file_path);
        return;
    }

    // Delete the file
    sprintf(buffer, "rm %s", file_path);
    system(buffer);

    fclose(fp);
}

int main() {
    // Create a directory
    create_directory("new_directory");

    // List the files in the directory
    list_files("new_directory");

    // Delete a file
    delete_file("new_directory/file.txt");

    return 0;
}