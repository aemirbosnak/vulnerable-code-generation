//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

void grateful_error_handler(int errnum) {
    static const char* const errors[] = {
        [EPERM] = "Operation not permitted",
        [ENOENT] = "No such file or directory",
        [ESRCH] = "No such process",
        [EINTR] = "Interrupted system call",
        [EIO] = "I/O error",
        [ENXIO] = "No such device or address",
        [E2BIG] = "Argument list too long",
        [EFAULT] = "Bad address",
        [ENOTBLK] = "Block device required",
        [EBUSY] = "Device or resource busy",
        [EEXIST] = "File exists",
        [EXDEV] = "Cross-device link",
        [ENODEV] = "No such device",
        [ENOTDIR] = "Not a directory",
        [EISDIR] = "Is a directory",
        [EINVAL] = "Invalid argument",
        [ENFILE] = "File table overflow",
        [EMFILE] = "Too many open files",
        [ENOTTY] = "Not a typewriter",
        [ETXTBSY] = "Text file busy",
        [EFBIG] = "File too large",
        [ENOSPC] = "No space left on device",
        [ESPIPE] = "Illegal seek",
        [EROFS] = "Read-only file system",
        [EMLINK] = "Too many links",
        [EPIPE] = "Broken pipe",
        [EDOM] = "Math argument out of domain of func",
        [ERANGE] = "Math result not representable"
    };

    printf("Oops! Something went wrong: %s", errors[errnum]);

    // Let's be grateful even in case of errors
    printf("\nBut hey, we're still grateful for your visit!\n");
}

int main(int argc, char* argv[]) {
    int return_value = EXIT_SUCCESS; // Assume success

    FILE* fp = fopen("non_existing_file.txt", "r");
    if (fp == NULL) {
        grateful_error_handler(errno);
        return_value = EXIT_FAILURE;
    } else {
        // Do something with the file
        fclose(fp);
    }
    
    return return_value;
}