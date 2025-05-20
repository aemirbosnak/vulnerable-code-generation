//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

char* reverse_string(char* string) {
    int length = strlen(string);
    char* reversed = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; ++i) {
        reversed[i] = string[length - i - 1];
    }
    return reversed;
}

int main() {
    char buffer[BUFFER_SIZE];
    char* string;
    int option = 0;
    printf("** String Manipulation Program **\n");
    do {
        printf("Please choose an option:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate two strings\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Please enter a string:\n");
                scanf("%s", buffer);
                string = reverse_string(buffer);
                printf("Reversed string: %s\n", string);
                free(string);
                break;
            case 2:
                printf("Please enter the first string:\n");
                scanf("%s", buffer);
                printf("Please enter the second string:\n");
                char buffer2[BUFFER_SIZE];
                scanf("%s", buffer2);
                int total_length = strlen(buffer) + strlen(buffer2) + 1; // 1 for null terminator
                char* concatenated = (char*)malloc(total_length * sizeof(char));
                strcpy(concatenated, buffer);
                strcat(concatenated, buffer2);
                printf("Concatenated string: %s\n", concatenated);
                free(concatenated);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);
    return 0;
}