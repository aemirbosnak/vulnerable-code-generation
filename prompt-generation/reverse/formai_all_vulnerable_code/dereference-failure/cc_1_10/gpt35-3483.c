//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
// Minimalist FTP client in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to handle errors
void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    // Get the server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    // Set up the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    
    printf("Connected to server.\n");
    
    // Prompt for username and password
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE-1, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE-1, stdin);
    
    // Send username to server
    n = write(sockfd, username, strlen(username));
    if (n < 0) 
         error("ERROR writing to socket");
    
    // Receive response from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    
    // If the server asks for password, send it
    if (strcmp(buffer, "PASSWORD\n") == 0) {
        n = write(sockfd, password, strlen(password));
        if (n < 0) 
             error("ERROR writing to socket");
        
        // Receive response from server
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE-1);
        if (n < 0) 
             error("ERROR reading from socket");
    }
    
    // If the server authenticates, proceed
    if (strcmp(buffer, "AUTHENTICATED\n") == 0) {
        printf("Authentication successful.\n");
        
        // Command loop
        while(1) {
            printf("FTP > ");
            bzero(buffer, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE-1, stdin);
            
            // Send command to server
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) 
                 error("ERROR writing to socket");
            
            // Receive response from server
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE-1);
            if (n < 0) 
                 error("ERROR reading from socket");
            
            printf("%s",buffer);
            
            // If the server sends the exit signal, exit the program
            if (strcmp(buffer, "EXIT\n") == 0) {
                printf("Exiting.\n");
                break;
            }
        }
        
    } else {
        printf("Authentication failed.\n");
    }
    
    close(sockfd);
    return 0;
}