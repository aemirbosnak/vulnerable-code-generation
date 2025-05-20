//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char *string;
    int is_palindrome;
} PalindromeCheck;

void *check_palindrome(void *arg) {
    PalindromeCheck *check = (PalindromeCheck *)arg;
    char *str = check->string;
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (start < end) {
        // Move the start pointer if it's not alphanumeric
        while (start < end && !isalnum(str[start])) {
            start++;
        }
        // Move the end pointer if it's not alphanumeric
        while (start < end && !isalnum(str[end])) {
            end--;
        }

        // Convert to lower case and compare
        if (tolower(str[start]) != tolower(str[end])) {
            check->is_palindrome = 0;
            return NULL;
        }
        start++;
        end--;
    }
    check->is_palindrome = 1;
    return NULL;
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int n;
    printf("Enter the number of strings to check: ");
    scanf("%d", &n);
    getchar();  // Consume the newline character left by scanf

    PalindromeCheck *checks = malloc(n * sizeof(PalindromeCheck));
    pthread_t *threads = malloc(n * sizeof(pthread_t));

    for (int i = 0; i < n; i++) {
        printf("Enter string %d (max %d characters): ", i + 1, MAX_LENGTH);
        checks[i].string = malloc(MAX_LENGTH * sizeof(char));
        fgets(checks[i].string, MAX_LENGTH, stdin);
        trim_newline(checks[i].string);
        checks[i].is_palindrome = -1;  // Default value
    }

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, check_palindrome, &checks[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nPalindrome Check Results:\n");
    for (int i = 0; i < n; i++) {
        printf("String '%s' is %s\n", checks[i].string, checks[i].is_palindrome ? "a palindrome" : "not a palindrome");
        free(checks[i].string);
    }

    free(checks);
    free(threads);
    return 0;
}