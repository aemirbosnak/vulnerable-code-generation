//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define VIRUS_NAME "virus.exe"

int is_infected(char* file_data, int file_size);

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_path> <scan_mode>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    char* scan_mode = argv[2];

    FILE* file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", file_path);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%d bytes)\n", file_size);
        fclose(file);
        return 1;
    }

    char* file_data = malloc(file_size + 1);
    if (file_data == NULL) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_data, file_size, 1, file);
    fclose(file);

    if (scan_mode[0] == 'c' || scan_mode[0] == 'C') {
        if (is_infected(file_data, file_size)) {
            printf("File is infected with %s\n", VIRUS_NAME);
        } else {
            printf("File is clean\n");
        }
    } else if (scan_mode[0] == 'r' || scan_mode[0] == 'R') {
        char* output_path = malloc(strlen(file_path) + 5);
        if (output_path == NULL) {
            printf("Error: Could not allocate memory for output path\n");
            free(file_data);
            return 1;
        }

        strcpy(output_path, file_path);
        strcat(output_path, ".clean");

        FILE* output_file = fopen(output_path, "wb");
        if (output_file == NULL) {
            printf("Error: Could not open output file '%s'\n", output_path);
            free(output_path);
            free(file_data);
            return 1;
        }

        fwrite(file_data, file_size, 1, output_file);
        fclose(output_file);

        printf("File cleaned and saved as '%s'\n", output_path);

        free(output_path);
    } else {
        printf("Invalid scan mode\n");
    }

    free(file_data);
    return 0;
}

int is_infected(char* file_data, int file_size) {
    char* virus_data = "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";
    int virus_size = strlen(virus_data);

    for (int i = 0; i < file_size - virus_size + 1; i++) {
        if (memcmp(file_data + i, virus_data, virus_size) == 0) {
            return 1;
        }
    }

    return 0;
}