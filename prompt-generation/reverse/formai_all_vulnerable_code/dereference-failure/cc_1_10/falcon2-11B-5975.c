//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 256

// Function to create a directory
void create_directory(char *path) {
    char command[MAX_PATH_LENGTH];
    sprintf(command, "mkdir %s", path);
    system(command);
}

// Function to remove a directory
void remove_directory(char *path) {
    char command[MAX_PATH_LENGTH];
    sprintf(command, "rm -rf %s", path);
    system(command);
}

// Function to create a file
void create_file(char *path, char *content) {
    char command[MAX_PATH_LENGTH];
    sprintf(command, "touch %s", path);
    system(command);
    FILE *fp = fopen(path, "w");
    if (fp!= NULL) {
        fputs(content, fp);
        fclose(fp);
    }
}

// Function to read a file
void read_file(char *path) {
    FILE *fp = fopen(path, "r");
    if (fp!= NULL) {
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char buffer[size];
        if (fread(buffer, 1, size, fp)!= size) {
            printf("Error reading file.\n");
            return;
        }
        fclose(fp);
        printf("%s", buffer);
    } else {
        printf("Error opening file.\n");
    }
}

int main() {
    char path1[MAX_PATH_LENGTH];
    create_directory(path1);
    create_file(path1, "This is a test file.");
    read_file(path1);
    remove_directory(path1);
    return 0;
}