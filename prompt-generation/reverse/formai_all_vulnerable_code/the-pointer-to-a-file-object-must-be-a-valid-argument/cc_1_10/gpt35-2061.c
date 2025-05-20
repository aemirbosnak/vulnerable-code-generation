//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATAS 10

struct metadata {
    char name[50];
    char content[100];
};

typedef struct metadata Metadata;

void extractMetadata(char* filename, Metadata* metadataList, int* count) {
    FILE* file = fopen(filename, "r");
    char line[100];
    while(fgets(line, 100, file) != NULL) {
        if(line[0] == '@') {
            // metadata detected
            char* separator = strchr(line+1, ':');
            if(separator != NULL) {
                // found separator
                int index = separator - line - 1;
                strncpy(metadataList[*count].name, line+1, index);
                metadataList[*count].name[index] = '\0';
                strcpy(metadataList[*count].content, separator+1);
                (*count)++;
                if((*count) == MAX_METADATAS) {
                    break;
                }
            }
        }
    }
    fclose(file);
}

int main(int argc, char** argv) {
    if(argc == 1) {
        printf("Please specify a file name\n");
        return 1;
    }
    Metadata metadataList[MAX_METADATAS];
    int count = 0;
    extractMetadata(argv[1], metadataList, &count);
    printf("Metadata detected:\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %s\n", metadataList[i].name, metadataList[i].content);
    }
    return 0;
}