//FormAI DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[50];
    int room_num;
    float room_rate;
    int nights;
    int total_cost;
};

void display_menu() {
    printf("\n\t============= C Hotel Management System =============\n\n");
    printf("\t1. Check-In\n");
    printf("\t2. Check-Out\n");
    printf("\t3. Display All Customers\n");
    printf("\t4. Exit\n");
    printf("\tEnter your choice: ");
}

void check_in(struct customer* ptr) {
    printf("\n\tEnter Customer Name: ");
    scanf("%s", ptr->name);
    
    printf("\tEnter Room Number: ");
    scanf("%d", &ptr->room_num);
    
    printf("\tEnter Room Rate: ");
    scanf("%f", &ptr->room_rate);
    
    printf("\tEnter Number of Nights: ");
    scanf("%d", &ptr->nights);
    
    ptr->total_cost = ptr->nights * ptr->room_rate;
    
    printf("\t%s's total cost is: %d\n", ptr->name, ptr->total_cost);
}

void check_out(struct customer* ptr) {
    printf("\n\t%s checked out of Room %d", ptr->name, ptr->room_num);
    printf("\n\tTotal Cost: %d", ptr->total_cost);
    strcpy(ptr->name, "N/A");
    ptr->room_num = 0;
    ptr->room_rate = 0.0;
    ptr->nights = 0;
    ptr->total_cost = 0;
}

void display_customers(struct customer* ptr, int count) {
    printf("\n\t============= List of Customers =============\n\n");
    for(int i=0; i<count; i++) {
        if(strcmp(ptr[i].name, "N/A") != 0) {
            printf("\tCustomer Name: %s\n", ptr[i].name);
            printf("\tRoom Number: %d\n", ptr[i].room_num);
            printf("\tTotal Cost: %d\n\n", ptr[i].total_cost);
        }
    }
}

int main() {
    int choice, count=0, max_customers;
    struct customer* ptr;
    
    printf("\n\tEnter maximum number of customers: ");
    scanf("%d", &max_customers);
    
    ptr = (struct customer*) malloc(max_customers * sizeof(struct customer));
    
    while(1) {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(count == max_customers) {
                    printf("\n\tHotel is fully booked. Try again later.\n");
                    break;
                }
                check_in(&ptr[count]);
                count++;
                break;
            
            case 2:
                printf("\n\tEnter Room Number: ");
                int room_num;
                scanf("%d", &room_num);
                for(int i=0; i<count; i++) {
                    if(ptr[i].room_num == room_num) {
                        check_out(&ptr[i]);
                        break;
                    }
                }
                break;
            
            case 3:
                display_customers(ptr, count);
                break;
            
            case 4:
                printf("\n\tGood Bye!");
                exit(0);
            
            default:
                printf("\n\tInvalid Choice!");
                break;
        }
    }
    
    free(ptr);
    return 0;
}