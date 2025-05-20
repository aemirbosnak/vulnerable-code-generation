//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct Hotel
{
    char name[100];
    int capacity;
    int rooms;
    double rate;
    int guests;
} Hotel;

Hotel* createHotel(char name[], int capacity, int rooms, double rate)
{
    Hotel* hotel = malloc(sizeof(Hotel));
    if (hotel == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    hotel->rooms = rooms;
    hotel->rate = rate;
    hotel->guests = 0;
    
    return hotel;
}

void destroyHotel(Hotel* hotel)
{
    free(hotel);
}

void displayHotelInfo(Hotel* hotel)
{
    printf("Hotel Name: %s\n", hotel->name);
    printf("Capacity: %d\n", hotel->capacity);
    printf("Number of Rooms: %d\n", hotel->rooms);
    printf("Rate: $%.2f\n", hotel->rate);
    printf("Number of Guests: %d\n", hotel->guests);
}

void updateRooms(Hotel* hotel, int newRooms)
{
    hotel->rooms = newRooms;
}

void updateRate(Hotel* hotel, double newRate)
{
    hotel->rate = newRate;
}

int main()
{
    Hotel* hotel = createHotel("The Happy Hotel", 100, 50, 150.00);
    
    displayHotelInfo(hotel);
    printf("Current number of guests: %d\n", hotel->guests);
    
    updateRooms(hotel, 75);
    updateRate(hotel, 200.00);
    
    displayHotelInfo(hotel);
    
    destroyHotel(hotel);
    
    return 0;
}