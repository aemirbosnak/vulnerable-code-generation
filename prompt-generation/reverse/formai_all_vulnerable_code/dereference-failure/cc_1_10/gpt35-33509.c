//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid address");
    }
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }
    
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;
    
    char message[BUFFER_SIZE];
    sprintf(message, "USER %s\r\nPASS %s\r\n", username, password);
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    if (strncmp(buffer, "+OK", 3) != 0) {
        error("ERROR invalid credentials");
    }
    
    n = write(sockfd, "LIST\r\n", 6);
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    char *p = strtok(buffer, " ");
    p = strtok(NULL, " ");
    int num_messages = atoi(p);
    
    for (int i = 1; i <= num_messages; i++) {
        char command[BUFFER_SIZE];
        sprintf(command, "RETR %d\r\n", i);
        n = write(sockfd, command, strlen(command));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s\n", buffer);
        
        printf("Press enter to continue...");
        getchar();
    }
    
    n = write(sockfd, "QUIT\r\n", 6);
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    close(sockfd);
    return 0;
}