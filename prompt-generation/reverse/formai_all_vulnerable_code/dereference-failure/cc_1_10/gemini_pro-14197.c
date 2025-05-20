//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction {
    int id;
    char *items;
};

struct itemset {
    int id;
    char *items;
    int support;
};

struct frequent_itemset {
    int id;
    char *items;
    int support;
};

int compare_transactions(const void *a, const void *b) {
    struct transaction *t1 = (struct transaction *)a;
    struct transaction *t2 = (struct transaction *)b;

    return strcmp(t1->items, t2->items);
}

int compare_itemsets(const void *a, const void *b) {
    struct itemset *i1 = (struct itemset *)a;
    struct itemset *i2 = (struct itemset *)b;

    return i1->support - i2->support;
}

int compare_frequent_itemsets(const void *a, const void *b) {
    struct frequent_itemset *f1 = (struct frequent_itemset *)a;
    struct frequent_itemset *f2 = (struct frequent_itemset *)b;

    return f1->support - f2->support;
}

int main() {
    // Read the transactions from a file
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int num_transactions = 0;
    fscanf(file, "%d\n", &num_transactions);

    struct transaction *transactions = malloc(sizeof(struct transaction) * num_transactions);
    for (int i = 0; i < num_transactions; i++) {
        transactions[i].id = i;
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, file);
        transactions[i].items = strdup(line);
    }

    fclose(file);

    // Sort the transactions by their items
    qsort(transactions, num_transactions, sizeof(struct transaction), compare_transactions);

    // Create a list of unique items
    struct itemset *items = NULL;
    int num_items = 0;
    for (int i = 0; i < num_transactions; i++) {
        char *item = strtok(transactions[i].items, " ");
        while (item != NULL) {
            int found = 0;
            for (int j = 0; j < num_items; j++) {
                if (strcmp(item, items[j].items) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                items = realloc(items, sizeof(struct itemset) * (num_items + 1));
                items[num_items].id = num_items;
                items[num_items].items = strdup(item);
                items[num_items].support = 0;
                num_items++;
            }

            item = strtok(NULL, " ");
        }
    }

    // Calculate the support for each item
    for (int i = 0; i < num_transactions; i++) {
        char *item = strtok(transactions[i].items, " ");
        while (item != NULL) {
            for (int j = 0; j < num_items; j++) {
                if (strcmp(item, items[j].items) == 0) {
                    items[j].support++;
                    break;
                }
            }

            item = strtok(NULL, " ");
        }
    }

    // Sort the items by their support
    qsort(items, num_items, sizeof(struct itemset), compare_itemsets);

    // Find the frequent itemsets
    struct frequent_itemset *frequent_itemsets = NULL;
    int num_frequent_itemsets = 0;
    for (int i = 0; i < num_items; i++) {
        if (items[i].support >= 2) {
            frequent_itemsets = realloc(frequent_itemsets, sizeof(struct frequent_itemset) * (num_frequent_itemsets + 1));
            frequent_itemsets[num_frequent_itemsets].id = items[i].id;
            frequent_itemsets[num_frequent_itemsets].items = strdup(items[i].items);
            frequent_itemsets[num_frequent_itemsets].support = items[i].support;
            num_frequent_itemsets++;
        }
    }

    // Sort the frequent itemsets by their support
    qsort(frequent_itemsets, num_frequent_itemsets, sizeof(struct frequent_itemset), compare_frequent_itemsets);

    // Print the frequent itemsets
    for (int i = 0; i < num_frequent_itemsets; i++) {
        printf("%s (%d)\n", frequent_itemsets[i].items, frequent_itemsets[i].support);
    }

    // Free the memory
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].items);
    }
    free(transactions);

    for (int i = 0; i < num_items; i++) {
        free(items[i].items);
    }
    free(items);

    for (int i = 0; i < num_frequent_itemsets; i++) {
        free(frequent_itemsets[i].items);
    }
    free(frequent_itemsets);

    return EXIT_SUCCESS;
}