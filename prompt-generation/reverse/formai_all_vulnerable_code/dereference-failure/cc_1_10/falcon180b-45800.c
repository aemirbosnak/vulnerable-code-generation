//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

// Function prototypes
void process_command(char *command);
void turn_on_lights(void);
void turn_off_lights(void);
void set_temperature(char *temperature_str);
void play_romantic_music(void);
void display_time(void);
bool is_valid_temperature(char *temperature_str);

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Welcome to the Romantic Smart Home Automation System!\n");
    printf("Enter commands to control the lights, temperature, and music.\n");
    while (true) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        process_command(command);
    }
    return 0;
}

void process_command(char *command) {
    char *token;
    token = strtok(command, " ");
    if (strcmp(token, "lights") == 0) {
        token = strtok(NULL, " ");
        if (strcmp(token, "on") == 0) {
            turn_on_lights();
        } else if (strcmp(token, "off") == 0) {
            turn_off_lights();
        } else {
            printf("Invalid lights command.\n");
        }
    } else if (strcmp(token, "temperature") == 0) {
        token = strtok(NULL, " ");
        if (is_valid_temperature(token)) {
            set_temperature(token);
        } else {
            printf("Invalid temperature command.\n");
        }
    } else if (strcmp(token, "music") == 0) {
        play_romantic_music();
    } else if (strcmp(token, "time") == 0) {
        display_time();
    } else {
        printf("Invalid command.\n");
    }
}

void turn_on_lights(void) {
    printf("The lights are now on, setting the mood for a romantic evening.\n");
}

void turn_off_lights(void) {
    printf("The lights are now off, leaving only the soft glow of candlelight.\n");
}

void set_temperature(char *temperature_str) {
    double temperature;
    if (sscanf(temperature_str, "%lf", &temperature)!= 1 || temperature < 60 || temperature > 80) {
        printf("Invalid temperature. Please enter a number between 60 and 80.\n");
    } else {
        printf("The temperature is now set to a cozy %.1lf degrees Fahrenheit.\n", temperature);
    }
}

void play_romantic_music(void) {
    printf("Soft, romantic music begins to play in the background.\n");
}

void display_time(void) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("The current time is %d:%d:%d.\n", t->tm_hour, t->tm_min, t->tm_sec);
}

bool is_valid_temperature(char *temperature_str) {
    double temperature;
    return sscanf(temperature_str, "%lf", &temperature) == 1 && temperature >= 60 && temperature <= 80;
}