//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int client_socket = 0;
    struct sockaddr_in server_address;

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error: %s", strerror(errno));
        return -1;
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported: %s", strerror(errno));
        return -1;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Connection failed: %s", strerror(errno));
        return -1;
    }

    char username[30], message[100];
    while (1)
    {
        printf("\nEnter your username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
        send(client_socket, username, strlen(username), 0);

        printf("\nStart chatting! Enter 'exit' to end the chat.\n");

        while (1)
        {
            printf("\n%s: ", username);
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0;
            send(client_socket, message, strlen(message), 0);

            if (strcmp(message, "exit") == 0)
                break;

            char buffer[1024];
            int read_val = read(client_socket, buffer, 1024);
            buffer[read_val] = '\0';
            printf("\nServer: %s", buffer);

            if (strcmp(buffer, "exit") == 0)
                break;
        }

        printf("\nChat ended. Do you want to start a new chat? (y/n): ");

        char choice;
        scanf("%c", &choice);

        if (choice == 'n' || choice == 'N')
            break;
    }

    close(client_socket);
    return 0;
}