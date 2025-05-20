//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void send_receive(int sockfd, char *message, char *response) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));  // clear the buffer
    
    // send message to the server
    if(send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }
    
    // receive response from the server
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    
    // copy the server response to the response array
    strcpy(response, buffer);
}

int main(int argc, char *argv[]) {
    // check command line arguments
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);  // convert port number from string to int
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // get host information using hostname
    struct hostent *server = gethostbyname(hostname);
    if(server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    // create socket address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  // clear the struct
    
    serv_addr.sin_family = AF_INET;  // use IPv4
    serv_addr.sin_port = htons(port);  // set the port number
    
    // copy server IP address to the socket address structure
    if(inet_pton(AF_INET, server->h_addr, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: invalid address '%s'\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    // connect to the server
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server %s on port %d\n", hostname, port);
    
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    
    // get user credentials
    printf("\nEnter your username: ");
    fgets(username, BUFFER_SIZE, stdin);
    
    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);
    
    // format the user credentials for sending to the server
    // example: user <username>\r\npass <password>\r\n
    char credentials[BUFFER_SIZE];
    sprintf(credentials, "user %s\tpass %s\r\n", username, password);
    
    // send user credentials to the server
    char response[BUFFER_SIZE];
    send_receive(sockfd, credentials, response);
    
    // check if the server accepted the user credentials
    if(strncmp(response, "+OK", 3) != 0) {
        printf("Error: invalid login credentials\n");
        exit(EXIT_FAILURE);
    }
    
    // send LIST command to the server to get a list of messages
    send_receive(sockfd, "LIST\r\n", response);
    
    printf("\nHere are your messages:\n\n");
    
    // display the list of messages
    printf("%s", response);
    
    // get message number from user
    int message_number;
    printf("\nEnter the message number you want to read (1-9): ");
    scanf("%d", &message_number);
    
    // format RETR command for the selected message
    char retr_command[BUFFER_SIZE];
    sprintf(retr_command, "RETR %d\r\n", message_number);
    
    // send RETR command to the server to get the selected message
    send_receive(sockfd, retr_command, response);
    
    // print the selected message
    printf("\nHere is your message:\n\n%s", response);
    
    // close the socket
    close(sockfd);
    
    return 0;
}