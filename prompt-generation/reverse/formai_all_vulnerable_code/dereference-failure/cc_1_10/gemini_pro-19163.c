//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: protected
/* System Event Logger Example in Protected Mode */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/syscall.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define EVENT_LOG_SIZE (4096 * 16) /* 64KB event log buffer */
#define EVENT_LOG_MAGIC 0x12345678 /* Magic number to identify event log buffer */

/* Event log buffer */
static char *event_log_buffer;

/* Write an event to the event log */
static int event_log_write(const char *fmt, ...)
{
    int n;
    va_list ap;

    va_start(ap, fmt);
    n = vsprintf(event_log_buffer, fmt, ap);
    va_end(ap);

    return n;
}

/* Initialize the event log */
static int event_log_init(void)
{
    int fd;

    /* Open the event log device */
    fd = open("/dev/event_log", O_RDWR);
    if (fd < 0) {
        perror("open(/dev/event_log)");
        return -1;
    }

    /* Get the event log buffer address */
    event_log_buffer = mmap(NULL, EVENT_LOG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (event_log_buffer == MAP_FAILED) {
        perror("mmap()");
        close(fd);
        return -1;
    }

    /* Check the event log buffer magic number */
    if (*(uint32_t *)event_log_buffer != EVENT_LOG_MAGIC) {
        fprintf(stderr, "Invalid event log buffer magic number\n");
        munmap(event_log_buffer, EVENT_LOG_SIZE);
        close(fd);
        return -1;
    }

    return fd;
}

/* Main program */
int main(void)
{
    int fd;
    struct timeval tv;
    struct tm *tm;
    char timestamp[32];

    /* Initialize the event log */
    fd = event_log_init();
    if (fd < 0) {
        return -1;
    }

    /* Write some events to the event log */
    gettimeofday(&tv, NULL);
    tm = localtime(&tv.tv_sec);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    event_log_write("%s: Program started\n", timestamp);

    event_log_write("Info: This is an informational message\n");
    event_log_write("Warning: This is a warning message\n");
    event_log_write("Error: This is an error message\n");

    /* Close the event log */
    munmap(event_log_buffer, EVENT_LOG_SIZE);
    close(fd);

    return 0;
}