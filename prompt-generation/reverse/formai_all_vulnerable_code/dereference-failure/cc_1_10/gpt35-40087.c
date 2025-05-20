//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]){
    int sock;
    char buff[MAX_BUFF_SIZE];
    struct sockaddr_in server_addr;
    char *server_ip;
    int server_port;
    int bytes_received;
    
    if(argc != 3){
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    server_port = atoi(argv[2]);
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        printf("Failed to create socket!\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0){
        printf("Invalid address/ Address not supported!\n");
        exit(1);
    }

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("Failed to connect to server!\n");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    strcpy(buff, "SCAN_WIRELESS_NETWORKS");
    send(sock, buff, strlen(buff), 0);
    printf("Sent command: %s\n", buff);

    bytes_received = recv(sock, buff, MAX_BUFF_SIZE-1, 0);
    if(bytes_received < 0){
        printf("Error receiving data from server!\n");
        exit(1);
    }
    buff[bytes_received] = '\0';

    printf("Received response: %s\n", buff);

    close(sock);
    printf("Disconnected from server.\n");
    return 0;
}