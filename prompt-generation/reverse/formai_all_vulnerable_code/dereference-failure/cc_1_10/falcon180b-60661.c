//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int is_virus(char *buffer, size_t size) {
    if (size < VIRUS_SIGNATURE_LENGTH ||
        memcmp(buffer, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH)!= 0) {
        return 0;
    }

    return 1;
}

int main() {
    char *filename = "example.txt";
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file '%s' is too large (%ld bytes)\n", filename, file_size);
        fclose(file);
        return 1;
    }

    rewind(file);
    char *buffer = malloc(file_size + 1);

    if (buffer == NULL) {
        printf("Error: could not allocate memory for buffer\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);

    if (bytes_read!= file_size) {
        printf("Error: could not read entire file '%s'\n", filename);
        free(buffer);
        fclose(file);
        return 1;
    }

    buffer[file_size] = '\0'; // add null terminator

    int is_infected = is_virus(buffer, file_size);

    if (is_infected) {
        printf("Virus detected in file '%s'\n", filename);
    } else {
        printf("No virus detected in file '%s'\n", filename);
    }

    free(buffer);
    fclose(file);

    return 0;
}