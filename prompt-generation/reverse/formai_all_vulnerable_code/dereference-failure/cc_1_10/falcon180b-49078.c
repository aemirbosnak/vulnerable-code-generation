//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float cost;
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    FILE *file = fopen("items.txt", "r");
    if (file == NULL) {
        printf("Error: items.txt not found\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        char *description = strtok(NULL, ",");
        float cost = atof(strtok(NULL, ","));

        strcpy(items[num_items].name, name);
        strcpy(items[num_items].description, description);
        items[num_items].cost = cost;

        num_items++;
    }

    fclose(file);

    FILE *output_file = fopen("expenses.txt", "w");
    if (output_file == NULL) {
        printf("Error: expenses.txt could not be created\n");
        return 1;
    }

    printf("Enter expenses:\n");
    while (fgets(line, sizeof(line), stdin)!= NULL) {
        char *name = strtok(line, ",");
        char *description = strtok(NULL, ",");
        float cost = atof(strtok(NULL, ","));

        int i;
        for (i = 0; i < num_items; i++) {
            if (strcmp(items[i].name, name) == 0) {
                printf("Item found: %s\n", name);
                fprintf(output_file, "%s,%s,%.2f\n", name, description, cost);
                break;
            }
        }

        if (i == num_items) {
            printf("Item not found\n");
        }
    }

    fclose(output_file);

    return 0;
}