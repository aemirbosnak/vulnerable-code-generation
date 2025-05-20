//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void compress(const char *input, char *output);
void decompress(const char *input, char *output);
int main(int argc, char *argv[]);

void compress(const char *input, char *output) {
    int count = 1;
    int j = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            // Appending the character
            output[j++] = input[i];
            // Appending the count
            if (count > 1) {
                j += sprintf(&output[j], "%d", count);
            }
            count = 1; // Reset count
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void decompress(const char *input, char *output) {
    int j = 0;
    int len = strlen(input);
    for (int i = 0; i < len;) {
        char ch = input[i++];
        output[j++] = ch;
        // If next character is a digit, then it's a count
        if (i < len && isdigit(input[i])) {
            int count = input[i++] - '0'; // Convert char digit to integer
            for (int k = 1; k < count; k++) {
                output[j++] = ch; // Repeat the character
            }
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <compress|decompress> <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char output[1024]; // Buffer for the output
    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], output);
        printf("Compressed: %s\n", output);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], output);
        printf("Decompressed: %s\n", output);
    } else {
        fprintf(stderr, "Invalid option. Use 'compress' or 'decompress'.\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}