//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to convert bytes into either KB, MB or GB
void convertBytes(long int bytes, char* convertedBytes) {
    if (bytes >= 1073741824) {
        sprintf(convertedBytes, "%.2f GB", (double)bytes / 1073741824);
    }
    else if (bytes >= 1048576) {
        sprintf(convertedBytes, "%.2f MB", (double)bytes / 1048576);
    }
    else if (bytes >= 1024) {
        sprintf(convertedBytes, "%.2f KB", (double)bytes / 1024);
    }
    else {
        sprintf(convertedBytes, "%ld bytes", bytes);
    }
}

// Function to scan all the files in a directory recursively
long int scanDirectory(char* directory) {
    long int totalSize = 0;
    char command[200];
    sprintf(command, "du -sb \"%s\"", directory); // du command to get size of directory
    FILE* fp = popen(command, "r"); // Execute command in read mode using popen
    if (fp != NULL) {
        char output[100];
        while (fgets(output, sizeof(output), fp) != NULL) {
            char* token = strtok(output, "\t");
            token = strtok(NULL, "\t");
            totalSize = atol(token); // Convert size to long int
        }
        pclose(fp); // Close the file stream
    }
    return totalSize;
}

// Function to print top N largest files in a directory
void printLargestFiles(char* directory, int number) {
    char command[200];
    sprintf(command, "find \"%s\" -type f -printf \"%%s %%p\\n\" | sort -rn | head -n %d", directory, number); // find command to get largest files in directory
    FILE* fp = popen(command, "r"); // Execute command in read mode using popen
    if (fp != NULL) {
        printf("\nTop %d largest files in directory %s:\n", number, directory);
        char* line = NULL;
        size_t len = 0;
        while (getline(&line, &len, fp) != -1) {
            long int fileSize = atol(strtok(line, " "));
            char* fileName = strtok(NULL, "\n");
            char convertedSize[20];
            convertBytes(fileSize, convertedSize);
            printf("%s - %s\n", convertedSize, fileName);
        }
        free(line);
        pclose(fp); // Close the file stream
    }
}

int main() {
    char directory[100];
    printf("Enter the directory to scan: ");
    scanf("%[^\n]%*c", directory); // Get directory path from user input

    long int totalSize = scanDirectory(directory);
    char convertedSize[20];
    convertBytes(totalSize, convertedSize);
    printf("\nTotal size of directory %s: %s\n", directory, convertedSize);

    int number;
    printf("\nEnter the number of largest files to print: ");
    scanf("%d", &number); // Get number of files to print from user input
    printLargestFiles(directory, number);

    return 0;
}