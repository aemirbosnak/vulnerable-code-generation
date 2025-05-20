//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGIT 256

typedef struct Digit
{
    int number;
    struct Digit* next;
} Digit;

Digit* insertDigit(int number, Digit* head)
{
    Digit* newDigit = malloc(sizeof(Digit));
    newDigit->number = number;
    newDigit->next = NULL;

    if (head == NULL)
    {
        head = newDigit;
    }
    else
    {
        head->next = newDigit;
    }

    return head;
}

void convertBinary(Digit* head)
{
    int i = 0;
    int power = 1;
    int result = 0;

    while (head)
    {
        int digit = head->number;
        head = head->next;

        result += digit * power;
        power *= 2;
        i++;
    }

    printf("The binary equivalent of the number is: %d", result);
}

int main()
{
    Digit* head = insertDigit(13, NULL);
    insertDigit(4, head);
    insertDigit(1, head);

    convertBinary(head);

    return 0;
}