//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char* key;
    char* value;
} Metadata;

Metadata* createMetadata() {
    Metadata* metadata = (Metadata*)malloc(sizeof(Metadata));
    metadata->key = NULL;
    metadata->value = NULL;
    return metadata;
}

void destroyMetadata(Metadata* metadata) {
    if (metadata->key!= NULL) {
        free(metadata->key);
        metadata->key = NULL;
    }
    if (metadata->value!= NULL) {
        free(metadata->value);
        metadata->value = NULL;
    }
    free(metadata);
}

void setKey(Metadata* metadata, char* key) {
    if (metadata->key!= NULL) {
        free(metadata->key);
    }
    metadata->key = strdup(key);
}

void setValue(Metadata* metadata, char* value) {
    if (metadata->value!= NULL) {
        free(metadata->value);
    }
    metadata->value = strdup(value);
}

char* getKey(Metadata* metadata) {
    return metadata->key;
}

char* getValue(Metadata* metadata) {
    return metadata->value;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Metadata* metadata = createMetadata();

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char* equal_pos = strchr(line, '=');
        if (equal_pos == NULL) {
            continue;
        }

        *equal_pos = '\0';
        char* key = line;
        char* value = equal_pos + 1;

        setKey(metadata, key);
        setValue(metadata, value);

        fprintf(output_file, "Key: %s\nValue: %s\n\n", getKey(metadata), getValue(metadata));
    }

    destroyMetadata(metadata);
    fclose(input_file);
    fclose(output_file);

    return 0;
}