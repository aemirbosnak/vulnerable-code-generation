//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    int length;
} String;

String *createString(const char *s) {
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc(MAX_LENGTH * sizeof(char));
    strcpy(result->str, s);
    result->length = strlen(s);
    return result;
}

void deleteString(String *s) {
    free(s->str);
    free(s);
}

String *concat(String *s1, String *s2) {
    String *result = (String *)malloc(sizeof(String));
    result->str = (char *)malloc(MAX_LENGTH * sizeof(char));
    strcpy(result->str, s1->str);
    strcat(result->str, s2->str);
    result->length = strlen(result->str);
    return result;
}

int isPalindrome(String *s) {
    int i, j;
    for (i = 0, j = s->length - 1; i < j; i++, j--) {
        if (s->str[i]!= s->str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    String *s1 = createString("racecar");
    String *s2 = createString("hello");
    String *s3 = concat(s1, s2);
    int isPalindromeResult = isPalindrome(s3);
    printf("%s\n", isPalindromeResult? "Yes" : "No");
    deleteString(s1);
    deleteString(s2);
    deleteString(s3);
    return 0;
}