//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUFF_SIZE 1000

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Initialize the socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    struct hostent *server_info;
    server_info = gethostbyname(argv[1]);
    if (server_info == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server_info->h_addr, (char *) &server_address.sin_addr.s_addr, server_info->h_length);
    server_address.sin_port = htons(110);
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the login command
    char login_cmd[BUFF_SIZE];
    strcpy(login_cmd, "USER username\r\n");
    send(socket_fd, login_cmd, strlen(login_cmd), 0);

    // Receive the response
    char response[BUFF_SIZE];
    recv(socket_fd, response, BUFF_SIZE, 0);

    // Parse the response to get the number of messages
    int num_messages;
    sscanf(response, "%d", &num_messages);

    // Send the CAPAB command to get the available capabilities
    char capab_cmd[BUFF_SIZE];
    sprintf(capab_cmd, "CAPAB %d\r\n", num_messages);
    send(socket_fd, capab_cmd, strlen(capab_cmd), 0);

    // Receive the capabilities response
    char capabilities_response[BUFF_SIZE];
    recv(socket_fd, capabilities_response, BUFF_SIZE, 0);

    // Close the connection
    close(socket_fd);

    return 0;
}