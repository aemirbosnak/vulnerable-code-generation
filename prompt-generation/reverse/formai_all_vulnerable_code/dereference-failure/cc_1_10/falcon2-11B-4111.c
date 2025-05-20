//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    struct hostent *he;
    struct in_addr *ip_addr;
    int sockfd, bytes_sent, bytes_received, retval;
    struct sockaddr_in server_addr;

    /* Check if enough arguments are provided */
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    /* Convert the hostname to an IPv4 address */
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error: hostname not found\n");
        return 1;
    }
    ip_addr = (struct in_addr *) he->h_addr_list[0];

    /* Initialize the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    /* Set up the server address */
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = ip_addr->s_addr;

    /* Connect to the server */
    retval = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (retval < 0) {
        perror("Error connecting to server");
        return 1;
    }

    /* Send a ping request */
    bytes_sent = send(sockfd, "GET / HTTP/1.1\r\n\r\n", 40, 0);
    if (bytes_sent < 0) {
        perror("Error sending data");
        return 1;
    }

    /* Receive the response */
    bytes_received = recv(sockfd, NULL, 0, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        return 1;
    }

    /* Close the socket */
    close(sockfd);

    printf("Ping to %s succeeded with %d bytes received\n", argv[1], bytes_received);
    return 0;
}