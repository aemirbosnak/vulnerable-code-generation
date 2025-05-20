//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define MAX_ERROR_LEN 1024

struct error_context {
    int errnum;
    char *message;
};

void handle_error(int sig, siginfo_t *info, void *context) {
    struct error_context *ctx = (struct error_context *)context;
    char *message = ctx->message;
    int errnum = ctx->errnum;

    // Create a new error context with the original error number and message
    struct error_context new_ctx = {errnum, message};

    // Asynchronously report the error to the main thread
    kill(getppid(), SIGUSR1);

    // If the main thread is waiting for us, let it continue
    if (wait(NULL) == 0) {
        // The main thread is waiting, so we'll just exit
        exit(1);
    }

    // If the main thread is not waiting for us, we'll print the error and exit
    fprintf(stderr, "Error %d: %s\n", errnum, message);
    exit(1);
}

int main() {
    // Set up our error context
    struct error_context ctx = {0, NULL};

    // Perform some potentially error-prone operations
    int result = system("ls -l /nonexistentfile");

    // Check if an error occurred
    if (result == -1) {
        // If an error occurred, set the error number and message
        ctx.errnum = errno;
        ctx.message = strerror(ctx.errnum);

        // Asynchronously report the error to the main thread
        kill(getppid(), SIGUSR1);
    }

    // Wait for the main thread to finish
    wait(NULL);

    return 0;
}