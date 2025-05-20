//FormAI DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void print_error_message(int error_number) {
    switch(error_number) {
        case EINVAL:
            printf("Error number %d: Invalid argument\n", error_number);
            break;
        case ENOMEM:
            printf("Error number %d: Out of memory\n", error_number);
            break;
        case EACCES:
            printf("Error number %d: Permission denied\n", error_number);
            break;
        case EIO:
            printf("Error number %d: Input/output error\n", error_number);
            break;
        default:
            printf("Error number %d: Unknown error\n", error_number);
            break;
    }
}

int main() {
    FILE *fp;
    char *filename = "nonexistent_file.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        int error_number = errno;
        print_error_message(error_number);
        printf("Attempting to create a new file: %s\n", filename);
        fp = fopen(filename, "w");
        if (fp == NULL) {
            error_number = errno;
            print_error_message(error_number);
            printf("Exiting program due to errors.\n");
            exit(1);
        } else {
            printf("New file created successfully!\n");
            fclose(fp);
            return 0;
        }
    } else {
        printf("File opened successfully!\n");
        fclose(fp);
        return 0;
    }
}