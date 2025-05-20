//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int value;
} Metadata;

Metadata *metadata_create(char *name, int value) {
    Metadata *m = malloc(sizeof(Metadata));
    m->name = strdup(name);
    m->value = value;
    return m;
}

void metadata_destroy(Metadata *m) {
    free(m->name);
    free(m);
}

int metadata_get_value(Metadata *m) {
    return m->value;
}

char *metadata_get_name(Metadata *m) {
    return m->name;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata>\n", argv[0]);
        return 1;
    }

    char *metadata_str = argv[1];
    char *delimiter = "=";
    char *name;
    char *value_str;
    int value;

    Metadata *metadata = NULL;
    while ((name = strtok(metadata_str, delimiter))!= NULL && (value_str = strtok(NULL, delimiter))!= NULL) {
        value = atoi(value_str);
        metadata = metadata_create(name, value);
    }

    printf("Name: %s\n", metadata_get_name(metadata));
    printf("Value: %d\n", metadata_get_value(metadata));

    metadata_destroy(metadata);
    return 0;
}