//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
// Building a POP3 Client Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024 // maximum length of receiving buffer

int main(int argc, char* argv[]) { 

    if(argc != 2) { // check if the hostname is provided
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(0);
    }
    
    char* hostname = argv[1];
    char* username = "example_user";
    char* password = "example_password";

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolving hostname to IP address
    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // Setting up socket address
    struct sockaddr_in serv_addr;
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110); // POP3 port number

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Reading server response
    char recv_buffer[BUFFER_SIZE];
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s\n", recv_buffer);

    // Sending username
    char send_buffer[BUFFER_SIZE];
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "USER %s\r\n", username);
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s\n", recv_buffer);

    // Sending password
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "PASS %s\r\n", password);
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s\n", recv_buffer);

    // Sending STAT command to get the number of emails and total size
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "STAT\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s\n", recv_buffer);

    // Extracting number of emails and total size
    int num_emails, total_size;
    sscanf(recv_buffer, "+OK %d %d", &num_emails, &total_size);
    printf("Number of emails: %d\n", num_emails);
    printf("Total size: %d bytes\n", total_size);

    // Sending LIST command to get the list of emails
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "LIST\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    printf("List of emails:\n");

    // Reading the email list
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);
    while (strncmp(recv_buffer, ".\r\n", 3) != 0) {
        bzero(recv_buffer, BUFFER_SIZE);
        recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        printf("%s", recv_buffer);
    }

    // Sending RETR command to retrieve an email
    int email_id = 1; // email ID to retrieve
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "RETR %d\r\n", email_id);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Reading the email contents
    printf("Email contents:\n");
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s", recv_buffer);
    while (strncmp(recv_buffer, ".\r\n", 3) != 0) {
        bzero(recv_buffer, BUFFER_SIZE);
        recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        printf("%s", recv_buffer);
    }

    // Sending QUIT command to exit POP3 session
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "QUIT\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bzero(recv_buffer, BUFFER_SIZE);
    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    printf("%s\n", recv_buffer);

    // Closing the socket
    close(sockfd);
    
    return 0;
}