//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int light_id;
    char light_name[25];
    int brightness;
    int is_on;
} light;

int num_of_lights = 0;
light *lights;

void add_light() {
    num_of_lights++;
    lights = realloc(lights, sizeof(light) * num_of_lights);

    light new_light;
    new_light.light_id = num_of_lights;

    printf("Enter light name: ");
    scanf("%s", new_light.light_name);
    printf("Enter initial brightness level (0-100): ");
    scanf("%d", &new_light.brightness);
    printf("Is the light on? (1 for Yes, 0 for No): ");
    scanf("%d", &new_light.is_on);

    lights[num_of_lights - 1] = new_light;

    printf("New light added!\n");
}

void list_lights() {
    printf("-------------------------------\n");
    printf("ID\tName\t\tBrightness\tStatus\n");
    printf("-------------------------------\n");
    for(int i=0; i<num_of_lights; i++) {
        printf("%d\t", lights[i].light_id);
        printf("%-15s", lights[i].light_name);
        printf("%d%%\t\t", lights[i].brightness);
        printf("%s\n", lights[i].is_on ? "On" : "Off");
    }
}

void toggle_light() {
    int id;
    printf("Enter light ID to toggle: ");
    scanf("%d", &id);

    for(int i=0; i<num_of_lights; i++) {
        if(lights[i].light_id == id) {
            lights[i].is_on = !lights[i].is_on;
            printf("%s turned %s!\n", lights[i].light_name, lights[i].is_on ? "On" : "Off");
            return;
        }
    }

    printf("Invalid light ID!\n");
}

void set_brightness() {
    int id, brightness;
    printf("Enter light ID to adjust brightness: ");
    scanf("%d", &id);

    for(int i=0; i<num_of_lights; i++) {
        if(lights[i].light_id == id) {
            printf("Enter new brightness level (0-100): ");
            scanf("%d", &brightness);
            lights[i].brightness = brightness;
            printf("%s brightness set to %d%%\n", lights[i].light_name, lights[i].brightness);
            return;
        }
    }

    printf("Invalid light ID!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n\n1. Add new light\n");
        printf("2. List all lights\n");
        printf("3. Toggle light\n");
        printf("4. Set brightness level\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_light();
                break;
            case 2:
                list_lights();
                break;
            case 3:
                toggle_light();
                break;
            case 4:
                set_brightness();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}