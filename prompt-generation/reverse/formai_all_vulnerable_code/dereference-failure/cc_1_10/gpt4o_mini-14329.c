//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_RECOVERED_FILES 100
#define FILENAME_SIZE 256
#define SUCCESS 0
#define FAILURE -1

typedef struct {
    char filename[FILENAME_SIZE];
    long offset;
    char* data;
    size_t size;
} RecoveredFile;

void initialize_recovered_files(RecoveredFile* files, int count) {
    for (int i = 0; i < count; ++i) {
        strncpy(files[i].filename, "recovered_file_", FILENAME_SIZE);
        snprintf(files[i].filename + strlen(files[i].filename), FILENAME_SIZE - strlen(files[i].filename), "%d.txt", i);
        files[i].offset = 0;
        files[i].data = NULL;
        files[i].size = 0;
    }
}

void free_recovered_files(RecoveredFile* files, int count) {
    for (int i = 0; i < count; ++i) {
        free(files[i].data);
        files[i].data = NULL;
    }
}

int recover_file(FILE* source, RecoveredFile* file) {
    fseek(source, file->offset, SEEK_SET);
    file->data = (char*)malloc(BLOCK_SIZE);
    if (file->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for recovery: %s\n", strerror(errno));
        return FAILURE;
    }

    size_t bytesRead = fread(file->data, 1, BLOCK_SIZE, source);
    if (bytesRead <= 0) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        free(file->data);
        return FAILURE;
    }

    file->size = bytesRead;
    return SUCCESS;
}

void write_recovered_file(const RecoveredFile* file) {
    FILE* recoveredFile = fopen(file->filename, "wb");
    if (!recoveredFile) {
        fprintf(stderr, "Error opening %s for writing: %s\n", file->filename, strerror(errno));
        return;
    }
    
    fwrite(file->data, 1, file->size, recoveredFile);
    fclose(recoveredFile);
    printf("Recovered: %s (%zu bytes)\n", file->filename, file->size);
}

void simulate_data_recovery(const char* sourceFilename) {
    FILE* source = fopen(sourceFilename, "rb");
    if (!source) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return;
    }

    RecoveredFile recoveredFiles[MAX_RECOVERED_FILES];
    initialize_recovered_files(recoveredFiles, MAX_RECOVERED_FILES);

    int recoveryCount = 0;

    // Simulating recovery from distinct file offsets
    for (int i = 0; i < MAX_RECOVERED_FILES; ++i) {
        recoveredFiles[i].offset = i * BLOCK_SIZE;  // Adjusting for 512-byte blocks
        if (recover_file(source, &recoveredFiles[i]) == SUCCESS) {
            write_recovered_file(&recoveredFiles[i]);
            recoveryCount++;
        }
    }

    free_recovered_files(recoveredFiles, MAX_RECOVERED_FILES);
    fclose(source);
    printf("Total files recovered: %d\n", recoveryCount);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    simulate_data_recovery(argv[1]);

    return EXIT_SUCCESS;
}