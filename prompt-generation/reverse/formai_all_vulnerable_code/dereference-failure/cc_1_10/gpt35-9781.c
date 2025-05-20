//FormAI DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorHandler(int errorNum) {
    char* errorMsg = "";
    switch(errorNum) {
        case 1:
            errorMsg = "File not found.";
            break;
        case 2:
            errorMsg = "Memory allocation failed.";
            break;
        case 3:
            errorMsg = "Invalid input entered.";
            break;
        default:
            errorMsg = "Error occurred.";
            break;
    }
    printf("ERROR: %s", errorMsg);
    exit(errorNum);
}

int main() {
    FILE* txtFile;
    char* txtFileName = "example.txt";
    char* txtContent = "";

    // Attempt to open txt file
    txtFile = fopen(txtFileName, "r");
    if(!txtFile) {
        errorHandler(1);
    }

    // Attempt to allocate memory for txt content
    txtContent = (char*) malloc(10 * sizeof(char));
    if(!txtContent) {
        errorHandler(2);
    }

    // Attempt to read txt file content into txtContent variable
    if(!fgets(txtContent, 10, txtFile)) {
        errorHandler(3);
    }

    printf("%s\n", txtContent);

    // Clean up and close txt file
    free(txtContent);
    fclose(txtFile);
    return 0;  
}