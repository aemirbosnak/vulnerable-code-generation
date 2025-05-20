//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Structure to store information about a network device
typedef struct device {
    int id;
    char ip[INET_ADDRSTRLEN];
    char name[256];
    struct device* next;
} device_t;

// Function to add a device to the linked list
void add_device(device_t** head, device_t* new_device) {
    if (*head == NULL) {
        *head = new_device;
        return;
    }
    device_t* cur_device = *head;
    while (cur_device->next != NULL) {
        cur_device = cur_device->next;
    }
    cur_device->next = new_device;
}

// Function to display all devices in the network
void display_devices(device_t* head) {
    device_t* cur_device = head;
    while (cur_device != NULL) {
        printf("Device ID: %d\n", cur_device->id);
        printf("Device Name: %s\n", cur_device->name);
        printf("Device IP: %s\n", cur_device->ip);
        cur_device = cur_device->next;
    }
}

// Function to map the network topology
void map_topology(device_t* head) {
    device_t* cur_device;
    for (cur_device = head; cur_device != NULL; cur_device = cur_device->next) {
        printf("Mapping topology for device: %s\n", cur_device->name);

        // Create socket and connect to device
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(1);
        }

        struct sockaddr_in device_addr;
        memset(&device_addr, 0, sizeof(device_addr));
        device_addr.sin_family = AF_INET;
        device_addr.sin_port = htons(80);
        device_addr.sin_addr.s_addr = inet_addr(cur_device->ip);

        if (connect(sockfd, (struct sockaddr*) &device_addr, sizeof(device_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        // Send command to device and receive response
        char* command = "show cdp neighbors";
        char response[1024];

        if (send(sockfd, command, strlen(command), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (recv(sockfd, response, sizeof(response), 0) < 0) {
            perror("recv");
            exit(1);
        }

        // Extract neighbor devices from response and add them to linked list
        char* device_info;
        char* save_ptr;

        device_info = strtok_r(response, "\n", &save_ptr);

        while (device_info != NULL) {
            device_info = strtok_r(NULL, "\n", &save_ptr);
            if (device_info != NULL) {
                device_t* new_device = (device_t*) malloc(sizeof(device_t));
                new_device->id = head->id++;
                strcpy(new_device->name, strtok(device_info, " "));
                strcpy(new_device->ip, strtok(NULL, " "));
                new_device->next = NULL;
                add_device(&head, new_device);
            }
        }

        // Close socket
        close(sockfd);
    }
}

int main(int argc, char** argv) {
    // Initialize first device in network
    device_t* head = (device_t*) malloc(sizeof(device_t));
    head->id = 1;
    strcpy(head->ip, "192.168.1.1");
    strcpy(head->name, "Router");
    head->next = NULL;

    map_topology(head);
    display_devices(head);

    return 0;
}