//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    char *word;
    char ch;
    int count=0;
    int i=0;
    int j=0;
    char filename[20];

    if(argc<2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get filename from command line argument
    strcpy(filename, argv[1]);

    // Open file
    fp = fopen(filename, "r");

    // Check if file exists
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Allocate memory for word
    word = (char *) malloc(100*sizeof(char));

    // Loop through file
    while((ch=fgetc(fp))!=EOF) {

        // If character is not a space or a newline
        if(ch!=' ' && ch!='\n') {

            // Add character to word
            word[i] = ch;
            i++;
        }

        // If character is a space or newline
        else {

            // Terminate word
            word[i] = '\0';

            // If word is not empty
            if(strlen(word)>0) {

                // Increment count
                count++;

                // Display word
                printf("%s\n", word);

                // Reset word
                memset(word, 0, 100*sizeof(char));
                i = 0;
            }
        }
    }

    // Close file
    fclose(fp);

    // Display total count
    printf("Total words: %d\n", count);

    // Free memory
    free(word);

    return 0;
}