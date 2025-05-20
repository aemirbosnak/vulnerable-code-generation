//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

void send_request(int sockfd, char* request){
    int n;
    char buffer[BUF_SIZE];

    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "%s", request);
    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
        perror("[ERROR] Failed to send request");
        exit(1);
    }
}

void download_file(int sockfd, char* filename){
    int n;
    char buffer[BUF_SIZE];
    FILE *fptr;

    memset(buffer, 0, BUF_SIZE);

    fptr = fopen(filename, "wb");
    if(fptr == NULL){
        perror("[ERROR] Failed to download file");
        exit(1);
    }

    while((n = read(sockfd, buffer, BUF_SIZE)) > 0){
        fwrite(buffer, sizeof(char), n, fptr);
        memset(buffer, 0, BUF_SIZE);
    }

    fclose(fptr);
}

int main(int argc, char* argv[]){
    if(argc < 3){
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("[ERROR] Failed to create socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL){
        fprintf(stderr, "[ERROR] Failed to get host %s\n", argv[1]);
        exit(1);
    }

    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        perror("[ERROR] Failed to connect to server");
        exit(1);
    }

    char request[BUF_SIZE];
    char response[BUF_SIZE];
    int n;

    memset(request, 0, BUF_SIZE);
    memset(response, 0, BUF_SIZE);

    sprintf(request, "USER anonymous\r\n");
    send_request(sockfd, request);

    sprintf(request, "PASS guest@\r\n");
    send_request(sockfd, request);

    sprintf(request, "TYPE I\r\n");
    send_request(sockfd, request);

    sprintf(request, "PASV\r\n");
    send_request(sockfd, request);

    n = read(sockfd, response, BUF_SIZE);
    if(n < 0){
        perror("[ERROR] Failed to receive response");
        exit(1);
    }

    char ip[16];
    int port;

    char* pch;
    pch = strtok(response, ",");
    int i = 0;

    while(pch != NULL){
        if(i == 4){
            sprintf(ip, "%s.%s.%s.%s", pch, strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));
        }

        if(i == 5){
            port = atoi(pch) * 256 + atoi(strtok(NULL, ","));
        }

        pch = strtok(NULL, ",");
        i++;
    }

    sprintf(request, "RETR example.txt\r\n");
    send_request(sockfd, request);

    struct sockaddr_in data_addr;
    int data_sockfd;
    socklen_t data_len;

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("[ERROR] Failed to create data socket");
        exit(1);
    }

    memset((char*)&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(ip);
    data_addr.sin_port = htons(port);

    if(connect(data_sockfd, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0){
        perror("[ERROR] Failed to connect to server data socket");
        exit(1);
    }

    download_file(data_sockfd, "example.txt");

    sprintf(request, "QUIT\r\n");
    send_request(sockfd, request);

    close(data_sockfd);
    close(sockfd);

    return 0;
}