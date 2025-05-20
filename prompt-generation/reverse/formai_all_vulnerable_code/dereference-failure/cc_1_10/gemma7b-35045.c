//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define NUM_MOTORS 4

typedef struct Motor {
    int position;
    int speed;
    struct Motor *next;
} Motor;

Motor *createMotor(int position, int speed) {
    Motor *motor = malloc(sizeof(Motor));
    motor->position = position;
    motor->speed = speed;
    motor->next = NULL;
    return motor;
}

void drive(Motor *motor, int direction, int acceleration) {
    switch (direction) {
        case 0:
            motor->speed += acceleration;
            break;
        case 1:
            motor->speed -= acceleration;
            break;
        default:
            break;
    }
}

int main() {
    Motor *head = createMotor(0, 0);
    Motor *second = createMotor(1, 0);
    Motor *third = createMotor(2, 0);
    Motor *fourth = createMotor(3, 0);

    head->next = second;
    second->next = third;
    third->next = fourth;

    drive(head, 0, 5);
    drive(second, 1, 3);
    drive(third, 0, 2);

    printf("Motor positions:");
    for (Motor *motor = head; motor; motor = motor->next) {
        printf(", %d", motor->position);
    }

    printf("\nMotor speeds:");
    for (Motor *motor = head; motor; motor = motor->next) {
        printf(", %d", motor->speed);
    }

    return 0;
}