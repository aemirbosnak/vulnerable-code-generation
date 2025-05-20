//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: medieval
// In a realm of ancient lore, where valiant knights and fair maidens dwell,
// there exists a tale of a bold voyager, seeking knowledge and treasures from afar.
// With a trusty steed of steel, known as an FTP client, this adventurer embarks on a perilous quest.

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A humble servant to render our valiant hero's decrees
int main(int argc, char **argv) {
    // The domain of the distant server, where the treasures reside
    char *server;
    // The port through which we knock upon the server's gate
    int port;
    // A socket, the conduit through which we exchange messages
    int sockfd;
    // An array of characters for our messages
    char buffer[1024];

    // Let us first acquire the decree from our fair sovereign
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Unfurling our sails, we set course for the distant shores
    server = argv[1];
    port = atoi(argv[2]);

    // By the grace of the network gods, we create our trusty steed
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // With our steed ready, we prepare our journey's plan
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // We knock upon the server's gate, seeking its gracious permission
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // The server responds, its voice booming through the land
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // The server's words reach our weary ears
    printf("Server: %s", buffer);

    // The knight types his humble request, seeking the fabled treasures
    printf("Client: LIST\n");
    n = write(sockfd, "LIST\n", 5);
    if (n < 0) {
        perror("write");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // The server, in its boundless wisdom, bestows its treasures upon the valiant knight
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // The knight's eyes widen, marvels filling his gaze as the server's words paint a tapestry of treasures
    printf("Server: %s", buffer);

    // Our quest nears completion, and with a heavy heart, we bid farewell to the server
    printf("Client: QUIT\n");
    n = write(sockfd, "QUIT\n", 5);
    if (n < 0) {
        perror("write");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Our valiant quest ends here, the treasures secured in our hearts
    close(sockfd);
    return 0;
}