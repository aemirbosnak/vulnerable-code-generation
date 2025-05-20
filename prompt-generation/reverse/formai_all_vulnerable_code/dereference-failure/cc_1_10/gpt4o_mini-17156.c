//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Knight {
    char *name;
    int voltage;
    int current;
    int resistance;
    int power;
} Knight;

void declareKnight(Knight *knight, char *name, int voltage, int current) {
    knight->name = name;
    knight->voltage = voltage;
    knight->current = current;
    knight->resistance = voltage / current; 
    knight->power = voltage * current; 
}

void doBattle(Knight *knight1, Knight *knight2) {
    printf("Upon the noble jousting grounds, %s shall face %s!\n", knight1->name, knight2->name);
    printf("Behold the combatants strength:\n");
    printf("%s: Voltage - %dV, Current - %dA\n", knight1->name, knight1->voltage, knight1->current);
    printf("%s: Voltage - %dV, Current - %dA\n", knight2->name, knight2->voltage, knight2->current);
    
    if (knight1->power > knight2->power) {
        printf("%s emerges victorious with a power of %dW! Glory be unto him!\n", knight1->name, knight1->power);
    } else if (knight1->power < knight2->power) {
        printf("%s prevails triumphantly with a power of %dW! Honor to his name!\n", knight2->name, knight2->power);
    } else {
        printf("A stalemate! Both knights possess equal power of %dW! Let it be a draw!\n", knight1->power);
    }
    printf("\n");
}

void performRitual() {
    printf("In the sacred realm of Ohm's Law, we shall now perform a ritual:\n");
    printf("Voltage = Current * Resistance. Fear not the enlightenment!\n\n");
}

int main() {
    Knight *sirGalen = malloc(sizeof(Knight));
    Knight *sirElrik = malloc(sizeof(Knight));

    declareKnight(sirGalen, "Sir Galen", 12, 3);
    declareKnight(sirElrik, "Sir Elrik", 9, 3);

    performRitual();

    doBattle(sirGalen, sirElrik);

    free(sirGalen);
    free(sirElrik);

    return 0;
}