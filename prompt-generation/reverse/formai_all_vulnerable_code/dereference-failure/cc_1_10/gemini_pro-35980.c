//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    UNINITIALIZED,
    READY,
    RUNNING,
    DONE
} state_t;

typedef struct {
    state_t state;
    char *input;
    size_t input_size;
    char *clean_input;
    size_t clean_input_size;
} sanitizer_t;

sanitizer_t *sanitizer_create(void) {
    sanitizer_t *sanitizer = malloc(sizeof(sanitizer_t));
    if (!sanitizer) {
        return NULL;
    }

    sanitizer->state = UNINITIALIZED;
    sanitizer->input = NULL;
    sanitizer->input_size = 0;
    sanitizer->clean_input = NULL;
    sanitizer->clean_input_size = 0;

    return sanitizer;
}

void sanitizer_destroy(sanitizer_t *sanitizer) {
    if (!sanitizer) {
        return;
    }

    if (sanitizer->input) {
        free(sanitizer->input);
    }

    if (sanitizer->clean_input) {
        free(sanitizer->clean_input);
    }

    free(sanitizer);
}

int sanitizer_initialize(sanitizer_t *sanitizer) {
    if (sanitizer->state != UNINITIALIZED) {
        return -1;
    }

    sanitizer->input = malloc(sizeof(char) * 1024);
    if (!sanitizer->input) {
        return -1;
    }

    sanitizer->input_size = 1024;

    sanitizer->clean_input = malloc(sizeof(char) * 1024);
    if (!sanitizer->clean_input) {
        return -1;
    }

    sanitizer->clean_input_size = 1024;

    sanitizer->state = READY;

    return 0;
}

int sanitizer_run(sanitizer_t *sanitizer) {
    if (sanitizer->state != READY) {
        return -1;
    }

    printf("Enter input: ");
    fgets(sanitizer->input, sanitizer->input_size, stdin);

    char *clean = malloc(sizeof(char) * strlen(sanitizer->input));
    if (!clean) {
        return -1;
    }

    strcpy(clean, sanitizer->input);

    for (size_t i = 0; i < strlen(clean); i++) {
        if (!isalnum(clean[i])) {
            clean[i] = '\0';
        }
    }

    sanitizer->clean_input = clean;
    sanitizer->clean_input_size = strlen(clean);

    sanitizer->state = DONE;

    return 0;
}

int main(void) {
    sanitizer_t *sanitizer = sanitizer_create();
    if (!sanitizer) {
        fprintf(stderr, "Error: Could not create sanitizer.\n");
        return EXIT_FAILURE;
    }

    if (sanitizer_initialize(sanitizer) != 0) {
        fprintf(stderr, "Error: Could not initialize sanitizer.\n");
        return EXIT_FAILURE;
    }

    if (sanitizer_run(sanitizer) != 0) {
        fprintf(stderr, "Error: Could not run sanitizer.\n");
        return EXIT_FAILURE;
    }

    printf("Clean input: %s\n", sanitizer->clean_input);

    sanitizer_destroy(sanitizer);

    return EXIT_SUCCESS;
}