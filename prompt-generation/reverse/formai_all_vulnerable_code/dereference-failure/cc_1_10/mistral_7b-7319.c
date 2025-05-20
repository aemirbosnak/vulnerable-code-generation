//MISTRAL-7B DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TABLE_SIZE 10
#define MAX_PATTERN_LEN 10

typedef struct Pattern {
    char pattern[MAX_PATTERN_LEN];
    int hash;
} Pattern;

Pattern patterns[TABLE_SIZE] = {{"ATTACK1", 0}, {"ATTACK2", 0}, {"NORMAL", 0}};

int hash_func(char *str) {
    int hash = 0, i;
    for (i = 0; i < strlen(str); i++)
        hash += (str[i] << (i % 3));
    return hash % TABLE_SIZE;
}

int check_pattern(char *input) {
    int idx = hash_func(input);
    Pattern *pattern = &patterns[idx];
    if (strcmp(pattern->pattern, "NORMAL") == 0)
        return 1;
    if (strlen(input) != strlen(pattern->pattern))
        return 1;
    for (int i = 0; i < strlen(input); i++)
        if (input[i] != pattern->pattern[i])
            return 1;
    return 0;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter input: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (check_pattern(input)) {
            printf("Warning: Possible intrusion detected!\n");
            printf("Input: %s\n", input);
            sleep(3);
        } else {
            printf("Input: %s\n", input);
        }
    }
    return 0;
}