//MISTRAL-7B DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define BOOT_MAGIC 0xDEADBEEF
#define BOOT_SIZE 4096
#define FS_MAGIC 0xCAFEBABE
#define FS_START 0x10000
#define FS_SIZE (1024 * 1024)

typedef struct {
    unsigned int magic;
    unsigned int size;
} boot_header_t;

typedef struct {
    unsigned int magic;
    unsigned int start;
    unsigned int size;
} fs_header_t;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void boot() {
    boot_header_t *boot_hdr;
    void *boot_mem;

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) die("/dev/mem");

    boot_mem = mmap(NULL, BOOT_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (boot_mem == MAP_FAILED) die("/dev/mem mmap");

    boot_hdr = (boot_header_t *)boot_mem;
    boot_hdr->magic = BOOT_MAGIC;
    boot_hdr->size = sizeof(boot_header_t) + sizeof(fs_header_t) + FS_SIZE;

    fs_header_t *fs_hdr = (fs_header_t *)((char *)boot_hdr + sizeof(boot_header_t));
    fs_hdr->magic = FS_MAGIC;
    fs_hdr->start = FS_START;
    fs_hdr->size = FS_SIZE;

    msync(boot_mem, boot_hdr->size, MS_SYNC);
    munmap(boot_mem, BOOT_SIZE);
    close(fd);
}

void fork_and_exec() {
    pid_t pid;
    int status;

    char *args[] = {"/bin/sh", NULL};

    pid = fork();
    if (pid == -1) die("fork");

    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    waitpid(pid, &status, 0);
}

void sig_int(int sig) {
    printf("Caught SIGINT, exiting...\n");
    exit(0);
}

int main() {
    struct sigaction act;
    struct itimerval tv;

    act.sa_handler = sig_int;
    sigaction(SIGINT, &act, NULL);

    tv.it_interval.tv_sec = 1;
    tv.it_interval.tv_usec = 0;
    tv.it_value.tv_sec = 1;
    tv.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &tv, NULL);

    boot();
    fork_and_exec();

    while(1);
}