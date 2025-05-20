//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

typedef struct {
    char *filename;
    unsigned char *data;
    size_t size;
} FileData;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FileData file_data = {0};
    file_data.filename = argv[1];

    FILE *file = fopen(file_data.filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'.\n", file_data.filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_data.size = ftell(file);
    if (file_data.size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%zu bytes).\n", file_data.size);
        fclose(file);
        return 1;
    }

    rewind(file);
    file_data.data = malloc(file_data.size);
    if (!file_data.data) {
        printf("Error: Could not allocate memory for file data.\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(file_data.data, 1, file_data.size, file);
    if (bytes_read!= file_data.size) {
        printf("Error: Could not read entire file.\n");
        free(file_data.data);
        fclose(file);
        return 1;
    }

    fclose(file);

    if (memcmp(file_data.data, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
        printf("Virus detected in file '%s'.\n", file_data.filename);
    } else {
        printf("No virus detected in file '%s'.\n", file_data.filename);
    }

    free(file_data.data);
    return 0;
}