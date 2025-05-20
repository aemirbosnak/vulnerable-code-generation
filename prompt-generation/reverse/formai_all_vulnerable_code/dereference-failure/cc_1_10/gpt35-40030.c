//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];

    // Check if file exists
    if (access(file, F_OK) != 0) {
        printf("Error: file %s does not exist\n", file);
        return 1;
    }

    // Check if user has read permissions for file
    if (access(file, R_OK) != 0) {
        printf("Error: you do not have read permissions for %s\n", file);
        return 1;
    }

    // Check if file is a directory
    if (access(file, X_OK) == 0) {
        printf("Error: %s is a directory\n", file);
        return 1;
    }

    // Print file size
    FILE *fp = fopen(file, "r");
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fclose(fp);
    printf("Size of file %s: %ld bytes\n", file, size);

    // Print last modified time
    char command[100] = "stat -c '%y' ";
    strcat(command, file);
    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Error: failed to get last modified time\n");
        return 1;
    }
    char output[30];
    fgets(output, sizeof(output), pipe);
    pclose(pipe);
    printf("Last modified time of file %s: %s", file, output);
    
    return 0;
}