//FormAI DATASET v1.0 Category: Client Server Application ; Style: irregular
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>

#define PORT_NO 8000
#define BACKLOG 20
#define BUFF_SIZE 1024

int main(int argc, char* argv[])
{
    int sock_fd, client_fd;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len;

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_NO);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) == -1){
        fprintf(stderr, "Failed to bind socket: %s\n", strerror(errno));
        exit(1);
    }

    if((listen(sock_fd, BACKLOG)) == -1){
        fprintf(stderr, "Failed to listen: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started successfully, listening on port %d.\n", PORT_NO);

    while(1){
        client_len = sizeof(client_addr);
        if((client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len)) == -1){
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        char buffer[BUFF_SIZE];
        memset(buffer, 0, BUFF_SIZE);

        int n = read(client_fd, buffer, BUFF_SIZE-1);
        if(n < 0){
            fprintf(stderr, "Failed to read from socket: %s\n", strerror(errno));
            close(client_fd);
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Request received: %s\n", buffer);

        char response[BUFF_SIZE];
        memset(response, 0, BUFF_SIZE);

        if(strcmp(buffer, "Hello?") ==0){
            strcpy(response, "Hello there!");
        }else if(strcmp(buffer, "What time is it?") ==0){
            time_t raw_time;
            struct tm *time_info;

            time(&raw_time);
            time_info = localtime(&raw_time);
            strftime(response, BUFF_SIZE-1, "The time is %I:%M%p", time_info);
        }else{
            strcpy(response, "I am sorry, I did not understand that.");
        }

        if((n = write(client_fd, response, strlen(response))) < 0){
            fprintf(stderr, "Failed to send response: %s\n", strerror(errno));
        }

        close(client_fd);
    }

    return 0;
}