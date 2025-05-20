//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GENIUS_FILE "Genius.txt"

int main(void) {
    FILE *fp;
    char genius_str[] = "I am a genius!";
    char file_contents[100];

    // Step 1: Create a new file named "Genius.txt"
    fp = fopen(GENIUS_FILE, "w");
    if (fp == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    // Step 2: Write the string "I am a genius!" to the file
    if (fprintf(fp, "%s\n", genius_str) < 0) {
        perror("Error writing to file");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Step 3: Read the contents of the file back into a character array
    rewind(fp);
    if (fgets(file_contents, sizeof(file_contents), fp) == NULL) {
        perror("Error reading from file");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Step 4: Print the contents of the file to the console
    printf("File contents: %s", file_contents);

    // Step 5: Delete the file after printing
    if (remove(GENIUS_FILE) != 0) {
        perror("Error deleting file");
        exit(EXIT_FAILURE);
    }

    // Just for fun, let's print some random numbers and calculate their sum
    int i, sum = 0;
    for (i = 0; i < 10; i++) {
        sum += rand() % 100;
        printf("%d ", rand() % 100);
    }
    printf("\nSum: %d\n", sum);

    // And finally, let's free the memory we didn't even allocate
    free(genius_str);

    // Don't forget to close the file
    fclose(fp);

    return EXIT_SUCCESS;
}