//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

/* Function to check if a string contains any special characters */
int has_special_character(char *str) {
    for(int i=0; i<strlen(str); i++) {
        if(!isalnum(str[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char filename[MAX_LENGTH];
    char line[MAX_LENGTH];

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    FILE *infile = fopen(filename, "r");
    if(infile == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    /* Read the header line */
    if(fgets(line, MAX_LENGTH, infile) == NULL) {
        printf("Error: File is empty\n");
        exit(1);
    }

    /* Check the header line for special characters */
    if(has_special_character(line)) {
        printf("Error: Header line contains special characters\n");
        exit(1);
    }

    /* Read the data lines */
    while(fgets(line, MAX_LENGTH, infile) != NULL) {
        char *token;
        char *rest = line;
        int count = 0;

        /* Count the number of commas in the line */
        while((token = strtok_r(rest, ",", &rest))) {
            count++;
            /* Check for special characters in the token */
            if(has_special_character(token)) {
                printf("Error: Line %d contains special characters\n", count);
                exit(1);
            }
        }
    }

    printf("CSV file %s is clean\n", filename);

    fclose(infile);
    return 0;
}