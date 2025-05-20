//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_ERROR 5

typedef struct {
    char *message;
    int code;
} Error;

void logError(const Error *error) {
    FILE *file = fopen("error_log.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open error log file for writing.\n");
        return;
    }
    fprintf(file, "Error Code: %d, Error Message: %s\n", error->code, error->message);
    fclose(file);
}

void usage(const char *programName) {
    printf("Usage: %s <input>\n", programName);
    printf("Input can be any string that will be processed!\n");
}

Error createError(int code, const char *message) {
    Error error;
    error.code = code;
    error.message = malloc(strlen(message) + 1);
    if (error.message == NULL) {
        perror("Failed to allocate memory for error message");
        exit(EXIT_FAILURE);
    }
    strcpy(error.message, message);
    return error;
}

void freeError(Error *error) {
    free(error->message);
    error->message = NULL;
}

int processInput(const char *input) {
    if (input == NULL || strlen(input) == 0) {
        return -1; // Invalid input
    }
    return 0; // Input valid
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input = argv[1];
    int retVal;

    retVal = processInput(input);
    if (retVal < 0) {
        Error inputError = createError(101, "Invalid input received.");
        logError(&inputError);
        freeError(&inputError);
        fprintf(stderr, "Error: Invalid input! Check error_log.txt for more information.\n");
        return EXIT_FAILURE;
    }

    printf("Processing input: %s\n", input);
    // Simulate processing and potential errors
    for (int i = 0; i < MAX_ERROR; i++) {
        if (rand() % 2) { // Randomly generate an error
            Error simulatedError = createError(200 + i, "Simulated processing error.");
            logError(&simulatedError);
            freeError(&simulatedError);
            fprintf(stderr, "Error Code: %d - Simulated processing error occurred! Check error_log.txt for details.\n", 200 + i);
            return EXIT_FAILURE;
        }
    }

    printf("Input '%s' processed successfully!\n", input);
    return EXIT_SUCCESS;
}