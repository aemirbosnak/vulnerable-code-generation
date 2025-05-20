//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNATURE_LENGTH 256

typedef struct {
    char *signature;
    size_t length;
} Signature;

typedef struct {
    Signature *signatures;
    size_t count;
} SignatureDatabase;

SignatureDatabase *load_signature_database(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    SignatureDatabase *database = malloc(sizeof(SignatureDatabase));
    if (database == NULL) {
        fclose(file);
        return NULL;
    }

    database->signatures = NULL;
    database->count = 0;

    char line[MAX_SIGNATURE_LENGTH];
    while (fgets(line, MAX_SIGNATURE_LENGTH, file) != NULL) {
        size_t length = strlen(line);
        if (line[length - 1] == '\n') {
            length--;
        }

        Signature *signature = malloc(sizeof(Signature));
        if (signature == NULL) {
            fclose(file);
            free(database);
            return NULL;
        }

        signature->signature = malloc(length + 1);
        if (signature->signature == NULL) {
            fclose(file);
            free(database);
            free(signature);
            return NULL;
        }

        memcpy(signature->signature, line, length);
        signature->signature[length] = '\0';
        signature->length = length;

        database->signatures = realloc(database->signatures, (database->count + 1) * sizeof(Signature));
        if (database->signatures == NULL) {
            fclose(file);
            free(database);
            free(signature);
            return NULL;
        }

        database->signatures[database->count++] = *signature;
    }

    fclose(file);
    return database;
}

void free_signature_database(SignatureDatabase *database) {
    if (database == NULL) {
        return;
    }

    for (size_t i = 0; i < database->count; i++) {
        free(database->signatures[i].signature);
    }
    free(database->signatures);
    free(database);
}

int scan_file(SignatureDatabase *database, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fclose(file);
        return -1;
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    for (size_t i = 0; i < database->count; i++) {
        Signature *signature = &database->signatures[i];
        for (size_t j = 0; j < file_size - signature->length + 1; j++) {
            if (memcmp(&buffer[j], signature->signature, signature->length) == 0) {
                free(buffer);
                return 1;
            }
        }
    }

    free(buffer);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <signature database> <file>\n", argv[0]);
        return 1;
    }

    SignatureDatabase *database = load_signature_database(argv[1]);
    if (database == NULL) {
        printf("Error loading signature database\n");
        return 1;
    }

    int result = scan_file(database, argv[2]);
    if (result == -1) {
        printf("Error scanning file\n");
        return 1;
    }

    if (result == 1) {
        printf("File is infected\n");
    } else {
        printf("File is clean\n");
    }

    free_signature_database(database);
    return 0;
}