//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to reverse a string
char* reverseString(char *str) {
    char *rev_str = (char*)malloc(strlen(str) * sizeof(char));
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        rev_str[i] = str[j];
    }
    rev_str[i] = '\0';
    return rev_str;
}

// Function to count the number of vowels in a string
int countVowels(char *str) {
    int vowelCount = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowelCount++;
        }
    }
    return vowelCount;
}

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "This is a test string.";
    char str3[] = "This is a test string.";

    // Reverse the strings
    char *rev_str1 = reverseString(str1);
    printf("Reverse of %s is %s\n", str1, rev_str1);
    free(rev_str1);

    char *rev_str2 = reverseString(str2);
    printf("Reverse of %s is %s\n", str2, rev_str2);
    free(rev_str2);

    char *rev_str3 = reverseString(str3);
    printf("Reverse of %s is %s\n", str3, rev_str3);
    free(rev_str3);

    // Count the number of vowels in each string
    int vowelCount1 = countVowels(str1);
    printf("Number of vowels in %s is %d\n", str1, vowelCount1);

    int vowelCount2 = countVowels(str2);
    printf("Number of vowels in %s is %d\n", str2, vowelCount2);

    int vowelCount3 = countVowels(str3);
    printf("Number of vowels in %s is %d\n", str3, vowelCount3);

    return 0;
}