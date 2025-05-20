//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Unit {
    char name[20];
    double value;
    struct Unit* next;
} Unit;

Unit* createUnit(char* name, double value) {
    Unit* unit = malloc(sizeof(Unit));
    strcpy(unit->name, name);
    unit->value = value;
    unit->next = NULL;
    return unit;
}

void addUnit(Unit* head, char* name, double value) {
    Unit* unit = createUnit(name, value);
    if (head == NULL) {
        head = unit;
    } else {
        head->next = unit;
    }
    head = unit;
}

double convertUnits(Unit* head, char* targetUnit, double value) {
    Unit* currentUnit = head;
    double conversionFactor = 1.0;
    while (currentUnit) {
        if (strcmp(currentUnit->name, targetUnit) == 0) {
            conversionFactor = currentUnit->value;
            break;
        }
        currentUnit = currentUnit->next;
    }
    return value * conversionFactor;
}

int main() {
    Unit* head = NULL;
    addUnit(head, "kg", 10.0);
    addUnit(head, "g", 20.0);
    addUnit(head, "mg", 30.0);
    addUnit(head, "L", 10.0);
    addUnit(head, "ml", 20.0);
    addUnit(head, "dl", 30.0);

    double convertedValue = convertUnits(head, "g", 5.0);
    printf("%f g is equal to %f kg\n", 5.0, convertedValue);

    return 0;
}