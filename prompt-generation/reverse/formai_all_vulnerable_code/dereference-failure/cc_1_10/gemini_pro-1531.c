//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>

// Signature database
typedef struct {
    uint8_t *bytes;
    size_t len;
} Signature;

// Scan state
typedef struct {
    FILE *file;
    uint8_t *buf;
    size_t buf_size;
    size_t buf_pos;
} ScanState;

// Initialize the scan state
void scan_state_init(ScanState *state, FILE *file) {
    state->file = file;
    state->buf = NULL;
    state->buf_size = 0;
    state->buf_pos = 0;
}

// Free the scan state
void scan_state_free(ScanState *state) {
    if (state->buf != NULL) {
        free(state->buf);
    }
}

// Read the next byte from the file
int scan_state_next(ScanState *state) {
    if (state->buf_pos == state->buf_size) {
        state->buf_size = fread(state->buf, 1, 4096, state->file);
        state->buf_pos = 0;
    }
    if (state->buf_pos == state->buf_size) {
        return EOF;
    }
    return state->buf[state->buf_pos++];
}

// Scan the file for a signature
int scan_file(FILE *file, Signature *signature) {
    ScanState state;
    int c;

    scan_state_init(&state, file);

    while ((c = scan_state_next(&state)) != EOF) {
        for (size_t i = 0; i < signature->len; i++) {
            if (c != signature->bytes[i]) {
                break;
            }
            if (i == signature->len - 1) {
                scan_state_free(&state);
                return 1;
            }
            c = scan_state_next(&state);
        }
    }

    scan_state_free(&state);
    return 0;
}

// Main function
int main(int argc, char **argv) {
    FILE *file;
    Signature signature;
    int infected;

    if (argc < 3) {
        printf("Usage: %s <signature file> <file to scan>\n", argv[0]);
        return 1;
    }

    // Load the signature
    file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    signature.bytes = malloc(4096);
    signature.len = fread(signature.bytes, 1, 4096, file);
    fclose(file);

    // Scan the file
    file = fopen(argv[2], "rb");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    infected = scan_file(file, &signature);
    fclose(file);

    // Print the results
    if (infected) {
        printf("File is infected\n");
    } else {
        printf("File is clean\n");
    }

    return 0;
}