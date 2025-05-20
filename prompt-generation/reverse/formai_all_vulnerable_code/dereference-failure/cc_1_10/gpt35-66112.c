//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program extracts metadata from a file in a post-apocalyptic world where files are
   randomly scrambled due to the damage caused by the apocalypse. The metadata extracted consists of 
   file name, file size, and date modified. */

int main(int argc, char* argv[]) {
    char* fileName; // Pointer to store the file name
    int fileSize; // Variable to store the file size
    char* dateModified; // Pointer to store the date modified
    
    if(argc != 2) { // Checking if the correct number of arguments have been passed
        printf("Usage: ./metadata_extractor <filePath>\n");
        return 1;
    }
    
    // Randomly scrambling the file name due to post-apocalyptic damage
    fileName = malloc(strlen(argv[1])+1); // Allocating memory for the file name
    strcpy(fileName, argv[1]); // Copying the original file name to the pointer
    fileName[0] = 'f';
    fileName[1] = 'i';
    fileName[2] = 'l';
    fileName[3] = 'e';
    fileName[4] = '_';
    for(int i=5; i<strlen(fileName); i++) {
        int randomChar = rand()%26 + 'a'; // Generating a random character
        fileName[i] = (char)randomChar;
    }
    
    // Randomly generating the file size due to post-apocalyptic damage
    fileSize = rand()%1000 + 1; // Generating a random number between 1 and 1000
    
    // Randomly generating the date modified due to post-apocalyptic damage
    dateModified = malloc(11); // Allocating memory for the date modified
    int year = rand()%21 + 2000; // Generating year between 2000 and 2020
    int month = rand()%12 + 1; // Generating month between 1 and 12
    int day;
    if(month == 2) { // February has 28 days in non-leap years
        day = rand()%28 + 1;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) { // Months with 30 days
        day = rand()%30 + 1;
    } else { // Months with 31 days
        day = rand()%31 + 1;
    }
    sprintf(dateModified, "%d/%02d/%02d", year, month, day); // Formatting the date into a string
    
    printf("File name: %s\n", fileName);
    printf("File size: %d bytes\n", fileSize);
    printf("Last modified: %s\n", dateModified);
    
    // Freeing the allocated memory
    free(fileName);
    free(dateModified);
    
    return 0;
}