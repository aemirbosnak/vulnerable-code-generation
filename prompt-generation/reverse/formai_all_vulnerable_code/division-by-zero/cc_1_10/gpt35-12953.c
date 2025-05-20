//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number
int random_num(int n) {
    srand(time(NULL));
    int r = rand() % n;
    return r;
}

// Function to retrieve a random fortune from the fortunes.txt file
char *get_fortune() {
    FILE *fileptr;
    char *fortune = malloc(1000 * sizeof(char));
    char *line = malloc(1000 * sizeof(char));
    int count = 0, r, i;
    
    // Open fortunes.txt for reading
    fileptr = fopen("fortunes.txt", "r");
    
    // Count the number of fortunes in the file
    while (fgets(line, 1000, fileptr)) {
        if (line[0] == '%' && count > 0) {
            count++;
        } else if (line[0] == '%') {
            count = 1;
        }
    }
    
    // Generate a random number between 1 and the number of fortunes in the file
    r = random_num(count) + 1;
    
    // Return to the start of the file
    fseek(fileptr, 0, SEEK_SET);
    
    // Retrieve the random fortune
    count = 0;
    while (fgets(line, 1000, fileptr)) {
        if (line[0] == '%' && count == r) {
            strcpy(fortune, "");
            count++;
        } else if (line[0] == '%') {
            count++;
        } else {
            strcat(fortune, line);
        }
    }
    
    // Close the file and return the fortune
    fclose(fileptr);
    return fortune;
}

int main() {
    char name[100];
    char question[1000];
    char response[4][100] = {"Yes", "No", "It is certain", "Cannot predict now"};
    int r;

    // Print intro message
    printf("Welcome, my dear friend. I am your Automated Fortune Teller.\n");
    printf("Please call me Sherlock Holmes. What is your name?\n");
    scanf("%s", name);
    printf("\nHello %s. What burning question do you have that you wish me to answer?\n", name);
    scanf("%s", question);
    
    // Generate a random response
    r = random_num(4);
    
    // Print the response
    printf("\nAh, %s. The answer to your question \"%s\" is: %s.\n", name, question, response[r]);
    printf("\nHere is your fortune for the day:\n\n%s", get_fortune());

    return 0;
}