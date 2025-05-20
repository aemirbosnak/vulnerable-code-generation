//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments were passed
    if (argc!= 2) {
        printf("Usage: %s <target_host> \n", argv[0]);
        return 1;
    }

    // Get the hostname and port number
    struct hostent *host_entry;
    if ((host_entry = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Hostname not found.\n");
        return 1;
    }

    struct in_addr *address = (struct in_addr *) host_entry->h_addr_list[0];
    unsigned short port = htons(atoi(argv[2]));

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &address, sizeof(struct sockaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char msg[] = "Hello, world!";
    send(sockfd, msg, strlen(msg), 0);

    // Receive a response from the server
    char response[100];
    memset(response, 0, sizeof(response));
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    printf("Response from server: %s\n", response);

    return 0;
}