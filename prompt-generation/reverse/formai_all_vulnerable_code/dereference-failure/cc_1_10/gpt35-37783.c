//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100

// function to generate unique file name
char* generate_file_name(void) {
    char* file_name = malloc(MAX_FILENAME_LENGTH * sizeof(char));
    time_t current_time;
    struct tm* time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    sprintf(file_name, "backup_%04d%02d%02d_%02d%02d%02d.txt", time_info->tm_year + 1900,
            time_info->tm_mon + 1, time_info->tm_mday, time_info->tm_hour, time_info->tm_min,
            time_info->tm_sec);

    return file_name;
}

int main(int argc, char *argv[]) {
    FILE* input_file_ptr;
    FILE* output_file_ptr;
    char* file_name;

    // check for valid input arguments
    if (argc < 2) {
        printf("Usage: %s input_file_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open input file for reading
    input_file_ptr = fopen(argv[1], "r");

    if (input_file_ptr == NULL) {
        printf("Could not open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // generate unique file name for backup file
    file_name = generate_file_name();

    // open output file for writing
    output_file_ptr = fopen(file_name, "w");

    if (output_file_ptr == NULL) {
        printf("Could not open file %s for writing\n", file_name);
        exit(EXIT_FAILURE);
    }

    // read input file and write to output file
    int c;

    while ((c = fgetc(input_file_ptr)) != EOF) {
        fputc(c, output_file_ptr);
    }

    // close files and free memory
    fclose(input_file_ptr);
    fclose(output_file_ptr);
    free(file_name);

    printf("File backup successful\n");
    
    return EXIT_SUCCESS;
}