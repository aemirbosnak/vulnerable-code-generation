//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_NUM_TAGS 50

struct tag {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

int num_tags = 0;
struct tag tags[MAX_NUM_TAGS];

void add_tag(char* name, char* value) {
    if (num_tags >= MAX_NUM_TAGS) {
        printf("Error: Maximum number of tags reached.\n");
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            char* name = strtok(line, ":");
            char* value = strtok(NULL, ":");
            add_tag(name, value);
        }
    }
    fclose(file);

    print_tags();

    return 0;
}