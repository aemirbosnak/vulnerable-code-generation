//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main() {

    printf("Welcome to our smart home automation system,\n");
    printf("where we make your life not just comfortable but sweet.\n");

    // Setup time and date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hour = tm.tm_hour;
    int minute = tm.tm_min;

    bool lights_on = false;
    bool AC_on = false;

    printf("It's now %d:%02d in the evening.\n", hour, minute);

    // Check if it's nighttime
    if (hour >= 18 || hour < 6) {
        lights_on = true;
        printf("The lights are on to create a warm and cozy atmosphere.\n");
    } else {
        lights_on = false;
        printf("The lights are off to save energy.\n");
    }

    // Check the temperature
    float temperature = 23.4;
    if (temperature > 25.0 && !AC_on) {
        AC_on = true;
        printf("The air-conditioner is turned on to cool down the room.\n");
    } else {
        AC_on = false;
        printf("The air-conditioner is turned off to save energy.\n");
    }

    // Check if the couple is at home
    bool couple_at_home = true;
    if (couple_at_home) {
        printf("The front door is unlocked and the security system is turned off.\n");
    } else {
        printf("The front door is locked and the security system is turned on.\n");
    }

    // Conclusion
    printf("We hope you have a lovely evening at home.\n");

    return 0;
}