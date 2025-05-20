//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCAN_SIZE 1024 * 1024 // 1MB

typedef struct {
    char *name;
    unsigned char *signature;
    size_t signature_len;
} virus_signature;

static virus_signature viruses[] = {
    { "Virus A", (unsigned char *)"1234567890", 10 },
    { "Virus B", (unsigned char *)"ABCDEFGHIJ", 10 },
    { "Virus C", (unsigned char *)"ZYXWVUTSRQ", 10 },
};

static size_t num_viruses = sizeof(viruses) / sizeof(virus_signature);

int scan_file(const char *filename) {
    FILE *fp;
    unsigned char *file_buffer;
    size_t file_size;
    int found = 0;

    fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    if (file_size > MAX_SCAN_SIZE) {
        fprintf(stderr, "File too large: %s\n", filename);
        fclose(fp);
        return -1;
    }

    file_buffer = malloc(file_size);
    if (!file_buffer) {
        perror("malloc");
        fclose(fp);
        return -1;
    }

    if (fread(file_buffer, file_size, 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        free(file_buffer);
        return -1;
    }

    fclose(fp);

    for (size_t i = 0; i < num_viruses; i++) {
        if (memcmp(file_buffer, viruses[i].signature, viruses[i].signature_len) == 0) {
            printf("Virus %s found in file %s\n", viruses[i].name, filename);
            found = 1;
        }
    }

    free(file_buffer);

    return found;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    return scan_file(argv[1]);
}