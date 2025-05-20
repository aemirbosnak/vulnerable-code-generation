//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

// Macro for printing error messages
#define ERR(msg,...) fprintf(stderr, "Error: " msg "\n", ##__VA_ARGS__)

// Function to extract metadata from a file
void extract_metadata(const char* filename, void(*callback)(const char* key, const char* value)) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        ERR("Failed to open file: %s", filename);
        return;
    }

    char line[1024];
    char* key = NULL;
    char* value = NULL;
    size_t key_len = 0;
    size_t value_len = 0;

    while (fgets(line, sizeof(line), file)) {
        char* p = line;
        while (isspace(*p)) p++;
        if (*p == '#') {
            p++;
            while (isspace(*p)) p++;
            if (*p == '\0') continue;

            if (key) {
                (*callback)(key, value);
                key = NULL;
                value = NULL;
            }

            key = p;
            key_len = strlen(key);
        } else if (key) {
            if (value) {
                value = realloc(value, value_len + strlen(p) + 1);
                strcat(value, p);
            } else {
                value = strdup(p);
                value_len = strlen(value);
            }
        }
    }

    if (key) {
        (*callback)(key, value);
    }

    fclose(file);
}

// Callback function to print extracted metadata
void print_metadata(const char* key, const char* value) {
    printf("%s: %s\n", key, value);
}

// Main function
int main(int argc, char** argv) {
    if (argc < 3) {
        ERR("Usage: %s FILE [KEY]", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    const char* key = (argc >= 3)? argv[2] : NULL;

    extract_metadata(filename, print_metadata);

    return 0;
}