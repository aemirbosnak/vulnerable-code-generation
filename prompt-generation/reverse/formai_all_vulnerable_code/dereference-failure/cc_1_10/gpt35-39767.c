//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int socket_desc;
    struct sockaddr_in server;
    char *message;
    char server_reply[2000];
    int port_start, port_end, i, j;

    //check the command line argument correctness
    if (argc < 4) {
        printf("Invalid arguments received.\n Usage : %s <IP> <Port Start> <Port End>\n", argv[0]);
        return 1;
    }

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    //assign IP, PORT
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    printf("Scanning started on IP %s\n", argv[1]);
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    //scanning through the given ports
    for(i = port_start; i <= port_end; i++) {
        server.sin_port = htons(i);
        //Connect to remote server
        if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
            printf("Port %d is closed\n" , i);
            fflush(stdout);
        } else {
            printf("Port %d is open\n" , i);
            fflush(stdout);
            close(socket_desc);
            socket_desc = socket(AF_INET, SOCK_STREAM , 0);
            if (socket_desc == -1){
                printf("Could not create socket");
            }
        }
    }
    printf("Scanning completed!\n");

    return 0;
}