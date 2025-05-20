//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

// Function to print error message and exit
void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sock_fd, port_no, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];

    // Check for command line arguments
    if(argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    // Get the port number from command line arguments
    port_no = atoi(argv[2]);
    
    // Create a TCP socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        error("Error: Could not create socket\n");
    }
    
    // Get server details from hostname
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error: No such host named %s\n", argv[1]);
        exit(1);
    }
    
    // Set server address details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_no);
    
    // Connect to server
    if(connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: Could not connect to server\n");
    }
    
    // Read a response from server
    bzero(buffer, MAX_SIZE);
    n = read(sock_fd, buffer, MAX_SIZE-1);
    if(n < 0) {
        error("Error: Could not read a response from server\n");
    }
    printf("%s", buffer);
    
    // Send email
    char from[] = "From: example@gmail.com\n";
    char to[] = "To: receiver@gmail.com\n";
    char subject[] = "Subject: SMTP Client Example Program\n\n";
    char message[] = "This is a test email sent using a SMTP client\n";
    char data[] = "DATA\n";
    char quit[] = "QUIT\n";
    
    // Send FROM command
    n = write(sock_fd, from, strlen(from));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send TO command
    n = write(sock_fd, to, strlen(to));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send SUBJECT command
    n = write(sock_fd, subject, strlen(subject));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send MESSAGE command
    n = write(sock_fd, message, strlen(message));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send DATA command
    n = write(sock_fd, data, strlen(data));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send email message
    n = write(sock_fd, message, strlen(message));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Send QUIT command
    n = write(sock_fd, quit, strlen(quit));
    if(n < 0) {
        error("Error: Could not write to socket\n");
    }
    
    // Read response from server
    bzero(buffer, MAX_SIZE);
    n = read(sock_fd, buffer, MAX_SIZE-1);
    if(n < 0) {
        error("Error: Could not read a response from server\n");
    }
    printf("%s", buffer);
    
    // Close socket
    close(sock_fd);
    
    return 0;
}