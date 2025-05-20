//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to print usage instructions
void print_usage(char *program_name) {
    printf("Usage: %s <SSID>\n", program_name);
}

// Function to get the signal strength of a Wi-Fi network
int get_signal_strength(char *ssid) {
    FILE *fp;
    char command[100] = "iwconfig ";
    strcat(command, ssid);
    strcat(command, " | grep Quality");
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, fp);
    pclose(fp);
    int signal_strength = atoi(strtok(buffer, " "));
    return signal_strength;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        exit(1);
    }

    char *ssid = argv[1];
    int signal_strength = get_signal_strength(ssid);

    if (signal_strength == -1) {
        printf("Wi-Fi network not found.\n");
    } else {
        printf("Signal strength of %s: %d\n", ssid, signal_strength);
    }

    return 0;
}