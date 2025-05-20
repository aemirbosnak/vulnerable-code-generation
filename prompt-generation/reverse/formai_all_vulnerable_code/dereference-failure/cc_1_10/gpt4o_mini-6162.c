//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define MAX_NAME_LENGTH 256
#define WARNING_THRESHOLD 80  // percentage

typedef struct {
    char name[MAX_NAME_LENGTH];
    long size;
} DiskItem;

void analyze_directory(const char *path, DiskItem *items, int *count);
long get_total_size(DiskItem *items, int count);
void print_report(DiskItem *items, int count, long total_size);
void print_usage_warning(long total_size, long used_size);

int main(void) {
    char base_path[MAX_PATH_LENGTH] = "/";
    DiskItem items[1000]; // Let's assume we don't have more than 1000 items for simplicity
    int count = 0;

    printf("Welcome, wanderer, to the remnants of this digital wasteland...\n");
    printf("Analyzing disk space, please wait...\n");

    analyze_directory(base_path, items, &count);

    long total_size = get_total_size(items, count);
    long used_size = 0;

    for (int i = 0; i < count; i++) {
        used_size += items[i].size;
    }

    print_report(items, count, total_size);
    print_usage_warning(total_size, used_size);

    return 0;
}

void analyze_directory(const char *path, DiskItem *items, int *count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Failed to read directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) {
                strncpy(items[*count].name, entry->d_name, MAX_NAME_LENGTH);
                items[*count].size = file_stat.st_size;
                (*count)++;
            } else if (S_ISDIR(file_stat.st_mode)) {
                analyze_directory(full_path, items, count);
            }
        }
    }
    closedir(dir);
}

long get_total_size(DiskItem *items, int count) {
    long total_size = 0;
    for (int i = 0; i < count; i++) {
        total_size += items[i].size;
    }
    return total_size;
}

void print_report(DiskItem *items, int count, long total_size) {
    if (total_size == 0) {
        printf("The digital wasteland is eerily empty...\n");
        return;
    }

    printf("A report of the found relics:\n");
    for (int i = 0; i < count; i++) {
        printf(" - %s (Size: %ld bytes)\n", items[i].name, items[i].size);
    }
    printf("Total data scavenged: %ld bytes\n", total_size);
}

void print_usage_warning(long total_size, long used_size) {
    if (total_size == 0) return;

    int used_percentage = (used_size * 100) / total_size;
    if (used_percentage > WARNING_THRESHOLD) {
        printf("Warning! The data wasteland is over %d%% full!\n", WARNING_THRESHOLD);
        printf("Used: %ld bytes of %ld bytes (Used: %d%%)\n", used_size, total_size, used_percentage);
    } else {
        printf("The digital kingdom appears stable... Used: %ld bytes of %ld bytes (Used: %d%%)\n",
               used_size, total_size, used_percentage);
    }
}