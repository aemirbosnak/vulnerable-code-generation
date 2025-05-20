//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include<stdio.h>  

struct product {  
    int id;  
    char name[20];  
    float price;  
};  

struct node {  
    struct product item;  
    struct node *next;  
};  

void display(struct node *list) {  
    if (list == NULL) {  
        printf("List is empty\n");  
    } else {  
        printf("\nProduct Id\t\tProduct Name\t\tProduct Price\n\n");  
        while (list != NULL) {  
            printf("%d\t\t\t%s\t\t\t%0.2f\n", list->item.id, list->item.name, list->item.price);  
            list = list->next;  
        }  
    }  
}  

struct node* add(struct node *list, struct product item) {  
    struct node *new_node = (struct node*)malloc(sizeof(struct node));  
    new_node->item = item;  
    new_node->next = list;  
    list = new_node;  
    return list;  
}  

struct node* delete(struct node *list, int id) {  
    struct node *temp = list, *prev = NULL;  
    if (list == NULL) {  
        printf("List is empty\n");  
        return list;  
    }  
    if (list->item.id == id) {  
        list = list->next;  
        free(temp);  
        return list;  
    }  
    while (temp != NULL && temp->item.id != id) {  
        prev = temp;  
        temp = temp->next;  
    }  
    if (temp == NULL) {  
        printf("Product not found\n");  
        return list;  
    }  
    prev->next = temp->next;  
    free(temp);  
    return list;  
}  

void search(struct node *list, int id) {  
    if (list == NULL) {  
        printf("List is empty\n");  
    } else {  
        while (list != NULL && list->item.id != id) {  
            list = list->next;  
        }  
        if (list == NULL) {  
            printf("Product not found\n");  
        } else {  
            printf("\nProduct details:\n");  
            printf("Id: %d\nName: %s\nPrice: %0.2f\n", list->item.id, list->item.name, list->item.price);  
        }  
    }  
}  

int main() {  
    struct node *list = NULL;  
    int choice, id;  
    struct product item;  
    do {  
        printf("\n1. Display\n2. Add\n3. Delete\n4. Search\n5. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        switch(choice) {  
            case 1:  
                display(list);  
                break;  
            case 2:  
                printf("\nEnter product id: ");  
                scanf("%d", &item.id);  
                printf("Enter product name: ");  
                scanf("%s", item.name);  
                printf("Enter product price: ");  
                scanf("%f", &item.price);  
                list = add(list, item);  
                printf("\nProduct added successfully\n");  
                break;  
            case 3:  
                printf("\nEnter product id to delete: ");  
                scanf("%d", &id);  
                list = delete(list, id);  
                printf("\nProduct deleted successfully\n");  
                break;  
            case 4:  
                printf("\nEnter product id to search: ");  
                scanf("%d", &id);  
                search(list, id);  
                break;  
            case 5:  
                printf("\nExiting...\n");  
                break;  
            default:  
                printf("\nInvalid choice\n");  
        }  
    } while (choice != 5);  
    return 0;  
}