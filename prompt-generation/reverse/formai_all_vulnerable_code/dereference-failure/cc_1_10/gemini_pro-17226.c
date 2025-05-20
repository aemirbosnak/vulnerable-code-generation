//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

struct song_list {
    struct song *songs;
    int num_songs;
};

struct song_list *create_song_list() {
    struct song_list *sl = malloc(sizeof(struct song_list));
    sl->songs = malloc(sizeof(struct song) * 100);
    sl->num_songs = 0;
    return sl;
}

void add_song_to_list(struct song_list *sl, struct song *s) {
    sl->songs[sl->num_songs++] = *s;
}

void print_song_list(struct song_list *sl) {
    for (int i = 0; i < sl->num_songs; i++) {
        printf("%s - %s - %s - %d\n", sl->songs[i].title, sl->songs[i].artist, sl->songs[i].album, sl->songs[i].year);
    }
}

int main() {
    int sockfd, newsockfd, retval;
    socklen_t addrlen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    addrlen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        struct song_list *sl = create_song_list();

        while (1) {
            char buffer[256];
            bzero(buffer, 256);
            retval = read(newsockfd, buffer, 255);
            if (retval < 0) {
                perror("read");
                exit(1);
            }

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            struct song s;
            sscanf(buffer, "%s %s %s %d", s.title, s.artist, s.album, &s.year);
            add_song_to_list(sl, &s);
        }

        print_song_list(sl);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}