//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 1000
typedef struct Palindrome {
    char str[MAX_LENGTH];
    int length;
    struct Palindrome *next;
} Palindrome;
Palindrome *head = NULL;
void addToList(char *str) {
    Palindrome *newNode = (Palindrome *) malloc(sizeof(Palindrome));
    int len = strlen(str);
    newNode->length = len;
    strcpy(newNode->str, str);
    newNode->next = head;
    head = newNode;
}
int isPalindrome(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
void printList() {
    Palindrome *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->str);
        temp = temp->next;
    }
}
int main() {
    char input[MAX_LENGTH];
    while (1) {
        printf("Enter a string or type 'quit' to exit: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (isPalindrome(input)) {
            printf("%s is a palindrome.\n", input);
        } else {
            addToList(input);
            printf("%s is not a palindrome. Added to list for later check.\n", input);
        }
    }
    printList();
    Palindrome *temp = head;
    while (temp != NULL) {
        Palindrome *next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}