//Falcon-180B DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int frequency;
} Item;

typedef struct {
    int itemIndex;
    int quantity;
} Transaction;

typedef struct {
    char name[50];
    int index;
} Category;

Item items[MAX_ITEMS];
Transaction transactions[MAX_TRANSACTIONS];
Category categories[MAX_CATEGORIES];

void readItems(FILE *fp) {
    int i = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(items[i].name, line);
        items[i].frequency = 0;
        i++;
    }
}

void readTransactions(FILE *fp) {
    int i = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%d %d", &transactions[i].itemIndex, &transactions[i].quantity);
        i++;
    }
}

void readCategories(FILE *fp) {
    int i = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(categories[i].name, line);
        categories[i].index = i;
        i++;
    }
}

void generateAssociationRules(FILE *fp) {
    int i, j, k;
    char rule[100];
    for (i = 0; i < MAX_CATEGORIES; i++) {
        for (j = 0; j < MAX_CATEGORIES; j++) {
            if (i!= j) {
                sprintf(rule, "Category %s -> Category %s", categories[i].name, categories[j].name);
                fprintf(fp, "%s\n", rule);
            }
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "r");

    readItems(fp);
    readTransactions(fp);
    readCategories(fp);

    generateAssociationRules(fp);

    fclose(fp);
    return 0;
}