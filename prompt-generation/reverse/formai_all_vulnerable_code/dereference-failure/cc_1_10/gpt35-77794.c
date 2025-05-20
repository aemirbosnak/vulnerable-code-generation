//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// Structure to store hotel room details
struct room{
    int room_no;
    int num_of_beds;
    int room_status;
};

// Function to display menu and return user's choice
int menu(){
    int choice;
    printf("1. Book Room\n");
    printf("2. Check Out\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to book a room
void book_room(struct room hotel[], int n){
    int i, room_no, num_of_guests;
    printf("Enter room no: ");
    scanf("%d", &room_no);

    for(i=0; i<n; i++){
        if(hotel[i].room_no == room_no){
            if(hotel[i].room_status == 0){
                printf("Enter number of guests: ");
                scanf("%d", &num_of_guests);
                if(num_of_guests<=hotel[i].num_of_beds){
                    hotel[i].room_status = 1;
                    printf("Room booked successfully!\n");
                }
                else{
                    printf("Room doesn't have enough beds to accommodate these many guests!\n");
                }
            }
            else{
                printf("Room is already booked!\n");
            }
            return;
        }
    }

    printf("Invalid room no!\n");
}

// Function to check out from a room and calculate bill
void check_out(struct room hotel[], int n){
    int i, room_no, days;
    printf("Enter room no: ");
    scanf("%d", &room_no);

    for(i=0; i<n; i++){
        if(hotel[i].room_no == room_no){
            if(hotel[i].room_status == 1){
                hotel[i].room_status = 0;
                printf("Enter number of days: ");
                scanf("%d", &days);
                printf("Total bill: $%d\n", days*hotel[i].num_of_beds*50);
            }
            else{
                printf("Room is not booked!\n");
            }
            return;
        }
    }

    printf("Invalid room no!\n");
}

// Function to display room details
void display(struct room hotel[], int n){
    int i;
    printf("Room No \t Num of Beds \t Status\n");
    for(i=0; i<n; i++){
        printf("%d \t\t %d \t\t %s\n", hotel[i].room_no, hotel[i].num_of_beds, hotel[i].room_status==1?"Booked":"Available");
    }
}

int main(){
    int i, n, choice;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    // Allocate memory for array of structures
    struct room *hotel = (struct room*) malloc(n * sizeof(struct room));

    // Initialize room details
    for(i=0; i<n; i++){
        hotel[i].room_no = i+1;
        hotel[i].num_of_beds = rand()%4 + 1;
        hotel[i].room_status = rand()%2;
    }

    while(1){
        choice = menu();
        switch(choice){
            case 1:
                book_room(hotel, n);
                break;
            case 2:
                check_out(hotel, n);
                break;
            case 3:
                display(hotel, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    free(hotel);
    return 0;
}