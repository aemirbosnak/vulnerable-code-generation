//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000

char* receiveResponse(int sock) {
    char* response = (char*)malloc(MAX_MSG_LENGTH*sizeof(char));
    char received;
    int i = 0;
    while (recv(sock, &received, 1, 0) > 0) {
        response[i] = received;
        i++;
        if (i >= MAX_MSG_LENGTH) break;
        if (received == '\n') break;
    }
    response[i] = '\0';
    return response;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s POP3_SERVER_IP USERNAME\n", argv[0]);
        return 0;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(110);
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        printf("Connection error\n");
        return 0;
    }
    char* response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    char* cmd = (char*)malloc(MAX_MSG_LENGTH*sizeof(char));
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    sprintf(cmd, "USER %s\n", argv[2]);
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    printf("Enter password: ");
    char* password = (char*)malloc(MAX_MSG_LENGTH*sizeof(char));
    scanf("%s", password);
    sprintf(cmd, "PASS %s\n", password);
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    sprintf(cmd, "STAT\n");
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    sprintf(cmd, "LIST\n");
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    printf("Enter the number of the message you want to read: ");
    char* messageNum = (char*)malloc(MAX_MSG_LENGTH*sizeof(char));
    scanf("%s", messageNum);
    sprintf(cmd, "RETR %s\n", messageNum);
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    if (strstr(response, "+OK") == NULL) {
        printf("Error retrieving message: %s", response);
        free(cmd);
        free(password);
        free(messageNum);
        return 0;
    }
    printf("%s", response);
    free(response);
    response = receiveResponse(sock);
    while (strcmp(response, ".\n")) {
        printf("%s", response);
        free(response);
        response = receiveResponse(sock);
    }
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    printf("Enter the number of the message you want to delete: ");
    scanf("%s", messageNum);
    sprintf(cmd, "DELE %s\n", messageNum);
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    memset(cmd, 0, MAX_MSG_LENGTH*sizeof(char));
    sprintf(cmd, "QUIT\n");
    send(sock, cmd, strlen(cmd), 0);
    response = receiveResponse(sock);
    printf("%s", response);
    free(response);
    close(sock);
    free(cmd);
    free(password);
    free(messageNum);
    return 0;
}