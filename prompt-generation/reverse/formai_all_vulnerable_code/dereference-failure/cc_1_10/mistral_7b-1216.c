//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 50

typedef struct {
    int floor;
    int people;
} Elevator;

void simulate_elevator(Elevator *elevator, int *buttons, int num_buttons) {
    int current_floor = 0;
    int target_floor = 0;
    int direction = 1;
    int people_inside = 0;

    while (1) {
        // Check if there is a button pressed
        for (int i = 0; i < num_buttons; i++) {
            if (buttons[i] == 1) {
                target_floor = i + 1;
                break;
            }
        }

        // Move to the next floor
        current_floor += direction;
        people_inside += (elevator->floor == current_floor) ? elevator->people : 0;
        elevator->floor = current_floor;

        // Open door and let people in or out
        printf("Floor %d: Elevator is at floor %d. Doors open.\n", current_floor, current_floor);
        for (int i = 0; i < MAX_PEOPLE; i++) {
            if (buttons[current_floor - 1 + i] == 1) {
                printf("Person %d enters the elevator.\n", i + 1);
                buttons[current_floor - 1 + i] = 0;
                elevator->people++;
            }
        }
        printf("Floor %d: Elevator door closes.\n", current_floor);

        // Check if target floor reached
        if (elevator->floor == target_floor) {
            printf("Floor %d: Elevator has arrived. Doors open.\n", target_floor);
            for (int i = 0; i < MAX_PEOPLE; i++) {
                if (buttons[target_floor - 1 + i] == 1) {
                    printf("Person %d enters the elevator.\n", i + 1);
                    buttons[target_floor - 1 + i] = 0;
                    elevator->people++;
                }
            }
            printf("Floor %d: Elevator door closes.\n", target_floor);

            // Check if all people have left the elevator
            if (elevator->people == 0) {
                // Reset people counter and move to the next floor
                people_inside = 0;
                direction *= -1;
                printf("Floor %d: Elevator is moving to the next floor.\n", current_floor);
            } else {
                // If not, move to the next button
                continue;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Elevator elevator;
    int buttons[MAX_FLOORS];

    for (int i = 0; i < MAX_FLOORS; i++) {
        buttons[i] = rand() % 2;
        printf("Floor %d: Button %s pressed.\n", i + 1, buttons[i] ? "is" : "is not");
    }

    simulate_elevator(&elevator, buttons, MAX_FLOORS);

    return 0;
}