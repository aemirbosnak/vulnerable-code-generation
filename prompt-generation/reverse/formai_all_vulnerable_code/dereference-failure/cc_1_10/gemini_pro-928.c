//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNATURE_COUNT 100
#define MAX_SIGNATURE_LENGTH 256

typedef struct {
    char *signature;
    int length;
} Signature;

typedef struct {
    Signature signatures[MAX_SIGNATURE_COUNT];
    int count;
} SignatureDatabase;

SignatureDatabase *loadSignatureDatabase() {
    SignatureDatabase *database = (SignatureDatabase *)malloc(sizeof(SignatureDatabase));
    if (database == NULL) {
        return NULL;
    }

    database->count = 0;

    FILE *file = fopen("signatures.txt", "r");
    if (file == NULL) {
        free(database);
        return NULL;
    }

    char line[MAX_SIGNATURE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        Signature *signature = (Signature *)malloc(sizeof(Signature));
        if (signature == NULL) {
            free(database);
            fclose(file);
            return NULL;
        }

        signature->signature = strdup(line);
        signature->length = strlen(signature->signature);

        database->signatures[database->count++] = *signature;
    }

    fclose(file);

    return database;
}

void freeSignatureDatabase(SignatureDatabase *database) {
    for (int i = 0; i < database->count; i++) {
        free(database->signatures[i].signature);
    }

    free(database);
}

int scanFile(FILE *file, SignatureDatabase *database) {
    char buffer[MAX_SIGNATURE_LENGTH];
    int matches = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < database->count; i++) {
            if (strstr(buffer, database->signatures[i].signature) != NULL) {
                matches++;
                printf("Match found: %s\n", database->signatures[i].signature);
            }
        }
    }

    return matches;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    SignatureDatabase *database = loadSignatureDatabase();
    if (database == NULL) {
        fclose(file);
        fprintf(stderr, "Error loading signature database\n");
        return EXIT_FAILURE;
    }

    int matches = scanFile(file, database);
    printf("Found %d matches\n", matches);

    freeSignatureDatabase(database);
    fclose(file);

    return EXIT_SUCCESS;
}