//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <sys/epoll.h>
#include <poll.h>
#include <signal.h>
#include <errno.h>

#define MAX_EVENTS 10

static int epoll_fd;
static int timer_fd;

static void sighandler(int signum) {
    fprintf(stderr, "Received signal %d, exiting...\n", signum);
    close(epoll_fd);
    close(timer_fd);
    exit(0);
}

static int init_scheduler(void) {
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        return -1;
    }

    timer_fd = timerfd_create(CLOCK_REALTIME, 0);
    if (timer_fd == -1) {
        perror("timerfd_create");
        return -1;
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = timer_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, timer_fd, &event) == -1) {
        perror("epoll_ctl");
        return -1;
    }

    return 0;
}

static int schedule_task(unsigned int seconds) {
    struct itimerspec ts;
    ts.it_interval.tv_sec = 0;
    ts.it_interval.tv_nsec = 0;
    ts.it_value.tv_sec = seconds;
    ts.it_value.tv_nsec = 0;

    if (timerfd_settime(timer_fd, 0, &ts, NULL) == -1) {
        perror("timerfd_settime");
        return -1;
    }

    return 0;
}

static void handle_events(void) {
    struct epoll_event events[MAX_EVENTS];
    int nfds;

    while ((nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1)) > 0) {
        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == timer_fd) {
                uint64_t exp;
                if (read(timer_fd, &exp, sizeof(exp)) != sizeof(exp)) {
                    perror("read");
                    close(epoll_fd);
                    close(timer_fd);
                    exit(1);
                }

                // Do something...
                printf("Task scheduled at %ld seconds ago\n", exp);
            }
        }
    }

    if (nfds == -1 && errno != EINTR) {
        perror("epoll_wait");
        close(epoll_fd);
        close(timer_fd);
        exit(1);
    }
}

int main(void) {
    // Setup signal handler
    signal(SIGINT, sighandler);

    // Init scheduler
    if (init_scheduler() == -1) {
        fprintf(stderr, "Failed to initialize scheduler\n");
        return 1;
    }

    // Schedule task
    if (schedule_task(5) == -1) {
        fprintf(stderr, "Failed to schedule task\n");
        return 1;
    }

    // Handle events
    handle_events();

    return 0;
}