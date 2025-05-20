//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

/* Function to check if an IP address is valid */
bool is_valid_ip(const char *ip_str) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_str, &(sa.sin_addr));
    return result != 0;
}

/* Function to print the details of a wireless network */
void print_network_details(const char *ssid, const char *password, const char *ip_address) {
    printf("SSID: %s\n", ssid);
    printf("Password: %s\n", password);
    printf("IP Address: %s\n", ip_address);
}

/* Function to scan for available wireless networks */
void scan_wireless_networks() {
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;
    int family, s, n;
    char host[NI_MAXHOST];
    char ssid[50];
    char password[50];
    char ip_address[INET_ADDRSTRLEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    /* Iterate through all interfaces */
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        /* Check if the interface is a wireless interface */
        if (strcmp(ifa->ifa_name, "wlan0") == 0 && family == AF_PACKET) {
            /* Open a socket to connect to the wireless network */
            s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (s == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            /* Set the IP address and port of the wireless network */
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(80);
            inet_pton(AF_INET, "192.168.1.1", &(addr.sin_addr));

            /* Connect to the wireless network */
            n = connect(s, (struct sockaddr *)&addr, sizeof(addr));
            if (n == -1) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            /* Get the SSID of the wireless network */
            strcpy(ssid, ifa->ifa_name);

            /* Get the password of the wireless network */
            printf("Please enter the password for '%s': ", ssid);
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = 0;

            /* Get the IP address of the wireless network */
            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) != 0) {
                perror("getnameinfo");
                exit(EXIT_FAILURE);
            }
            strcpy(ip_address, host);

            /* Print the details of the wireless network */
            printf("\n");
            print_network_details(ssid, password, ip_address);
            printf("\n");

            close(s);
        }
    }

    freeifaddrs(ifaddr); /* Do not forget to free memory */
}

int main() {
    printf("Scanning for available wireless networks...\n\n");
    scan_wireless_networks();
    return 0;
}