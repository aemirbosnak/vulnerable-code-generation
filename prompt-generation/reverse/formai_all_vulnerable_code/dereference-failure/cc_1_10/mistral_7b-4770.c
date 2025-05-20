//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void print_char_at_index(char *str, int index) {
    if (index >= 0 && index < strlen(str)) {
        printf("%c", str[index]);
    } else {
        printf("Index out of range\n");
    }
}

void print_string_length(char *str) {
    printf("Length of string: %ld\n", strlen(str));
}

int main() {
    char user_input[MAX_LENGTH];
    char *manipulated_string;
    int choice;

    printf("Enter a string: ");
    fgets(user_input, MAX_LENGTH, stdin);

    manipulated_string = malloc(strlen(user_input) + 1);
    strcpy(manipulated_string, user_input);

    do {
        printf("\n1. Reverse String\n");
        printf("2. Print Char at Index\n");
        printf("3. Print String Length\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverse_string(manipulated_string);
                printf("Reversed String: %s\n", manipulated_string);
                break;
            case 2:
                printf("Enter index: ");
                int index;
                scanf("%d", &index);
                print_char_at_index(manipulated_string, index);
                printf("\n");
                break;
            case 3:
                print_string_length(manipulated_string);
                printf("\n");
                break;
            case 4:
                free(manipulated_string);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (1);

    free(manipulated_string);
    return 0;
}