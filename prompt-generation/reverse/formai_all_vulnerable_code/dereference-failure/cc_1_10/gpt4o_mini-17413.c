//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_ITEM_NAME_LENGTH 50
#define INITIAL_CAPACITY 10

typedef struct {
    char item[MAX_ITEM_NAME_LENGTH];
    float price;
} Purchase;

typedef struct {
    Purchase *purchases;
    int totalPurchases;
    int capacity;
} PurchaseData;

void initializePurchaseData(PurchaseData *data) {
    data->totalPurchases = 0;
    data->capacity = INITIAL_CAPACITY;
    data->purchases = malloc(data->capacity * sizeof(Purchase));
    if (data->purchases == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void addPurchase(PurchaseData *data, const char *item, float price) {
    if (data->totalPurchases >= data->capacity) {
        data->capacity *= 2;
        data->purchases = realloc(data->purchases, data->capacity * sizeof(Purchase));
        if (data->purchases == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(data->purchases[data->totalPurchases].item, item);
    data->purchases[data->totalPurchases].price = price;
    data->totalPurchases++;
}

void loadPurchases(const char *filename, PurchaseData *data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char item[MAX_ITEM_NAME_LENGTH];
        float price;
        sscanf(line, "%49[^,],%f", item, &price);
        addPurchase(data, item, price);
    }
    fclose(file);
}

float calculateAverage(PurchaseData *data) {
    float total = 0.0;
    for (int i = 0; i < data->totalPurchases; i++) {
        total += data->purchases[i].price;
    }
    return data->totalPurchases > 0 ? total / data->totalPurchases : 0;
}

void findMostBoughtItem(PurchaseData *data) {
    int *itemCount = malloc(data->totalPurchases * sizeof(int));
    char **itemNames = malloc(data->totalPurchases * sizeof(char*));

    for (int i = 0; i < data->totalPurchases; i++) {
        itemCount[i] = 0;
        itemNames[i] = strdup(data->purchases[i].item);
    }

    for (int i = 0; i < data->totalPurchases; i++) {
        for (int j = 0; j < data->totalPurchases; j++) {
            if (strcmp(data->purchases[i].item, itemNames[j]) == 0) {
                itemCount[j]++;
            }
        }
    }

    int maxCount = 0;
    char *mostBoughtItem = NULL;
    for (int i = 0; i < data->totalPurchases; i++) {
        if (itemCount[i] > maxCount) {
            maxCount = itemCount[i];
            mostBoughtItem = itemNames[i];
        }
    }

    printf("Most bought item: %s with count: %d\n", mostBoughtItem, maxCount);

    free(itemCount);
    for (int i = 0; i < data->totalPurchases; i++) {
        free(itemNames[i]);
    }
    free(itemNames);
}

void cleanupPurchaseData(PurchaseData *data) {
    free(data->purchases);
}

int main() {
    PurchaseData data;
    initializePurchaseData(&data);

    loadPurchases("purchases.csv", &data);
    
    printf("Total purchases: %d\n", data.totalPurchases);
    printf("Average purchase value: %.2f\n", calculateAverage(&data));
    
    findMostBoughtItem(&data);
    
    cleanupPurchaseData(&data);
    return 0;
}