//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int age;
};

struct database {
    struct customer customers[10];
    int num_customers;
};

struct customer* find_customer(struct database* db, char* name) {
    for (int i = 0; i < db->num_customers; i++) {
        if (strcmp(db->customers[i].name, name) == 0) {
            return &(db->customers[i]);
        }
    }
    return NULL;
}

void add_customer(struct database* db, char* name, int age) {
    struct customer* customer = malloc(sizeof(struct customer));
    strcpy(customer->name, name);
    customer->age = age;
    if (db->num_customers >= 10) {
        printf("Database is full.\n");
        return;
    }
    db->customers[db->num_customers++] = *customer;
    printf("Customer '%s' added to the database.\n", name);
}

void delete_customer(struct database* db, char* name) {
    struct customer* customer = find_customer(db, name);
    if (customer!= NULL) {
        for (int i = customer->age; i < db->num_customers - 1; i++) {
            db->customers[i] = db->customers[i + 1];
        }
        db->num_customers--;
        printf("Customer '%s' deleted from the database.\n", name);
    } else {
        printf("Customer '%s' not found in the database.\n", name);
    }
}

int main() {
    struct database db;
    db.num_customers = 0;

    add_customer(&db, "John Doe", 25);
    add_customer(&db, "Jane Doe", 30);
    add_customer(&db, "Mike Smith", 35);

    printf("Database:\n");
    for (int i = 0; i < db.num_customers; i++) {
        printf("%d. %s, age: %d\n", i + 1, db.customers[i].name, db.customers[i].age);
    }

    delete_customer(&db, "John Doe");
    printf("\nDatabase after deletion:\n");
    for (int i = 0; i < db.num_customers; i++) {
        printf("%d. %s, age: %d\n", i + 1, db.customers[i].name, db.customers[i].age);
    }

    return 0;
}