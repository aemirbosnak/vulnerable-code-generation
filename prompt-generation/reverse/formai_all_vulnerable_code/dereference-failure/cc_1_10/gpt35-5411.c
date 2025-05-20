//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the states of the lights
typedef enum 
{
    OFF,
    ON,
    DIM,
    COLOR
} light_state_t;

// Define the colors of the lights
typedef enum 
{
    RED,
    BLUE,
    GREEN,
    YELLOW,
    PURPLE,
    ORANGE,
    WHITE
} light_color_t;

// Define the structure for a light
typedef struct 
{
    light_state_t state;
    light_color_t color;
    int brightness;
} light_t;

// Define the function to turn a light on or off
void toggle_light(light_t *light) 
{
    if (light->state == OFF) 
    {
        light->state = ON;
        printf("Light is on!\n");
    }
    else 
    {
        light->state = OFF;
        printf("Light is off!\n");
    }
}

// Define the function to set the brightness of a light
void set_brightness(light_t *light, int brightness) 
{
    if (brightness > 100) 
    {
        printf("Brightness must be between 0 and 100!\n");
        return;
    }
    
    light->brightness = brightness;
    printf("Brightness: %d\n", light->brightness);
}

// Define the function to change the color of a light
void set_color(light_t *light, light_color_t color) 
{
    light->color = color;
    printf("Color set to %d\n", color);
}

// Define the main function
int main() 
{
    // Define the lights in the house
    int num_lights = 5;
    light_t *lights = malloc(num_lights * sizeof(light_t));
    
    for (int i = 0; i < num_lights; i++) 
    {
        lights[i].state = OFF;
        lights[i].brightness = 0;
        lights[i].color = WHITE;
    }
    
    // Turn on the lights in the living room
    printf("Living room lights:\n");
    toggle_light(&lights[0]);
    toggle_light(&lights[1]);
    
    // Set the brightness and color of the kitchen light
    printf("Kitchen light:\n");
    set_brightness(&lights[2], 50);
    set_color(&lights[2], YELLOW);
    
    // Turn off the lights in the guest bedroom
    printf("Guest bedroom:\n");
    toggle_light(&lights[3]);
    
    // Dim the lights in the master bedroom
    printf("Master bedroom:\n");
    set_brightness(&lights[4], 30);
    
    free(lights);
    return 0;
}