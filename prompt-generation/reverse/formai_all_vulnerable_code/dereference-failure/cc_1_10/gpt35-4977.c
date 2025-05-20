//FormAI DATASET v1.0 Category: Client Server Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int send_msg(int sockfd, char* msg){
    int n = send(sockfd, msg, strlen(msg), 0);
    if (n < 0) {
        perror("ERROR sending message");
        return -1;
    }
    printf("Message sent: %s\n", msg);
    return 0;
}

int recv_msg(int sockfd){
    char buffer[MAX_MSG_LEN] = {0};
    int r = read(sockfd, buffer, MAX_MSG_LEN);
    if (r < 0) {
        perror("ERROR receiving message");
        return -1;
    }
    printf("Message received: %s\n", buffer);
    return 0;
}

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_MSG_LEN] = {0};

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR creating socket");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IP address from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
        perror("ERROR invalid address");
        return -1; 
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    char* user = "Client";
    char* msg = malloc(MAX_MSG_LEN);

    while (1) {
        printf("%s: ", user);
        fgets(msg, MAX_MSG_LEN, stdin);
        // Remove trailing newline character
        msg[strcspn(msg, "\n")] = 0;
        
        if (strcmp(msg, "QUIT") == 0) {
            printf("Closing connection...\n");
            break;
        }

        // Send message
        send_msg(sockfd, msg);
        
        // Receive response
        recv_msg(sockfd);
    }
    
    // Cleanup
    free(msg);
    close(sockfd);

    return 0;
}