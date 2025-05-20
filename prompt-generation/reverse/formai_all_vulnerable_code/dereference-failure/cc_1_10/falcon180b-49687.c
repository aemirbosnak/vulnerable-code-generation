//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} Tag;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *pos;
    int num_tags = 0;
    Tag *tags = NULL;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        pos = strchr(line, ':');
        if (pos!= NULL) {
            *pos = '\0';
            pos++;
            while (isspace(*pos)) {
                pos++;
            }
            if (num_tags >= MAX_NUM_TAGS) {
                printf("Error: Too many tags.\n");
                fclose(fp);
                return 1;
            }
            tags = realloc(tags, sizeof(Tag) * ++num_tags);
            tags[num_tags - 1].name = strdup(line);
            tags[num_tags - 1].value = strdup(pos);
        }
    }

    fclose(fp);

    printf("Filename: %s\n", argv[1]);
    printf("Number of tags: %d\n", num_tags);
    for (int i = 0; i < num_tags; i++) {
        printf("Tag %d:\n", i + 1);
        printf("  Name: %s\n", tags[i].name);
        printf("  Value: %s\n", tags[i].value);
    }

    for (int i = 0; i < num_tags; i++) {
        free(tags[i].name);
        free(tags[i].value);
    }
    free(tags);

    return 0;
}