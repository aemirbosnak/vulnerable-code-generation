//FormAI DATASET v1.0 Category: Chat server ; Style: mathematical
// Mathematical Chat Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000 

int create_socket(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Mathematical Chat Server could not create socket: %s \n", strerror(errno));
        exit(1);
    }
    return sockfd;
}

void bind_socket(int sockfd){
    struct sockaddr_in serv_addr; 
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT); 

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Mathematical Chat Server could not bind the socket: %s \n", strerror(errno));
        exit(1);
    }
}

void listen_for_clients(int sockfd){
    if (listen(sockfd, 10) < 0) {
        printf("Mathematical Chat Server could not listen for clients: %s \n", strerror(errno));
        exit(1);
    }
    printf("Mathematical Chat Server is listening for clients on port %d...\n", PORT);
}

int initiate_chat(int sockfd){
    struct sockaddr_in cli_addr;
    int newsockfd;
    socklen_t clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("Mathematical Chat Server could not accept connection: %s \n", strerror(errno));
        exit(1);
    }
    char buffer[256];
    printf("Client connected from IP address %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    return newsockfd;
}

int perform_math_operation(char operation, int left_operand, int right_operand){
    int result;
    switch(operation){
        case '+': result = left_operand + right_operand;
                  break;
        case '-': result = left_operand - right_operand;
                  break;
        case '*': result = left_operand * right_operand;
                  break;
        case '/': result = left_operand / right_operand;
                  break;
        default: printf("Mathematical Chat Server could not perform operation.\n");
                 exit(1);
    }
    return result;
}

int main(){
    int sockfd, newsockfd, n;
    char buffer[256];
    memset(buffer, 0, 256);
    
    sockfd = create_socket();
    bind_socket(sockfd);
    listen_for_clients(sockfd);

    newsockfd = initiate_chat(sockfd);

    while(1){
        memset(buffer, 0, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            printf("Mathematical Chat Server could not read from socket: %s \n", strerror(errno));
            exit(1);
        }
        if(strcmp(buffer, "exit\n") == 0){
            break;
        }
        int left_operand, right_operand;
        char operation;
        sscanf(buffer, "%d%c%d", &left_operand, &operation, &right_operand);
        int result = perform_math_operation(operation, left_operand, right_operand);
        sprintf(buffer, "%d\n", result);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            printf("Mathematical Chat Server could not write to socket: %s \n", strerror(errno));
            exit(1);
        }
    }
    close(newsockfd);
    close(sockfd);
    return 0; 
}