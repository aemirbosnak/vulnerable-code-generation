//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>

#define MAX 1024

// Function to connect to POP3 server
void connect_server(char *ip_address, int port, int *server_socket, struct sockaddr_in *server_address)
{
    *server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*server_socket < 0)
    {
        perror("Error in creating socket.\n");
        exit(EXIT_FAILURE);
    }

    memset(server_address, 0, sizeof(*server_address));
    server_address->sin_family = AF_INET;
    server_address->sin_port = htons(port);

    if(inet_pton(AF_INET, ip_address, &server_address->sin_addr)<=0)
    {
        perror("Invalid IP address.\n");
        exit(EXIT_FAILURE);
    }

    if (connect(*server_socket, (struct sockaddr *)server_address, sizeof(*server_address)) < 0)
    {
        perror("Connection Failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the POP3 server.\n");
}

// Function to read response from server
void read_response(int server_socket, char *response)
{
    memset(response, 0, MAX);
    if (read(server_socket, response, MAX) < 0)
    {
        perror("Error in receiving data from server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server Response:\n%s", response);
}

// Function to send data to server
void send_data(int server_socket, char *request)
{
    if (send(server_socket, request, strlen(request), 0) < 0)
    {
        perror("Error in sending data to server.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s [IP address] [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_socket;
    char ip_address[20];
    struct sockaddr_in server_address;
    int port = atoi(argv[2]);
    char request[MAX];
    char response[MAX];

    strcpy(ip_address, argv[1]);

    connect_server(ip_address, port, &server_socket, &server_address);

    read_response(server_socket, response);
    send_data(server_socket, "USER john.doe@gmail.com\r\n");
    read_response(server_socket, response);

    send_data(server_socket, "PASS password\r\n");
    read_response(server_socket, response);

    send_data(server_socket, "STAT\r\n");
    read_response(server_socket, response);

    char *message_id = strtok(response, " \t\n");
    char *total_messages = strtok(NULL, " \t\n");
    printf("Total number of messages: %s\n", total_messages);

    sprintf(request, "RETR %s\r\n", message_id);
    send_data(server_socket, request);

    read_response(server_socket, response);
    printf("Message for ID %s:\n%s", message_id, response);

    send_data(server_socket, "QUIT\r\n");
    read_response(server_socket, response);

    close(server_socket);
    return 0;
}