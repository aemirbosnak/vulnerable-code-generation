//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    size_t file_size;
    char file_data[MAX_FILE_SIZE];
} FileInfo;

int main() {
    char *recover_path = "./recovered_files";
    char *input_path = "./input_files";
    char *file_name = "test.txt";
    FileInfo file_info;
    FILE *input_file = fopen(input_path, "rb");
    FILE *recover_file = NULL;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = 0;

    // Check if input file exists
    if (input_file == NULL) {
        printf("Error: Input file does not exist.\n");
        return 1;
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    file_info.file_size = ftell(input_file);
    rewind(input_file);

    // Read file into buffer
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        memcpy(file_info.file_data, buffer, bytes_read);
    }

    // Create recover file path
    sprintf(file_info.file_name, "%s/%s", recover_path, file_name);
    recover_file = fopen(file_info.file_name, "wb");

    // Write buffer to recover file
    if (recover_file!= NULL) {
        fwrite(file_info.file_data, 1, file_info.file_size, recover_file);
        printf("Successfully recovered file: %s\n", file_info.file_name);
    } else {
        printf("Error: Could not create recover file.\n");
        return 1;
    }

    fclose(input_file);
    fclose(recover_file);

    return 0;
}