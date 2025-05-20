//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Metadata {
    char *name;
    char *value;
} Metadata;

typedef struct MetadataExtract {
    char *filename;
    int num_metadata;
    Metadata *metadata_list;
} MetadataExtract;

MetadataExtract* extract_metadata(char *filename) {
    FILE *fp;
    MetadataExtract *metadata_extract;
    char line[100];
    char *name, *value;
    int num_metadata = 0;
    Metadata *metadata_list = NULL;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }
    
    while(fgets(line, sizeof(line), fp)) {
        name = strtok(line, ":");
        value = strtok(NULL, "\n");
        if (name != NULL && value != NULL) {
            metadata_list = realloc(metadata_list, (num_metadata+1) * sizeof(Metadata));
            metadata_list[num_metadata].name = (char*) malloc(strlen(name)+1);
            metadata_list[num_metadata].value = (char*) malloc(strlen(value)+1);
            strcpy(metadata_list[num_metadata].name, name);
            strcpy(metadata_list[num_metadata].value, value);
            num_metadata++;
        }
    }
    
    metadata_extract = malloc(sizeof(MetadataExtract));
    metadata_extract->filename = (char*) malloc(strlen(filename)+1);
    strcpy(metadata_extract->filename, filename);
    metadata_extract->num_metadata = num_metadata;
    metadata_extract->metadata_list = metadata_list;
    
    fclose(fp);
    
    return metadata_extract;
}

void print_metadata(MetadataExtract *metadata_extract) {
    int i;
    printf("Metadata for file %s:\n", metadata_extract->filename);
    for(i = 0; i < metadata_extract->num_metadata; i++) {
        printf("%s: %s\n", metadata_extract->metadata_list[i].name, metadata_extract->metadata_list[i].value);
    }
}

int main() {
    MetadataExtract *metadata_extract = extract_metadata("example.txt");
    print_metadata(metadata_extract);
    return 0;
}