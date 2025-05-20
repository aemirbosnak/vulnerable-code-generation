//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

int main(){
    int sock_fd, recv_size;
    socklen_t len;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFF_SIZE];

    fd_set read_fd_set;
    struct timeval tv;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0){
        perror("socket creation failed\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(6666);

    if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("connection failed\n");
        return -1;
    }

    FD_ZERO(&read_fd_set);
    FD_SET(sock_fd, &read_fd_set);

    tv.tv_sec = 5;  // set timeout to 5 seconds
    tv.tv_usec = 0;

    if(select(sock_fd+1, &read_fd_set, NULL, NULL, &tv) == -1){
        perror("select error\n");
        return -1;
    }

    if(FD_ISSET(sock_fd, &read_fd_set)){
        memset(buffer, 0, MAX_BUFF_SIZE);
        recv_size = recv(sock_fd, buffer, MAX_BUFF_SIZE, 0);
        if(recv_size < 0){
            perror("receive message failed\n");
            return -1;
        }
        printf("Received message: %s\n", buffer);
    }else{
        printf("Server is not responding.\n");
    }

    close(sock_fd);
    return 0;
}