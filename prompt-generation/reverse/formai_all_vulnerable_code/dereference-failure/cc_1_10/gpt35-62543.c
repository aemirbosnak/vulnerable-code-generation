//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

// Define the target IP address and port
#define IP_ADDR "google.com"
#define PORT 80

int main()
{
    int sockfd, ret_code;
    struct sockaddr_in serv_addr;
    char *http_request = "GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n";
    char http_reply[1024], *host;
    struct hostent* host_info;
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Get the IP address for the target host
    host_info = gethostbyname(IP_ADDR);
    if (host_info == NULL) {
        printf("ERROR: Invalid host: %s\n", IP_ADDR);
        return 1;
    } else {
        host = inet_ntoa(*(struct in_addr*)host_info->h_addr_list[0]);
    }

    // Create a socket and set the timeout option
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Set up the socket address for the target host
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(PORT);

    // Connect to the target host
    ret_code = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret_code != 0) {
        printf("ERROR: Failed to connect to host: %s\n", strerror(errno));
        return 1;
    }

    // Send the HTTP request to the target host
    if (send(sockfd, http_request, strlen(http_request), 0) < 0) {
        printf("ERROR: Failed to send HTTP request: %s\n", strerror(errno));
        return 1;
    }

    // Receive the HTTP reply from the target host
    if (recv(sockfd, http_reply, sizeof(http_reply), 0) < 0) {
        printf("ERROR: Failed to receive HTTP reply: %s\n", strerror(errno));
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Check the QoS of the network
    if (strstr(http_reply, "200 OK") != NULL) {
        printf("SUCCESS: The network QoS is good!\n");
    } else {
        printf("WARNING: The network QoS is poor!\n");
    }

    return 0;
}