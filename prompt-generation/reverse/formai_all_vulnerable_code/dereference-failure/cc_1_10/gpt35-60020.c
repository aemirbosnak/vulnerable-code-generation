//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    int atomic_number;
    char symbol[3];
    char name[20];
    char electron_config[50];
} Element;

void initialize_table(Element *table[]) {
    table[0] = (Element*)malloc(sizeof(Element));
    table[0]->atomic_number = 1;
    strcpy(table[0]->symbol, "H");
    strcpy(table[0]->name, "Hydrogen");
    strcpy(table[0]->electron_config, "1s^1");

    table[1] = (Element*)malloc(sizeof(Element));
    table[1]->atomic_number = 2;
    strcpy(table[1]->symbol, "He");
    strcpy(table[1]->name, "Helium");
    strcpy(table[1]->electron_config, "1s^2");

    table[2] = (Element*)malloc(sizeof(Element));
    table[2]->atomic_number = 3;
    strcpy(table[2]->symbol, "Li");
    strcpy(table[2]->name, "Lithium");
    strcpy(table[2]->electron_config, "[He]2s^1");

    table[3] = (Element*)malloc(sizeof(Element));
    table[3]->atomic_number = 4;
    strcpy(table[3]->symbol, "Be");
    strcpy(table[3]->name, "Beryllium");
    strcpy(table[3]->electron_config, "[He]2s^2");

    table[4] = (Element*)malloc(sizeof(Element));
    table[4]->atomic_number = 5;
    strcpy(table[4]->symbol, "B");
    strcpy(table[4]->name, "Boron");
    strcpy(table[4]->electron_config, "[He]2s^2 2p^1");

    table[5] = (Element*)malloc(sizeof(Element));
    table[5]->atomic_number = 6;
    strcpy(table[5]->symbol, "C");
    strcpy(table[5]->name, "Carbon");
    strcpy(table[5]->electron_config, "[He]2s^2 2p^2");

    table[6] = (Element*)malloc(sizeof(Element));
    table[6]->atomic_number = 7;
    strcpy(table[6]->symbol, "N");
    strcpy(table[6]->name, "Nitrogen");
    strcpy(table[6]->electron_config, "[He]2s^2 2p^3");

    table[7] = (Element*)malloc(sizeof(Element));
    table[7]->atomic_number = 8;
    strcpy(table[7]->symbol, "O");
    strcpy(table[7]->name, "Oxygen");
    strcpy(table[7]->electron_config, "[He]2s^2 2p^4");

    table[8] = (Element*)malloc(sizeof(Element));
    table[8]->atomic_number = 9;
    strcpy(table[8]->symbol, "F");
    strcpy(table[8]->name, "Fluorine");
    strcpy(table[8]->electron_config, "[He]2s^2 2p^5");

    table[9] = (Element*)malloc(sizeof(Element));
    table[9]->atomic_number = 10;
    strcpy(table[9]->symbol, "Ne");
    strcpy(table[9]->name, "Neon");
    strcpy(table[9]->electron_config, "[He]2s^2 2p^6");
}

void print_table(Element *table[]) {
    printf("-----------------------------------------------------------\n");
    printf("| Atomic Number | Symbol |      Name      | Electron Config |\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("| %13d | %6s | %14s | %15s |\n", table[i]->atomic_number, table[i]->symbol, table[i]->name, table[i]->electron_config);
    }
    printf("-----------------------------------------------------------\n");
}

int main() {
    Element *table[10];

    initialize_table(table);
    print_table(table);

    return 0;
}