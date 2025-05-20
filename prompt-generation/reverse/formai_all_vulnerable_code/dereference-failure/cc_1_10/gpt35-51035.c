//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void print_help() {
    printf("This program is a cryptic example of a system administration tool.\n");
    printf("Use the following flags to perform different actions:\n");
    printf("-s: Show system status\n");
    printf("-r: Restart the system\n");
    printf("-p [PID]: Kill a specific process\n");
    printf("-k [KEY]: Set a system key\n");
    printf("-c [FILE]: Check the integrity of a file\n");
}

void show_status() {
    printf("System status: OK\n");
}

void restart_system() {
    printf("Restarting system...\n");
    sleep(5);
    printf("System restarted!\n");
}

void kill_process(pid_t pid) {
    printf("Killing process with PID %d...\n", pid);
    kill(pid, SIGKILL);
    printf("Process killed!\n");
}

void set_key(char* key) {
    printf("Setting system key to %s...\n", key);
}

void check_file_integrity(char* file) {
    printf("Checking integrity of file %s...\n", file);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_help();
        return 0;
    }

    char* arg = argv[1];
    if (arg[0] != '-') {
        printf("Invalid argument: %s\n", arg);
        return 0;
    }

    switch(arg[1]) {
        case 's':
            show_status();
            break;
        case 'r':
            restart_system();
            break;
        case 'p':
            if (argc < 3) {
                printf("Invalid argument: -p\n");
                return 0;
            }
            kill_process(atoi(argv[2]));
            break;
        case 'k':
            if (argc < 3) {
                printf("Invalid argument: -k\n");
                return 0;
            }
            set_key(argv[2]);
            break;
        case 'c':
            if (argc < 3) {
                printf("Invalid argument: -c\n");
                return 0;
            }
            check_file_integrity(argv[2]);
            break;
        default:
            printf("Invalid argument: %s\n", arg);
            return 0;
    }

    return 0;
}