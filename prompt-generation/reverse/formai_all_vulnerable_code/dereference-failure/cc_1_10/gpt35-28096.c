//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    
    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    
    portno = atoi(argv[2]);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        error("ERROR receiving response");
    }
    
    printf("%s", buffer);
    
    char user_input[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    int command_number = 0;
    while (1) {
        printf("Enter Command %d: ", ++command_number);
        fgets(user_input, MAX_BUFFER_SIZE, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        
        if (send(sockfd, user_input, strlen(user_input), 0) < 0) {
            error("ERROR sending command");
        }
        
        if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            error("ERROR receiving response");
        }
        
        if (strcmp(buffer, "+OK") == 0) {
            if (strncmp(user_input, "USER", 4) == 0) {
                sscanf(user_input, "USER %s", username);
            }
            else if (strncmp(user_input, "PASS", 4) == 0) {
                sscanf(user_input, "PASS %s", password);
            }
        }
        printf("%s\n", buffer);
        
        if (strncmp(user_input, "QUIT", 4) == 0) {
            break;
        }
    }
    close(sockfd);
    return 0;
}