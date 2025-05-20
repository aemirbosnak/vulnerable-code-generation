//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILE_NAME 256
#define MAX_FILE_SIZE 1048576

// structure to store file details
struct file {
    char name[MAX_FILE_NAME];
    char *content;
    long size;
};

int main() {
    printf("Welcome to the C Antivirus Scanner!\n");

    // initialize array to store file details
    struct file files[MAX_FILES];
    int num_files = 0;

    // get file names from user
    while (1) {
        char file_name[MAX_FILE_NAME];
        printf("Enter the name of a file to scan (or 'q' to quit): ");
        scanf("%s", file_name);

        // check if user wants to quit
        if (strcmp(file_name, "q") == 0) {
            break;
        }
        
        // check if maximum number of files has been reached
        if (num_files == MAX_FILES) {
            printf("Error: Maximum number of files exceeded\n");
            break;
        }

        // open file and read content into memory
        FILE *fp;
        fp = fopen(file_name, "r");
        if (!fp) {
            printf("Error: File not found\n");
            continue;
        }
        fseek(fp, 0L, SEEK_END);
        long file_size = ftell(fp);
        rewind(fp);
        files[num_files].content = (char*) malloc(file_size);
        fread(files[num_files].content, file_size, 1, fp);
        fclose(fp);

        // save file details
        strcpy(files[num_files].name, file_name);
        files[num_files].size = file_size;
        num_files++;
    }

    // perform virus scan on each file
    printf("\nStarting virus scan...\n");
    for (int i = 0; i < num_files; i++) {
        printf("Scanning %s...\n", files[i].name);

        // check for common virus signatures
        if (strstr(files[i].content, "virus") != NULL ||
            strstr(files[i].content, "malware") != NULL ||
            strstr(files[i].content, "trojan") != NULL) {
            printf("Warning: Virus detected in %s!\n", files[i].name);
        } else {
            printf("%s is clean!\n", files[i].name);
        }

        // free memory used to store file content
        free(files[i].content);
    }

    printf("\nThanks for using the C Antivirus Scanner!\n");

    return 0;
}