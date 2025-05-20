//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the frequency of a character in a string
int countFrequency(char *str, char ch) {
    int count = 0;
    int i = 0;
    while (str[i]) {
        if (tolower(str[i]) == tolower(ch)) {
            count++;
        }
        i++;
    }
    return count;
}

// Function to count the frequency of all characters in a string
void countAllFrequency(char *str) {
    int i = 0;
    int count = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            count++;
        }
        i++;
    }
    printf("Total frequency = %d\n", count);
}

// Function to print the frequency of all characters in a string
void printFrequency(int freq[], char ch) {
    printf("Frequency of %c = %d\n", ch, freq[ch - 'a']);
}

int main() {
    char str[1000];
    int freq[26] = {0};
    printf("Enter a string: ");
    scanf("%s", str);

    // Counting the frequency of all characters in the string
    countAllFrequency(str);

    // Counting the frequency of a specific character in the string
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    int index = tolower(ch) - 'a';
    freq[index] = countFrequency(str, ch);
    printFrequency(freq, ch);

    return 0;
}