//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1 MB

char* read_file(char* filename);
int is_virus(char* content);
char* trim(char* str);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./scanner filename\n");
        return 1;
    }

    char* filename = argv[1];
    char* content = read_file(filename);
    int result = is_virus(content);

    if (result) {
        printf("File '%s' is infected with a virus.\n", filename);
    } else {
        printf("File '%s' is clean.\n", filename);
    }

    return 0;
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long int filesize = ftell(fp);
    rewind(fp);

    if (filesize > MAX_FILE_SIZE) {
        fclose(fp);
        printf("File is too large.\n");
        exit(1);
    }

    char* content = (char*) malloc(filesize + 1);
    fread(content, filesize, 1, fp);
    fclose(fp);

    content[filesize] = '\0';
    return content;
}

int is_virus(char* content) {
    char* viruses[] = {"hack", "virus", "trojan", "worm", "malware"};
    int num_viruses = 5;

    char* token = strtok(content, " ");
    while (token != NULL) {
        char* word = trim(token);
        for (int i = 0; i < num_viruses; i++) {
            if (strstr(word, viruses[i])) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
    }
    *(end+1) = '\0';

    char* start = str;
    while (isspace(*start)) {
        start++;
    }

    return start;
}