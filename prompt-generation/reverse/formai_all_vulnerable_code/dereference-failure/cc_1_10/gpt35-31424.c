//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

char* bold(char str[]) {
    char* res = malloc(sizeof(char) * (strlen(str) * 5));
    strcpy(res, "");
    for(int i = 0; i < strlen(str); i++) {
        char temp[10];
        sprintf(temp, " %c ", str[i]);
        strcat(res, temp);
    }
    return res;
}

char* italics(char str[]) {
    char* res = malloc(sizeof(char) * (strlen(str) * 5));
    strcpy(res, "");
    for(int i = 0; i < strlen(str); i++) {
        char temp[10];
        sprintf(temp, " %c ", str[i]);
        strcat(res, temp);
    }
    return res;
}

char* bravify(char str[]) {
    char* res = malloc(sizeof(char) * (strlen(str) * 5));
    strcpy(res, "");

    char* temp = bold(str);
    strcat(res, temp);
    free(temp);

    temp = italics(str);
    strcat(res, temp);
    free(temp);

    return res;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to bravify: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    char* output = bravify(input);

    printf("\n%s\n", output);
    free(output);

    return 0;
}