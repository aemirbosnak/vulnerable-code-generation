//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_PATH 256
#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_file_infected(char *file_path) {
    FILE *fp;
    char buffer[1024];
    int file_size = 0;
    int signature_found = 0;

    fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        return 1;
    }

    while (fread(buffer, 1, 1024, fp) > 0) {
        int i = 0;
        while (i < strlen(VIRUS_SIGNATURE)) {
            if (memcmp(buffer, VIRUS_SIGNATURE + i, strlen(VIRUS_SIGNATURE) - i) == 0) {
                signature_found = 1;
                break;
            }
            i++;
        }
        if (signature_found) {
            break;
        }
        file_size += 1024;
    }

    fclose(fp);

    if (signature_found) {
        printf("File %s is infected with EICAR test virus.\n", file_path);
        return 1;
    } else {
        printf("File %s is clean.\n", file_path);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char file_path[MAX_FILE_PATH];
    strncpy(file_path, argv[1], MAX_FILE_PATH - 1);
    file_path[MAX_FILE_PATH - 1] = '\0';

    int result = is_file_infected(file_path);

    return result;
}