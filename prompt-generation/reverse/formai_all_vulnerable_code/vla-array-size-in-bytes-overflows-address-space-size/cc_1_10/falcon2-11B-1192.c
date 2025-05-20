//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numGuests;
    printf("How many guests would you like to book? ");
    scanf("%d", &numGuests);

    int rooms[numGuests];
    for(int i=0; i<numGuests; i++)
    {
        printf("Enter room %d number: ", i+1);
        scanf("%d", &rooms[i]);
    }

    int room_type[numGuests];
    for(int i=0; i<numGuests; i++)
    {
        printf("Enter room type for room %d: ", i+1);
        scanf("%d", &room_type[i]);
    }

    int price_per_night[numGuests];
    for(int i=0; i<numGuests; i++)
    {
        printf("Enter price per night for room %d: ", i+1);
        scanf("%d", &price_per_night[i]);
    }

    int days_staying[numGuests];
    for(int i=0; i<numGuests; i++)
    {
        printf("Enter number of days staying for room %d: ", i+1);
        scanf("%d", &days_staying[i]);
    }

    int total_price[numGuests];
    for(int i=0; i<numGuests; i++)
    {
        total_price[i] = days_staying[i] * price_per_night[i];
    }

    printf("Room\t\tRoom Type\tPrice Per Night\tDays Staying\tTotal Price\n");
    for(int i=0; i<numGuests; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t%d\n", rooms[i], room_type[i], price_per_night[i], days_staying[i], total_price[i]);
    }

    return 0;
}