//FormAI DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_NUMS 5

void handle_error(int errnum) {
    switch (errnum) {
        case EACCES:
            fprintf(stderr, "Error: Permission denied\n");
            break;
        case ENOENT:
            fprintf(stderr, "Error: File not found\n");
            break;
        case ENOMEM:
            fprintf(stderr, "Error: Out of memory\n");
            break;
        default:
            fprintf(stderr, "Unknown error: %d\n", errnum);
    }

    exit(EXIT_FAILURE);
}

int main(void) {
    int nums[MAX_NUMS];
    FILE *fp;
    int i;

    fp = fopen("nums.txt", "r");
    if (!fp) {
        handle_error(errno);
    }

    for (i = 0; i < MAX_NUMS; i++) {
        if (fscanf(fp, "%d", &nums[i]) != 1) {
            if (errno == EIO) {
                handle_error(errno);
            } else {
                fprintf(stderr, "Error: Invalid format in file\n");
                fclose(fp);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(fp);

    printf("The numbers in the file are:");
    for (i = 0; i < MAX_NUMS; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");

    return 0;
}