//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int length;
} String;

String* createString(char *str) {
    String *s = (String*)malloc(sizeof(String));
    s->data = strdup(str);
    s->length = strlen(str);
    return s;
}

void destroyString(String *s) {
    free(s->data);
    free(s);
}

void printString(String *s) {
    printf("%s", s->data);
}

int compareStrings(String *s1, String *s2) {
    return strcmp(s1->data, s2->data);
}

void addString(String *dest, String *src) {
    int len = dest->length + src->length;
    char *temp = (char*)malloc(len + 1);
    strcpy(temp, dest->data);
    strcat(temp, src->data);
    free(dest->data);
    dest->data = temp;
    dest->length = len;
}

int main() {
    char input[MAX_SIZE];
    String *result = NULL;
    int n, i;

    printf("Enter a list of strings (up to %d):\n", MAX_SIZE);
    fgets(input, MAX_SIZE, stdin);
    n = strlen(input);

    for (i = 0; i < n; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            String *s = createString(&input[i + 1]);
            if (result == NULL) {
                result = s;
            } else {
                addString(result, s);
            }
            i += s->length + 1;
        }
    }

    printf("Longest string: ");
    printString(result);

    destroyString(result);
    return 0;
}