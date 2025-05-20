//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB
#define VIRUS_SIGNATURE "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
    char *file_name;
    unsigned char *buffer;
    size_t file_size;
} FileData;

void print_results(int num_infected_files) {
    printf("Scan complete.\n");
    if (num_infected_files == 0) {
        printf("No viruses found.\n");
    } else {
        printf("%d viruses found.\n", num_infected_files);
    }
}

int is_infected(FileData *file_data) {
    size_t i;
    for (i = 0; i < file_data->file_size; i++) {
        if (strchr(VIRUS_SIGNATURE, file_data->buffer[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int num_infected_files = 0;
    FileData *file_data = NULL;

    printf("Starting scan...\n");

    while (1) {
        char file_path[256];
        printf("Enter file path: ");
        if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
            break;
        }
        file_path[strcspn(file_path, "\n")] = '\0';

        FILE *file = fopen(file_path, "rb");
        if (file == NULL) {
            printf("Error: Could not open file.\n");
            continue;
        }

        fseek(file, 0, SEEK_END);
        size_t file_size = ftell(file);
        if (file_size > MAX_FILE_SIZE) {
            printf("Error: File is too large.\n");
            fclose(file);
            continue;
        }

        rewind(file);
        file_data = malloc(sizeof(FileData));
        file_data->file_name = strdup(file_path);
        file_data->buffer = malloc(file_size);
        file_data->file_size = file_size;
        size_t bytes_read = fread(file_data->buffer, 1, file_size, file);
        if (bytes_read!= file_size) {
            printf("Error: Could not read file.\n");
            free(file_data->buffer);
            free(file_data->file_name);
            free(file_data);
            file_data = NULL;
            fclose(file);
            continue;
        }

        if (is_infected(file_data)) {
            printf("Virus found in file: %s\n", file_data->file_name);
            num_infected_files++;
        }

        free(file_data->buffer);
        free(file_data->file_name);
        free(file_data);
        file_data = NULL;
        fclose(file);
    }

    print_results(num_infected_files);

    return 0;
}