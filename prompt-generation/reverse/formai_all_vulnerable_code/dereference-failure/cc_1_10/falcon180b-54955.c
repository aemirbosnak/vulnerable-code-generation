//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
    char *data;
} FileData;

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(file_size + 1);
    if (data == NULL) {
        printf("Error: could not allocate memory for file data\n");
        exit(1);
    }

    size_t bytes_read = fread(data, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: could not read entire file '%s'\n", filename);
        exit(1);
    }

    data[file_size] = '\0';
    fclose(file);

    return data;
}

void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    size_t bytes_written = fwrite(data, 1, strlen(data), file);
    if (bytes_written!= strlen(data)) {
        printf("Error: could not write entire file '%s'\n", filename);
        exit(1);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    FileData input_data = { input_filename, NULL };
    FileData output_data = { output_filename, NULL };

    input_data.data = read_file(input_filename);
    output_data.data = strdup(input_data.data);

    printf("Image editor started.\n");
    printf("Press enter to save changes to '%s'.\n", output_filename);

    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (input_buffer[0] == '\n') {
            break;
        }

        char *line_end = strchr(input_buffer, '\n');
        if (line_end!= NULL) {
            *line_end = '\0';
        }

        strcat(output_buffer, input_buffer);
        strcat(output_buffer, "\n");
    }

    output_data.data = realloc(output_data.data, strlen(output_buffer) + 1);
    strcpy(output_data.data, output_buffer);

    write_file(output_filename, output_data.data);
    printf("Changes saved to '%s'.\n", output_filename);

    free(input_data.data);
    free(output_data.data);

    return 0;
}