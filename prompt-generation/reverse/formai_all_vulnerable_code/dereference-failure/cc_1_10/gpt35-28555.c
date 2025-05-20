//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ifaddrs.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_NETWORKS 50
#define MAX_SSID_LEN 32
#define MAX_PATH 1024
#define MAX_BUFFER 1024
#define TIMEOUT 5 // in seconds

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} network;

volatile bool running;

void signal_int_handler(int sig) {
    running = false;
}

void print_networks(network networks[], int num_networks) {
    printf("\nDetected Wi-Fi Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("\t%d. %s (Signal Strength: %d dBm)\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }
}

int main(int argc, char** argv) {
    running = true;

    // register signal handler for SIGINT (Ctrl-C)
    signal(SIGINT, signal_int_handler);

    // get list of network interfaces
    struct ifaddrs* ifaddr;
    if (getifaddrs(&ifaddr) == -1) {
        perror("Error getting list of network interfaces.");
        return 1;
    }

    // iterate through network interfaces
    struct ifaddrs* interface;
    char ip_address[MAX_BUFFER];
    char netmask[MAX_BUFFER];
    network networks[MAX_NETWORKS];
    int num_networks = 0;
    for (interface = ifaddr; interface != NULL && num_networks < MAX_NETWORKS && running; interface = interface->ifa_next) {
        
        // skip interfaces without a valid IPv4 address
        if (interface->ifa_addr == NULL || interface->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        // get IP address and netmask for interface
        if (getnameinfo(interface->ifa_addr, sizeof(struct sockaddr_in), ip_address, MAX_BUFFER, NULL, 0, NI_NUMERICHOST) != 0 ||
            getnameinfo(interface->ifa_netmask, sizeof(struct sockaddr_in), netmask, MAX_BUFFER, NULL, 0, NI_NUMERICHOST) != 0) {
            continue;
        }

        // create socket for network interface
        int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd == -1) {
            perror("Error creating socket.");
            return 1;
        }

        // set socket timeout
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(struct timeval));

        // set socket options
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr("255.255.255.255"); // broadcast address
        sin.sin_port = htons(8080); // port number can be anything

        if (bind(sock_fd, (struct sockaddr*)&sin, sizeof(struct sockaddr_in)) == -1) {
            perror("Error binding socket to network interface.");
            close(sock_fd);
            return 1;
        }

        // send broadcast message to ask for Wi-Fi networks
        char message[MAX_BUFFER];
        snprintf(message, MAX_BUFFER, "GET /wifi_networks HTTP/1.1\r\nHost: %s\r\n\r\n", ip_address);
        struct sockaddr_in broadcast;
        broadcast.sin_family = AF_INET;
        broadcast.sin_addr.s_addr = INADDR_BROADCAST;
        broadcast.sin_port = htons(8080);

        if (sendto(sock_fd, message, strlen(message), 0, (struct sockaddr*)&broadcast, sizeof(struct sockaddr_in)) == -1) {
            perror("Error sending broadcast message.");
            close(sock_fd);
            return 1;
        }

        // receive response from Wi-Fi networks
        char buffer[MAX_BUFFER];
        struct sockaddr_in source;
        socklen_t addr_len = sizeof(struct sockaddr_in);
        while (recvfrom(sock_fd, buffer, MAX_BUFFER, 0, (struct sockaddr*)&source, &addr_len) != -1 && running) {
            printf("Received message from %s:%d.\n", inet_ntoa(source.sin_addr), ntohs(source.sin_port));
            printf("Message: %s\n", buffer);

            // parse Wi-Fi networks from response
            char* ptr = strtok(buffer, "\r\n");
            while (ptr != NULL) {
                if (strncmp(ptr, "SSID: ", 6) == 0) {
                    ptr += 6;
                    strncpy(networks[num_networks].ssid, ptr, MAX_SSID_LEN);
                } else if (strncmp(ptr, "Signal Strength: ", 17) == 0) {
                    ptr += 17;
                    networks[num_networks].signal_strength = atoi(ptr);
                    num_networks++;
                    break;
                }
                ptr = strtok(NULL, "\r\n");
            }
        }

        close(sock_fd);
    }

    freeifaddrs(ifaddr);

    print_networks(networks, num_networks);

    return 0;
}