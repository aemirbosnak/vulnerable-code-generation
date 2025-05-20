//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for Hotel Guests
struct Guest{
   int guestID;
   char firstName[20];
   char lastName[20];
   char checkInDate[10];
   char checkOutDate[10];
   int roomNumber;
   float totalBill;
}guests[50];

//Function to add a new guest in the system
void addGuest(){
   int guestID;
   char firstName[20];
   char lastName[20];
   char checkInDate[10];
   char checkOutDate[10];
   int roomNumber;
   float totalBill;
   
   printf("\nEnter Guest ID: ");
   scanf("%d",&guestID);
   guests[guestID].guestID = guestID;

   printf("\nEnter First Name: ");
   scanf("%s",firstName);
   strcpy(guests[guestID].firstName,firstName);

   printf("\nEnter Last Name: ");
   scanf("%s",lastName);
   strcpy(guests[guestID].lastName,lastName);

   printf("\nEnter Check-In Date (DD/MM/YYYY): ");
   scanf("%s",checkInDate);
   strcpy(guests[guestID].checkInDate,checkInDate);

   printf("\nEnter Check-Out Date (DD/MM/YYYY): ");
   scanf("%s",checkOutDate);
   strcpy(guests[guestID].checkOutDate,checkOutDate);

   printf("\nEnter Room Number: ");
   scanf("%d",&roomNumber);
   guests[guestID].roomNumber = roomNumber;

   printf("\nEnter Total Bill: ");
   scanf("%f",&totalBill);
   guests[guestID].totalBill = totalBill;
   
   printf("\nGuest ID %d added successfully!",guestID);
}

//Function to display existing guests in the system
void viewGuests(){
   printf("\n-----------------------------");
   printf("\nGuest ID\tGuest Name\tCheck-In Date\tCheck-Out Date\tRoom Number\tTotal Bill\n");
   printf("-----------------------------");
   for(int i=0; i<50; i++){
        if(guests[i].guestID != 0){
            printf("\n%d\t\t%s %s\t%s\t%s\t\t%d\t\t%.2f",guests[i].guestID,
            guests[i].firstName,guests[i].lastName,guests[i].checkInDate,guests[i].checkOutDate,guests[i].roomNumber,guests[i].totalBill);
        }
   }
   printf("\n\n");
}

//Function to search for an existing guest in the system
void searchGuest(){
   int guestID;
   printf("\nEnter Guest ID: ");
   scanf("%d",&guestID);
   if(guests[guestID].guestID == guestID){
       printf("\nGuest ID: %d\nName: %s %s\nCheck-In Date: %s\nCheck-Out Date: %s\nRoom Number: %d\nTotal Bill: %.2f",
            guests[guestID].guestID,guests[guestID].firstName,guests[guestID].lastName,guests[guestID].checkInDate,guests[guestID].checkOutDate,
            guests[guestID].roomNumber,guests[guestID].totalBill);
   }
   else{
      printf("\nGuest ID %d not found in the system!",guestID);
   }
}

//Main function to display menu and perform actions based on user input
int main(){
    int option;
    while(1){
        printf("\nMenu:");
        printf("\n1. Add a new guest");
        printf("\n2. View existing guests");
        printf("\n3. Search for a guest");
        printf("\n4. Exit");
        printf("\nPlease enter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                addGuest();
                break;
            case 2:
                viewGuests();
                break;
            case 3:
                searchGuest();
                break;
            case 4:
                printf("\nThank you for using the Hotel Management System!");
                exit(0);
    }
  }
  return 0;
}