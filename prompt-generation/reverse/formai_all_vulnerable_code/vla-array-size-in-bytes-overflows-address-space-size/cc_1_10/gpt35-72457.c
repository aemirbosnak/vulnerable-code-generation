//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>

int main() {
    int totalLuggage, conveyorBeltCapacity, planeCapacity;
    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");
    printf("How many luggages are there in total? ");
    scanf("%d", &totalLuggage);
    printf("What is the capacity of the conveyor belt? ");
    scanf("%d", &conveyorBeltCapacity);
    printf("What is the capacity of the plane? ");
    scanf("%d", &planeCapacity);

    int conveyorBelt[conveyorBeltCapacity];
    int plane[planeCapacity];
    int conveyorBeltIndex = 0, planeIndex = 0;

    for (int i = 1; i <= totalLuggage; i++) {
        if (conveyorBeltIndex == conveyorBeltCapacity) {
            printf("\nConveyor belt is full! Luggages cannot be added.");
            printf("\nPlease wait until the plane is ready to depart.\n");
            break;
        }
        conveyorBelt[conveyorBeltIndex] = i;
        printf("\nLuggage %d has been added to the conveyor belt.", i);
        conveyorBeltIndex++;
    }

    printf("\n\nLuggages on the conveyor belt:\n");
    for (int i = 0; i < conveyorBeltCapacity; i++) {
        if (conveyorBelt[i]) {
            printf("%d ", conveyorBelt[i]);
        } else {
            printf("- ");
        }
    }

    printf("\n\nLuggages loaded on the plane:\n");
    while (planeIndex < planeCapacity && conveyorBeltIndex > 0) {
        plane[planeIndex] = conveyorBelt[conveyorBeltIndex - 1];
        printf("%d ", plane[planeIndex]);
        conveyorBeltIndex--;
        planeIndex++;
    }

    if (!planeIndex) {
        printf("\n\nNo luggages have been loaded on the plane.");
    } else {
        printf("\n\n%d luggages have been loaded on the plane.", planeIndex);
    }

    printf("\n\nThank you for using the Airport Baggage Handling Simulation!");

    return 0;
}