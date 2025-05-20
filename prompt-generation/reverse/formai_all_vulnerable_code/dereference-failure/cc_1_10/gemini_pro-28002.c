//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define MAX_SIGS 1024
#define MAX_SIG_LEN 128

typedef struct {
    char *name;
    char *pattern;
    int len;
} signature;

signature signatures[MAX_SIGS];
int num_sigs = 0;

int load_signatures(const char *filename) {
    FILE *fp;
    char line[MAX_SIG_LEN];
    char *name, *pattern;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(line, MAX_SIG_LEN, fp) != NULL) {
        if (line[0] == '#') {
            continue;
        }

        name = strdup(strtok(line, ","));
        pattern = strdup(strtok(NULL, ","));
        if (name != NULL && pattern != NULL) {
            signatures[num_sigs].name = name;
            signatures[num_sigs].pattern = pattern;
            signatures[num_sigs].len = strlen(pattern);
            num_sigs++;
        }
    }

    fclose(fp);

    return 0;
}

int scan_file(const char *filename) {
    FILE *fp;
    char buffer[4096];
    int i, j, found = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        for (i = 0; i < num_sigs; i++) {
            for (j = 0; j < (int)(sizeof(buffer) - signatures[i].len); j++) {
                if (memcmp(&buffer[j], signatures[i].pattern, signatures[i].len) == 0) {
                    printf("Found %s at offset %d\n", signatures[i].name, j);
                    found = 1;
                }
            }
        }
    }

    fclose(fp);

    return found;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 3) {
        printf("Usage: %s <signatures file> <files to scan>\n", argv[0]);
        return -1;
    }

    if (load_signatures(argv[1]) < 0) {
        printf("Error loading signatures\n");
        return -1;
    }

    printf("Loaded %d signatures\n", num_sigs);

    for (i = 2; i < argc; i++) {
        if (scan_file(argv[i]) == 1) {
            printf("File %s is infected\n", argv[i]);
        } else {
            printf("File %s is clean\n", argv[i]);
        }
    }

    return 0;
}