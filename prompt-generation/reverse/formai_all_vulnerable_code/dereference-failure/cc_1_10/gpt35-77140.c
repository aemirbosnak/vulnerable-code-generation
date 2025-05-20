//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h>
#include <unistd.h> 
#include <time.h>

#define PORT 80
#define MAX_BUFFER_SIZE 1024

void scan_for_wireless_networks()
{
    struct ifaddrs *ifaddr, *ifa;
    int s, n;
    char host[NI_MAXHOST];
    char ip_address[INET_ADDRSTRLEN];
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr = {0};

    if (getifaddrs(&ifaddr) == -1) 
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) 
    {
        if (ifa->ifa_addr == NULL)
            continue;

        s = socket(AF_INET, SOCK_STREAM, 0);

        if (s == -1) 
        {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);

        if (inet_ntop(AF_INET, &((struct sockaddr_in *) ifa->ifa_addr)->sin_addr, ip_address, INET_ADDRSTRLEN) == NULL) 
        {
            perror("inet_ntop");
            continue;
        }

        if (strncmp(ip_address, "127.", 4) == 0)
            continue; // Skip localhost address

        if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) 
        {
            perror("inet_pton");
            continue;
        }

        if (connect(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
            printf("%s - down\n", ifa->ifa_name);
        else
        {
            printf("%s - up\n", ifa->ifa_name);
            memset(buffer, 0, MAX_BUFFER_SIZE);
            snprintf(buffer, MAX_BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", "google.com");

            if (send(s, buffer, strlen(buffer), 0) == -1)
            {
                perror("send");
                continue;
            }

            if (recv(s, buffer, MAX_BUFFER_SIZE, MSG_PEEK | MSG_DONTWAIT) == -1)
            {
                perror("recv");
                continue;
            }

            printf("Received data on %s: %s\n", ifa->ifa_name, buffer);

        }

        close(s);
    }

    freeifaddrs(ifaddr);
}

int main()
{
    srand(time(NULL));
    int rand_num = rand() % 10;

    printf("Performing wireless network scan...\n");
    sleep(rand_num); // Mimic processing time
    printf("Wireless network scan complete.\n");

    scan_for_wireless_networks();

    return 0;
}