//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMeta {
    char **data;
    int size;
} CMeta;

CMeta *extract_c_metadata(FILE *fp) {
    CMeta *meta = malloc(sizeof(CMeta));
    meta->data = NULL;
    meta->size = 0;

    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '#') {
                char *key = strchr(buffer, '=');
                if (key) {
                    key++;
                    char *value = strchr(key, '#');
                    if (value) {
                        value++;
                        meta->data = realloc(meta->data, (meta->size + 1) * sizeof(char *));
                        meta->data[meta->size++] = strdup(value);
                    }
                }
            }
        }
    }

    return meta;
}

int main() {
    FILE *fp = fopen("my_file.c", "r");
    CMeta *meta = extract_c_metadata(fp);

    for (int i = 0; i < meta->size; i++) {
        printf("%s: %s\n", meta->data[i], "");
    }

    fclose(fp);

    return 0;
}