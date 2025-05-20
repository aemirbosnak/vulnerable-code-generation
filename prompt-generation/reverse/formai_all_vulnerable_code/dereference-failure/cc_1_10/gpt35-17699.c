//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} Metadata;

Metadata meta[] = {
    {"author", "John Doe"},
    {"date", "2020-05-01"},
    {"description", "This program extracts metadata from a C source file"}
};
int n_meta = 3;

int is_comment(char* line) {
    return line[0] == '/' && line[1] == '/';
}

Metadata* extract_metadata(char* filename) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    Metadata* metadata = malloc(n_meta * sizeof(Metadata));
    int n = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (is_comment(line)) {
            for (int i = 0; i < n_meta; i++) {
                if (strstr(line, meta[i].key) != NULL) {
                    char* value = strchr(line, ':') + 1;
                    metadata[n].key = meta[i].key;
                    metadata[n].value = value;
                    n++;
                    break;
                }
            }
        }
    }

    fclose(fp);
    if (line)
        free(line);

    return metadata;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Error: usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Metadata* metadata = extract_metadata(argv[1]);
    for (int i = 0; i < n_meta; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    free(metadata);
    return 0;
}