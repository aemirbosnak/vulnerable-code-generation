//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from your TCP/IP Surrealist Server!";
    char buffer[1024] = {0};
    char *str = (char *) malloc(1024 * sizeof(char));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Bind to the IP address 127.0.0.1 and port 8080
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    // Send a greeting message to client
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    while (1) {
        valread = recv(sock, buffer, 1024, 0);
        if (valread == 0) {
            printf("\nConnection Closed\n");
            close(sock);
            return 0;
        }
        // Process received data in a surrealist way
        str = (char *) malloc(valread * sizeof(char));
        strncpy(str, buffer, valread);
        char *word = strtok(str, " ");
        while (word != NULL) {
            if (strstr(word, "apple") != NULL) {
                // If the word contains 'apple', send a melon instead
                char *melon = "A surreal melon for you!";
                send(sock, melon, strlen(melon), 0);
            }
            word = strtok(NULL, " ");
        }
        free(str);
    }

    return 0;
}