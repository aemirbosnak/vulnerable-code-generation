//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_SIZE 1
#define MAX_SIZE 10000

typedef struct palindromePal {
    int size;
    char *str;
} palindrome;

void printMessage(int isPalindrome) {
    if (isPalindrome) {
        printf("Ooh, what a curious coincidence!\n");
        printf("The given string is a palindrome!\n");
    } else {
        printf("Hmm, such a curious string you've got there!\n");
        printf("But unfortunately, it's not a palindrome.\n");
    }
}

int checkPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    while (left < right) {
        // Check for uppercase letters
        if (isupper(str[left]) && isupper(str[right]) && toupper(str[left]) != toupper(str[right])) {
            isPalindrome = 0;
            break;
        }

        // Check for lowercase letters
        if (islower(str[left]) && islower(str[right]) && tolower(str[left]) != tolower(str[right])) {
            isPalindrome = 0;
            break;
        }

        // Check for digits
        if (isdigit(str[left]) && isdigit(str[right]) && str[left] - '0' != str[right] - '0') {
            isPalindrome = 0;
            break;
        }

        if (!isPalindrome) {
            break;
        }

        left++;
        right--;
    }

    return isPalindrome;
}

palindrome *createPalindrome(char *str) {
    palindrome *pPalindrome = (palindrome *) malloc(sizeof(palindrome));

    if (pPalindrome == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    pPalindrome->size = strlen(str);
    pPalindrome->str = (char *) malloc((pPalindrome->size + 1) * sizeof(char));

    if (pPalindrome->str == NULL) {
        printf("Memory allocation failed!\n");
        free(pPalindrome);
        return NULL;
    }

    strcpy(pPalindrome->str, str);

    return pPalindrome;
}

void destroyPalindrome(palindrome *pPalindrome) {
    if (pPalindrome->str != NULL) {
        free(pPalindrome->str);
    }

    if (pPalindrome != NULL) {
        free(pPalindrome);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *inputStr = argv[1];
    palindrome *pPalindrome = createPalindrome(inputStr);

    int isPalindrome = checkPalindrome(pPalindrome->str);
    printMessage(isPalindrome);

    destroyPalindrome(pPalindrome);

    return 0;
}