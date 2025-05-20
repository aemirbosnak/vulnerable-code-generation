//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <pwd.h>
#include <time.h>

void print_uptime() {
    struct sysinfo info;
    if(sysinfo(&info) == 0) {
        printf("System Uptime: %ld days, %ld hours, %ld minutes\n",
               info.uptime / 86400, (info.uptime % 86400) / 3600,
               (info.uptime % 3600) / 60);
    } else {
        perror("Could not retrieve uptime");
    }
}

void print_disk_usage(const char* path) {
    struct statvfs stat;
    if(statvfs(path, &stat) == 0) {
        long total = stat.f_blocks * stat.f_frsize;
        long free = stat.f_bfree * stat.f_frsize;
        long used = total - free;
        
        printf("Disk Usage for %s:\n", path);
        printf("Total: %ld bytes\n", total);
        printf("Used: %ld bytes\n", used);
        printf("Free: %ld bytes\n", free);
    } else {
        perror("Could not retrieve disk usage");
    }
}

void print_current_user() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if(pw) {
        printf("Current User: %s (UID: %d)\n", pw->pw_name, uid);
    } else {
        perror("Could not retrieve user information");
    }
}

void print_current_time() {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current Time: %s\n", buffer);
}

int main() {
    printf("=== System Administration Tool ===\n");

    // Display Uptime
    print_uptime();

    // Display Disk Usage for root directory
    print_disk_usage("/");

    // Display Current User
    print_current_user();

    // Display Current Time
    print_current_time();

    printf("==================================\n");
    return 0;
}