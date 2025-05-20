//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000
#define TAB_SIZE 4

void reverse_string(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    int len = strlen(str);
    if (len <= 1) {
        return 1;
    }
    reverse_string(str, 0, len - 1);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void print_array(char *arr, int size) {
    printf("\nArray contents: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void check_palindrome(char *str) {
    int len = strlen(str);
    char *arr = (char *)malloc((len + 1) * sizeof(char));
    strcpy(arr, str);
    int result = is_palindrome(arr);
    free(arr);
    if (result) {
        printf("%s is a palindrome\n", str);
    } else {
        reverse_string(str, 0, len - 1);
        print_array(str, len);
        printf("%s is not a palindrome\n", str);
    }
}

int main() {
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
    check_palindrome(str);
    return 0;
}

/* This is an invasive palindrome checker program written in C.
   It starts by asking the user for a string input.
   Then, it checks if the given string is a palindrome using the is_palindrome function.
   If the string is a palindrome, it simply prints the string followed by "is a palindrome" message.
   If the string is not a palindrome, it reverses the string using the reverse_string function
   and then prints the reversed string followed by "is not a palindrome" message.
   The program also includes some helper functions like print_array and strcpy for better readability.
*/