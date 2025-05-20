//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double price;
    int volume;
} stock;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <stock_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *stock_name = argv[1];
    stock *stock = malloc(sizeof(stock));
    if (stock == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    FILE *file = fopen("stocks.csv", "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        if (strcmp(name, stock_name) == 0) {
            char *price = strtok(NULL, ",");
            char *volume = strtok(NULL, ",");
            stock->name = strdup(name);
            stock->price = atof(price);
            stock->volume = atoi(volume);
            break;
        }
    }

    fclose(file);

    if (stock->name == NULL) {
        fprintf(stderr, "Stock not found: %s\n", stock_name);
        return EXIT_FAILURE;
    }

    printf("Name: %s\n", stock->name);
    printf("Price: %f\n", stock->price);
    printf("Volume: %d\n", stock->volume);

    free(stock->name);
    free(stock);

    return EXIT_SUCCESS;
}