//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1); // +1 for null terminator
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        *reversed = *end;
        end--;
        *reversed += 1;
        reversed++;
        start++;
    }
    *reversed = '\0'; // Add null terminator
    strcpy(str, reversed);
    free(reversed);
}

// Function to capitalize every other letter in a string
void capitalizeEveryOther(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    while (*str) {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to replace all occurrences of a substring with another substring
void replaceSubstring(char* str, char* oldSubstr, char* newSubstr) {
    int length = strlen(str);
    int oldLength = strlen(oldSubstr);
    int newLength = strlen(newSubstr);
    char* temp = malloc(length + 1);
    strcpy(temp, str);
    char* start = temp;
    while ((start = strstr(start, oldSubstr))!= NULL) {
        int space = newLength - oldLength;
        memmove(start + newLength, start + oldLength, length - (start - temp) + 1);
        memcpy(start, newSubstr, newLength);
        start += newLength;
    }
    strcpy(str, temp);
    free(temp);
}

int main() {
    char string1[] = "Hello, world! ";
    printf("Original string: %s\n", string1);
    reverseString(string1);
    printf("Reversed string: %s\n", string1);

    char string2[] = "tHiS iS a StRiNg WiTh MiXeD cAsE";
    printf("Original string: %s\n", string2);
    capitalizeEveryOther(string2);
    printf("Capitalized every other letter: %s\n", string2);

    char string3[] = "The quick brown fox jumps over the lazy dog.";
    int vowelCount = countVowels(string3);
    printf("Number of vowels: %d\n", vowelCount);

    char string4[] = "The quick brown fox jumps over the lazy dog.";
    char* oldSubstr = "fox";
    char* newSubstr = "cat";
    replaceSubstring(string4, oldSubstr, newSubstr);
    printf("Replaced '%s' with '%s': %s\n", oldSubstr, newSubstr, string4);

    return 0;
}