//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <netdb.h> 

#define BUFFER_SIZE 1024 

// function to check if the server's response is an OK message
int isOK(char* response){
    if(strncmp(response,"+OK",3) == 0){
        return 1;
    }
    return 0;
}

int main(){
    char buffer[BUFFER_SIZE];
    int recv_bytes, message_count, i, sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char* hostname = "pop.gmail.com";
    int port_number = 995; // POP3s SSL port number

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Failed to create socket");
        exit(1);
    }

    // get host by name
    server = gethostbyname(hostname);
    if(server == NULL){
        perror("Failed to get host by name");
        exit(1);
    }

    // set fields of server_addr
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // connect to the server
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("Failed to connect to server");
        exit(1);
    }

    // read welcome message
    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send user name
    char* user = "myemail@gmail.com";
    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);

    // read response
    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // send password
    char* password = "mypassword";
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // read response
    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // list messages
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // read response
    memset(buffer, 0, BUFFER_SIZE);
    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(isOK(buffer)){
        message_count = atoi(strtok(buffer," ")); // get message count from response
        printf("There are %d messages in your inbox.\n", message_count);

        // print message numbers and sizes
        for(i=1; i<=message_count; i++){
            memset(buffer, 0, BUFFER_SIZE);
            recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
            printf("%s", buffer);
        }
    } else {
        printf("Failed to list messages.\n");
    }

    // quit
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // read response
    memset(buffer, 0, BUFFER_SIZE);
    recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}