//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} tag_t;

tag_t tags[MAX_NUM_TAGS];
int num_tags = 0;

void add_tag(char* name, char* value) {
    if (num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags exceeded.\n");
        exit(1);
    }

    strcpy(tags[num_tags].name, name);
    strcpy(tags[num_tags].value, value);
    num_tags++;
}

void print_tags() {
    printf("Tags:\n");
    for (int i = 0; i < num_tags; i++) {
        printf("%s: %s\n", tags[i].name, tags[i].value);
    }
}

int main() {
    // Read in file
    FILE* file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Parse line for tags
        char* name = strtok(line, ":");
        char* value = strtok(NULL, ":");

        if (name == NULL || value == NULL) {
            printf("Error: Invalid tag format.\n");
            exit(1);
        }

        add_tag(name, value);
    }

    fclose(file);

    // Print tags
    print_tags();

    return 0;
}