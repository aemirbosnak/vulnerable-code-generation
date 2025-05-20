//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <server address> <port>\n", argv[0]);
        exit(1);
    }
    
    char server_address[50];
    strcpy(server_address, argv[1]);
    int port = atoi(argv[2]);
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error in creating socket");
        exit(1);
    }
    
    // initialize server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address\n");
        exit(1);
    }
    
    // connect to server
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connecting to server");
        exit(1);
    }
    
    // receive welcome message
    char welcome_msg[BUFF_SIZE];
    read(sockfd, welcome_msg, sizeof(welcome_msg));
    printf("%s", welcome_msg);
    
    char command[BUFF_SIZE];
    while(1) {
        printf("ftp> ");
        fflush(stdout);
        fgets(command, BUFF_SIZE, stdin);
        if(send(sockfd, command, strlen(command), 0) < 0) {
            fprintf(stderr, "Error in sending command\n");
            break;
        }
        
        if(strncmp(command, "quit", 4) == 0)
            break;
        
        // receive response from server
        char response[BUFF_SIZE];
        int bytes_recv = read(sockfd, response, sizeof(response));
        if(bytes_recv < 0) {
            perror("Error in receiving response");
            break;
        }
        response[bytes_recv] = '\0';
        printf("%s", response);
    }
    
    close(sockfd);
    return 0;
}