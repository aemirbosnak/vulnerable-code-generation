//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create an index file
void createIndexFile(const char* filename) {
    FILE* fp = fopen(filename, "w");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    char buffer[256];
    char* line = NULL;
    size_t len = 0;
    
    while (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
        len = strlen(buffer);
        line = malloc(len + 1);
        strcpy(line, buffer);
        fprintf(fp, "%s\n", line);
        free(line);
    }
    
    fclose(fp);
    printf("Index file created successfully\n");
}

// Function to search for a keyword in the index file
int searchIndex(const char* filename, const char* keyword) {
    FILE* fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    char buffer[256];
    char* line = NULL;
    size_t len = 0;
    
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        len = strlen(buffer);
        line = malloc(len + 1);
        strcpy(line, buffer);
        if (strstr(line, keyword)!= NULL) {
            printf("%s\n", line);
            free(line);
            return 1;
        }
        free(line);
    }
    
    fclose(fp);
    printf("Keyword not found\n");
    return 0;
}

int main() {
    char* filename = "index.txt";
    char* keyword = "example";
    
    createIndexFile(filename);
    searchIndex(filename, keyword);
    
    return 0;
}