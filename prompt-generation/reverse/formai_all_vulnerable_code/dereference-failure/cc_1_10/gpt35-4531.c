//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_NAME "pop3.mailserver.com"
#define POP_PORT 110

void pop3_send(int sockfd, char* msg){
    send(sockfd, msg, strlen(msg), 0);
}

int pop3_recv(int sockfd, char* buffer, int buffer_size){
    int bytes = recv(sockfd, buffer, buffer_size - 1, 0);
    buffer[bytes] = '\0';
    return bytes;
}

int pop3_auth_user(int sockfd, char* username, char* password){
    char buffer[1024];

    /* Send USER command */
    sprintf(buffer, "USER %s\r\n", username);
    pop3_send(sockfd, buffer);
    pop3_recv(sockfd, buffer, sizeof(buffer));

    /* Send PASS command */
    sprintf(buffer, "PASS %s\r\n", password);
    pop3_send(sockfd, buffer);
    pop3_recv(sockfd, buffer, sizeof(buffer));
    
    /* Check for authentication success */
    if(strstr(buffer, "+OK") == NULL){
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]){
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in server_addr;

    char buffer[1024];
    int sockfd;
    int bytes;

    /* Get IP address of server */
    if ((he = gethostbyname(SERVER_NAME)) == NULL) {
        printf("Error: Cannot resolve host name.\n");
        return -1; 
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    /* Open TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* Set up server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *addr_list[0];
    server_addr.sin_port = htons(POP_PORT);

    /* Connect to server */
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("Error: Cannot connect to server.\n");
        return -1;
    }

    /* Get server greeting */
    bytes = pop3_recv(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    /* Authenticate user */
    if(pop3_auth_user(sockfd, "myusername", "mypassword") < 0){
        printf("Error: Authentication failed.\n");
        return -1;
    }

    /* Send STAT command to get mailbox status */
    pop3_send(sockfd, "STAT\r\n");
    bytes = pop3_recv(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    /* Send LIST command to get message list */
    pop3_send(sockfd, "LIST\r\n");
    bytes = pop3_recv(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    /* Send RETR command to get message content */
    sprintf(buffer, "RETR %d\r\n", 1);
    pop3_send(sockfd, buffer);
    bytes = pop3_recv(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    /* Send QUIT command to end session */
    pop3_send(sockfd, "QUIT\r\n");
    bytes = pop3_recv(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    /* Close socket */
    close(sockfd);

    return 0;
}