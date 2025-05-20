//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
/* HTML Beautifier Program */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

/* Function to remove leading and trailing spaces from a string */
void trim(char *str) {
    int i, j;
    for(i = 0; str[i] == ' '; i++);   // remove leading spaces
    for(j = strlen(str) - 1; str[j] == ' '; j--);    // remove trailing spaces
    str[j+1] = '\0';
    strcpy(str, str+i);  // shift string to left
}

/* Function to beautify HTML by adding indentation */
void beautifyHTML(char *filename) {

    FILE *fp;
    char line[MAX_LINE], prevLine[MAX_LINE];
    int i, count = 0, braceCount = 0, prevBraceCount = 0, openTagCount = 0, prevOpenTagCount = 0;

    fp = fopen(filename, "r");  // open file for reading

    if(fp == NULL) {
        printf("Error in opening file!\n");
        return;
    }

    printf("----- HTML BEAUTIFIER -----\n\n");

    while(fgets(line, MAX_LINE, fp) != NULL) {

        /* Remove leading and trailing spaces from the line */
        trim(line);

        /* Determine the current and previous number of braces */
        braceCount = (strstr(line, "</") != NULL) ? prevBraceCount - 1 : braceCount;
        braceCount = (strstr(line, "<") != NULL && strstr(line, "</") == NULL && strstr(line, "/>") == NULL) ? braceCount + 1 : braceCount;
        braceCount = (strstr(line, "/>") != NULL) ? braceCount - 1 : braceCount;

        prevBraceCount = braceCount;

        /* Determine the current and previous number of open tags */
        openTagCount = (strstr(line, "<") != NULL && strstr(line, "</") == NULL && strstr(line, "/>") == NULL) ? prevOpenTagCount + 1 : openTagCount;
        openTagCount = (strstr(line, "</") != NULL) ? prevOpenTagCount - 1 : openTagCount;

        prevOpenTagCount = openTagCount;

        /* Add indentation based on number of braces and open tags */
        for(i = 0; i < braceCount + openTagCount; i++) {
            printf("\t");
        }

        /* Print the current line */
        printf("%s\n", line);

        /* Save the current line as the previous line */
        strcpy(prevLine, line);

        /* Remove extra blank lines */
        if(strcmp(prevLine, "\n") == 0 && strcmp(line, "\n") == 0) {
            continue;
        }

        count++;
    }

    printf("----- END OF HTML BEAUTIFIER -----\n\n");
    fclose(fp);     // close file
}

/* Main function */
int main() {
    beautifyHTML("sample.html");    // function call
    return 0;
}