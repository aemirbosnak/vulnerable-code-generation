//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SUCCESS,
    FAILURE,
    INVALID_ARGUMENT
} ErrorCodes;

typedef struct {
    ErrorCodes code;
    const char *message;
} ErrorMessage;

ErrorMessage *createErrorMessage(ErrorCodes code, const char *message) {
    ErrorMessage *errorMessage = malloc(sizeof(ErrorMessage));
    if (errorMessage == NULL) {
        return NULL;
    }

    errorMessage->code = code;
    errorMessage->message = message;

    return errorMessage;
}

void freeErrorMessage(ErrorMessage *errorMessage) {
    free(errorMessage);
}

void printErrorMessage(ErrorMessage *errorMessage) {
    switch (errorMessage->code) {
        case SUCCESS:
            printf("Success\n");
            break;
        case FAILURE:
            printf("Failure: %s\n", errorMessage->message);
            break;
        case INVALID_ARGUMENT:
            printf("Invalid argument: %s\n", errorMessage->message);
            break;
    }
}

int main() {
    ErrorMessage *errorMessage = createErrorMessage(SUCCESS, "No errors");
    printErrorMessage(errorMessage);
    freeErrorMessage(errorMessage);

    errorMessage = createErrorMessage(FAILURE, "An error occurred");
    printErrorMessage(errorMessage);
    freeErrorMessage(errorMessage);

    errorMessage = createErrorMessage(INVALID_ARGUMENT, "Invalid argument");
    printErrorMessage(errorMessage);
    freeErrorMessage(errorMessage);

    return 0;
}