//Falcon-180B DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ATTRIBUTES 10
#define MAX_VALUE_LENGTH 50

struct attribute {
    char name[MAX_VALUE_LENGTH];
    int type;
};

struct item {
    int id;
    struct attribute *attributes;
    int num_attributes;
};

struct item *items;
int num_items;

void load_items() {
    FILE *fp;
    char line[MAX_VALUE_LENGTH];
    char *token;
    int i;

    fp = fopen("items.txt", "r");
    if (fp == NULL) {
        printf("Error loading items.\n");
        exit(1);
    }

    num_items = 0;
    items = malloc(MAX_ITEMS * sizeof(struct item));

    while (fgets(line, MAX_VALUE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        items[num_items].id = atoi(token);

        items[num_items].attributes = malloc(MAX_ATTRIBUTES * sizeof(struct attribute));
        items[num_items].num_attributes = 0;

        for (i = 0; i < MAX_ATTRIBUTES; i++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                break;
            }

            strcpy(items[num_items].attributes[i].name, token);
            items[num_items].attributes[i].type = 0;
        }

        num_items++;
    }

    fclose(fp);
}

void save_items(struct item *items, int num_items, FILE *fp) {
    int i, j;

    for (i = 0; i < num_items; i++) {
        fprintf(fp, "%d,", items[i].id);

        for (j = 0; j < items[i].num_attributes; j++) {
            fprintf(fp, "%s,", items[i].attributes[j].name);
        }

        fprintf(fp, "\n");
    }
}

void print_items() {
    int i, j;

    for (i = 0; i < num_items; i++) {
        printf("%d:\n", items[i].id);

        for (j = 0; j < items[i].num_attributes; j++) {
            printf("%s\n", items[i].attributes[j].name);
        }

        printf("\n");
    }
}

int main() {
    load_items();

    print_items();

    return 0;
}