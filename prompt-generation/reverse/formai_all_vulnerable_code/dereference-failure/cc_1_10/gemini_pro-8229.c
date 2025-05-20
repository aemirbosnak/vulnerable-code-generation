//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// STOCK MARKET TICKER ..

typedef struct stock_node
{
    char code[11];
    char name[21];
    float ltp;
    int qty;
    struct stock_node *next;
} stock_node;

typedef struct buyer_queue
{
    char code[11];
    int qty;
    int price;
    struct buyer_queue *next;
} buyer_queue;

typedef struct seller_queue
{
    char code[11];
    int qty;
    int price;
    struct seller_queue *next;
} seller_queue;

stock_node *stock_head = NULL;
buyer_queue *buyer_head = NULL;
seller_queue *seller_head = NULL;

void add_stock(char code[], char name[], float ltp, int qty)
{
    stock_node *new_stock = (stock_node *)malloc(sizeof(stock_node));
    strcpy(new_stock->code, code);
    strcpy(new_stock->name, name);
    new_stock->ltp = ltp;
    new_stock->qty = qty;
    new_stock->next = stock_head;
    stock_head = new_stock;
}

void add_buyer(char code[], int qty, int price)
{
    buyer_queue *new_buyer = (buyer_queue *)malloc(sizeof(buyer_queue));
    strcpy(new_buyer->code, code);
    new_buyer->qty = qty;
    new_buyer->price = price;
    new_buyer->next = buyer_head;
    buyer_head = new_buyer;
}

void add_seller(char code[], int qty, int price)
{
    seller_queue *new_seller = (seller_queue *)malloc(sizeof(seller_queue));
    strcpy(new_seller->code, code);
    new_seller->qty = qty;
    new_seller->price = price;
    new_seller->next = seller_head;
    seller_head = new_seller;
}

void print_stock()
{
    stock_node *temp = stock_head;
    while (temp != NULL)
    {
        printf("%s %s %.2f %d\n", temp->code, temp->name, temp->ltp, temp->qty);
        temp = temp->next;
    }
}

void print_buyer()
{
    buyer_queue *temp = buyer_head;
    while (temp != NULL)
    {
        printf("%s %d %d\n", temp->code, temp->qty, temp->price);
        temp = temp->next;
    }
}

void print_seller()
{
    seller_queue *temp = seller_head;
    while (temp != NULL)
    {
        printf("%s %d %d\n", temp->code, temp->qty, temp->price);
        temp = temp->next;
    }
}

int main()
{
    add_stock("RELIANCE", "Reliance Industries Limited", 2000.00, 100000);
    add_stock("TATASTEEL", "Tata Steel Limited", 1200.00, 50000);
    add_stock("HDFC", "HDFC Bank Limited", 1500.00, 75000);

    add_buyer("RELIANCE", 5000, 2020.00);
    add_buyer("TATASTEEL", 3000, 1220.00);
    add_buyer("HDFC", 4000, 1520.00);

    add_seller("RELIANCE", 4000, 1980.00);
    add_seller("TATASTEEL", 2000, 1180.00);
    add_seller("HDFC", 3000, 1480.00);

    print_stock();
    printf("\n\n");
    print_buyer();
    printf("\n\n");
    print_seller();

    return 0;
}