//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Function to parse a line of the resume
void parseLine(char* line)
{
    // Split the line into words
    char* word;
    char** words = strtok(line, " ");

    // Iterate over the words
    int i = 0;
    while (words[i]!= NULL) {
        // Print each word
        printf("%s\n", words[i]);

        // Move to the next word
        i++;
        words = strtok(NULL, " ");
    }
}

// Function to parse the entire resume
void parseResume(char* resume)
{
    // Split the resume into lines
    char* line;
    char** lines = strtok(resume, "\n");

    // Iterate over the lines
    int i = 0;
    while (lines[i]!= NULL) {
        // Call the parseLine function for each line
        parseLine(lines[i]);

        // Move to the next line
        i++;
        lines = strtok(NULL, "\n");
    }
}

int main()
{
    // Get the resume from the user
    char* resume = (char*)malloc(sizeof(char) * 100);
    printf("Enter the resume: ");
    fgets(resume, 100, stdin);

    // Call the parseResume function to parse the resume
    parseResume(resume);

    // Free the memory allocated for the resume
    free(resume);

    return 0;
}