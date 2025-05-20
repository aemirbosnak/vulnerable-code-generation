//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000

struct Metadata {
    char project_name[50];
    char created_by[50];
    char creation_date[15];
    char last_modified[15];
};

char* extract_metadata(FILE* file_ptr, char* metadata_keyword) {
    char* line = NULL;
    size_t line_size = 0;
    ssize_t line_length;
    char* metadata = NULL;
    int metadata_found = 0;
    while ((line_length = getline(&line, &line_size, file_ptr)) != -1) {
        if (strstr(line, metadata_keyword) != NULL) {
            metadata = (char*)malloc(MAX_DATA_SIZE * sizeof(char));
            strcpy(metadata, line);
            metadata_found = 1;
            break;
        }
    }

    if (!metadata_found) {
        printf("Error: could not find metadata %s\n", metadata_keyword);
    }

    free(line);
    return metadata;
}

int main() {

    struct Metadata metadata;

    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    char* project_name_meta = extract_metadata(file_ptr, "PROJECT_NAME");
    if (project_name_meta != NULL) {
        sscanf(project_name_meta, "%*s %*s %[^\n]", metadata.project_name);
    }
    free(project_name_meta);

    char* created_by_meta = extract_metadata(file_ptr, "CREATED_BY");
    if (created_by_meta != NULL) {
        sscanf(created_by_meta, "%*s %*s %[^\n]", metadata.created_by);
    }
    free(created_by_meta);

    char* creation_date_meta = extract_metadata(file_ptr, "CREATION_DATE");
    if (creation_date_meta != NULL) {
        sscanf(creation_date_meta, "%*s %*s %[^\n]", metadata.creation_date);
    }
    free(creation_date_meta);

    char* last_modified_meta = extract_metadata(file_ptr, "LAST_MODIFIED");
    if (last_modified_meta != NULL) {
        sscanf(last_modified_meta, "%*s %*s %[^\n]", metadata.last_modified);
    }
    free(last_modified_meta);

    fclose(file_ptr);

    printf("\nExtracted Metadata:\n");
    printf("Project Name: %s\n", metadata.project_name);
    printf("Created By: %s\n", metadata.created_by);
    printf("Creation Date: %s\n", metadata.creation_date);
    printf("Last Modified: %s\n", metadata.last_modified);

    return 0;
}