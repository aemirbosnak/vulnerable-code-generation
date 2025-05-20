//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char* name;
    char* value;
} tag_t;

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_tags = 0;
    tag_t tags[MAX_NUM_TAGS];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char* pos = strchr(line, '<');
        if (pos == NULL) {
            continue;
        }

        tag_t* tag = &tags[num_tags];
        tag->name = strdup(pos + 1);
        pos = strchr(pos + 1, '>');
        if (pos == NULL) {
            printf("Error parsing tag.\n");
            fclose(fp);
            return 1;
        }

        tag->value = strdup(pos + 1);
        num_tags++;
    }

    fclose(fp);

    printf("Filename: %s\n", argv[1]);
    printf("Number of tags: %d\n", num_tags);

    for (int i = 0; i < num_tags; i++) {
        printf("Tag %d:\n", i + 1);
        printf("  Name: %s\n", tags[i].name);
        printf("  Value: %s\n\n", tags[i].value);
    }

    for (int i = 0; i < num_tags; i++) {
        free(tags[i].name);
        free(tags[i].value);
    }

    return 0;
}