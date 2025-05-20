//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ConverTER_SIZE 10

typedef struct Converter {
    char name[MAX_ConverTER_SIZE];
    double conversion_factor;
    struct Converter* next;
} Converter;

Converter* head = NULL;

void add_converter(char* name, double factor) {
    Converter* new_converter = (Converter*)malloc(sizeof(Converter));
    strcpy(new_converter->name, name);
    new_converter->conversion_factor = factor;
    new_converter->next = NULL;

    if (head == NULL) {
        head = new_converter;
    } else {
        Converter* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_converter;
    }
}

double convert(char* source_unit, char* target_unit, double value) {
    Converter* current = head;
    while (current) {
        if (strcmp(current->name, source_unit) == 0 && strcmp(current->name, target_unit) == 0) {
            return value * current->conversion_factor;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    add_converter("kg", 1.0);
    add_converter("g", 1000.0);
    add_converter("mg", 1000000.0);
    add_converter("L", 1000.0);
    add_converter("ml", 1000.0);
    add_converter("dl", 1000.0);

    double result = convert("g", "kg", 50);
    if (result != -1) {
        printf("%lf kg", result);
    } else {
        printf("Error converting units");
    }

    return 0;
}