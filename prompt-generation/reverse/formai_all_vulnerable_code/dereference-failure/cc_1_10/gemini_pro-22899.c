//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 1000

char *sigs[MAX_SIGS];
int sig_lens[MAX_SIGS];
int num_sigs = 0;

void load_sigs() {
    // Placeholder function to load signatures from a file
}

int scan_file(char *file_name) {
    FILE *fp = fopen(file_name, "rb");
    if (!fp) {
        return -1;
    }

    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size);
    if (!buffer) {
        return -1;
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    for (int i = 0; i < num_sigs; i++) {
        char *found = strstr(buffer, sigs[i]);
        if (found) {
            printf("Found virus signature '%s' at offset %ld in file '%s'\n", sigs[i], found - buffer, file_name);
            free(buffer);
            return 1;
        }
    }

    free(buffer);
    return 0;
}

int main() {
    load_sigs();

    char file_name[256];
    printf("Enter file name to scan: ");
    scanf("%s", file_name);

    int result = scan_file(file_name);
    if (result == -1) {
        printf("Error opening file\n");
    } else if (result == 1) {
        printf("Virus detected!\n");
    } else {
        printf("No virus detected\n");
    }

    return 0;
}