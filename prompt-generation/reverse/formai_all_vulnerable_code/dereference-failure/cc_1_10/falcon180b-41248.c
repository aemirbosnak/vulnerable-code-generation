//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *str;
    int len;
} String;

String *createString(const char *s) {
    String *str = malloc(sizeof(String));
    str->str = malloc(MAX_SIZE);
    str->len = strlen(s);
    strcpy(str->str, s);
    return str;
}

String *concatStrings(String *s1, String *s2) {
    String *str = malloc(sizeof(String));
    str->str = malloc(MAX_SIZE);
    str->len = s1->len + s2->len;
    strcpy(str->str, s1->str);
    strcat(str->str, s2->str);
    return str;
}

String *copyString(String *s) {
    String *str = malloc(sizeof(String));
    str->str = malloc(MAX_SIZE);
    str->len = s->len;
    strcpy(str->str, s->str);
    return str;
}

void deleteString(String *s) {
    free(s->str);
    free(s);
}

void printString(String *s) {
    printf("String: %s\n", s->str);
    printf("Length: %d\n", s->len);
}

int main() {
    String *s1 = createString("Hello");
    String *s2 = createString("World");
    String *s3 = concatStrings(s1, s2);
    String *s4 = copyString(s3);
    deleteString(s3);
    printString(s1);
    printString(s2);
    printString(s4);
    return 0;
}