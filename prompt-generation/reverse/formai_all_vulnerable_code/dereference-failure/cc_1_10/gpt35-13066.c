//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_BUFF_SIZE 1024

void scan_wireless_networks(struct ifaddrs* ifaddr);
void print_wireless_network_info(struct ifaddrs* ifaddr);

int main(int argc, char *argv[]) {
    struct ifaddrs* ifaddr;
    if(getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    scan_wireless_networks(ifaddr);
    freeifaddrs(ifaddr);

    return 0;
}

void scan_wireless_networks(struct ifaddrs* ifaddr) {
    char* interface_name;
    struct sockaddr_in* ip_addr;

    for(; ifaddr != NULL; ifaddr = ifaddr->ifa_next) {
        if(ifaddr->ifa_addr == NULL) {
            continue;
        }

        int family = ifaddr->ifa_addr->sa_family;
        
        if(family == AF_INET || family == AF_INET6) {
            interface_name = ifaddr->ifa_name;
            ip_addr = (struct sockaddr_in*) ifaddr->ifa_addr;

            if(strcmp(interface_name, "wlan0") == 0) {
                print_wireless_network_info(ifaddr);
            }
        }
    }
}

void print_wireless_network_info(struct ifaddrs* ifaddr) {
    char buffer[MAX_BUFF_SIZE];
    const int port = 8888;
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");

    if(server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    sprintf(buffer, "%s\n", inet_ntoa(((struct sockaddr_in *)ifaddr->ifa_addr)->sin_addr));
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);
}