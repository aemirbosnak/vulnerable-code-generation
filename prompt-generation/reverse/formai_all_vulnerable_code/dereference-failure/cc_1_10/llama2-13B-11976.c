//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_ERROR_MESSAGE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 1024

typedef enum {
    NO_ERROR = 0,
    FILE_NOT_FOUND,
    PERMISSION_DENIED,
    NOT_A_REGULAR_FILE,
    INVALID_FILE_NAME
} error_type_t;

error_type_t check_file_for_errors(const char *file_name) {
    int err;
    struct stat file_stat;

    if (file_name == NULL) {
        return FILE_NOT_FOUND;
    }

    err = stat(file_name, &file_stat);
    if (err == -1) {
        if (errno == ENOENT) {
            return FILE_NOT_FOUND;
        } else if (errno == EACCES) {
            return PERMISSION_DENIED;
        } else {
            return INVALID_FILE_NAME;
        }
    }

    if (!S_ISREG(file_stat.st_mode)) {
        return NOT_A_REGULAR_FILE;
    }

    return NO_ERROR;
}

void display_error_message(error_type_t error_type, const char *file_name) {
    char error_message[MAX_ERROR_MESSAGE_LENGTH];

    switch (error_type) {
        case FILE_NOT_FOUND:
            snprintf(error_message, sizeof(error_message),
                     "File not found: %s", file_name);
            break;
        case PERMISSION_DENIED:
            snprintf(error_message, sizeof(error_message),
                     "Permission denied: %s", file_name);
            break;
        case NOT_A_REGULAR_FILE:
            snprintf(error_message, sizeof(error_message),
                     "Not a regular file: %s", file_name);
            break;
        case INVALID_FILE_NAME:
            snprintf(error_message, sizeof(error_message),
                     "Invalid file name: %s", file_name);
            break;
        default:
            snprintf(error_message, sizeof(error_message),
                     "Unknown error: %s", file_name);
            break;
    }

    fprintf(stderr, "%s\n", error_message);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];
    error_type_t error_type = check_file_for_errors(file_name);
    display_error_message(error_type, file_name);

    return 0;
}