//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct warehouse {
    int id;
    char name[50];
    char location[50];
};

void add_warehouse(struct warehouse* warehouses, int num_warehouses) {
    int new_warehouse_id = num_warehouses + 1;
    char new_warehouse_name[50];
    char new_warehouse_location[50];

    printf("Enter the name of the new warehouse: ");
    scanf("%s", new_warehouse_name);

    printf("Enter the location of the new warehouse: ");
    scanf("%s", new_warehouse_location);

    warehouses[new_warehouse_id].id = new_warehouse_id;
    strcpy(warehouses[new_warehouse_id].name, new_warehouse_name);
    strcpy(warehouses[new_warehouse_id].location, new_warehouse_location);

    printf("Warehouse added successfully.\n");
}

void remove_warehouse(struct warehouse* warehouses, int num_warehouses) {
    int warehouse_to_remove = num_warehouses - 1;
    char warehouse_name[50];
    char warehouse_location[50];

    printf("Enter the name of the warehouse to remove: ");
    scanf("%s", warehouse_name);

    printf("Enter the location of the warehouse to remove: ");
    scanf("%s", warehouse_location);

    if (strstr(warehouses[warehouse_to_remove].name, warehouse_name) == warehouse_name && strstr(warehouses[warehouse_to_remove].location, warehouse_location) == warehouse_location) {
        for (int i = warehouse_to_remove; i < num_warehouses - 1; i++) {
            strcpy(warehouses[i].name, warehouses[i + 1].name);
            strcpy(warehouses[i].location, warehouses[i + 1].location);
        }

        num_warehouses--;

        printf("Warehouse removed successfully.\n");
    } else {
        printf("Warehouse not found.\n");
    }
}

void update_warehouse(struct warehouse* warehouses, int num_warehouses, int warehouse_id) {
    char warehouse_name[50];
    char warehouse_location[50];

    printf("Enter the name of the warehouse to update: ");
    scanf("%s", warehouse_name);

    printf("Enter the new name of the warehouse: ");
    scanf("%s", warehouse_name);

    printf("Enter the new location of the warehouse: ");
    scanf("%s", warehouse_location);

    if (strstr(warehouses[warehouse_id].name, warehouse_name) == warehouse_name && strstr(warehouses[warehouse_id].location, warehouse_location) == warehouse_location) {
        strcpy(warehouses[warehouse_id].name, warehouse_name);
        strcpy(warehouses[warehouse_id].location, warehouse_location);

        printf("Warehouse updated successfully.\n");
    } else {
        printf("Warehouse not found.\n");
    }
}

void print_warehouses(struct warehouse* warehouses, int num_warehouses) {
    for (int i = 0; i < num_warehouses; i++) {
        printf("ID: %d\n", warehouses[i].id);
        printf("Name: %s\n", warehouses[i].name);
        printf("Location: %s\n", warehouses[i].location);
        printf("\n");
    }
}

int main() {
    struct warehouse warehouses[100];
    int num_warehouses = 0;

    while (1) {
        printf("1. Add Warehouse\n2. Remove Warehouse\n3. Update Warehouse\n4. Print Warehouses\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_warehouse(warehouses, num_warehouses);
                break;
            case 2:
                remove_warehouse(warehouses, num_warehouses);
                break;
            case 3:
                update_warehouse(warehouses, num_warehouses, 0);
                break;
            case 4:
                print_warehouses(warehouses, num_warehouses);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}