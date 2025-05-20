//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 101

void reverse(char *str, int start, int end) {
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
 if (len & 1) // odd length
 return is_palindrome_odd(str, 0, len - 1);
 else // even length
 return is_palindrome_even(str, 0, len - 1);
}

int is_palindrome_odd(char *str, int i, int j) {
 if (str[i] != str[j])
 return 0;
 i++;
 j--;
 return is_palindrome_odd(str, i, j);
}

int is_palindrome_even(char *str, int i, int j) {
 if (str[i] != str[j])
 return 0;
 i++;
 j--;
 return is_palindrome_even(str, i, j);
}

void print_surreal(char *str) {
 int len = strlen(str);
 int i;
 for (i = 0; i < len; i++) {
 printf("%c", isdigit(str[i]) ? str[i] + '0' - '0' : str[i] == ' ' ? ' ' : (rand() % 26) + 'a');
 }
 printf("\n");
}

int main() {
 char str[SIZE];
 printf("Enter a string: ");
 fgets(str, SIZE, stdin);
 str[strcspn(str, "\n")] = '\0';
 if (is_palindrome(str))
 printf("The given string is a palindrome.\n");
 else {
 printf("The given string is not a palindrome.\n");
 print_surreal(str);
 }
 return 0;
}

/* A surrealist palindrome checker
 * Reverses a string and checks if it is equal to the original.
 * If not, it generates a surrealist version of the given string
 * and prints it instead. */