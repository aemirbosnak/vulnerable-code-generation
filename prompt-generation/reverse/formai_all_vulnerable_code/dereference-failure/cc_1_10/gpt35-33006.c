//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100] = "";
    int count = 0, num = 0, flag = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character

    printf("Original String: %s\n", str);

    // Count the number of digits and special characters
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            count++;
        } else if(str[i] >= '!' && str[i] <= '/') {
            num++;
        }
    }

    printf("Number of digits: %d\n",count);
    printf("Number of special characters: %d\n",num);

    // Reverse the string
    char *reversed_str = malloc(strlen(str)+1);
    int j = strlen(str)-1;
    for(int i=0; i<strlen(str); i++) {
        reversed_str[i] = str[j];
        j--;
    }
    reversed_str[strlen(str)] = '\0';

    printf("Reversed String: %s\n", reversed_str);

    // Check if string is palindrome
    for(int i=0; i<strlen(str); i++) {
        if(str[i] != reversed_str[i]) {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    free(reversed_str);

    return 0;
}