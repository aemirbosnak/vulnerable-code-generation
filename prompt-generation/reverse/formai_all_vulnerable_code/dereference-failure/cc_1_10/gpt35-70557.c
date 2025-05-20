//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* value;
} Metadata;

int get_metadata_count(const char* str) {
    int count = 0;
    int n = strlen(str);
    int i = 0;
    while (i < n) {
        if (str[i] == '@') {
            count++;
        }
        i++;
    }
    return count;
}

void extract_metadata(const char* str, Metadata* metadata, int count) {
    int n = strlen(str);
    int i = 0; // index of the start of a metadata tag
    int j = 0; // index of the end of a metadata tag
    int k = 0; // index of the current metadata array
    while (i < n) {
        if (str[i] == '@') {
            j = i + 1;
            while (j < n && str[j] != '=') {
                j++;
            }
            if (j >= n) {
                break;
            }
            metadata[k].name = (char*)malloc((j - i) * sizeof(char));
            memcpy(metadata[k].name, &str[i], (j - i) * sizeof(char));
            metadata[k].name[j - i] = '\0';
            i = j + 1;
            j = i;
            while (j < n && str[j] != '\n') {
                j++;
            }
            metadata[k].value = (char*)malloc((j - i) * sizeof(char));
            memcpy(metadata[k].value, &str[i], (j - i) * sizeof(char));
            metadata[k].value[j - i] = '\0';
            k++;
        }
        i++;
    }
}

void print_metadata(const Metadata* metadata, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s=%s\n", metadata[i].name, metadata[i].value);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file '%s'\n", argv[1]);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    char* buffer = (char*)malloc(size * sizeof(char));
    long bytes_read = fread(buffer, sizeof(char), size, fp);
    fclose(fp);
    if (bytes_read != size) {
        printf("Failed to read file '%s'\n", argv[1]);
        return 1;
    }
    int count = get_metadata_count(buffer);
    Metadata* metadata = (Metadata*)malloc(count * sizeof(Metadata));
    extract_metadata(buffer, metadata, count);
    print_metadata(metadata, count);
    for (int i = 0; i < count; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);
    free(buffer);
    return 0;
}