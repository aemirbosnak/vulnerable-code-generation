//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

#define MAX_DEVICES 10
#define MAX_VENDOR_LENGTH 256

// A structure to store information about a connected USB device
typedef struct {
    char vendor[MAX_VENDOR_LENGTH];
    char* device_class;
    int connection_time;
} USBDevice;

// A function to print the details of a connected USB device
void printDeviceDetails(USBDevice device) {
    printf("Vendor: %s\nDevice class: %s\nConnection time: %d\n", device.vendor, device.device_class, device.connection_time);
}

// The main function
int main() {
    char* authorized_devices[MAX_DEVICES] = {"Apple Inc.", "Logitech Inc.", "Samsung Electronics Co. Ltd."};  // An array of authorized device vendor names
    USBDevice connected_devices[MAX_DEVICES];  // An array to store information about connected devices
    int num_devices = 0;  // A counter for the number of connected devices

    while (1) {
        // Open the file containing information about USB devices
        int fd = open("/var/log/syslog", O_RDONLY);
        if (fd < 0) {
            printf("Error %d opening file: %s\n", errno, strerror(errno));
            exit(1);
        }

        // Read the file line by line
        char line[256];
        while (read(fd, line, sizeof(line)) > 0) {
            // Check if the line contains information about a USB device connection
            if (strstr(line, "usb") != NULL && strstr(line, "connected") != NULL) {
                // Extract the vendor name
                int vendor_start = strstr(line, "Manufacturer:") - line + 14;
                int vendor_end = strstr(line, "\n") - line;
                char vendor[MAX_VENDOR_LENGTH];
                strncpy(vendor, line + vendor_start, vendor_end - vendor_start);
                vendor[vendor_end - vendor_start] = '\0';

                // Check if the connected device is authorized
                int authorized = 0;
                for (int i = 0; i < MAX_DEVICES; i++) {
                    if (strcmp(vendor, authorized_devices[i]) == 0) {
                        authorized = 1;
                        break;
                    }
                }

                // If the device is not authorized, record its details and sound an alarm
                if (!authorized) {
                    printf("Unauthorized device connected!\n");
                    USBDevice new_device;
                    strncpy(new_device.vendor, vendor, sizeof(new_device.vendor));
                    new_device.device_class = "Unknown";
                    new_device.connection_time = time(NULL);
                    connected_devices[num_devices++] = new_device;
                    if (num_devices >= MAX_DEVICES) {
                        printf("Maximum number of connected devices exceeded!\n");
                        exit(1);
                    }
                }
            }
        }

        // Close the file descriptor
        close(fd);

        // Sleep for a while before checking again
        sleep(1);
    }

    // Print information about all connected unauthorized devices
    for (int i = 0; i < num_devices; i++) {
        printf("Unathorized device %d:\n", i+1);
        printDeviceDetails(connected_devices[i]);
    }

    return 0;
}