//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <string.h>

struct hotel
{
    char name[50];
    int room_number;
    float charge;
    int occupied;
};

void check_in(struct hotel h[], int n)
{
    int room_number, flag = 0;

    printf("\n\nEnter Room Number: ");
    scanf("%d", &room_number);

    for (int i = 0; i < n; i++)
    {
        if (h[i].room_number == room_number)
        {
            if (h[i].occupied == 1)
            {
                printf("\n\nRoom Already Occupied!");
                flag = 1;
                break;
            }
            h[i].occupied = 1;
            printf("\n\nChecked in Successfully!");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\n\nInvalid Room Number!");
    }
}

void check_out(struct hotel h[], int n)
{
    int room_number, flag = 0;

    printf("\n\nEnter Room Number: ");
    scanf("%d", &room_number);

    for (int i = 0; i < n; i++)
    {
        if (h[i].room_number == room_number)
        {
            if (h[i].occupied == 0)
            {
                printf("\n\nRoom Already Vacant!");
                flag = 1;
                break;
            }
            h[i].occupied = 0;
            printf("\n\nChecked out Successfully!");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\n\nInvalid Room Number!");
    }
}

void available_rooms(struct hotel h[], int n)
{
    printf("\n\nAvailable Rooms: ");
    for (int i = 0; i < n; i++)
    {
        if (h[i].occupied == 0)
        {
            printf("%d ", h[i].room_number);
        }
    }
}

void occupied_rooms(struct hotel h[], int n)
{
    printf("\n\nOccupied Rooms: ");
    for (int i = 0; i < n; i++)
    {
        if (h[i].occupied == 1)
        {
            printf("%d ", h[i].room_number);
        }
    }
}

int main()
{
    int n;
    printf("\n\nWelcome to the C Hotel Management System!\n\n");
    printf("Enter the number of rooms: ");
    scanf("%d", &n);

    struct hotel h[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n\nEnter Room %d Details: \n\n", i+1);
        printf("Room Number: ");
        scanf("%d", &h[i].room_number);
        printf("Charge per night: ");
        scanf("%f", &h[i].charge);
        h[i].occupied = 0;
    }

    int choice;

    do
    {
        printf("\n\n1. Check in");
        printf("\n\n2. Check out");
        printf("\n\n3. Available Rooms");
        printf("\n\n4. Occupied Rooms");
        printf("\n\n5. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                check_in(h, n);
                break;
            case 2:
                check_out(h, n);
                break;
            case 3:
                available_rooms(h, n);
                break;
            case 4:
                occupied_rooms(h, n);
                break;
            case 5:
                printf("\n\nThank you for using C Hotel Management System!");
                break;
            default:
                printf("\n\nInvalid Choice, Try again!");
                break;
        }
    }
    while (choice != 5);

    return 0;
}