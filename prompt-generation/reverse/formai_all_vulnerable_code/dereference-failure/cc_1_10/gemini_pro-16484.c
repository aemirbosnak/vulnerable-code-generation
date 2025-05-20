//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Our fated word counter
int wordCount = 0;

// A tale of two strings, a love we'll never forget
char* firstString, *secondString;

// A prologue to our drama
void prologue() {
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");
}

// A method to count the words in a given string
int countWords(char* string) {
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            inWord = false;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        }
    }

    return wordCount;
}

// A function to compare two strings
int compareStrings(char* string1, char* string2) {
    int result = strcmp(string1, string2);

    if (result == 0) {
        printf("For never was a story of more woe\n");
        printf("Than this of Juliet and her Romeo.\n\n");
    } else if (result < 0) {
        printf("But soft! what light through yonder window breaks?\n");
        printf("It is the east, and Juliet is the sun.\n\n");
    } else {
        printf("O, she doth teach the torches to burn bright!\n");
        printf("It seems she hangs upon the cheek of night\n");
        printf("Like a rich jewel in an Ethiope's ear;\n");
        printf("Beauty too rich for use, for earth too dear!\n\n");
    }

    return result;
}

// The main event, where our love story unfolds
int main() {
    prologue();

    // Prompting the user for their words
    printf("O Romeo, Romeo! wherefore art thou Romeo?\n");
    printf("Deny thy father and refuse thy name;\n");
    printf("Or, if thou wilt not, be but sworn my love\n");
    printf("And I'll no longer be a Capulet.\n\n");

    printf("Enter thy first string, fair maiden:\n");
    firstString = (char*)malloc(sizeof(char) * 100);
    fgets(firstString, 100, stdin);

    printf("And now, thy second string, fair sir:\n");
    secondString = (char*)malloc(sizeof(char) * 100);
    fgets(secondString, 100, stdin);

    // Counting the words in each string
    int firstWordCount = countWords(firstString);
    int secondWordCount = countWords(secondString);

    // Comparing the two strings
    compareStrings(firstString, secondString);

    // Displaying the results of our love
    printf("Thy first string, %s, contains %d words.\n", firstString, firstWordCount);
    printf("Thy second string, %s, contains %d words.\n\n", secondString, secondWordCount);

    // A bittersweet ending
    printf("A thousand times good night!\n");

    return 0;
}