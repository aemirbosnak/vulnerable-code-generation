//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    FILE* fp;
    char buf[BUF_SIZE];
    char* filename = "nonexistentfile";
    int linecount = 0;
    
    /* Make sure filename argument is provided */
    if(argc < 2) {
        fprintf(stderr, "Error: No filename provided.\nUsage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        filename = argv[1];
    }
    
    /* Open file */
    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error: %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    /* Read file line-by-line */
    while(fgets(buf, BUF_SIZE, fp)) {
        linecount++;
        /* Check for buffer overflow */
        if(buf[strlen(buf)-1] != '\n' && !feof(fp)) {
            fprintf(stderr, "Error: %s:%d: Line too long.\n", filename, linecount);
            exit(EXIT_FAILURE);
        }
        /* Do something with the line */
        printf("%d: %s", linecount, buf);
    }
    
    /* Check for file read error */
    if(ferror(fp)) {
        fprintf(stderr, "Error: %s:%d: %s\n", filename, linecount, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    /* Close file */
    if(fclose(fp) != 0) {
        fprintf(stderr, "Error: %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Successfully processed file %s.\n", filename);
    return EXIT_SUCCESS;
}