//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hexadecimal digits
typedef struct HexDigit {
    int digit;
    struct HexDigit* next;
} HexDigit;

// Function to insert a hexadecimal digit into the list
void insertDigit(HexDigit** head, int digit) {
    HexDigit* newDigit = malloc(sizeof(HexDigit));
    newDigit->digit = digit;
    newDigit->next = NULL;

    if (*head == NULL) {
        *head = newDigit;
    } else {
        (*head)->next = newDigit;
    }
}

// Function to convert a hexadecimal number to a string
char* numberToStr(HexDigit* head) {
    char* str = malloc(16);
    int i = 0;

    for (HexDigit* current = head; current; current = current->next) {
        int digit = current->digit;
        str[i++] = digit + 0x30;
    }

    str[i] = '\0';

    return str;
}

int main() {
    HexDigit* head = NULL;
    insertDigit(&head, 0x12);
    insertDigit(&head, 0x3E);
    insertDigit(&head, 0x4A);

    char* str = numberToStr(head);

    printf("The hexadecimal number is: %s\n", str);

    free(str);
    free(head);

    return 0;
}