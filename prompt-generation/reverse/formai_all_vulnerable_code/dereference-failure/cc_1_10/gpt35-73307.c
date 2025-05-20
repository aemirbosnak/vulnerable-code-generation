//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define WIFI_MAX_SIGNAL_STRENGTH 100

typedef struct wifi_network {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
    struct wifi_network *next;
} wifi_network_t;

void add_network(wifi_network_t **head, char *ssid, int signal_strength) {
    wifi_network_t *current = *head;
    while (current != NULL) {
        if (strcmp(current->ssid, ssid) == 0) {
            if (signal_strength > current->signal_strength) {
                current->signal_strength = signal_strength;
            }
            return;
        }
        current = current->next;
    }

    wifi_network_t *new_network = malloc(sizeof(wifi_network_t));
    strcpy(new_network->ssid, ssid);
    new_network->signal_strength=signal_strength;
    new_network->next = *head;
    *head = new_network;
}

void print_network(wifi_network_t *network) {
    printf("SSID: %s, Signal Strength: %d\n", network->ssid, network->signal_strength);
}

void print_networks(wifi_network_t *head) {
    wifi_network_t *current = head;
    while (current != NULL) {
        print_network(current);
        current = current->next;
    }
}

int main() {
    wifi_network_t *head = NULL;
    add_network(&head, "Network1", 50);
    add_network(&head, "Network2", 75);
    add_network(&head, "Network1", 80);
    add_network(&head, "Network3", 60);
    add_network(&head, "Network2", 90);
    add_network(&head, "Network4", 100);
    add_network(&head, "Network5", 20);

    printf("All Networks:\n");
    print_networks(head);
    return 0;
}