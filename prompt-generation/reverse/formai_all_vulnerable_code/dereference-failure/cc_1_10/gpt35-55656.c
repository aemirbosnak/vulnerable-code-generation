//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

    // Check if the user gave the correct number of arguments
    if (argc < 3) {
        fprintf(stderr,"ERROR, no port number or hostname provided\n");
        exit(1);
    }

    // Define the port number using the first argument
    int port_number = atoi(argv[1]);

    // Define the socket using the right protocol, in this case AF_INET for IPv4
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (socket_fd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(1);
    }

    // Initialize the server address using the second argument
    struct hostent *server = gethostbyname(argv[2]);

    // Check if the server was found
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Define the server address structure
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(1);
    }

    // Ask for input from the user
    printf("Please enter the message: ");
    char buffer[BUFFER_SIZE];
    bzero(buffer,BUFFER_SIZE);
    fgets(buffer,BUFFER_SIZE,stdin);

    // Send the message to the server
    int n = write(socket_fd,buffer,strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(1);
    }

    // Receive the response from the server
    bzero(buffer,BUFFER_SIZE);
    n = read(socket_fd,buffer,BUFFER_SIZE);
    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(1);
    }
    printf("%s\n",buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}