//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// function to get the IP address from the domain name
int getIP(char *hostname , char *ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if ( (he = gethostbyname( hostname ) ) == NULL )
    {
        // hostname not found
        herror("gethostbyname");
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {
        // Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;
    }

    return 1;
}

int main(int argc, char **argv)
{
    char *host, *page, *message, *ip, *req_path;
    int port, sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // check for the correct arguments
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <page>\n", argv[0]);
        return 1;
    }
    host = argv[1];
    port = atoi(argv[2]);
    page = argv[3];

    // create a request message
    asprintf(&req_path, "GET /%s HTTP/1.1\r\nHost: %s:%u\r\nConnection: close\r\n\r\n",
             page, host, port);

    // Resolove DNS
    if ( (ip = malloc(INET_ADDRSTRLEN)) == NULL) {
        perror("malloc");
        exit(1);
    }

    if ( (getIP(host, ip)) != 0) {
        printf("Could not resolve host %s. Exiting.\n", host);
        return 1;
    }

    printf("IP address of %s is %s\n", host, ip);

    // Create socket
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) < 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send request message
    if ( (write(sockfd, req_path, strlen(req_path))) < 0) {
        perror("write");
        exit(1);
    }

    // Read response from server
    printf("Response from server:\n");

    while ( (message = malloc(80)) != NULL )
    {
        int len = read(sockfd, message, sizeof(char)*79);
        if ( (len) < 0) {
            perror("read");
            exit(1);
        }
        message[len] = '\0';
        printf("%s", message);
        free(message);
    }

    // close the socket
    close(sockfd);

    // free memory
    free(ip);
    free(req_path);

    return 0;
}