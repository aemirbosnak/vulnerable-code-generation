//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }
    
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;
    
    char *metadata[MAX_SIZE];
    int num_metadata = 0;
    
    while((read = getline(&line, &line_len, fp)) != -1) {
        if(strstr(line, "metadata")) {
            char *name = strtok(line, ":");
            char *value = strtok(NULL, ":");
            int value_len = strlen(value);
            if(value[value_len - 1] == '\n') {
                value[value_len - 1] = '\0';
            }
            metadata[num_metadata++] = value;
        }
    }
    
    fclose(fp);
    if(line) {
        free(line);
    }
    
    printf("Metadata:\n");
    for(int i = 0; i < num_metadata; i++) {
        printf("%s\n", metadata[i]);
    }
    
    return 0;
}