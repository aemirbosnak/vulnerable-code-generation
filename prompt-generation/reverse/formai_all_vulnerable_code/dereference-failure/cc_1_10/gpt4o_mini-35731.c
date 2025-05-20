//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_LIGHTS 5

typedef struct {
    int id;
    int is_on;
    int brightness; // 0 to 100
    pthread_mutex_t lock;
} Light;

Light lights[MAX_LIGHTS];

void* control_light(void* arg) {
    int light_id = *((int*)arg);
    free(arg);
    
    while (1) {
        char command[100];
        printf("Enter command for Light %d (on/off/brightness/exit): ", light_id + 1);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        pthread_mutex_lock(&lights[light_id].lock);

        if (strcmp(command, "on") == 0) {
            lights[light_id].is_on = 1;
            printf("Light %d is turned ON.\n", light_id + 1);
        } else if (strcmp(command, "off") == 0) {
            lights[light_id].is_on = 0;
            printf("Light %d is turned OFF.\n", light_id + 1);
        } else if (strncmp(command, "brightness", 10) == 0) {
            int brightness;
            sscanf(command + 11, "%d", &brightness);
            if (brightness >= 0 && brightness <= 100) {
                lights[light_id].brightness = brightness;
                printf("Light %d brightness set to %d%%.\n", light_id + 1, brightness);
            } else {
                printf("Invalid brightness value!\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            pthread_mutex_unlock(&lights[light_id].lock);
            break;
        } else {
            printf("Unknown command!\n");
        }

        pthread_mutex_unlock(&lights[light_id].lock);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_LIGHTS];
    
    // Initialize lights
    for (int i = 0; i < MAX_LIGHTS; ++i) {
        lights[i].id = i;
        lights[i].is_on = 0;
        lights[i].brightness = 0;
        pthread_mutex_init(&lights[i].lock, NULL);
        
        int* arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, control_light, arg);
    }
    
    printf("Smart Home Light Control System Initialized!\n");
    
    // Wait for all threads to finish
    for (int i = 0; i < MAX_LIGHTS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < MAX_LIGHTS; ++i) {
        pthread_mutex_destroy(&lights[i].lock);
    }

    printf("Smart Home Light Control System Terminated!\n");
    return 0;
}