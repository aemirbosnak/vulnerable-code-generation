//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 1024
#define MIN_FREE_MEMORY_PERCENT 10

typedef struct {
    unsigned long total;
    unsigned long used;
    unsigned long free;
    unsigned long available;
    unsigned long percent_used;
} MemoryStatus;

static void print_memory_status(const MemoryStatus *status) {
    printf("Total Memory: %lu bytes\n", status->total);
    printf("Used Memory: %lu bytes\n", status->used);
    printf("Free Memory: %lu bytes\n", status->free);
    printf("Available Memory: %lu bytes\n", status->available);
    printf("Percent Used: %lu%%\n\n", status->percent_used);
}

static void get_memory_status(MemoryStatus *status) {
    struct statvfs fs_stat;
    if (statvfs("/", &fs_stat) == 0) {
        status->total = fs_stat.f_blocks * fs_stat.f_frsize;
        status->used = fs_stat.f_blocks - fs_stat.f_bfree;
        status->free = fs_stat.f_bfree * fs_stat.f_frsize;
        status->available = status->free + status->used;
        status->percent_used = (status->used * 100) / status->total;
    } else {
        perror("statvfs");
    }
}

static int is_memory_low(const MemoryStatus *status) {
    return status->percent_used >= MIN_FREE_MEMORY_PERCENT;
}

static void send_alert(const char *subject, const char *body) {
    FILE *mail_fp;
    char cmd[MAX_PATH];

    snprintf(cmd, sizeof(cmd), "echo \"%s\" | mail -s \"%s\" root", body, subject);
    if ((mail_fp = popen(cmd, "r"))!= NULL) {
        pclose(mail_fp);
    } else {
        perror("popen");
    }
}

int main(int argc, char *argv[]) {
    MemoryStatus status;
    char buffer[MAX_PATH];

    get_memory_status(&status);

    if (is_memory_low(&status)) {
        snprintf(buffer, sizeof(buffer), "Low Memory Alert: %lu%% of memory is in use.", status.percent_used);
        send_alert("Low Memory Alert", buffer);
    }

    print_memory_status(&status);

    return 0;
}