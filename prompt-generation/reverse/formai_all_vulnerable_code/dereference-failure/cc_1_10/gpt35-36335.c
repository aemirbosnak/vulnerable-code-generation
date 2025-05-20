//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

int numOfFiles = 0;
char *fileNames[MAX_SIZE];
char *fileData[MAX_SIZE];

int createFile(char *fileName) {
    if (numOfFiles >= MAX_SIZE) {
        printf("Error: Maximum number of files exceeded.\n");
        return -1;
    }
    for (int i = 0; i < numOfFiles; i++) {
        if (strcmp(fileNames[i], fileName) == 0) {
            printf("Error: File already exists.\n");
            return -1;
        }
    }
    fileNames[numOfFiles] = strdup(fileName);
    fileData[numOfFiles] = NULL;
    numOfFiles++;
    printf("File created successfully.\n");
    return 0;
}

int writeFile(char *fileName, char *data) {
    for (int i = 0; i < numOfFiles; i++) {
        if (strcmp(fileNames[i], fileName) == 0) {
            free(fileData[i]);
            fileData[i] = strdup(data);
            printf("File written successfully.\n");
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

int readFile(char *fileName) {
    for (int i = 0; i < numOfFiles; i++) {
        if (strcmp(fileNames[i], fileName) == 0) {
            if (fileData[i] == NULL) {
                printf("Error: File is empty.\n");
                return -1;
            }
            printf("%s\n", fileData[i]);
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

int deleteFile(char *fileName) {
    for (int i = 0; i < numOfFiles; i++) {
        if (strcmp(fileNames[i], fileName) == 0) {
            free(fileNames[i]);
            free(fileData[i]);
            for (int j = i + 1; j < numOfFiles; j++) {
                fileNames[j - 1] = fileNames[j];
                fileData[j - 1] = fileData[j];
            }
            numOfFiles--;
            printf("File deleted successfully.\n");
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

int main() {
    int choice;
    char *fileName = (char*)malloc(sizeof(char) * MAX_SIZE);
    char *data = (char*)malloc(sizeof(char) * MAX_SIZE);
    while (1) {
        printf("\nFile System Simulation\n");
        printf("1. Create a new file\n");
        printf("2. Write data to a file\n");
        printf("3. Read data from a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter the name of the file: ");
                fgets(fileName, MAX_SIZE, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                createFile(fileName);
                break;
            case 2:
                printf("Enter the name of the file: ");
                fgets(fileName, MAX_SIZE, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                printf("Enter the data to be written: ");
                fgets(data, MAX_SIZE, stdin);
                data[strcspn(data, "\n")] = 0;
                writeFile(fileName, data);
                break;
            case 3:
                printf("Enter the name of the file: ");
                fgets(fileName, MAX_SIZE, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                readFile(fileName);
                break;
            case 4:
                printf("Enter the name of the file: ");
                fgets(fileName, MAX_SIZE, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                deleteFile(fileName);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}