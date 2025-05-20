//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX_MSG_SIZE 1024
#define MAX_MSG_TYPE 10

typedef struct {
    long type;
    char text[MAX_MSG_SIZE];
} msg_t;

// Create a new mailing list
int create_list(const char *name) {
    int fd = open(name, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    close(fd);
    return 0;
}

// Add a new subscriber to a mailing list
int add_subscriber(const char *list, const char *email) {
    int fd = open(list, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    char buf[MAX_MSG_SIZE];
    snprintf(buf, sizeof(buf), "%s\n", email);
    int n = write(fd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

// Remove a subscriber from a mailing list
int remove_subscriber(const char *list, const char *email) {
    int fd = open(list, O_RDWR);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    char buf[MAX_MSG_SIZE];
    int n = read(fd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    char *newbuf = malloc(n);
    if (newbuf == NULL) {
        perror("malloc");
        close(fd);
        return -1;
    }

    int newlen = 0;
    char *ptr = buf;
    while (*ptr != '\0') {
        if (strcmp(ptr, email) != 0) {
            newbuf[newlen++] = *ptr;
        }
        ptr++;
    }

    ftruncate(fd, newlen);
    lseek(fd, 0, SEEK_SET);
    write(fd, newbuf, newlen);
    close(fd);
    free(newbuf);
    return 0;
}

// Send a message to all subscribers on a mailing list
int send_message(const char *list, const char *message) {
    int fd = open(list, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    char buf[MAX_MSG_SIZE];
    int n = read(fd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    char *ptr = buf;
    while (*ptr != '\0') {
        int pid = fork();
        if (pid == 0) {
            // Child process
            execlp("mail", "mail", ptr, "-s", "Mailing list message", NULL);
            perror("execlp");
            exit(1);
        } else if (pid == -1) {
            // Error
            perror("fork");
            close(fd);
            return -1;
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                // Error sending message
                close(fd);
                return -1;
            }
        }
        ptr += strlen(ptr) + 1;
    }

    close(fd);
    return 0;
}

// Print the usage of the program
void usage(const char *name) {
    fprintf(stderr, "Usage: %s <command> <arguments>\n", name);
    fprintf(stderr, "Commands:\n");
    fprintf(stderr, "  create <list>\n");
    fprintf(stderr, "  add <list> <email>\n");
    fprintf(stderr, "  remove <list> <email>\n");
    fprintf(stderr, "  send <list> <message>\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        usage(argv[0]);
        return 1;
    }

    const char *command = argv[1];
    if (strcmp(command, "create") == 0) {
        if (argc != 3) {
            usage(argv[0]);
            return 1;
        }
        return create_list(argv[2]);
    } else if (strcmp(command, "add") == 0) {
        if (argc != 4) {
            usage(argv[0]);
            return 1;
        }
        return add_subscriber(argv[2], argv[3]);
    } else if (strcmp(command, "remove") == 0) {
        if (argc != 4) {
            usage(argv[0]);
            return 1;
        }
        return remove_subscriber(argv[2], argv[3]);
    } else if (strcmp(command, "send") == 0) {
        if (argc != 4) {
            usage(argv[0]);
            return 1;
        }
        return send_message(argv[2], argv[3]);
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}