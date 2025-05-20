//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TemperatureConverter
{
    char unit;
    double value;
    struct TemperatureConverter* next;
} TemperatureConverter;

void insertTemperatureConverter(TemperatureConverter** head, char unit, double value)
{
    TemperatureConverter* newNode = malloc(sizeof(TemperatureConverter));
    newNode->unit = unit;
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

double convertTemperature(TemperatureConverter* head, char targetUnit, double value)
{
    TemperatureConverter* current = head;

    while (current)
    {
        if (current->unit == targetUnit)
        {
            return value * current->value;
        }
        current = current->next;
    }

    return -1;
}

int main()
{
    TemperatureConverter* head = NULL;

    insertTemperatureConverter(&head, 'C', 20.0);
    insertTemperatureConverter(&head, 'F', 68.0);
    insertTemperatureConverter(&head, 'K', 293.15);

    double convertedValue = convertTemperature(head, 'F', 20.0);

    if (convertedValue != -1)
    {
        printf("Converted value: %.2lf", convertedValue);
    }
    else
    {
        printf("Error converting temperature.");
    }

    return 0;
}