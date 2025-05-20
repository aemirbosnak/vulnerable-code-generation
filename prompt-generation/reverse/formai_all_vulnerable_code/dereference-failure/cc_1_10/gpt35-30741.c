//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_RESUME_ITEMS 10

typedef struct {
    char* name;
    char* value;
} ResumeItem;

int parse_resume(char* content, ResumeItem* items) {
    int num_items = 0;
    char* name_start = content;
    char* name_end = NULL;
    char* value_start = NULL;
    char* value_end = NULL;

    while (*content != '\0') {
        if (*content == ':') {
            // Found a new resume item name
            name_end = content;
            value_start = content + 1;

            // Allocate memory for the name
            items[num_items].name = (char*) malloc(sizeof(char) * (name_end - name_start + 1));
            strncpy(items[num_items].name, name_start, name_end - name_start);
            items[num_items].name[name_end - name_start] = '\0';
        } else if (*content == '\n' && name_end != NULL && value_start != NULL) {
            // Found a new line indicating end of the resume item value
            value_end = content - 1;

            // Allocate memory for the value
            items[num_items].value = (char*) malloc(sizeof(char) * (value_end - value_start + 1));
            strncpy(items[num_items].value, value_start, value_end - value_start);
            items[num_items].value[value_end - value_start] = '\0';

            num_items++;

            // Once we have reached the maximum number of items, break out of the loop
            if (num_items == MAX_RESUME_ITEMS) {
                break;
            }

            name_start = value_start = name_end = value_end = NULL;
        }

        content++;
    }

    return num_items;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    ResumeItem items[MAX_RESUME_ITEMS];

    printf("Enter resume content:\n");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    int num_items = parse_resume(buffer, items);

    printf("Parsed %d resume items:\n", num_items);
    for (int i = 0; i < num_items; i++) {
        printf("%s: %s\n", items[i].name, items[i].value);
    }

    exit(0);
}