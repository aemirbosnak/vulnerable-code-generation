//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: Alan Turing
int main(int argc, char *argv[]) {
    // Define the elevator's state variables
    int currentFloor = 0;
    int destinationFloor = 0;
    int direction = 0; // 0 for up, 1 for down
    int numPassengers = 0;
    int maxPassengers = 5;
    int *passengers = calloc(maxPassengers, sizeof(int));

    // Define the floor buttons
    int *floorButtons = calloc(10, sizeof(int));

    // Initialize the floor buttons
    for (int i = 0; i < 10; i++) {
        floorButtons[i] = 0;
    }

    // Main simulation loop
    while (1) {
        // Check for new passengers
        for (int i = 0; i < 10; i++) {
            if (floorButtons[i] == 1) {
                if (passengers[i] >= 0) { // Ignore duplicate requests
                    passengers[i]++;
                } else {
                    passengers[i] = 0;
                }
                floorButtons[i] = 0;
            }
        }

        // Check if the elevator is at its destination floor
        if (currentFloor == destinationFloor) {
            // Unload passengers
            for (int i = 0; i < numPassengers; i++) {
                if (passengers[i] == currentFloor) {
                    passengers[i] = -1;
                    numPassengers--;
                }
            }

            // Check if there are any more passengers waiting on this floor
            for (int i = 0; i < numPassengers; i++) {
                if (passengers[i] == currentFloor) {
                    direction = passengers[i] > currentFloor ? 0 : 1;
                    destinationFloor = passengers[i];
                    break;
                }
            }

            // If there are no more passengers waiting on this floor, check the other floors
            if (numPassengers == 0) {
                for (int i = currentFloor + 1; i < 10; i++) {
                    for (int j = 0; j < numPassengers; j++) {
                        if (passengers[j] == i) {
                            direction = 0;
                            destinationFloor = i;
                            break;
                        }
                    }
                    if (destinationFloor != 0) {
                        break;
                    }
                }
                for (int i = currentFloor - 1; i >= 0; i--) {
                    for (int j = 0; j < numPassengers; j++) {
                        if (passengers[j] == i) {
                            direction = 1;
                            destinationFloor = i;
                            break;
                        }
                    }
                    if (destinationFloor != 0) {
                        break;
                    }
                }
            }
        }

        // Move the elevator
        currentFloor += direction;
    }

    return 0;
}