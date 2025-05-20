//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr1"

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <on/off>\n", argv[0]);
        return 1;
    }

    // Read the state of the LED
    int state = 0;
    FILE *file = fopen(LED_PATH, "r");
    if (file == NULL) {
        perror("Failed to open LED file");
        return 1;
    }
    if (fscanf(file, "%d\n", &state)!= 1) {
        perror("Failed to read LED state");
        return 1;
    }
    fclose(file);

    // Toggle the LED state
    if (strcmp(argv[1], "on") == 0) {
        state = 1;
    } else if (strcmp(argv[1], "off") == 0) {
        state = 0;
    }

    // Write the new LED state
    file = fopen(LED_PATH, "w");
    if (file == NULL) {
        perror("Failed to open LED file");
        return 1;
    }
    if (fprintf(file, "%d\n", state)!= 1) {
        perror("Failed to write LED state");
        return 1;
    }
    fclose(file);

    // Print the new LED state
    printf("LED state: %d\n", state);

    return 0;
}