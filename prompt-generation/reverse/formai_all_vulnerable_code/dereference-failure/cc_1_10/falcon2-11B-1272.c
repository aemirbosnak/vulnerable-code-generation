//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Function to check website uptime
int checkWebsiteUptime(char *website, int port) {
    struct hostent *server;
    struct sockaddr_in addr;

    int sockfd;
    int yes = 1;
    int result;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    // Resolve website IP address
    server = gethostbyname(website);
    if (server == NULL) {
        printf("Failed to resolve website IP address\n");
        return -1;
    }

    // Set up address struct
    memset((char *) &addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy((char *) &addr.sin_addr.s_addr, server->h_addr, server->h_length);
    addr.sin_port = htons(port);

    // Connect to the website
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("Failed to connect to website\n");
        return -1;
    }

    // Send a request to the website
    char request[256] = "GET / HTTP/1.1\r\nHost: ";
    strncat(request, website, sizeof(request) - strlen(request));
    strncat(request, "\r\n\r\n", sizeof(request) - strlen(request));
    send(sockfd, request, strlen(request), 0);

    // Receive response from the website
    char response[1024] = "";
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    response[bytes_received] = '\0';

    // Check if website is up
    if (strstr(response, "200 OK") == NULL) {
        printf("Website is down\n");
        return 0;
    } else {
        printf("Website is up\n");
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <website> <port>\n", argv[0]);
        return 1;
    }

    int result = checkWebsiteUptime(argv[1], atoi(argv[2]));
    if (result == 1)
        printf("Website is up\n");
    else
        printf("Website is down\n");

    return 0;
}