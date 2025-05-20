//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char title[50];
    char author[30];
    int yearPublished;
    char publisher[20];
} Book;

void printBook(Book b);
void extractMetadata(char *fileName);

int main(){
    char fileName[50];
    printf("Enter the name of the file to extract metadata: ");
    scanf("%s", fileName);
    extractMetadata(fileName);
    return 0;
}

void printBook(Book b){
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Year Published: %d\n", b.yearPublished);
    printf("Publisher: %s\n\n", b.publisher);
}

void extractMetadata(char *fileName){
    FILE *fp;
    Book b;
    char line[100];
    char metadata[20];
    char *token;

    fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Failed to open file!\n");
        return;
    }

    while(fgets(line, 100, fp) != NULL){
        strcpy(metadata, strtok(line, ":"));
        if(strcmp(metadata, "Title") == 0){
            strcpy(b.title, strtok(NULL, "\n"));
        } else if(strcmp(metadata, "Author") == 0){
            strcpy(b.author, strtok(NULL, "\n"));
        } else if(strcmp(metadata, "Year Published") == 0){
            b.yearPublished = atoi(strtok(NULL, "\n"));
        } else if(strcmp(metadata, "Publisher") == 0){
            strcpy(b.publisher, strtok(NULL, "\n"));
        }
    }

    fclose(fp);
    printBook(b);
}