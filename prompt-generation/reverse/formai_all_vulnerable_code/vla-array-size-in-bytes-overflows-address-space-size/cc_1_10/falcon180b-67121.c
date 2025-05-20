//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_META_DATA_LENGTH 4096

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char meta_data[MAX_META_DATA_LENGTH];
} FileData;

void* extract_metadata(void* arg) {
    FileData* file_data = (FileData*) arg;
    FILE* file = fopen(file_data->file_name, "r");

    if (file == NULL) {
        strcpy(file_data->meta_data, "File not found");
    } else {
        char buffer[MAX_META_DATA_LENGTH];
        fgets(buffer, MAX_META_DATA_LENGTH, file);
        fclose(file);
        strcpy(file_data->meta_data, buffer);
    }

    return NULL;
}

int main() {
    int num_files = 0;
    char input_dir[MAX_FILE_NAME_LENGTH];
    char output_file[MAX_FILE_NAME_LENGTH];
    FILE* output_file_ptr;

    printf("Enter the input directory path: ");
    scanf("%s", input_dir);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    output_file_ptr = fopen(output_file, "w");

    if (output_file_ptr == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    printf("Enter the number of files to extract metadata from: ");
    scanf("%d", &num_files);

    pthread_t threads[num_files];
    FileData data[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name %d: ", i+1);
        scanf("%s", data[i].file_name);
    }

    for (int i = 0; i < num_files; i++) {
        pthread_create(&threads[i], NULL, extract_metadata, &data[i]);
    }

    for (int i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    fprintf(output_file_ptr, "File Name\tMetadata\n");

    for (int i = 0; i < num_files; i++) {
        fprintf(output_file_ptr, "%s\t%s\n", data[i].file_name, data[i].meta_data);
    }

    fclose(output_file_ptr);

    return 0;
}