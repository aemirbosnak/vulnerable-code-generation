//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to parse the resume string and return an array of extracted information
char* parse_resume(char* resume) {
    // declare an array to store the extracted information
    char* info[6];

    // initialize all elements of the array to null
    memset(info, '\0', sizeof(info));

    // split the resume string into individual words using whitespace as the delimiter
    char* word = strtok(resume, " \n");

    // iterate through each word in the resume
    while (word!= NULL) {
        // check if the current word is a name
        if (strcmp(word, "name") == 0) {
            info[0] = malloc(strlen(word) + 1);
            strcpy(info[0], word);
        } else if (strcmp(word, "skills") == 0) {
            info[1] = malloc(strlen(word) + 1);
            strcpy(info[1], word);
        } else if (strcmp(word, "experience") == 0) {
            info[2] = malloc(strlen(word) + 1);
            strcpy(info[2], word);
        }

        // get the next word from the resume string
        word = strtok(NULL, " \n");
    }

    // return the array of extracted information
    return info;
}

// main function to test the parsing function
int main() {
    char* resume = "John Doe\n\
Skills:\n\
Programming\n\
Database Management\n\
Experience:\n\
Software Developer\n\
ABC Corp";

    // call the parsing function with the resume string
    char* info = parse_resume(resume);

    // print the extracted information
    printf("Name: %s\n", info[0]);
    printf("Skills: %s\n", info[1]);
    printf("Experience: %s\n", info[2]);

    // free the memory allocated for the extracted information
    for (int i = 0; i < 6; i++) {
        free(info[i]);
    }

    // return 0 to indicate successful execution
    return 0;
}