//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* file_name;
    int line_number;
    char* line;
} Line;

typedef struct {
    char* key;
    char* value;
} MetaData;

void print_metadata(MetaData* metadata) {
    printf("key: %s\n", metadata->key);
    printf("value: %s\n", metadata->value);
}

int main() {
    FILE* file = fopen("example.c", "r");

    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Line* lines = (Line*) malloc(sizeof(Line));
    lines->file_name = "example.c";
    lines->line_number = 0;
    lines->line = (char*) malloc(MAX_LINE_LENGTH);

    MetaData* metadata = NULL;

    while(fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines->line_number++;
        strcpy(lines->line, line);

        if(strstr(line, "//@")!= NULL) {
            char* key = strtok(line, " ");
            char* value = strtok(NULL, " ");

            if(metadata!= NULL) {
                free(metadata->key);
                free(metadata->value);
                free(metadata);
            }

            metadata = (MetaData*) malloc(sizeof(MetaData));
            metadata->key = strdup(key);
            metadata->value = strdup(value);
        }
    }

    fclose(file);

    print_metadata(metadata);

    free(lines->line);
    free(lines);

    if(metadata!= NULL) {
        free(metadata->key);
        free(metadata->value);
        free(metadata);
    }

    return 0;
}