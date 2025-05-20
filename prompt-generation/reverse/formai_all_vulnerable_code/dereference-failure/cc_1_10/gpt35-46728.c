//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) 
{
    char buffer[MAX_LINE];
    char message[MAX_LINE];
    int socket_fd, port_num, status;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    //Check argument count
    if (argc != 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Convert port number
    port_num = atoi(argv[2]);

    //Resolve host name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Create TCP socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error: unable to create socket");
        exit(EXIT_FAILURE);
    }

    //Set server details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(port_num);

    //Connect to server
    status = connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (status < 0) {
        perror("Error: unable to connect to server");
        exit(EXIT_FAILURE);
    }

    //Read welcome message
    bzero(buffer, MAX_LINE);
    status = read(socket_fd, buffer, MAX_LINE);
    if (status < 0) {
        perror("Error: unable to read server message");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    //Get user input
    printf("Enter your message: ");
    bzero(message, MAX_LINE);
    fgets(message, MAX_LINE, stdin);

    //Strip newline character
    int len = strlen(message) - 1;
    if (message[len] == '\n') {
        message[len] = '\0';
    }

    //Send message
    status = write(socket_fd, message, strlen(message));
    if (status < 0) {
        perror("Error: unable to send message");
        exit(EXIT_FAILURE);
    }

    //Read server response
    bzero(buffer, MAX_LINE);
    status = read(socket_fd, buffer, MAX_LINE);
    if (status < 0) {
        perror("Error: unable to read server response");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buffer);

    //Close socket
    close(socket_fd);

    return 0;
}