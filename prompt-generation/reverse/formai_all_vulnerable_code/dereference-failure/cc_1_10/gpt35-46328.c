//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

typedef struct medicine {
    char name[20];
    int id;
    int qty;
    float price;
    struct medicine *next;
} medicine;

medicine *head = NULL;
int count = 0;

void addMedicine() {
    printf("Enter details of medicine\n");
    medicine *temp = (medicine*) malloc(sizeof (medicine));
    printf("Enter Name : ");
    scanf("%s", temp->name);
    printf("Enter Id : ");
    scanf("%d", &temp->id);
    printf("Enter Quantity : ");
    scanf("%d", &temp->qty);
    printf("Enter Price : ");
    scanf("%f", &temp->price);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        medicine *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
    count++;
}

void display() {
    if (count == 0) {
        printf("No medicines available\n");
    } else {
        medicine *cur = head;
        printf("Medicine Details : \n");
        printf("Name\tId\tQuantity\tPrice\n");
        while (cur != NULL) {
            printf("%s\t%d\t%d\t\t%.2f\n", cur->name, cur->id, cur->qty, cur->price);
            cur = cur->next;
        }
    }
}

void search() {
    int id;
    printf("Enter Id : ");
    scanf("%d", &id);
    medicine *cur = head;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("Medicine Details : \n");
            printf("Name\tId\tQuantity\tPrice\n");
            printf("%s\t%d\t%d\t\t%.2f\n", cur->name, cur->id, cur->qty, cur->price);
            return;
        }
        cur = cur->next;
    }
    printf("Medicine not found\n");
}

void modify() {
    int id;
    printf("Enter Id : ");
    scanf("%d", &id);
    medicine *cur = head;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("Enter new details of medicine\n");
            printf("Enter Name : ");
            scanf("%s", cur->name);
            printf("Enter Quantity : ");
            scanf("%d", &cur->qty);
            printf("Enter Price : ");
            scanf("%f", &cur->price);
            return;
        }
        cur = cur->next;
    }
    printf("Medicine not found\n");
}

void delete() {
    int id;
    printf("Enter Id : ");
    scanf("%d", &id);
    medicine *cur1 = head;
    medicine *prev = NULL;
    while (cur1 != NULL) {
        if (cur1->id == id) {
            if (prev == NULL) {
                head = cur1->next;
            } else {
                prev->next = cur1->next;
            }
            free(cur1);
            count--;
            printf("Medicine deleted successfully\n");
            return;
        }
        prev = cur1;
        cur1 = cur1->next;
    }
    printf("Medicine not found\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter choice :\n1.Add Medicine\n2.Display Medicines\n3.Search Medicine\n4.Modify Medicine\n5.Delete Medicine\n6.Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                modify();
                break;
            case 5:
                delete();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}