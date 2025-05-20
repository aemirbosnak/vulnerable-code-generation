//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Curious little functions!
char *jumble(char *s) {
    char *t = malloc(strlen(s) + 1);
    int i, j, k;
    for (i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--) {
        t[i] = s[j];
    }
    t[strlen(s)] = '\0';
    return t;
}

char *mirror(char *s) {
    char *t = malloc(strlen(s) + 1);
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--) {
        t[i] = s[j];
    }
    t[strlen(s)] = '\0';
    return t;
}

char *shuffle(char *s) {
    char *t = malloc(strlen(s) + 1);
    int i, j;
    for (i = 0, j = strlen(s) / 2; i < strlen(s); i++, j++) {
        t[i] = s[j];
    }
    for (i = strlen(s) / 2, j = 0; i < strlen(s); i++, j++) {
        t[i] = s[j];
    }
    t[strlen(s)] = '\0';
    return t;
}

// Main function, where the magic happens!
int main() {
    char s[101];
    int i;

    printf("Enter a string: ");
    scanf("%s", s);

    printf("\nCurious transformations:\n\n");
    printf("Jumbled:   %s\n", jumble(s));
    printf("Mirrored:  %s\n", mirror(s));
    printf("Shuffled:  %s\n", shuffle(s));

    return 0;
}