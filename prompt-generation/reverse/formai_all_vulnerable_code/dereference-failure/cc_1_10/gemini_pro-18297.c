//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} attribute;

typedef struct {
    char *name;
    char **attributes;
    int num_attributes;
} tag;

int main() {
    char *html = "<html><head><title>Example</title></head><body><h1>Heading</h1><p>Paragraph</p></body></html>";

    tag *tags = malloc(sizeof(tag) * 5);
    tags[0].name = "html";
    tags[0].attributes = NULL;
    tags[0].num_attributes = 0;

    tags[1].name = "head";
    tags[1].attributes = NULL;
    tags[1].num_attributes = 0;

    tags[2].name = "title";
    tags[2].attributes = NULL;
    tags[2].num_attributes = 0;

    tags[3].name = "body";
    tags[3].attributes = NULL;
    tags[3].num_attributes = 0;

    tags[4].name = "h1";
    tags[4].attributes = NULL;
    tags[4].num_attributes = 0;

    tags[5].name = "p";
    tags[5].attributes = NULL;
    tags[5].num_attributes = 0;

    char *token = strtok(html, "<");
    while (token != NULL) {
        if (token[0] == '/') {
            // Closing tag
            char *tag_name = strtok(token, ">");
            tag_name++;
            for (int i = 0; i < 6; i++) {
                if (strcmp(tag_name, tags[i].name) == 0) {
                    tags[i].num_attributes = 0;
                    tags[i].attributes = NULL;
                    break;
                }
            }
        } else {
            // Opening tag
            char *tag_name = strtok(token, " ");
            for (int i = 0; i < 6; i++) {
                if (strcmp(tag_name, tags[i].name) == 0) {
                    tags[i].num_attributes++;
                    tags[i].attributes = realloc(tags[i].attributes, sizeof(char *) * tags[i].num_attributes);
                    char *attr = strtok(NULL, ">");
                    while (attr != NULL) {
                        char *attr_name = strtok(attr, "=");
                        char *attr_value = strtok(NULL, ">");
                        attr_value++;
                        tags[i].attributes[tags[i].num_attributes - 1] = malloc(strlen(attr_value) + 1);
                        strcpy(tags[i].attributes[tags[i].num_attributes - 1], attr_value);
                        attr = strtok(NULL, ">");
                    }
                    break;
                }
            }
        }
        token = strtok(NULL, "<");
    }

    for (int i = 0; i < 6; i++) {
        printf("<%s", tags[i].name);
        for (int j = 0; j < tags[i].num_attributes; j++) {
            printf(" %s=\"%s\"", tags[i].attributes[j], tags[i].attributes[j]);
        }
        printf(">");
    }

    return 0;
}