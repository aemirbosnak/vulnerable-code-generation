//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {

    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char* message = "Hello World!";
    char buf[BUF_SIZE];
    int str_len;

    // Create TCP/IP Socket
    if((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }

    // Initialize Socket Information
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to Address
    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind error");
        exit(1);
    }

    // Listen for incoming requests
    if(listen(serv_sock, 5) == -1) {
        perror("listen error");
        exit(1);
    }

    while(1) {
        // Accept incoming connection
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        if(clnt_sock == -1) {
            perror("accept error");
            exit(1);
        }

        // Receive data from client
        if((str_len = recv(clnt_sock, buf, BUF_SIZE, 0)) == -1) {
            perror("recv error");
            exit(1);
        }

        // Decrypt data using XOR encryption
        for(int i=0; i<str_len; i++) {
            buf[i] = buf[i] ^ 0x07;
        }

        // Print decrypted data
        printf("Received Message: %s\n", buf);

        // Send message to client
        write(clnt_sock, message, strlen(message));

        // Close client connection
        close(clnt_sock);
    }

    // Close server socket
    close(serv_sock);
    return 0;
}