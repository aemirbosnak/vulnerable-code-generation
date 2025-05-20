//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WIFI_NETWORKS 10
#define MAX_WIFI_NAME_LENGTH 32
#define MAX_WIFI_PASSWORD_LENGTH 64
#define MIN_WIFI_SIGNAL_STRENGTH -100
#define MAX_WIFI_SIGNAL_STRENGTH 0

typedef struct {
    char name[MAX_WIFI_NAME_LENGTH];
    char password[MAX_WIFI_PASSWORD_LENGTH];
    int signal_strength;
} wifi_network_t;

void print_usage() {
    printf("Usage:./wifi_analyzer <network_name> <password> <signal_strength>\n");
}

bool is_valid_network_name(char* name) {
    int i = 0;
    while (name[i]!= '\0') {
        if (!isalpha(name[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool is_valid_network_password(char* password) {
    int i = 0;
    while (password[i]!= '\0') {
        if (!isalnum(password[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char* network_name = argv[1];
    char* network_password = argv[2];
    int signal_strength = atoi(argv[3]);

    if (!is_valid_network_name(network_name)) {
        printf("Invalid network name.\n");
        return 1;
    }

    if (!is_valid_network_password(network_password)) {
        printf("Invalid network password.\n");
        return 1;
    }

    if (signal_strength < MIN_WIFI_SIGNAL_STRENGTH || signal_strength > MAX_WIFI_SIGNAL_STRENGTH) {
        printf("Invalid signal strength.\n");
        return 1;
    }

    wifi_network_t network = {
       .name = network_name,
       .password = network_password,
       .signal_strength = signal_strength
    };

    printf("Network name: %s\n", network.name);
    printf("Network password: %s\n", network.password);
    printf("Signal strength: %d\n", network.signal_strength);

    return 0;
}