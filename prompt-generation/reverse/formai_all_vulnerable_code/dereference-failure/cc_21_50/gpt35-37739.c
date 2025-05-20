//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define MAX_SIZE 1024
#define COMMAND_PORT 21

char command[MAX_SIZE];
char response[MAX_SIZE];
char buffer[MAX_SIZE];

int main(int argc, char *argv[])
{
    int sock_data, sock_command, response_code, data_port, len, i;
    struct sockaddr_in server_address, data_address;
    struct hostent *host;

    if(argc != 2)
    {
        printf("Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open command connection
    sock_command = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_command < 0)
    {
        perror("Error opening command socket");
        exit(EXIT_FAILURE);
    }

    // Get server information
    host = gethostbyname(argv[1]);
    if(!host)
    {
        perror("Error getting host information");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(COMMAND_PORT);
    server_address.sin_addr = *((struct in_addr*)host->h_addr);

    // Connect to command port
    if(connect(sock_command, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error connecting to command port");
        exit(EXIT_FAILURE);
    }

    // Receive login response
    if(recv(sock_command, response, MAX_SIZE, 0) < 0)
    {
        perror("Error receiving login response");
        exit(EXIT_FAILURE);
    }

    // Send username
    printf("Username: ");
    fgets(command, MAX_SIZE, stdin);
    len = strlen(command) - 1;
    if(command[len] == '\n')
        command[len] = '\0';
    sprintf(buffer, "USER %s\r\n", command);
    if(send(sock_command, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending username");
        exit(EXIT_FAILURE);
    }

    // Receive username response
    if(recv(sock_command, response, MAX_SIZE, 0) < 0)
    {
        perror("Error receiving username response");
        exit(EXIT_FAILURE);
    }

    // Send password
    printf("Password: ");
    fgets(command, MAX_SIZE, stdin);
    len = strlen(command) - 1;
    if(command[len] == '\n')
        command[len] = '\0';
    sprintf(buffer, "PASS %s\r\n", command);
    if(send(sock_command, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending password");
        exit(EXIT_FAILURE);
    }

    // Receive password response
    if(recv(sock_command, response, MAX_SIZE, 0) < 0)
    {
        perror("Error receiving password response");
        exit(EXIT_FAILURE);
    }

    // Enter passive mode
    sprintf(buffer, "PASV\r\n");
    if(send(sock_command, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error entering passive mode");
        exit(EXIT_FAILURE);
    }

    // Receive data port
    if(recv(sock_command, response, MAX_SIZE, 0) < 0)
    {
        perror("Error receiving data port");
        exit(EXIT_FAILURE);
    }

    // Extract data port
    i = 0;
    while(response[i] != ',')
        i++;
    data_port = atoi(&response[i+1]);
    i++;
    while(response[i] != ',')
        i++;
    data_port = data_port*256 + atoi(&response[i+1]);

    // Open data connection
    sock_data = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_data < 0)
    {
        perror("Error opening data socket");
        exit(EXIT_FAILURE);
    }

    // Get data address
    memset(&data_address, 0, sizeof(data_address));
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(data_port);
    data_address.sin_addr = server_address.sin_addr;

    // Connect to data port
    if(connect(sock_data, (struct sockaddr*)&data_address, sizeof(data_address)) < 0)
    {
        perror("Error connecting to data port");
        exit(EXIT_FAILURE);
    }

    // Send request
    sprintf(buffer, "RETR test.txt\r\n");
    if(send(sock_command, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }

    // Receive response
    if(recv(sock_command, response, MAX_SIZE, 0) < 0)
    {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Receive file
    FILE *fp = fopen("test.txt", "w");
    while((len = recv(sock_data, buffer, MAX_SIZE, 0)) > 0)
        fwrite(buffer, 1, len, fp);
    fclose(fp);

    // Close sockets
    close(sock_command);
    close(sock_data);

    return 0;
}