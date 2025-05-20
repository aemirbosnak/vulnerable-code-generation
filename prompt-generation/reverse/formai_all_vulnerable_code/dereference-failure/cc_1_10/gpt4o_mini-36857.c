//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

// Robot structure to hold current position
typedef struct {
    int x;
    int y;
    pthread_mutex_t lock;
} Robot;

// Function to move the robot
void* control_robot(void* arg) {
    Robot* robot = (Robot*)arg;
    char input[MAX_BUFFER_SIZE];

    while (1) {
        printf("Enter command (w/a/s/d to move, q to quit): ");
        fgets(input, MAX_BUFFER_SIZE, stdin);

        // Process input command
        pthread_mutex_lock(&robot->lock);
        
        if (strncmp(input, "w", 1) == 0) {
            robot->y += 1; // Move up
            printf("Robot moved up to (%d, %d)\n", robot->x, robot->y);
        } else if (strncmp(input, "s", 1) == 0) {
            robot->y -= 1; // Move down
            printf("Robot moved down to (%d, %d)\n", robot->x, robot->y);
        } else if (strncmp(input, "a", 1) == 0) {
            robot->x -= 1; // Move left
            printf("Robot moved left to (%d, %d)\n", robot->x, robot->y);
        } else if (strncmp(input, "d", 1) == 0) {
            robot->x += 1; // Move right
            printf("Robot moved right to (%d, %d)\n", robot->x, robot->y);
        } else if (strncmp(input, "q", 1) == 0) {
            pthread_mutex_unlock(&robot->lock);
            break; // Quit the loop
        } else {
            printf("Invalid command.\n");
        }

        pthread_mutex_unlock(&robot->lock);
    }
    return NULL;
}

// Function to continuously report robot's position
void* report_position(void* arg) {
    Robot* robot = (Robot*)arg;

    while (1) {
        sleep(2); // Report status every 2 seconds
        pthread_mutex_lock(&robot->lock);
        printf("Current robot position: (%d, %d)\n", robot->x, robot->y);
        pthread_mutex_unlock(&robot->lock);
    }
    return NULL;
}

int main() {
    Robot robot = {0, 0, PTHREAD_MUTEX_INITIALIZER};
    pthread_t control_thread, report_thread;

    // Create threads for controlling the robot and reporting position
    pthread_create(&control_thread, NULL, control_robot, (void*)&robot);
    pthread_create(&report_thread, NULL, report_position, (void*)&robot);

    pthread_join(control_thread, NULL); // Wait for control thread to finish
    // For graceful exit, we should also handle the reporting thread, so we can terminate it afterwards.
    
    // As we do not have a stop condition for the reporting thread in this example,
    // we would ideally signal it to stop before joining it. For simplicity, let's terminate it.
    pthread_cancel(report_thread); // Cancel the reporting thread

    pthread_mutex_destroy(&robot.lock); // Clean up mutex
    printf("Robot program terminated.\n");
    return 0;
}