//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_META_DATA_SIZE 1000

int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("ERROR: Please provide a file name as argument\n");
        return 1;
    }

    char* file_name = argv[1];
    FILE* file_ptr = fopen(file_name, "r");

    if(file_ptr == NULL) {
        printf("ERROR: Failed to open file %s\n", file_name);
        return 1;
    }

    char file_data[MAX_META_DATA_SIZE];
    size_t read_size = fread(file_data, sizeof(char), MAX_META_DATA_SIZE, file_ptr);

    if(read_size == 0) {
        printf("ERROR: Could not read any data from file %s\n", file_name);
        return 1;
    }

    char* start_pattern = "<metadata>";
    char* end_pattern = "</metadata>";

    char* start_ptr = strstr(file_data, start_pattern);
    char* end_ptr = NULL;

    while(start_ptr != NULL) {

        end_ptr = strstr(start_ptr, end_pattern);

        if(end_ptr == NULL) {
            break;
        }

        int meta_data_length = (int)(end_ptr - start_ptr) - strlen(start_pattern);
        char* meta_data = (char*)calloc(meta_data_length+1, sizeof(char));
        strncpy(meta_data, start_ptr + strlen(start_pattern), meta_data_length);

        printf("METADATA FOUND:\n%s\n", meta_data);

        free(meta_data);

        start_ptr = strstr(end_ptr, start_pattern);
    }

    fclose(file_ptr);

    return 0;
}