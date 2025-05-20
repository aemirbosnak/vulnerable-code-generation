//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int lineno;
    char* comment;
} Metadata;

Metadata* extract_metadata(char* filename) {
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->name = strdup("");
    metadata->lineno = 0;
    metadata->comment = strdup("");
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int i;
        for (i = 0; line[i]!= '\n'; i++) {
            if (line[i] == '*' && line[i + 1] == '/') {
                metadata->lineno = atoi(line + i + 2);
                break;
            }
        }
        
        if (line[0] == '/' && line[1] == '*') {
            metadata->comment = strdup(line + 2);
        }
    }
    
    fclose(file);
    
    return metadata;
}

int main() {
    char* filename = "example.c";
    Metadata* metadata = extract_metadata(filename);
    if (metadata!= NULL) {
        printf("File name: %s\n", metadata->name);
        printf("Line number: %d\n", metadata->lineno);
        printf("Comment: %s\n", metadata->comment);
    }
    
    free(metadata->name);
    free(metadata->comment);
    free(metadata);
    
    return 0;
}