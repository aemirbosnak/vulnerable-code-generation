//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_METADATA_SIZE 128

/* function to extract metadata from a given file */
char* extract_metadata(char* filename){
    FILE *fp;
    char *metadata = (char*)malloc(MAX_METADATA_SIZE * sizeof(char));
    char ch, file_data[MAX_FILE_SIZE];
    int i, j, flag = 0;

    /* opening the file in read mode */
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: Could not open file!\n");
        exit(0);
    }

    /* reading the file data */
    i = 0;
    while((ch = fgetc(fp)) != EOF){
        file_data[i] = ch;
        i++;
    }
    file_data[i] = '\0';

    /* checking for metadata in file data */
    for(i = 0, j = 0; i < strlen(file_data); i++){
        if(file_data[i] == '<' && file_data[i+1] == '?' && file_data[i+2] == 'm' && file_data[i+3] == 'e' && file_data[i+4] == 't' && file_data[i+5] == 'a'){
            flag = 1;
            i += 6;
        }
        if(flag == 1 && file_data[i] != '>'){
            metadata[j] = file_data[i];
            j++;
        }else if(flag == 1 && file_data[i] == '>'){
            flag = 0;
            metadata[j] = '\0';
            break;
        }
    }
    fclose(fp);
    return metadata;
}

int main(){
    char filename[MAX_FILE_SIZE], *metadata;

    printf("Enter the filename: ");
    scanf("%s", filename);

    metadata = extract_metadata(filename);
    if(strlen(metadata) > 0){
        printf("Metadata for file '%s':\n", filename);
        printf("%s\n", metadata);
    }else{
        printf("No metadata found in file '%s'!\n", filename);
    }
    free(metadata);
    return 0;
}