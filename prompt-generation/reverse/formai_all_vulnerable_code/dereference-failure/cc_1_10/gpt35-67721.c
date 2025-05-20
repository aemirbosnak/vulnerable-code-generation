//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <signal.h>
#include <stdbool.h>

#define BUF_SIZE 1024

void print_error(char *msg){
    fprintf(stderr, "Error: %s (%s)\n", msg, strerror(errno));
}

void ftp_client(int, struct sockaddr_in, char*);

int main(int argc, char *argv[]){
    char *ip_addr = argv[1];
    int port_num = atoi(argv[2]);
    char *filename = argv[3];

    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        print_error("Failed to create socket");
        return 1;
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    //Setup serv_addr struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);

    if(inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0){
        print_error("inet_pton error");
        close(sockfd);
        return 1;
    }

    //Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        print_error("Failed to connect to server");
        close(sockfd);
        return 1;
    }
    
    printf("Connected to server\n");

    ftp_client(sockfd, serv_addr, filename);

    return 0;
}

void ftp_client(int sockfd, struct sockaddr_in serv_addr, char *filename){
    //Send file name to server
    if(send(sockfd, filename, strlen(filename), 0) < 0){
        print_error("Failed to send file name to server");
        close(sockfd);
        return;
    }

    printf("Requesting file %s from server\n", filename);

    //Create file to write to
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL){
        print_error("Failed to create file");
        close(sockfd);
        return;
    }

    //Receive file size from server
    char file_size[BUF_SIZE];
    memset(file_size, 0, BUF_SIZE);
    if(recv(sockfd, file_size, BUF_SIZE, 0) < 0){
        print_error("Failed to receive file size from server");
        close(sockfd);
        return;
    }

    int size = atoi(file_size);

    printf("Server sending %d bytes of data\n", size);

    //Receive file data from server
    char buffer[BUF_SIZE];
    int bytes_received = 0;
    int bytes_written = 0;

    while(bytes_received < size){
        memset(buffer, 0, BUF_SIZE);

        int n = recv(sockfd, buffer, BUF_SIZE, 0);
        if(n < 0){
            print_error("Failed to receive data from server");
            break;
        }

        bytes_received += n;

        //Write data to file
        int m = fwrite(buffer, 1, n, fp);
        if(m < n){
            print_error("Failed to write data to file");
            break;
        }

        bytes_written += m;

        //Print progress
        printf("Received %d/%d bytes\n", bytes_received, size);
    }

    printf("Received file %s from server\n", filename);

    fclose(fp);
    close(sockfd);
}