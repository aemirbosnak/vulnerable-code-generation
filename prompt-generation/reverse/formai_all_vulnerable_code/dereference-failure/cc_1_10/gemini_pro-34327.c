//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIGS 1024
#define SIG_SIZE 1024

struct sig {
    char *name;
    uint8_t *data;
    size_t size;
};

struct sig sigs[MAX_SIGS];
int num_sigs = 0;

void load_sigs() {
    FILE *fp = fopen("sigs.txt", "r");
    if (fp == NULL) {
        perror("Error opening sigs.txt");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ":");
        char *data = strtok(NULL, ":");

        if (name == NULL || data == NULL) {
            continue;
        }

        size_t size = strlen(data) / 2;
        uint8_t *buf = malloc(size);
        if (buf == NULL) {
            perror("Error allocating memory for signature");
            exit(1);
        }

        for (size_t i = 0; i < size; i++) {
            char c = data[i * 2];
            char d = data[i * 2 + 1];
            buf[i] = (c << 4) | (d & 0xF);
        }

        struct sig sig = {
            .name = strdup(name),
            .data = buf,
            .size = size,
        };

        sigs[num_sigs++] = sig;
    }

    fclose(fp);
}

void scan_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t *buf = malloc(size);
    if (buf == NULL) {
        perror("Error allocating memory for file");
        exit(1);
    }

    fread(buf, size, 1, fp);
    fclose(fp);

    for (int i = 0; i < num_sigs; i++) {
        struct sig *sig = &sigs[i];
        for (size_t j = 0; j < size - sig->size + 1; j++) {
            if (memcmp(&buf[j], sig->data, sig->size) == 0) {
                printf("Found signature %s at offset %zu\n", sig->name, j);
            }
        }
    }

    free(buf);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_sigs();
    scan_file(argv[1]);

    return 0;
}