//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_DELIMITER ","
#define MAX_COLUMNS 10
#define MAX_COLUMN_LENGTH 100
#define MAX_ROWS 50

typedef struct {
    char name[MAX_COLUMN_LENGTH];
    float price;
    int quantity;
} pirate_treasure;

void parse_csv_line(char* line, pirate_treasure* treasure) {
    char* token;
    int i = 0;

    token = strtok(line, CSV_DELIMITER);

    strcpy(treasure->name, token);

    token = strtok(NULL, CSV_DELIMITER);
    treasure->price = atof(token);

    token = strtok(NULL, CSV_DELIMITER);
    treasure->quantity = atoi(token);
}

int main(int argc, char* argv[]) {
    FILE* file;
    char line[MAX_ROWS][MAX_COLUMN_LENGTH];
    pirate_treasure pirate_loot[MAX_ROWS];

    if (argc != 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int row = 0;
    while (fgets(line[row], MAX_COLUMN_LENGTH, file) != NULL) {
        parse_csv_line(line[row], &pirate_loot[row]);
        printf("Name: %s, Price: %.2f, Quantity: %d\n", pirate_loot[row].name, pirate_loot[row].price, pirate_loot[row].quantity);
        row++;

        if (row >= MAX_ROWS) {
            printf("Warning: Max number of rows reached!\n");
            break;
        }
    }

    fclose(file);

    return 0;
}