//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Signature database
typedef struct {
    char *name;
    char *signature;
    size_t signature_len;
} Signature;

// Virus detection function
bool detect_virus(const char *file_content, const Signature *signatures, size_t num_signatures) {
    for (size_t i = 0; i < num_signatures; i++) {
        if (strstr(file_content, signatures[i].signature) != NULL) {
            return true;
        }
    }
    return false;
}

// File scanning function
bool scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return false;
    }

    // Determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read file content into memory
    char *file_content = malloc(file_size + 1);  // +1 for null-terminator
    if (file_content == NULL) {
        perror("malloc");
        fclose(file);
        return false;
    }
    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    // Define virus signatures
    const Signature signatures[] = {
        { "Virus A", "0x12345678", 8 },
        { "Virus B", "0x9ABCDEF0", 8 },
        { "Virus C", "0xBBCDD123", 8 }
    };

    // Detect virus
    bool infected = detect_virus(file_content, signatures, sizeof(signatures) / sizeof(Signature));

    // Clean up
    free(file_content);
    fclose(file);

    // Report result
    if (infected) {
        printf("%s: Infected\n", filename);
    } else {
        printf("%s: Clean\n", filename);
    }

    return infected;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    bool infected = scan_file(argv[1]);
    return infected ? EXIT_FAILURE : EXIT_SUCCESS;
}