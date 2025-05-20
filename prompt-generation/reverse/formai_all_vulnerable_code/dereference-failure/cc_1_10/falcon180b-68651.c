//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 4096
#define MAX_TAG_LENGTH 32

typedef struct {
    char *start;
    char *end;
    char *tag;
} Tag;

void add_tag(Tag **tags, int *tag_count, char *start, char *end, char *tag) {
    (*tag_count)++;
    *tags = realloc(*tags, sizeof(Tag) * (*tag_count));
    Tag *new_tag = &(*tags)[*tag_count - 1];
    new_tag->start = start;
    new_tag->end = end;
    new_tag->tag = tag;
}

void print_tags(Tag *tags, int tag_count) {
    for (int i = 0; i < tag_count; i++) {
        printf("<%s>", tags[i].tag);
        printf("%s", tags[i].start);
        printf("</%s>", tags[i].tag);
    }
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char input_buffer[MAX_LINE_LENGTH];
    char *input_position = input_buffer;

    Tag *tags = NULL;
    int tag_count = 0;

    while (fgets(input_position, MAX_LINE_LENGTH - (input_position - input_buffer), input_file)!= NULL) {
        char *line = input_buffer;
        char *tag_start = NULL;
        char *tag_end = NULL;
        char *tag_content = NULL;

        while (*line!= '\0') {
            if (*line == '<') {
                if (tag_start!= NULL) {
                    tag_end = line;
                    break;
                } else {
                    tag_start = line;
                }
            } else if (*line == '>') {
                if (tag_start!= NULL) {
                    tag_end = line;
                    break;
                }
            }

            line++;
        }

        if (tag_start!= NULL && tag_end!= NULL) {
            tag_content = tag_start + 1;
            while (tag_content < tag_end &&!isspace(*tag_content)) {
                tag_content++;
            }

            add_tag(&tags, &tag_count, tag_start, tag_end, tag_content);
        }

        input_position += strlen(line);
    }

    fclose(input_file);

    print_tags(tags, tag_count);

    free(tags);

    return 0;
}