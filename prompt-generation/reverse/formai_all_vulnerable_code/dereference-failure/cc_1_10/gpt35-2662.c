//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define metadata structure */
typedef struct metadata {
    char* key;
    char* value;
} metadata;

/* Define function delcarations */
int extract_metadata(char* file_path, metadata** meta_data_arr_ptr);
void print_metadata(metadata* meta_data_arr, int num_metadata);

/* Main function */
int main() {
    char* file_path = "example_file.txt"; // Change this to your target file path

    metadata* meta_data_arr;
    int num_metadata = extract_metadata(file_path, &meta_data_arr);

    printf("Metadata extracted from file: %s\n", file_path);
    print_metadata(meta_data_arr, num_metadata);

    /* Free memory allocated for metadata array */
    for(int i = 0; i < num_metadata; i++) {
        free(meta_data_arr[i].key);
        free(meta_data_arr[i].value);
    }
    free(meta_data_arr);

    return 0;
}

/* Function to extract metadata from file */
int extract_metadata(char* file_path, metadata** meta_data_arr_ptr) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", file_path);
        exit(1);
    }

    /* Allocate memory for metadata array */
    metadata* meta_data_arr = (metadata*) malloc(sizeof(metadata));
    if (meta_data_arr == NULL) {
        printf("Failed to allocate memory for metadata array.\n");
        exit(1);
    }

    /* Variables to keep track of metadata array */
    int curr_size = 1;
    int curr_idx = 0;

    /* Read file line by line and extract metadata */
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        /* Check if line is a metadata line */
        if (line[0] == ':' && strchr(line, '=') != NULL) {
            /* Allocate memory for new metadata */
            if (curr_idx >= curr_size) {
                curr_size *= 2;
                meta_data_arr = realloc(meta_data_arr, curr_size * sizeof(metadata));
                if (meta_data_arr == NULL) {
                    printf("Failed to reallocate memory for metadata array.\n");
                    exit(1);
                }
            }
            meta_data_arr[curr_idx].key = (char*) malloc(strlen(line) * sizeof(char));
            meta_data_arr[curr_idx].value = (char*) malloc(strlen(line) * sizeof(char));

            /* Extract metadata key and value */
            sscanf(line, ":%[^=]=%[^\n]", meta_data_arr[curr_idx].key, meta_data_arr[curr_idx].value);
            curr_idx++;
        }
    }

    /* Free memory allocated for line */
    free(line);

    /* Close file */
    fclose(file);

    /* Update metadata array pointer and return number of metadata */
    *meta_data_arr_ptr = meta_data_arr;
    return curr_idx;
}

/* Function to print metadata */
void print_metadata(metadata* meta_data_arr, int num_metadata) {
    for(int i = 0; i < num_metadata; i++) {
        printf("%s=%s\n", meta_data_arr[i].key, meta_data_arr[i].value);
    }
}