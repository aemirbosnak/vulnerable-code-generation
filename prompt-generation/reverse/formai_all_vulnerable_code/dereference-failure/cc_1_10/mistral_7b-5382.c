//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    char *str = malloc(256);
    int len;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        free(str);
        exit(1);
    }

    strcpy(str, argv[1]); // Copy the input string into our allocated memory

    // Shock 1: A Hidden Message
    char hidden_msg[] = "YOU_SHOULD_NOT_BE_HERE!";
    int msg_len = strlen(hidden_msg);

    // Shock 2: String Splicing
    int splice_pos = rand() % 256;
    memmove(str + splice_pos, hidden_msg, msg_len);

    // Shock 3: Random String Changing
    for (int i = 0; i < 10; i++) {
        int rand_pos = rand() % 256;
        int rand_char = rand() % 26 + 'a'; // Random character from a to z
        str[rand_pos] = rand_char;
    }

    // Shock 4: File Writing
    int fd = open("shocked.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) die("Failed to open file for writing");
    write(fd, str, strlen(str));
    close(fd);

    // Shock 5: Reversing the String
    len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }

    printf("Original String: %s\n", str);
    free(str);
    return 0;
}