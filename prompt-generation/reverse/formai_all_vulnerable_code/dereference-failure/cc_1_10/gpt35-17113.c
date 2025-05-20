//FormAI DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

/*Function to perform arithmetic operation*/
float arithmetic(float num1, float num2, char op)
{
    switch (op)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            printf("Invalid operator");
    }
    return -1;
}

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    float num1, num2, result;
    char op;

    /* Create socket file descriptor for server*/
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    /* Set socket options*/
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    /* Attach socket to the port */
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    /* Accept client's connection request */
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    /* Receive data from client */
    valread = read(new_socket, buffer, 1024);
    sscanf(buffer, "%f %c %f", &num1, &op, &num2);

    /* Calculate the result */
    result = arithmetic(num1, num2, op);

    /* Convert the result to string */
    char resultStr[20];
    snprintf(resultStr, 20, "%.2f", result);

    /* Send the result to the client */
    send(new_socket, resultStr, strlen(resultStr), 0);
    printf("Result sent to the client.\n");

    return 0;
}