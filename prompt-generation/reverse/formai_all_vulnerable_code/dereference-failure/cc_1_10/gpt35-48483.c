//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room
{
    int roomNo;
    char type[10];
    int status;
    int price;
};

struct customer
{
    char name[30];
    char address[50];
    int phoneNo;
    int roomNo;
    int days;
};

typedef struct room Room;
typedef struct customer Customer;

void addRoom(Room *rooms, int numOfRooms);
void removeRoom(Room *rooms, int numOfRooms);
void displayRooms(Room *rooms, int numOfRooms);
void bookRoom(Room *rooms, Customer *customers, int numOfRooms, int numOfCustomers);
void checkOut(Room *rooms, Customer *customers, int numOfRooms, int numOfCustomers);
void displayCustomers(Customer *customers, int numOfCustomers);

int main()
{
    int choice, numOfRooms = 0, numOfCustomers = 0;
    Room *rooms = (Room*)malloc(sizeof(Room));
    Customer *customers = (Customer*)malloc(sizeof(Customer));

    do
    {
        printf("\nWelcome to the C Hotel Management System\n");
        printf("1. Add Room\n");
        printf("2. Remove Room\n");
        printf("3. Display Rooms\n");
        printf("4. Book Room\n");
        printf("5. Check Out\n");
        printf("6. Display Customers\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addRoom(rooms, numOfRooms);
                numOfRooms++;
                break;
            
            case 2:
                removeRoom(rooms, numOfRooms);
                numOfRooms--;
                break;

            case 3:
                displayRooms(rooms, numOfRooms);
                break;

            case 4:
                bookRoom(rooms, customers, numOfRooms, numOfCustomers);
                numOfCustomers++;
                break;

            case 5:
                checkOut(rooms, customers, numOfRooms, numOfCustomers);
                break;

            case 6:
                displayCustomers(customers, numOfCustomers);
                break;

            case 7:
                printf("\nThank you for using the C Hotel Management System!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }while(choice != 7);

    return 0;
}

void addRoom(Room *rooms, int numOfRooms)
{
    printf("\nEnter Room No: ");
    scanf("%d", &rooms[numOfRooms].roomNo);

    printf("Enter Room Type (Single/Double): ");
    scanf("%s", rooms[numOfRooms].type);

    rooms[numOfRooms].status = 0;

    printf("Enter Price per Day: ");
    scanf("%d", &rooms[numOfRooms].price);

    printf("\nRoom Added Successfully!\n");
}

void removeRoom(Room *rooms, int numOfRooms)
{
    int roomNo, i, found = 0;

    printf("\nEnter Room No to be Removed: ");
    scanf("%d", &roomNo);

    for(i = 0; i < numOfRooms; i++)
    {
        if(rooms[i].roomNo == roomNo)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
    {
        for(i = i; i < numOfRooms - 1; i++)
        {
            rooms[i] = rooms[i + 1];
        }

        printf("\nRoom Removed Successfully!\n");
    }
    else
    {
        printf("\nRoom Not Found!\n");
    }
}

void displayRooms(Room *rooms, int numOfRooms)
{
    int i;

    printf("\nRoom No\t\tRoom Type\t\tStatus\t\tPrice per Day\n");

    for(i = 0; i < numOfRooms; i++)
    {   
        printf("%d\t\t%s\t\t", rooms[i].roomNo, rooms[i].type);

        if(rooms[i].status == 0)
        {
            printf("Available\t\t");
        }
        else
        {
            printf("Booked\t\t");
        }

        printf("%d\n", rooms[i].price);
    }
}

void bookRoom(Room *rooms, Customer *customers, int numOfRooms, int numOfCustomers)
{
    int roomNo, i, found = 0;

    printf("\nEnter Room No to be Booked: ");
    scanf("%d", &roomNo);

    for(i = 0; i < numOfRooms; i++)
    {
        if(rooms[i].roomNo == roomNo)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
    {
        if(rooms[i].status == 0)
        {
            strcpy(customers[numOfCustomers].name, "");
            strcpy(customers[numOfCustomers].address, "");
            customers[numOfCustomers].phoneNo = 0;
            customers[numOfCustomers].roomNo = roomNo;

            printf("\nEnter Customer Details Below\n");
            printf("Name: ");
            scanf("%s", customers[numOfCustomers].name);

            printf("Address: ");
            scanf("%s", customers[numOfCustomers].address);

            printf("Phone No: ");
            scanf("%d", &customers[numOfCustomers].phoneNo);

            printf("No of Days to be Booked: ");
            scanf("%d", &customers[numOfCustomers].days);

            rooms[i].status = 1;

            printf("\nRoom Booked Successfully!\n");
        }
        else
        {
            printf("\nRoom Already Booked!\n");
        }
    }
    else
    {
        printf("\nRoom Not Found!\n");
    }
}

void checkOut(Room *rooms, Customer *customers, int numOfRooms, int numOfCustomers)
{
    int roomNo, i, found = 0;

    printf("\nEnter Room No to be Checked Out: ");
    scanf("%d", &roomNo);

    for(i = 0; i < numOfCustomers; i++)
    {
        if(customers[i].roomNo == roomNo)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
    {
        int price = rooms[i].price;
        int days = customers[i].days;
        int totalCost = price * days;

        printf("\nCustomer Details\n");
        printf("Name: %s\n", customers[i].name);
        printf("Address: %s\n", customers[i].address);
        printf("Phone No: %d\n", customers[i].phoneNo);
        printf("Room No: %d\n", customers[i].roomNo);
        printf("Days Booked: %d\n", customers[i].days);
        printf("Total Cost: %d\n", totalCost);

        rooms[i].status = 0;

        printf("\nRoom Checked Out Successfully!\n");
    }
    else
    {
        printf("\nRoom Not Found!\n");
    }
}

void displayCustomers(Customer *customers, int numOfCustomers)
{
    int i;

    printf("\nName\t\tAddress\t\tPhone No\t\tRoom No\t\tDays Booked\n");

    for(i = 0; i < numOfCustomers; i++)
    {   
        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\n", customers[i].name, customers[i].address, customers[i].phoneNo, customers[i].roomNo, customers[i].days);
    }
}