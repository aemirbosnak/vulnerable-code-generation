//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_RECEIVE_BUFFER 5000

/* Define a function to send user command to POP3 server */
void sendCommand(int socket, char* command)
{
    printf("Sending Command: %s", command);
    if(send(socket, command, strlen(command), 0) < 0)
    {
        perror("Send Failed: ");
        exit(EXIT_FAILURE);
    }
}

/* Define a function to receive data from POP3 server */
char* receiveData(int socket)
{
    char* buffer = calloc(MAX_RECEIVE_BUFFER, sizeof(char));
    ssize_t receiveStatus = recv(socket, buffer, MAX_RECEIVE_BUFFER, 0);
    if(receiveStatus < 0)
    {
        perror("Receive Failed: ");
        exit(EXIT_FAILURE);
    }
    printf("Receiving Data: %s\n", buffer);
    return buffer;
}

int main()
{
    int POP3_Server_Port = 110;     // Default POP3 Port
    char* POP3_Server_Address = "pop3.example.com";  // POP3 Server address

    // Connect to the POP3 Server
    int POP3_Client_Socket;
    POP3_Client_Socket = socket(AF_INET, SOCK_STREAM, 0);
    if(POP3_Client_Socket == -1)
    {
        perror("Socket Creation Failed: ");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in POP3_Server;
    POP3_Server.sin_addr.s_addr = inet_addr(POP3_Server_Address);
    POP3_Server.sin_family = AF_INET;
    POP3_Server.sin_port = htons(POP3_Server_Port);
    if(connect(POP3_Client_Socket, (struct sockaddr*)&POP3_Server, sizeof(POP3_Server)) < 0)
    {
        perror("Connection Failed: ");
        exit(EXIT_FAILURE);
    }
    printf("Connected to POP3 Server\n");

    // Authenticate the User
    char* Username = "example@example.com";   // Replace with your Email Address
    char* Password = "password";             // Replace with your Email Password
    char* SMTP_Request = calloc(MAX_RECEIVE_BUFFER, sizeof(char));
    receiveData(POP3_Client_Socket);
    sprintf(SMTP_Request, "USER %s\n", Username);
    sendCommand(POP3_Client_Socket, SMTP_Request);
    receiveData(POP3_Client_Socket);
    sprintf(SMTP_Request, "PASS %s\n", Password);
    sendCommand(POP3_Client_Socket, SMTP_Request);
    receiveData(POP3_Client_Socket);

    // Fetch Email Count
    char* POP3_Request = "STAT\n";
    sendCommand(POP3_Client_Socket, POP3_Request);
    char* Email_Count_Response = receiveData(POP3_Client_Socket);
    char* Message_Delimiter = " ";
    strtok(Email_Count_Response, Message_Delimiter);
    char* Email_Count = strtok(NULL, Message_Delimiter);
    printf("Total Emails: %s\n", Email_Count);

    // Fetch and Display Emails
    for(int i=1; i<=atoi(Email_Count); i++)
    {
        memset(SMTP_Request, 0x0, MAX_RECEIVE_BUFFER);
        sprintf(SMTP_Request, "RETR %d\n", i);
        sendCommand(POP3_Client_Socket, SMTP_Request);
        char* Email_Content = receiveData(POP3_Client_Socket);
        printf("Email %d:\n%s\n", i, Email_Content);
        free(Email_Content);
    }

    // Close the Connection
    sendCommand(POP3_Client_Socket, "QUIT\n");
    close(POP3_Client_Socket);
    printf("Connection Closed\n");

    return 0;
}