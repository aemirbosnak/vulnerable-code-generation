//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int floors = 10;
    int current_floor = 0;
    int num_people = 0;
    srand(time(0));
    while (1)
    {
        printf("Current Floor: %d\n", current_floor);
        printf("Number of People: %d\n", num_people);
        printf("Select Floor: ");
        scanf("%d", &current_floor);
        if (current_floor > floors)
        {
            printf("Invalid floor selected, please try again.\n");
            continue;
        }
        else if (current_floor == 0)
        {
            printf("Elevator is on ground floor.\n");
        }
        else if (current_floor == floors)
        {
            printf("Elevator is on top floor.\n");
        }
        else
        {
            int random_person = rand() % num_people;
            printf("A person gets on the elevator at floor %d.\n", current_floor);
            num_people++;
            if (num_people == 1)
            {
                printf("The elevator goes up.\n");
                current_floor++;
            }
            else if (num_people == 2)
            {
                if (current_floor == 1)
                {
                    printf("The elevator goes down.\n");
                    current_floor--;
                }
                else
                {
                    printf("The elevator goes up.\n");
                    current_floor++;
                }
            }
            else if (num_people > 2)
            {
                if (current_floor == 1 || current_floor == 2)
                {
                    printf("The elevator goes down.\n");
                    current_floor--;
                }
                else
                {
                    printf("The elevator goes up.\n");
                    current_floor++;
                }
            }
        }
        printf("Current Floor: %d\n", current_floor);
        printf("Number of People: %d\n", num_people);
        printf("Select Floor: ");
        scanf("%d", &current_floor);
    }
    return 0;
}