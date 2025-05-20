//FormAI DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define STAT_PATH "/proc/%s/stat"
#define MAX_BUFLEN 512

typedef struct {
    char pid[16];
    char comm[64];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned int flags;
    unsigned long minflt;
    unsigned long cminflt;
    unsigned long majflt;
    unsigned long cmajflt;
    unsigned long utime;
    unsigned long stime;
    long int cutime;
    long int cstime;
    long int priority;
    long int nice;
    long int num_threads;
    long int itrealvalue;
    unsigned long long starttime;
    unsigned long vsize;
    long int rss;
    unsigned long rsslim;
    unsigned long startcode;
    unsigned long endcode;
    unsigned long startstack;
    unsigned long kstkesp;
    unsigned long kstkeip;
    unsigned long signal;
    unsigned long blocked;
    unsigned long sigignore;
    unsigned long sigcatch;
    unsigned long wchan;
} process_t;

static bool is_number(const char *str)
{
    while (*str) {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

static bool read_process(const char *pid, process_t *process)
{
    FILE *fstat = NULL;
    bool success = false;
    char path[MAX_BUFLEN];

    snprintf(path, MAX_BUFLEN, STAT_PATH, pid);
    fstat = fopen(path, "r");
    if (fstat == NULL) {
        printf("Failed to open %s: %s\n", path, strerror(errno));
        return false;
    }

    if (fscanf(fstat, "%s %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %lu", 
            process->pid,
            process->comm,
            &process->state,
            &process->ppid,
            &process->pgrp,
            &process->session,
            &process->tty_nr,
            &process->tpgid,
            &process->flags,
            &process->minflt,
            &process->cminflt,
            &process->majflt,
            &process->cmajflt,
            &process->utime,
            &process->stime,
            &process->cutime,
            &process->cstime,
            &process->priority,
            &process->nice,
            &process->num_threads,
            &process->itrealvalue,
            &process->starttime,
            &process->vsize,
            &process->rss,
            &process->rsslim,
            &process->startcode,
            &process->endcode,
            &process->startstack,
            &process->kstkesp,
            &process->kstkeip,
            &process->signal,
            &process->blocked,
            &process->sigignore,
            &process->sigcatch,
            &process->wchan
    ) != EOF) {
        success = true;
    } else {
        printf("Failed to parse %s\n", path);
    }

    fclose(fstat);

    return success;
}

static void print_process_info(process_t *process)
{
    printf("| %6s | %20s | %c | %5d | %5d | %5d | %5d |\n", 
        process->pid, 
        process->comm, 
        process->state, 
        process->ppid, 
        process->pgrp, 
        process->session, 
        process->tty_nr
    );
}

static void print_processes()
{
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Failed to open /proc: %s\n", strerror(errno));
        return;
    }

    printf("| %6s | %20s | %2s | %5s | %5s | %5s | %5s |\n", "PID", "COMM", "S", "PPID", "PGRP", "SESS", "TTY");
    printf("|%s|\n", "======================================");

    struct dirent *entry = readdir(dir);
    while (entry != NULL) {
        if (is_number(entry->d_name)) {
            process_t process;
            if (read_process(entry->d_name, &process)) {
                print_process_info(&process);
            }
        }
        entry = readdir(dir);
    }

    closedir(dir);
}

static int read_input(int fd, char *buffer, int maxlen)
{
    int count = read(fd, buffer, maxlen - 1);
    if (count == -1) {
        printf("Failed to read input: %s\n", strerror(errno));
        return -1;
    } else {
        buffer[count] = '\0';
        return count;
    }
}

static int start_program()
{
    int pid = fork();
    if (pid == 0) {
        char *args[] = {"/bin/ls", "-la", "/", NULL};
        execvp(args[0], args);
        printf("Failed to start program: %s\n", strerror(errno));
        exit(1);
    } else if (pid == -1) {
        printf("Failed to fork process: %s\n", strerror(errno));
        return -1;
    } else {
        printf("Started program with PID %d\n", pid);
        return pid;
    }
}

int main()
{
    print_processes();

    int stdin_fd = STDIN_FILENO;
    int flags = fcntl(stdin_fd, F_GETFL, 0);
    fcntl(stdin_fd, F_SETFL, flags | O_NONBLOCK);

    int pid = start_program();
    if (pid == -1) {
        return 1;
    }

    bool running = true;
    while (running) {
        int status;
        int result = waitpid(pid, &status, WNOHANG);
        if (result == -1) {
            printf("Error waiting for program: %s\n", strerror(errno));
            running = false;
        } else if (result == 0) {
            char buffer[MAX_BUFLEN];
            int count = read_input(STDIN_FILENO, buffer, MAX_BUFLEN);
            if (count > 0) {
                printf("Received %d bytes of input: %s\n", count, buffer);
            }
        } else {
            printf("Program exited with status %d\n", status);
            running = false;
        }
    }

    return 0;
}