//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("joke.txt", "w"); // opening a file to write

    if (file == NULL) {
        printf("Sorry, I can't tell jokes today! File not found! \n");
        return 1;
    }
    else {
        printf("Welcome to my joke bot! I promise to make you laugh! \n");
    }

    char joke[100];
    char response[100];
    int i, length;

    printf("Please enter a joke: \n");
    fgets(joke, 100, stdin); // taking input from user

    length = strlen(joke); // calculating length of input

    for (i = 0; i < length; i++) { // reversing the input string
        response[i] = joke[length - i - 1];
    }

    response[i] = '\0'; // adding null character at the end of the reversed string

    fputs(response, file); // writing reversed input to the file

    printf("Thanks for the joke! Here's a funnier one for you: \n");

    FILE *file2 = fopen("joke.txt", "r"); // opening the same file to read
    char funny_joke[100];

    if (file2 == NULL) {
        printf("Oops, something went wrong! No jokes found :( \n");
        return 1;
    }
    else {
        while (fgets(funny_joke, sizeof(funny_joke), file2) != NULL) { // reading the file
            printf("%s", funny_joke); // printing the reversed joke
        }

        fclose(file2); // always remember to close the file!
    }

    fclose(file); // closing the file

    printf("\nI hope you had a good laugh! Come back soon for more :-D \n");

    return 0;
}