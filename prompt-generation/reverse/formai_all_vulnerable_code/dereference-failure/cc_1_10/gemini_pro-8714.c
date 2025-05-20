//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A beautiful stock market tracker
 
struct stock {
    char *name;
    double price;
    double change;
};
 
struct portfolio {
    struct stock *stocks;
    int num_stocks;
};
 
// Initialize a portfolio
struct portfolio *init_portfolio(int num_stocks) {
    struct portfolio *p = malloc(sizeof(struct portfolio));
    p->stocks = malloc(sizeof(struct stock) * num_stocks);
    p->num_stocks = num_stocks;
    return p;
}
 
// Add a stock to a portfolio
void add_stock(struct portfolio *p, struct stock *s) {
    p->stocks[p->num_stocks++] = *s;
}
 
// Print a portfolio
void print_portfolio(struct portfolio *p) {
    int i;
    for (i = 0; i < p->num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%)\n", p->stocks[i].name, p->stocks[i].price, p->stocks[i].change);
    }
}
 
int main() {
    // Create a portfolio
    struct portfolio *p = init_portfolio(3);
 
    // Add some stocks to the portfolio
    struct stock s1 = {"Apple", 123.45, 1.23};
    struct stock s2 = {"Google", 987.65, -2.34};
    struct stock s3 = {"Tesla", 456.78, 3.45};
    add_stock(p, &s1);
    add_stock(p, &s2);
    add_stock(p, &s3);
 
    // Print the portfolio
    print_portfolio(p);
 
    return 0;
}