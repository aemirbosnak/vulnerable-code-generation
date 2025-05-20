//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define VIRUS_SIGNATURE "ThisIsAVirus"

int is_virus(char *file_content, int file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int virus_signature_size = strlen(virus_signature);

    for (int i = 0; i < file_size - virus_signature_size; i++) {
        if (memcmp(file_content + i, virus_signature, virus_signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char file_path[1024];
    strcpy(file_path, argv[1]);

    int file_size;
    char *file_content = NULL;

    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        return 1;
    }

    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    fread(file_content, file_size, 1, fp);
    fclose(fp);

    if (is_virus(file_content, file_size)) {
        printf("Virus detected!\n");
    } else {
        printf("No virus detected.\n");
    }

    free(file_content);
    return 0;
}