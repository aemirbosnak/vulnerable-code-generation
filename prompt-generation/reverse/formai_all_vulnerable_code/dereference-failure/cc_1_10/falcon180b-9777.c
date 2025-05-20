//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

String *create_string(char *str) {
    String *s = (String *) malloc(sizeof(String));
    s->string = str;
    s->length = strlen(str);
    return s;
}

void delete_string(String *s) {
    free(s);
}

int compare_strings(String *s1, String *s2) {
    if (s1->length!= s2->length) {
        return s1->length - s2->length;
    } else {
        return strcmp(s1->string, s2->string);
    }
}

int main(int argc, char **argv) {
    int num_strings = 0;
    String *strings = NULL;

    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    strings = (String *) malloc(num_strings * sizeof(String));

    for (int i = 0; i < num_strings; i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", strings[i].string);
    }

    qsort(strings, num_strings, sizeof(String), compare_strings);

    printf("\nSorted strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i].string);
    }

    return 0;
}