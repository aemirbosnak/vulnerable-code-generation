//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }
    
    char server_name[BUFFER_SIZE];
    strcpy(server_name, argv[1]);
    char username[BUFFER_SIZE];
    strcpy(username, argv[2]);
    
    struct hostent *server = gethostbyname(server_name);
    
    if (server == NULL) {
        printf("Error: Could not resolve hostname!\n");
        return 1;
    }
    
    int client_socket;
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket!\n");
        return 1;
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110);
    
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    
    if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server!\n");
        return 1;
    }
    
    char buffer[BUFFER_SIZE];
    int byte_count;
    sleep(1);
    byte_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[byte_count] = '\0';
    
    printf("Server message: %s", buffer);
    bzero(buffer, BUFFER_SIZE);
    
    char user_command[BUFFER_SIZE];
    sprintf(user_command, "USER %s\r\n", username);
    
    if (send(client_socket, user_command, strlen(user_command), 0) < 0) {
        printf("Error: Could not send data!\n");
        return 1;
    }
    
    byte_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[byte_count] = '\0';
    printf("Server response: %s", buffer);
    bzero(buffer, BUFFER_SIZE);
    
    char pass[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(pass, BUFFER_SIZE, stdin);
    strtok(pass, "\n");
    char pass_command[BUFFER_SIZE];
    sprintf(pass_command, "PASS %s\r\n", pass);
    
    if (send(client_socket, pass_command, strlen(pass_command), 0) < 0) {
        printf("Error: Could not send data!\n");
        return 1;
    }
    
    byte_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[byte_count] = '\0';
    printf("Server response: %s", buffer);
    bzero(buffer, BUFFER_SIZE);
    
    if (strcmp(buffer, "+OK Logged in.\r\n") != 0) {
        printf("Error: Incorrect password or username!\n");
        return 1;
    }
    
    char list_command[] = "LIST\r\n";
    if (send(client_socket, list_command, strlen(list_command), 0) < 0) {
        printf("Error: Could not send data!\n");
        return 1;
    }
    
    sleep(1);
    bzero(buffer, BUFFER_SIZE);
    byte_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[byte_count] = '\0';
    
    printf("Server response: %s", buffer);
    
    close(client_socket);
    
    return 0;
}