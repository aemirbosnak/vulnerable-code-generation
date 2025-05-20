//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata {
    char *title;
    char *author;
    int year;
    char *publisher;
};

typedef struct metadata Metadata;

Metadata* extract_metadata(char *filename);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    Metadata *data = extract_metadata(filename);
    printf("Title: %s\n", data->title);
    printf("Author: %s\n", data->author);
    printf("Year: %d\n", data->year);
    printf("Publisher: %s\n", data->publisher);
    free(data->title);
    free(data->author);
    free(data->publisher);
    free(data);
    return 0;
}

/*
 * Function to extract metadata from file
 * @params - filename - name of the file to extract metadata from
 * @returns - pointer to Metadata object containing extracted metadata
 */
Metadata* extract_metadata(char *filename) {
    Metadata *data = (Metadata*) malloc(sizeof(Metadata));
    data->title = (char*) malloc(100 * sizeof(char));
    data->author = (char*) malloc(50 * sizeof(char));
    data->year = 0;
    data->publisher = (char*) malloc(50 * sizeof(char));
    FILE *fp;
    char buf[200], *title, *author, *year, *publisher;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    while(fgets(buf, 200, fp)) {
        if(strstr(buf, "Title:")) {
            title = strtok(buf, ":\n");
            title = strtok(NULL, ":\n");
            strcpy(data->title, title);
        }
        if(strstr(buf, "Author:")) {
            author = strtok(buf, ":\n");
            author = strtok(NULL, ":\n");
            strcpy(data->author, author);
        }
        if(strstr(buf, "Year:")) {
            year = strtok(buf, ":\n");
            year = strtok(NULL, ":\n");
            data->year = atoi(year);
        }
        if(strstr(buf, "Publisher:")) {
            publisher = strtok(buf, ":\n");
            publisher = strtok(NULL, ":\n");
            strcpy(data->publisher, publisher);
        }
    }
    fclose(fp);
    return data;
}