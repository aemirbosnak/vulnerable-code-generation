//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define MAX 1024 

void send_file(int sockfd, char* filename) 
{ 
    char buff[MAX] = { 0 }; 
    FILE* fp = fopen(filename, "r"); 

    if (fp == NULL) { 
        printf("Could not open file.\n"); 
        return; 
    } 

    while (fgets(buff, MAX, fp) != NULL) { 
        if (send(sockfd, buff, sizeof(buff), 0) == -1) { 
            printf("Error sending file.\n"); 
            return; 
        } 
        memset(buff, 0, MAX); 
    } 

    fclose(fp); 
    printf("File sent successfully.\n"); 
} 

void ftp_client(int sockfd) 
{ 
    char filename[MAX] = { 0 }; 
    printf("Enter filename: "); 
    fgets(filename, MAX, stdin); 

    strtok(filename, "\n"); 
    send_file(sockfd, filename); 

    return; 
} 

int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    // Socket creation 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Error creating socket.\n"); 
        exit(0); 
    } 
    else {
        printf("Socket created successfully.\n"); 
    }

    memset(&servaddr, 0, sizeof(servaddr)); 

    // Assigning IP and PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(3542); 

    // Connection to server 
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Error connecting to server.\n"); 
        exit(0); 
    } 
    printf("Connected to server.\n"); 

    ftp_client(sockfd); 

    close(sockfd); 

    return 0; 
}