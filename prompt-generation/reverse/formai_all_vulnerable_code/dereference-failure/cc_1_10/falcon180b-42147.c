//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 1024
#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_virus(char* file_data, int file_size) {
    int i = 0;
    while (i < file_size && i < MAX_VIRUS_SIZE && file_data[i] == VIRUS_SIGNATURE[i]) {
        i++;
    }
    return i == MAX_VIRUS_SIZE;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_data = malloc(file_size + 1);
    if (!file_data) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(file);
        return 1;
    }

    if (fread(file_data, 1, file_size, file)!= file_size) {
        printf("Error: Could not read file data\n");
        free(file_data);
        fclose(file);
        return 1;
    }

    file_data[file_size] = '\0';

    if (is_virus(file_data, file_size)) {
        printf("Virus detected in file '%s'\n", argv[1]);
    } else {
        printf("No virus detected in file '%s'\n", argv[1]);
    }

    free(file_data);
    fclose(file);

    return 0;
}