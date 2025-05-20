//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#define MAX_FN 100
#define MAX_BACKUPS 10
typedef char file_name[MAX_FN];
typedef struct {
    file_name fn;
    unsigned int back_count;
    struct {
        file_name back_fn;
    } backs[MAX_BACKUPS];
} file_backups;

void init_file_backups(file_backups *fb, char *fn) {
    int i;
    for (i = 0; i < MAX_FN; i++) {
        fb->fn[i] = fn[i];
    }
    fb->back_count = 0;
    int j;
    for (j = 0; j < MAX_BACKUPS; j++) {
        for (i = 0; i < MAX_FN; i++) {
            fb->backs[j].back_fn[i] = '\0';
        }
    }
}

void backup_file(file_backups *fb) {
    int i;
    for (i = MAX_BACKUPS - 1; i > 0; i--) {
        int j;
        for (j = 0; j < MAX_FN; j++) {
            fb->backs[i].back_fn[j] = fb->backs[i - 1].back_fn[j];
        }
    }
    for (i = 0; i < MAX_FN; i++) {
        fb->backs[0].back_fn[i] = fb->fn[i];
    }
    fb->back_count++;
}

void print_file_backups(file_backups *fb) {
    int i;
    printf("File: %s\n", fb->fn);
    printf("Number of backups: %u\n", fb->back_count);
    for (i = 0; i < fb->back_count; i++) {
        printf("Backup %u: %s\n", i, fb->backs[i].back_fn);
    }
}

int main() {
    file_backups fb;
    init_file_backups(&fb, "test.txt");
    backup_file(&fb);
    backup_file(&fb);
    print_file_backups(&fb);
    return 0;
}