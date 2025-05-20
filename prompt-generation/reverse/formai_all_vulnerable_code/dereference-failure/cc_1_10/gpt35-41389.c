//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELD 128

typedef struct {
    int id;
    char name[MAX_FIELD];
    float price;
} Item;

int main() {
    char line[MAX_LINE];
    char *token;
    char *delimiter = ",";
    int line_count = 0;
    Item items[MAX_LINE];

    FILE *file = fopen("items.csv", "r");
    if (!file) {
        printf("Could not open file.\n");
        return 0;
    }

    while (fgets(line, MAX_LINE, file)) {
        if (line_count == 0) {
            // skip header line
            line_count++;
            continue;
        }

        Item item;

        token = strtok(line, delimiter);
        item.id = atoi(token);

        token = strtok(NULL, delimiter);
        strcpy(item.name, token);

        token = strtok(NULL, delimiter);
        item.price = strtof(token, NULL);

        items[line_count-1] = item;
        line_count++;
    }

    fclose(file);

    printf("ID\tName\tPrice\n");
    for (int i = 0; i < line_count-1; i++) {
        Item item = items[i];
        printf("%d\t%s\t%.2f\n", item.id, item.name, item.price);
    }

    return 0;
}