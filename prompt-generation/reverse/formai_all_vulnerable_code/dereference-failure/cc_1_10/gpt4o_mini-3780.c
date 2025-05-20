//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_LIGHTS 5
#define LIGHT_NAME_LENGTH 20

typedef struct {
    char name[LIGHT_NAME_LENGTH];
    int brightness;
    int is_on;
} Light;

Light lights[MAX_LIGHTS];
sem_t sem;

void* control_light(void* light_index) {
    int index = *((int*)light_index);
    free(light_index);

    while (1) {
        sem_wait(&sem);

        if (lights[index].is_on) {
            printf("Adjusting %s brightness. Current brightness: %d%%\n", lights[index].name, lights[index].brightness);
            lights[index].brightness += 10;
            if (lights[index].brightness > 100) {
                lights[index].brightness = 0; // Loop back to 0
            }
            printf("%s brightness set to %d%%\n", lights[index].name, lights[index].brightness);
        }

        sem_post(&sem);
        sleep(1);
    }
    return NULL;
}

void* user_input(void* arg) {
    char command[50];
    
    while (1) {
        printf("Enter command (on/off <light_name>, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline
        
        if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting light control program.\n");
            exit(0);
        }

        char action[4], light_name[LIGHT_NAME_LENGTH];
        sscanf(command, "%s %s", action, light_name);
        
        sem_wait(&sem);

        int found = 0;
        for (int i = 0; i < MAX_LIGHTS; i++) {
            if (strncmp(lights[i].name, light_name, LIGHT_NAME_LENGTH) == 0) {
                found = 1;
                if (strncmp(action, "on", 2) == 0) {
                    lights[i].is_on = 1;
                    printf("%s light turned ON.\n", lights[i].name);
                } else if (strncmp(action, "off", 3) == 0) {
                    lights[i].is_on = 0;
                    printf("%s light turned OFF.\n", lights[i].name);
                } else {
                    printf("Invalid command. Use 'on' or 'off'.\n");
                }
                break;
            }
        }

        if (!found) {
            printf("Light named %s not found.\n", light_name);
        }

        sem_post(&sem);
    }
    return NULL;
}

void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, LIGHT_NAME_LENGTH, "Light%d", i + 1);
        lights[i].brightness = 0;
        lights[i].is_on = 0;
    }
}

int main() {
    pthread_t user_thread[MAX_LIGHTS];
    pthread_t control_thread[MAX_LIGHTS];
    sem_init(&sem, 0, 1);

    initialize_lights();
    for (int i = 0; i < MAX_LIGHTS; i++) {
        int* index = malloc(sizeof(int));
        *index = i;
        pthread_create(&control_thread[i], NULL, control_light, index);
    }

    pthread_create(&user_thread[0], NULL, user_input, NULL);

    for (int i = 0; i < MAX_LIGHTS; i++) {
        pthread_join(control_thread[i], NULL);
    }
    
    pthread_join(user_thread[0], NULL);
    sem_destroy(&sem);
    return 0;
}