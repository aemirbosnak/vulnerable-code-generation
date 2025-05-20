//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: ./ftpclient <serverIP> <serverPort> <username> <password>\n");
        exit(1);
    }
 
    char *serverIP = argv[1];
    int serverPort = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];
 
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
 
    // Configure server address
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serverIP);
    serv_addr.sin_port = htons(serverPort);
 
    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }
 
    // Send and receive greeting from server
    char buffer[256];
    bzero(buffer, 256);
    if (read(sockfd, buffer, 255) < 0) {
        perror("ERROR reading from server");
        exit(1);
    }
    printf("%s", buffer);
 
    // Send username to server
    bzero(buffer, 256);
    sprintf(buffer, "USER %s\r\n", username);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to server");
        exit(1);
    }
 
    // Receive response from server
    bzero(buffer, 256);
    if (read(sockfd, buffer, 255) < 0) {
        perror("ERROR reading from server");
        exit(1);
    }
    printf("%s", buffer);
 
    // Send password to server
    bzero(buffer, 256);
    sprintf(buffer, "PASS %s\r\n", password);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to server");
        exit(1);
    }
 
    // Receive response from server
    bzero(buffer, 256);
    if (read(sockfd, buffer, 255) < 0) {
        perror("ERROR reading from server");
        exit(1);
    }
    printf("%s", buffer);
 
    // Close socket
    close(sockfd);
 
    return 0;
}