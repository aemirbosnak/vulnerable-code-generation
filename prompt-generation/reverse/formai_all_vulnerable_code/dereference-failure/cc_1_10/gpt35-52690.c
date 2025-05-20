//FormAI DATASET v1.0 Category: String manipulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expand_string(char* str, int n) {
    char* new_str = (char*) malloc(n * sizeof(char));
    int len = strlen(str);
    int mid = len / 2;
    int i, j, k;
    
    for(i = 0, j = 0; i < n; i++, j++) {
        if(i < mid) {
            new_str[i] = str[j];
        } else {
            for(k = 0; k < i - mid; k++) {
                new_str[i] = str[j - mid];
            }
            new_str[i] = str[j - mid];
        }
    }
    new_str[n] = '\0';
    
    return new_str;
}

int main() {
    char str1[] = "hello";
    char* str2 = "world";
    char* combined_str = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    int i;
    
    strcpy(combined_str, str1);
    strcat(combined_str, str2);
    
    printf("Original string: %s\n", combined_str);
    
    char* expanded_str = expand_string(combined_str, 15);
    
    printf("Expanded string: %s\n", expanded_str);
    
    for(i = 0; i < strlen(expanded_str); i++) {
        if(i % 2 == 0) {
            expanded_str[i] = toupper(expanded_str[i]);
        } else {
            expanded_str[i] = tolower(expanded_str[i]);
        }
    }
    
    printf("Transformed string: %s\n", expanded_str);
    
    free(expanded_str);
    free(combined_str);
    
    return 0;
}