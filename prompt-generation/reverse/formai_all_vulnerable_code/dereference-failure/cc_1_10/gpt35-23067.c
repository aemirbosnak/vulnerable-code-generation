//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* s) {
    int len = strlen(s);
    char* rev = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

char* replace(char* s, char* old, char* new) {
    char* result;
    int i, cnt = 0;
    int newLen = strlen(new);
    int oldLen = strlen(old);
    
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], old) == &s[i]) {
            cnt++;
            i += oldLen - 1;
        }
    }
    
    result = (char*) malloc(i + cnt * (newLen - oldLen) + 1);
    
    i = 0;
    
    while (*s) {
        if (strstr(s, old) == s) {
            strcpy(&result[i], new);
            i += newLen;
            s += oldLen;
        } else {
            result[i++] = *s++;
        }
    }
    
    result[i] = '\0';
    return result;
}

void tokenize(char* s) {
    char* token = strtok(s, " ");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

int main() {
    char s[100], old[10], new[10];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0';
    
    printf("Reversed string: %s\n", reverse(s));
    
    printf("Enter the string you want to replace: ");
    scanf("%s", old);
    
    printf("Enter the new string: ");
    scanf("%s", new);
    
    char* replaced = replace(s, old, new);
    printf("Replaced string: %s\n", replaced);
    free(replaced);
    
    printf("Tokens:\n");
    tokenize(s);
    
    return 0;
}