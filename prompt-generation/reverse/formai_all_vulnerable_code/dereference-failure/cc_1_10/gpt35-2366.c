//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define MAX_BUFFER 1024
#define MAX_IP_LEN 16

int main(int argc, char **argv) {

    // arguments validation
    if (argc != 3) {
        printf("Usage: ./qosmonitor <server_hostname_or_ip> <port_number>\n");
        return 1;
    }

    struct addrinfo hints, *result, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int error = getaddrinfo(argv[1], NULL, &hints, &result);
    if (error) {
        fprintf(stderr, "Failed to get address info: %s\n", gai_strerror(error));
        return 1;
    }

    char ipstr[MAX_IP_LEN];
    for (res = result; res != NULL; res = res->ai_next) {
        void* addr;
        char* ipversion;

        if (res->ai_family == AF_INET) {
            // IPv4
            struct sockaddr_in* ipv4 = (struct sockaddr_in*)res->ai_addr;
            addr = &(ipv4->sin_addr);
            ipversion = "IPv4";
        } else {
            // IPv6
            struct sockaddr_in6* ipv6 = (struct sockaddr_in6*)res->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipversion = "IPv6";
        }

        inet_ntop(res->ai_family, addr, ipstr, sizeof(ipstr));
        printf("%s: %s\n", ipversion, ipstr);
    }

    freeaddrinfo(result);

    // create a socket for the given IP and port
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Failed to create socket");
        return 1;
    }

    int port = atoi(argv[2]);

    struct sockaddr_in server_address;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ipstr);
    server_address.sin_port = htons(port);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Send data to server
    if (send(sock, "QOS_CHECK", strlen("QOS_CHECK"), 0) < 0) {
        perror("Failed to send data");
        return 1;
    }

    // Receive the response from server
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        perror("Failed to receive data");
        return 1;
    }

    printf("Server responded with: %s\n", buffer);

    close(sock);

    return 0;
}