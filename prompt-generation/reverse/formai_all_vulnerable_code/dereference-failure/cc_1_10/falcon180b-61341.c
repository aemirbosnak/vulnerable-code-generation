//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define VIRUS_SIGNATURE "Virus123"
#define VIRUS_LEN strlen(VIRUS_SIGNATURE)

bool is_virus(const char *file_data, int file_size) {
    const char *virus_sig = VIRUS_SIGNATURE;
    int i, j;

    for (i = 0; i <= file_size - VIRUS_LEN; i++) {
        for (j = 0; j < VIRUS_LEN; j++) {
            if (tolower(file_data[i+j])!= tolower(virus_sig[j])) {
                break;
            }
        }
        if (j == VIRUS_LEN) {
            return true;
        }
    }

    return false;
}

void scan_file(const char *filename) {
    FILE *fp;
    char *file_data;
    int file_size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File %s is too large\n", filename);
        fclose(fp);
        return;
    }

    rewind(fp);
    file_data = (char *) malloc(file_size + 1);
    if (file_data == NULL) {
        printf("Error: Could not allocate memory\n");
        fclose(fp);
        return;
    }

    fread(file_data, 1, file_size, fp);
    file_data[file_size] = '\0';

    if (is_virus(file_data, file_size)) {
        printf("File %s is infected with Virus123\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }

    free(file_data);
    fclose(fp);
}

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }

    return 0;
}