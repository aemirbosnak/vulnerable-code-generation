//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    int value;
    char* string;
} Metadata;

Metadata* extract_metadata(char* filename) {
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->value = 0;
    metadata->string = NULL;
    
    char* line;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&line, &len, file)) != -1) {
        char* token = strtok(line, ",");
        
        while (token != NULL) {
            if (strcmp(token, "metadata") == 0) {
                token = strtok(NULL, ",");
                
                if (token != NULL) {
                    metadata->value = atoi(token);
                    
                    token = strtok(NULL, ",");
                    
                    if (token != NULL) {
                        metadata->string = malloc(strlen(token) + 1);
                        strcpy(metadata->string, token);
                    }
                }
                
                break;
            }
            
            token = strtok(NULL, ",");
        }
        
        if (metadata->string != NULL) {
            break;
        }
    }
    
    free(line);
    fclose(file);
    
    return metadata;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    Metadata* metadata = extract_metadata(argv[1]);
    
    printf("Value: %d\nString: %s\n", metadata->value, metadata->string);
    
    free(metadata->string);
    free(metadata);
    
    return 0;
}