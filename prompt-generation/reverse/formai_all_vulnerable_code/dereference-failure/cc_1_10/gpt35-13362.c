//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS_PER_LINE 500

void process_node(char *line);

int main(int argc, char const *argv[]) {
    
    FILE *fp;
    char line[MAX_CHARS_PER_LINE];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        process_node(line);
    }
    
    fclose(fp);
    return 0;
}

void process_node(char *line) {
    
    char *start_tag, *end_tag;

    start_tag = strchr(line, '<');
    end_tag = strchr(line, '>');

    if (start_tag != NULL && end_tag != NULL) {

        if (*start_tag == '<' && *(end_tag-1) == '/') {
            printf("Found empty element: %.*s\n", end_tag-start_tag+1, start_tag);
        } else if (*start_tag == '<') {
            int len = end_tag - start_tag + 1;
            char *tag_name = (char*) calloc(len, sizeof(char));
            strncpy(tag_name, start_tag, len);
            printf("Found opening tag: %s\n", tag_name);
            free(tag_name);
        } else if (*start_tag == '<' && *(start_tag+1) == '/') {
            int len = end_tag - start_tag + 1;
            char *tag_name = (char*) calloc(len, sizeof(char));
            strncpy(tag_name, start_tag+1, len-2);
            printf("Found closing tag: %s\n", tag_name);
            free(tag_name);
        }
    }

}