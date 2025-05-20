//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 //1MB
#define VIRUS_SIGNATURE "ThisIsAVirus"

int is_virus(char* file_content){
    char* virus_signature = VIRUS_SIGNATURE;
    int i = 0;
    while(1){
        if(i >= strlen(file_content) || i >= strlen(virus_signature)){
            return 0;
        }
        if(tolower(file_content[i])!= tolower(virus_signature[i])){
            return 0;
        }
        i++;
    }
    return 1;
}

void scan_file(char* filename){
    FILE* file;
    char* file_content = NULL;
    long file_size = 0;

    file = fopen(filename, "rb");
    if(!file){
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if(file_size > MAX_FILE_SIZE){
        printf("File is too large: %s\n", filename);
        fclose(file);
        return;
    }

    rewind(file);
    file_content = (char*)malloc(file_size+1);
    if(!file_content){
        printf("Error allocating memory\n");
        fclose(file);
        return;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    if(is_virus(file_content)){
        printf("Virus found in file: %s\n", filename);
    }else{
        printf("No virus found in file: %s\n", filename);
    }

    free(file_content);
    fclose(file);
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}