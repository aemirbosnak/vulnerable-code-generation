//FormAI DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for storing details of guests
struct guest 
{
   char name[100];
   int age;
   char gender[7];
   long int phone;
};

// Function for displaying room details
void showRooms(int roomCount[])
{
   int i, num;

   printf("\n\n***************************************************\n");
   printf("Rooms Available:\n");

   for(i = 0; i < 10; i++)
   {
      if(roomCount[i] == 0)
      {
         printf("Room Number: %d\n", i+1);
         printf("Status: Available\n\n");
      }
      else
      {
         printf("Room Number: %d\n", i+1);
         printf("Status: Booked\n");
         printf("Guest Name: %s\n\n", roomCount[i]);
      }
   }

   printf("Press any key to continue...\n");
   scanf("%d", &num);
}

// Function for booking a room
void bookRoom(int choice, int roomCount[], struct guest guests[])
{
   char name[100];
   int age, num, i;
   long int phone;
   char gender[7];

   if(roomCount[choice-1] == 0)
   {
      roomCount[choice-1] = 1;

      printf("\n\n***************************************************\n");
      printf("Please provide your details to book the room:\n\n");

      printf("Name: ");
      scanf("%s", guests[choice-1].name);

      printf("Age: ");
      scanf("%d", &guests[choice-1].age);

      printf("Gender (M/F/O): ");
      scanf("%s", guests[choice-1].gender);

      printf("Phone Number: ");
      scanf("%ld", &guests[choice-1].phone);

      printf("\n\n***************************************************\n");
      printf("Room has been booked successfully!\n");
   }
   else
   {
      printf("This room is already booked! Press any key to continue...\n");
      scanf("%d", &num);
   }
}

// Function for checking out from a room
void checkout(int choice, int roomCount[], struct guest guests[])
{
   int num;

   if(roomCount[choice-1] == 1)
   {
      printf("\n\n***************************************************\n");
      printf("Guest: %s\nAge: %d\nGender: %s\nPhone: %ld\n", guests[choice-1].name, guests[choice-1].age, guests[choice-1].gender, guests[choice-1].phone);
      printf("\nRoom Number %d has been successfully checked out!\n", choice);
      printf("Thank you for staying with us!\n");
      roomCount[choice-1] = 0;
   }
   else
   {
      printf("This room is not booked yet! Press any key to continue...\n");
      scanf("%d", &num);
   }
}

// Main function
int main()
{
   int roomCount[10] = {0}; // 0 indicates an available room, 1 indicates a booked room
   struct guest guests[10];

   int choice;

   while(1)
   {
      printf("\n\n***************************************************\n");
      printf("Welcome to C Hotel Management System!\n\n");
      printf("1. Show available rooms\n");
      printf("2. Book a room\n");
      printf("3. Checkout from a room\n");
      printf("4. Exit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
         case 1: showRooms(roomCount);
                 break;
         case 2: printf("\n\n***************************************************\n");
                 printf("Which room would you like to book (1-10)? ");
                 scanf("%d", &choice);
                 bookRoom(choice, roomCount, guests);
                 break;
         case 3: printf("\n\n***************************************************\n");
                 printf("Which room would you like to check out from (1-10)? ");
                 scanf("%d", &choice);
                 checkout(choice, roomCount, guests);
                 break;
         case 4: printf("\nThank you for using C Hotel Management System.\n");
                 exit(0);
         default:printf("\nInvalid choice! Please try again.\n");
      }
   }
}