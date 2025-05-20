//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: secure
#include <stdio.h>
#include <string.h>

/* Function to sanitize user input */
void sanitize(char *input) {
    int i, j;
    char temp;

    /* Remove leading and trailing whitespaces */
    while(input[0] == ' ') {
        strcpy(input, input+1);
    }
    while(input[strlen(input)-1] == ' ') {
        input[strlen(input)-1] = '\0';
    }

    /* Remove non-alphanumeric characters */
    for(i=0; input[i]!='\0'; i++) {
        while(!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && !(input[i] >= '0' && input[i] <= '9')) {
            for(j=i; input[j]!='\0'; j++) {
                input[j] = input[j+1];
            }
            input[j] = '\0';
        }
    }

    /* Convert string to lowercase */
    for(i=0; input[i]!='\0'; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }
    }

    /* Remove duplicates */
    for(i=0; input[i]!='\0'; i++) {
        for(j=i+1; input[j]!='\0'; j++) {
            if(input[j] == input[i]) {
                for(int k=j; input[k]!='\0'; k++) {
                    input[k] = input[k+1];
                }
                input[j] = '\0';
            }
        }
    }
}

int main() {
    char input[100];

    printf("Enter your name: ");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized name: %s\n", input);

    printf("Enter your email address: ");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized email address: %s\n", input);

    printf("Enter your phone number: ");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized phone number: %s\n", input);

    return 0;
}