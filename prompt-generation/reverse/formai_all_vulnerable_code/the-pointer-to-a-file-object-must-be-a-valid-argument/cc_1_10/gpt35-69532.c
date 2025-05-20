//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

// Declare a function to display the file contents
void display(char filename[]) {
    FILE* fpointer = fopen(filename, "r"); // Open file in read mode
    char line[255];

    // Read the file line by line and display it
    while(fgets(line, 255, fpointer)) {
        printf("%s", line);
    }

    printf("\n");
    fclose(fpointer); // Close the file
}

// Declare a function to count the occurrence of a specific word in the file
int countWord(char filename[], char word[]) {
    FILE* fpointer = fopen(filename, "r"); // Open file in read mode
    char line[255];
    int count = 0;

    while(fgets(line, 255, fpointer)) {
        // Split the line into words
        char* token = strtok(line, " ");
        while(token != NULL) {
            // If the word matches, increment the count
            if(strcmp(token, word) == 0) {
                count++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fpointer); // Close the file
    return count;
}

int main() {
    char filename[] = "sherlock.txt"; // Name of the file
    char word[] = "elementary"; // Word to search for
    printf("Welcome to the Sherlock Holmes text processing program!\n");
    printf("The file '%s' contains the following text:\n\n", filename);
    display(filename); // Display the contents of the file
    int count = countWord(filename, word); // Count the occurrence of the word
    printf("The word '%s' occurs %d times in the file.\n", word, count);

    return 0;
}