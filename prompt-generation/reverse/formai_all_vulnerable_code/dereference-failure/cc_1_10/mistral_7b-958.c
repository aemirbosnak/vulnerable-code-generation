//MISTRAL-7B DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define ACCESS_CONTROL_FILE "access_control.txt"
#define HASH_SIZE SHA256_DIGEST_LENGTH

typedef struct {
    char filename[MAX_INPUT_SIZE];
    char hash[HASH_SIZE * 2 + 1];
} FileHash;

void checkAccessControl(const char *filename) {
    FILE *file;
    char line[1024];
    int accessGranted = 0;

    file = fopen(ACCESS_CONTROL_FILE, "r");
    if (file == NULL) {
        perror("Error opening access control file.");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, filename) != NULL) {
            accessGranted = 1;
            break;
        }
    }

    fclose(file);

    if (!accessGranted) {
        fprintf(stderr, "Access to file '%s' denied.\n", filename);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *inputBuffer;
    char filename[MAX_INPUT_SIZE];
    int fileSize;
    FileHash fileHash;
    unsigned char hash[HASH_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, argv[1]);
    checkAccessControl(filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    inputBuffer = malloc(fileSize);
    if (inputBuffer == NULL) {
        perror("Error allocating memory for input buffer.");
        exit(EXIT_FAILURE);
    }

    fread(inputBuffer, 1, fileSize, file);
    SHA256((unsigned char *)inputBuffer, fileSize, hash);

    sprintf(fileHash.filename, "%s", filename);
    for (int i = 0; i < HASH_SIZE; i++) {
        sprintf(fileHash.hash + (i * 2), "%02X", hash[i]);
    }

    printf("File '%s' hash:\n", filename);
    for (int i = 0; i < HASH_SIZE * 2; i++) {
        putchar(fileHash.hash[i]);
    }
    putchar('\n');

    free(inputBuffer);
    fclose(file);

    return EXIT_SUCCESS;
}