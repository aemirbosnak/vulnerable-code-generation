//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 8

typedef struct Vehicle
{
    int x, y;
    char direction;
    struct Vehicle* next;
} Vehicle;

void draw_lane(int x, int y, int length, int color)
{
    for (int i = x; i < x + length; i++)
    {
        for (int j = y; j < y + HEIGHT; j++)
        {
            if (i == x && j == y)
            {
                printf("%c ", color);
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void draw_vehicle(Vehicle* vehicle)
{
    switch (vehicle->direction)
    {
        case 'N':
            draw_lane(vehicle->x, vehicle->y, 2, 2);
            break;
        case 'S':
            draw_lane(vehicle->x, vehicle->y, 2, 2);
            break;
        case 'E':
            draw_lane(vehicle->x, vehicle->y, 2, 2);
            break;
        case 'W':
            draw_lane(vehicle->x, vehicle->y, 2, 2);
            break;
    }
}

int main()
{
    srand(time(NULL));

    Vehicle* head = NULL;

    // Create a few vehicles
    for (int i = 0; i < 5; i++)
    {
        Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
        vehicle->x = rand() % WIDTH;
        vehicle->y = rand() % HEIGHT;
        vehicle->direction = 'N' + rand() % 4;
        vehicle->next = head;
        head = vehicle;
    }

    // Draw the vehicles
    draw_vehicle(head);

    // Print the traffic flow
    printf("\n");

    // Simulate traffic flow
    for (int t = 0; t < 10; t++)
    {
        // Move the vehicles
        head = head->next;
        while (head)
        {
            switch (head->direction)
            {
                case 'N':
                    head->y--;
                    break;
                case 'S':
                    head->y++;
                    break;
                case 'E':
                    head->x++;
                    break;
                case 'W':
                    head->x--;
                    break;
            }

            // Draw the vehicles
            draw_vehicle(head);

            printf("\n");
            sleep(1);
        }
    }

    return 0;
}