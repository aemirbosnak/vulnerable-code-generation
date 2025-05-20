//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* name;
    char* value;
} metadata_t;

int main(int argc, char** argv) {
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char* metadata_name = NULL;
    char* metadata_value = NULL;
    metadata_t metadata_list[10];
    int metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (metadata_name!= NULL) {
            if (metadata_value == NULL) {
                char* value_start = strchr(line, ':');
                if (value_start == NULL) {
                    printf("Error: Invalid metadata format.\n");
                    return 1;
                }
                metadata_value = value_start + 1;
            } else {
                metadata_value = realloc(metadata_value, strlen(metadata_value) + strlen(line) + 1);
                strcat(metadata_value, line);
            }
        } else {
            char* equals_pos = strchr(line, '=');
            if (equals_pos == NULL) {
                continue;
            }
            metadata_name = strndup(line, equals_pos - line);
            metadata_value = strdup(equals_pos + 1);
        }
    }

    if (metadata_name!= NULL) {
        metadata_list[metadata_count].name = metadata_name;
        metadata_list[metadata_count].value = metadata_value;
        metadata_count++;
    }

    fclose(input_file);

    printf("Metadata:\n");
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata_list[i].name, metadata_list[i].value);
    }

    return 0;
}