//FormAI DATASET v1.0 Category: Hotel Management System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room{
    int room_no;
    char name[50];
    int age;
    int phone_no;
    int days;
};

void add_new_guest(struct room *r){
    printf("Enter the Room number: ");
    scanf("%d",&r->room_no);
    printf("Enter the Name: ");
    scanf("%s",&r->name);
    printf("Enter the Age: ");
    scanf("%d",&r->age);
    printf("Enter the Phone number: ");
    scanf("%d",&r->phone_no);
    printf("Enter the number of days you want to stay: ");
    scanf("%d",&r->days);
    printf("\n");
}

void checkout(struct room *r){
    printf("Room Number: %d\n", r->room_no);
    printf("Name: %s\tAge: %d\tPhone number: %d\n", r->name, r->age, r->phone_no);
    printf("Total Days stayed: %d\n", r->days);
    printf("Total Bill Amount: %d\n", r->days*2000);
    printf("Thank you for staying with us! We hope to see you again.\n\n");
    r->room_no = 0;
    strcpy(r->name,"");
    r->age = 0;
    r->phone_no = 0;
    r->days = 0;
}

void check_room_availability(struct room *r){
    for(int i=0; i<20; i++){
        if(r[i].room_no == 0){
            printf("Room %d is available.\n", i+1);
        }
        else
            printf("Room %d is not available.\n", i+1);
    }
    printf("\n");
}

void print_guest_info(struct room *r){
    for(int i=0; i<20; i++){
        if(r[i].room_no != 0){
            printf("Room Number: %d\n", r[i].room_no);
            printf("Name: %s\tAge: %d\tPhone number: %d\n", r[i].name, r[i].age, r[i].phone_no);
            printf("Total Days stayed: %d\n", r[i].days);
            printf("Total Bill Amount: %d\n", r[i].days*2000);
            printf("----------------------------\n");
        }
    }
    printf("\n");
}

int main(){
    struct room r[20] = {0};
    int choice;
    int room_no;

    while(1){
        printf("------------------------------\n");
        printf("1. Add new Guest\n");
        printf("2. Check-out\n");
        printf("3. Check room availability\n");
        printf("4. Print Guest Information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_new_guest(&r[0]);
                break;
            case 2:
                printf("Enter the Room number to checkout: ");
                scanf("%d", &room_no);
                checkout(&r[room_no-1]);
                break;
            case 3:
                check_room_availability(&r[0]);
                break;
            case 4:
                print_guest_info(&r[0]);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Input. Please try again.\n\n");
        }
    }
    return 0;
}