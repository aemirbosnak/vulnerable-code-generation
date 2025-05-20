//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        char name[50];
        int quantity;
        float price;
    } Medicine;

    Medicine *stock;
    int num_medicines = 0;
    int capacity = 10;

    void init_stock() {
        stock = (Medicine*)malloc(capacity * sizeof(Medicine));
        strcpy(stock[0].name, "Paracetamol");
        stock[0].quantity = 100;
        stock[0].price = 10.0;
        strcpy(stock[1].name, "Ibuprofen");
        stock[1].quantity = 50;
        stock[1].price = 15.0;
        strcpy(stock[2].name, "Aspirin");
        stock[2].quantity = 25;
        stock[2].price = 5.0;
        num_medicines = 3;
    }

    void add_medicine(char *name, int quantity, float price) {
        if (num_medicines == capacity) {
            capacity *= 2;
            stock = (Medicine*)realloc(stock, capacity * sizeof(Medicine));
        }
        strcpy(stock[num_medicines].name, name);
        stock[num_medicines].quantity = quantity;
        stock[num_medicines].price = price;
        num_medicines++;
    }

    void remove_medicine(char *name) {
        int i;
        for (i = 0; i < num_medicines; i++) {
            if (strcmp(stock[i].name, name) == 0) {
                break;
            }
        }
        if (i == num_medicines) {
            printf("Medicine not found\n");
            return;
        }
        for (; i < num_medicines - 1; i++) {
            stock[i] = stock[i + 1];
        }
        num_medicines--;
    }

    void update_medicine(char *name, int quantity, float price) {
        int i;
        for (i = 0; i < num_medicines; i++) {
            if (strcmp(stock[i].name, name) == 0) {
                break;
            }
        }
        if (i == num_medicines) {
            printf("Medicine not found\n");
            return;
        }
        stock[i].quantity = quantity;
        stock[i].price = price;
    }

    void print_stock() {
        int i;
        for (i = 0; i < num_medicines; i++) {
            printf("%s %d %.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
        }
    }

    int main() {
        init_stock();
        add_medicine("Amoxicillin", 50, 20.0);
        remove_medicine("Aspirin");
        update_medicine("Ibuprofen", 100, 18.0);
        print_stock();
        return 0;
    }