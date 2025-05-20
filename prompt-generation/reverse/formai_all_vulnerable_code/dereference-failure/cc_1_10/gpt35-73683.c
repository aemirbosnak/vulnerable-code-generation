//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void send_data(int sockfd, char* data){
    printf("-> %s", data);
    send(sockfd, data, strlen(data), 0);
}

char* receive_data(int sockfd){
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("<- %s", buffer);
    char* data = malloc(bytes_received + 1);
    strncpy(data, buffer, bytes_received);
    return data;
}

int main(){

    char* host = "imap.gmail.com";
    char* port = "993";

    struct hostent* server = gethostbyname(host);
    if (server == NULL){
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(port));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    receive_data(sockfd); // wait for server greeting

    send_data(sockfd, "a001 LOGIN user password\n");

    char* response = receive_data(sockfd);
    if (strstr(response, "a001 OK") == NULL){
        printf("Error: Login failed\n");
        exit(EXIT_FAILURE);
    }

    send_data(sockfd, "a002 SELECT \"INBOX\"\n");

    response = receive_data(sockfd);
    if (strstr(response, "a002 OK") == NULL){
        printf("Error: Select failed\n");
        exit(EXIT_FAILURE);
    }

    send_data(sockfd, "a003 FETCH 1 BODY[HEADER.FIELDS (FROM TO SUBJECT)]\n");

    response = receive_data(sockfd);
    if (strstr(response, "a003 OK") == NULL){
        printf("Error: Fetch failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Email Header: %s", response); // print email header

    send_data(sockfd, "a004 LOGOUT\n");

    close(sockfd);

    return 0;
}