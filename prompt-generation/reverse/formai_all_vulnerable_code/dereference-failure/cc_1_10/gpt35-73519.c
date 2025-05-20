//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 10000
#define MAX_WORD_LENGTH 100

/* function prototypes */
char *readResumeFromFile(char *fileName);
void parseResume(char *resume);

/* main function */
int main(int argc, char **argv) {
    char *resume = NULL;
    
    if (argc < 2) {
        printf("Error: Missing input file name.\n");
        return 1;
    }
    
    /* read resume from input file */
    resume = readResumeFromFile(argv[1]);
    if (!resume) {
        printf("Error: Failed to read input file.\n");
        return 1;
    }
    
    /* parse resume */
    parseResume(resume);
    
    /* free memory */
    free(resume);
    
    return 0;
}

/* function to read resume from file */
char *readResumeFromFile(char *fileName) {
    FILE *fp = NULL;
    char *resume = (char*) malloc(sizeof(char) * MAX_RESUME_LENGTH);
    
    fp = fopen(fileName, "r");
    if (!fp) {
        return NULL;
    }
    
    fgets(resume, MAX_RESUME_LENGTH, fp);
    
    fclose(fp);
    
    return resume;  
}

/* function to parse resume */
void parseResume(char *resume) {
    char *token;
    char words[MAX_WORD_LENGTH];
    
    /* loop through resume string and extract words */
    token = strtok(resume, " ,.-");
    while (token != NULL) {
        strcpy(words, token);
        
        /* remove any punctuation from end of word */
        if (strchr(".-,", words[strlen(words) - 1])) {
            words[strlen(words) - 1] = '\0';
        }
        
        /* do something with each word */
        printf("%s\n", words);
        
        /* get next token */
        token = strtok(NULL, " ,.-");
    }
}