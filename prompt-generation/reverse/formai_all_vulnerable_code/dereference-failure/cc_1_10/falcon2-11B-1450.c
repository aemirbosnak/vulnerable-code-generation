//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENT_DATA 1024
#define MAX_SERVER_DATA 1024

int main(int argc, char **argv) {
    // Initialize variables
    char client_data[MAX_CLIENT_DATA];
    char server_data[MAX_SERVER_DATA];
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <server_ip_address>\n", argv[0]);
        return 1;
    }

    // Convert IP address to integer
    portno = atoi(argv[1]);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Create a struct for server address information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error connecting");
        return 1;
    }

    // Send email data
    printf("Enter email data:\n");
    fgets(client_data, MAX_CLIENT_DATA, stdin);

    // Send email data to server
    send(sockfd, client_data, strlen(client_data), 0);

    // Receive email response
    bzero(server_data, MAX_SERVER_DATA);
    if (recv(sockfd, server_data, MAX_SERVER_DATA, 0) < 0) {
        perror("Error receiving data");
        return 1;
    }

    // Print email response
    printf("Server response:\n%s\n", server_data);

    // Close socket
    close(sockfd);

    return 0;
}