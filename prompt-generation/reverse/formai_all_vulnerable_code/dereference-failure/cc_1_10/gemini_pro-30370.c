//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: introspective
// A journey into the realm of smart lighting begins,
// A symphony of illumination, where intelligence reigns.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the light's properties
typedef struct Light {
    bool isOn;
    int brightness;
    char *color;
} Light;

// Initialize a light with default values
Light create_light() {
    Light light;
    light.isOn = false;
    light.brightness = 50;
    light.color = "white";
    return light;
}

// Toggle the light's on/off state
void toggle_light(Light *light) {
    light->isOn = !light->isOn;
    printf("Light is now %s\n", light->isOn ? "on" : "off");
}

// Adjust the light's brightness
void adjust_brightness(Light *light, int delta) {
    int newBrightness = light->brightness + delta;
    if (newBrightness < 0) {
        newBrightness = 0;
    } else if (newBrightness > 100) {
        newBrightness = 100;
    }
    light->brightness = newBrightness;
    printf("Light brightness is now %d%%\n", light->brightness);
}

// Change the light's color
void change_color(Light *light, char *newColor) {
    free(light->color);
    light->color = malloc(strlen(newColor) + 1);
    strcpy(light->color, newColor);
    printf("Light color is now %s\n", light->color);
}

// Print the light's current state
void print_light_state(Light light) {
    printf("Light is currently:\n");
    printf(" - On: %s\n", light.isOn ? "Yes" : "No");
    printf(" - Brightness: %d%%\n", light.brightness);
    printf(" - Color: %s\n", light.color);
}

// Main function: a conductor of light's symphony
int main() {
    // Let there be light!
    Light livingRoomLight = create_light();

    // A user's whim: illuminate the room!
    toggle_light(&livingRoomLight);

    // Adjust the light's intensity: a softer glow at night
    adjust_brightness(&livingRoomLight, -20);

    // Transform the color: a warm ambiance for the evening
    change_color(&livingRoomLight, "orange");

    // Print the light's current state: a glimpse into its inner workings
    print_light_state(livingRoomLight);

    // Release the light's memory, allowing it to gracefully fade into darkness
    free(livingRoomLight.color);

    return 0;
}