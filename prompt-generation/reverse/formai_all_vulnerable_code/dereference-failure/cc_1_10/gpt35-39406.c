//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum file extension length
#define MAX_EXTENSION_LEN 6

// Maximum file name length
#define MAX_FILENAME_LEN 256

// Function to check if a file extension is executable
int is_executable(char *extension) {
    char *exec_extensions[8] = {".exe", ".bat", ".com", ".pif", ".vb", ".vbs", ".cmd", ".msi"};
    int i;

    for (i = 0; i < 8; i++) {
        if (strcmp(extension, exec_extensions[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LEN];
    char extension[MAX_EXTENSION_LEN];
    int len;
    FILE *fp;

    if (argc == 1) {
        printf("Please specify a file to scan.\n");
        return 0;
    }

    strncpy(filename, argv[1], MAX_FILENAME_LEN);
    len = strlen(filename);

    if (len > MAX_EXTENSION_LEN) {
        strncpy(extension, &filename[len - MAX_EXTENSION_LEN], MAX_EXTENSION_LEN);
        if (is_executable(extension)) {
            printf("File '%s' contained a virus.\n", filename);
        } else {
            printf("File '%s' is clean.\n", filename);
        }
    } else {
        printf("Invalid file extension.\n");
    }

    return 0;
}