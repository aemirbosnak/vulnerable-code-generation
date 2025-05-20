//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void prettyPrint(char* filename) {
    FILE* fptr;

    //Opening the file for reading
    fptr = fopen(filename, "r");

    //Checking if file exists or not
    if (fptr == NULL) {
        printf("Error: File not found.\n");
        exit(0);
    }

    //Counting the number of lines in file
    int lines = 0;
    char ch = fgetc(fptr);

    while (ch != EOF) {
        if (ch == '\n') {
            lines++;
        }
        ch = fgetc(fptr);
    }

    //Resetting the cursor to begining of file
    rewind(fptr);

    //Storing the contents of file to a string
    char* fileContent = (char*) malloc(sizeof(char) * lines);
    char tempLine[200];
    while (fgets(tempLine, 200, fptr)) {
        strcat(fileContent, tempLine);
    }

    fclose(fptr);
    fptr = NULL;

    //Removing all spaces and newlines from the file contents
    int len = strlen(fileContent);
    char* temp = (char*) malloc(sizeof(char) * len);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (fileContent[i] != ' ' && fileContent[i] != '\n') {
            temp[j++] = fileContent[i];
        }
    }

    temp[j] = '\0';

    //Printing the file contents out with proper indentation
    int tabCount = 0;
    len = strlen(temp);
    for (int i = 0; i < len; i++) {
        if (temp[i] == '<') {
            printf("%*s%c", tabCount * 4, "", temp[i]);
            if (temp[i + 1] == '/') {
                tabCount--;
            } 
            else {
                tabCount++;
            }
            printf("\n");
        } 
        else if (temp[i] == '>') {
            printf("%*c\n", tabCount * 4 + 1, temp[i]);
        } 
        else {
            printf("%c", temp[i]);
        }
    }
}

int main() {
    prettyPrint("example.html");
    return 0;
}