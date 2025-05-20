//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255
#define MAX_METADATA_LINES 20

struct Metadata {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

int extract_metadata(char *file_name, struct Metadata *metadata_arr) {
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int metadata_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (line[0] == '#') {
            // This is a metadata line
            char *key = strtok(line, "=");
            char *value = strtok(NULL, "=");

            // Remove any leading/trailing whitespace in the value
            char *trimmed_value = value;
            while (*trimmed_value == ' ' || *trimmed_value == '\t' || *trimmed_value == '\n' || *trimmed_value == '\r') {
                trimmed_value++;
            }
            int value_len = strlen(trimmed_value);
            while (value_len > 0 && (trimmed_value[value_len - 1] == ' ' || trimmed_value[value_len - 1] == '\t' || trimmed_value[value_len - 1] == '\n' || trimmed_value[value_len - 1] == '\r')) {
                value_len--;
            }
            trimmed_value[value_len] = '\0';

            strcpy(metadata_arr[metadata_count].key, key);
            strcpy(metadata_arr[metadata_count].value, trimmed_value);
            metadata_count++;
        }
        if (metadata_count == MAX_METADATA_LINES) {
            printf("Max metadata lines reached\n");
            break;
        }
    }

    fclose(fp);
    return metadata_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s file_name\n", argv[0]);
        return 1;
    }

    struct Metadata metadata_arr[MAX_METADATA_LINES];
    int metadata_count = extract_metadata(argv[1], metadata_arr);

    printf("%d metadata lines found:\n", metadata_count);
    for (int i = 0; i < metadata_count; i++) {
        printf("%s=%s\n", metadata_arr[i].key, metadata_arr[i].value);
    }

    return 0;
}