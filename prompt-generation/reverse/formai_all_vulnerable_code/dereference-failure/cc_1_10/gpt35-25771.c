//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_DATA_LEN 1024

typedef struct file_data {
    char filename[MAX_FILENAME_LEN];
    char data[MAX_DATA_LEN];
    size_t data_len;
} file_data_t;

void recover(const char *input_filename, const char *output_filename);
int check_file_size(const char *filename);

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    recover(argv[1], argv[2]);

    exit(EXIT_SUCCESS);
}

/*
 * Recovers corrupted data from input file to output file.
 *
 * Recovers data by reading 1024 bytes chunks and ignoring corrupted data
 * by skipping chunks until non-corrupted data is found. The corrupted
 * chunks are replaced with null bytes.
 */
void recover(const char *input_filename, const char *output_filename)
{
    FILE *input_file, *output_file;
    int i = 0, j = 0, k = 0;
    char buffer[MAX_DATA_LEN], temp_buffer[MAX_DATA_LEN];
    size_t bytes_read;
    file_data_t *file_data = NULL;

    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Failed to open input file: %s\n", input_filename);
        exit(EXIT_FAILURE);
    }

    output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Failed to create output file: %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    while (!feof(input_file)) {
        bytes_read = fread(buffer, 1, MAX_DATA_LEN, input_file);
        if (bytes_read == 0) {
            break;
        }

        k = 0;
        for (i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\0') {
                file_data = malloc(sizeof(file_data_t));
                if (!file_data) {
                    printf("Failed to allocate memory for file data\n");
                    exit(EXIT_FAILURE);
                }
                memset(file_data, 0, sizeof(file_data_t));
                memcpy(file_data->filename, temp_buffer, j);
                memcpy(file_data->data, temp_buffer + j + 1, k - j - 1);
                file_data->data_len = k - j - 1;
                fwrite(file_data->data, 1, file_data->data_len, output_file);

                free(file_data);
                file_data = NULL;
                j = 0;
            }
            else {
                temp_buffer[k] = buffer[i];
                k++;

                if (j == 0 && k > MAX_FILENAME_LEN) {
                    printf("Filename length exceeds maximum: %s\n", temp_buffer);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
}

/*
 * Checks if file size is valid (i.e., positive and less than 1 MB).
 *
 * Returns file size on success and exits with error message on failure.
 */
int check_file_size(const char *filename)
{
    FILE *input_file;
    int file_size = 0;

    input_file = fopen(filename, "rb");
    if (!input_file) {
        printf("Failed to open input file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);

    fclose(input_file);

    if (file_size <= 0) {
        printf("Invalid file size: %d\n", file_size);
        exit(EXIT_FAILURE);
    } 

    if (file_size > 1048576) {
        printf("File size exceeds maximum: %d\n", file_size);
        exit(EXIT_FAILURE);
    }

    return file_size;
}