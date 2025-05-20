//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    reverseString(str1);
    reverseString(str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2) {
        int count = 0;
        for (int i = 0; i < len1; i++) {
            if (str1[i] == str2[i]) {
                count++;
            }
        }
        if (count == len1) {
            printf("The strings are anagrams.\n");
        } else {
            printf("The strings are not anagrams.\n");
        }
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}