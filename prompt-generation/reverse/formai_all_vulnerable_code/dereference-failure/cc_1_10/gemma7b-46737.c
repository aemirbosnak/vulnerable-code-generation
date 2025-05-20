//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERT_NUMBER 1000000

typedef struct Unit {
    char name[20];
    int multiplier;
    struct Unit* next;
} Unit;

Unit* createUnit(char* name, int multiplier) {
    Unit* unit = malloc(sizeof(Unit));
    strcpy(unit->name, name);
    unit->multiplier = multiplier;
    unit->next = NULL;
    return unit;
}

void addUnit(Unit* head, char* name, int multiplier) {
    Unit* newUnit = createUnit(name, multiplier);
    if (head == NULL) {
        head = newUnit;
    } else {
        Unit* lastUnit = head;
        while (lastUnit->next) {
            lastUnit = lastUnit->next;
        }
        lastUnit->next = newUnit;
    }
}

void convertUnits(Unit* head, int number) {
    int convertedNumber = 0;
    Unit* currentUnit = head;
    while (currentUnit) {
        int unitMultiplier = currentUnit->multiplier;
        char* unitName = currentUnit->name;
        int units = number / unitMultiplier;
        number %= unitMultiplier;
        convertedNumber += units * unitMultiplier;
        printf("%d %s ", units, unitName);
        if (units > 0) {
            printf(", ");
        }
        currentUnit = currentUnit->next;
    }
    printf("\n");
    printf("Converted number: %d\n", convertedNumber);
}

int main() {
    Unit* head = createUnit("kg", 1000);
    addUnit(head, "g", 1000);
    addUnit(head, "mg", 1000);
    addUnit(head, "L", 1000);
    addUnit(head, "ml", 1000);
    addUnit(head, "dl", 1000);
    convertUnits(head, 2500);

    return 0;
}