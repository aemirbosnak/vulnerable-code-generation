//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to create a file
void createFile(char* filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "This is an example file.\n");
    fprintf(fp, "It is used to demonstrate C file handling.\n");
    fprintf(fp, "You can use it to test various file handling functions.\n");
    fclose(fp);
    printf("File created successfully.\n");
}

// Function to read from a file
void readFile(char* filename) {
    FILE *fp;
    char buff[255];
    fp = fopen(filename, "r");
    while (fgets(buff, 255, fp)) {
        printf("%s", buff);
    }
    fclose(fp);
}

// Function to write to a file
void writeFile(char* filename) {
    FILE *fp;
    char buff[255];
    printf("Enter some text:\n");
    fgets(buff, 255, stdin);
    fp = fopen(filename, "a");
    fprintf(fp, "%s\n", buff);
    fclose(fp);
    printf("Text written to file successfully.\n");
}

// Function to delete a file
void deleteFile(char* filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Unable to delete the file.\n");
    }
}

// Main function
int main() {
    char filename[] = "example.txt";
    int choice;
    printf("Welcome to the file handling example program!\n");
    printf("What would you like to do?\n");
    printf("1. Create a file\n");
    printf("2. Read from a file\n");
    printf("3. Write to a file\n");
    printf("4. Delete a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2:
            readFile(filename);
            break;
        case 3:
            writeFile(filename);
            break;
        case 4:
            deleteFile(filename);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}