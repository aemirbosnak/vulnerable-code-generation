//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if a device is ON or OFF
bool device_check(char* device, char* state, int n, char device_arr[], char state_arr[]) {
    if(n == -1) {
        return false;
    }

    if(strcmp(device_arr[n], device) == 0) {
        if(strcmp(state_arr[n], state) == 0) {
            return true;
        } else {
            return false;
        }
    }

    return device_check(device, state, n-1, device_arr, state_arr);
}

// Recursive function to turn ON/OFF a device
void device_switch(char* device, char* state, int n, char device_arr[], char state_arr[]) {
    if(n == -1) {
        printf("Device not found!\n");
        return;
    }

    if(strcmp(device_arr[n], device) == 0) {
        strcpy(state_arr[n], state);
        printf("%s %s\n", device_arr[n], state_arr[n]);
        return;
    }

    device_switch(device, state, n-1, device_arr, state_arr);
}

int main() {
    char device_arr[5][20] = {"Light Bulb", "Thermostat", "Smart Lock", "Surveillance Camera", "Smart Speaker"};
    char state_arr[5][10] = {"OFF", "OFF", "LOCKED", "OFF", "OFF"};

    while (true) {
        printf("What would you like to do?\n");
        printf("1. Check device status\n");
        printf("2. Turn device on/off\n");
        printf("3. Exit\n");

        int choice;
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char device[20];
            printf("Enter the device name: ");
            scanf("%s", device);

            bool device_status = device_check(device, "ON", 4, device_arr, state_arr);

            if(device_status) {
                printf("%s is ON!\n", device);
            } else {
                printf("%s is OFF!\n", device);
            }
        } else if (choice == 2) {
            char device[20];
            char state[10];
            printf("Enter the device name: ");
            scanf("%s", device);

            bool device_status = device_check(device, "ON", 4, device_arr, state_arr);

            if(device_status) {
                strcpy(state, "OFF");
                device_switch(device, state, 4, device_arr, state_arr);
            } else {
                strcpy(state, "ON");
                device_switch(device, state, 4, device_arr, state_arr);
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}