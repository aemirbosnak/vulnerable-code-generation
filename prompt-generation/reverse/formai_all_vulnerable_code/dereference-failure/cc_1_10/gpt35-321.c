//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_FILE_NAME_LENGTH 256

//Function to get the file extension
char* getFileExtension(char* fileName) {
    char* extension = strrchr(fileName,'.');
    if (extension == NULL) {
        return "";
    }
    return extension+1; //+1 to remove the dot from the extension
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the path of the file you want to scan: ");
    fgets(fileName, MAX_FILE_NAME_LENGTH, stdin);

    //Remove the newline character from the end of the fileName
    fileName[strcspn(fileName, "\n")] = 0;

    //Check if the file extension is supported
    char* fileExtension = getFileExtension(fileName);
    if (strcmp(fileExtension,"exe") != 0 && strcmp(fileExtension,"dll") != 0 && strcmp(fileExtension,"sys") != 0) {
        printf("This file is not supported by this antivirus.\n");
        exit(0);
    }

    //Open the file
    FILE *fp = fopen(fileName, "r+b");
    if (fp == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    //Scanning the file
    char byte;
    while(fread(&byte, sizeof(char), 1, fp)) {
        if (byte == 'v' || byte == 'i' || byte == 'r' || byte == 'u' || byte == 's') {
            printf("WARNING: Virus detected in the file.\n");
            exit(0);
        }
    }

    printf("The file is clean, it does not contain any viruses.\n");
    fclose(fp);
    return 0;
}