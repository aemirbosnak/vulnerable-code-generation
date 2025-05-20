//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Immersive C antivirus scanner
* This program scans a file for viruses using a unique scanning algorithm
*/

int scan_file(char* filename);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(0);
    }

    char* filename = argv[1];

    int result = scan_file(filename);

    if(result) {
        printf("File %s is infected!\n", filename);
    }
    else {
        printf("File %s is clean!\n", filename);
    }

    return 0;
}

int scan_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if(!file) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size * sizeof(char));
    fread(buffer, sizeof(char), file_size, file);

    fclose(file);

    // Scanning algorithm
    int virus_count = 0;
    for(int i = 0; i < file_size; i+=5) {
        char temp[6];
        memcpy(temp, &buffer[i], 5);
        temp[5] = '\0';

        if(strcmp(temp, "VIRUS") == 0) {
            virus_count++;
        }
    }

    free(buffer);

    if(virus_count > 0) {
        return 1;
    }
    else {
        return 0;
    }
}