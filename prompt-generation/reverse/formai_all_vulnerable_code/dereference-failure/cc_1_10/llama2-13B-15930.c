//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DIARY_SIZE (1024 * 1024)
#define ENTRY_SIZE (128)

typedef struct {
    char date[16];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    char *name;
    char *path;
    off_t size;
    off_t offset;
} diary_file_t;

static diary_file_t *diary_files;
static size_t diary_file_count;

void init_diary(void) {
    diary_file_count = 0;
    diary_files = calloc(1, sizeof(diary_file_t));
}

void add_diary_entry(const char *date, const char *entry) {
    diary_entry_t *entry_ptr = calloc(1, sizeof(diary_entry_t));
    strcpy(entry_ptr->date, date);
    strcpy(entry_ptr->entry, entry);
    diary_files[diary_file_count].offset += sizeof(diary_entry_t);
    diary_files[diary_file_count].size += sizeof(diary_entry_t);
    diary_file_count++;
}

void write_diary(const char *date, const char *entry) {
    char *file_name = malloc(strlen(date) + 1);
    strcpy(file_name, date);
    file_name[strcspn(file_name, "-/")] = 0;
    char *file_path = malloc(strlen(file_name) + 1);
    strcpy(file_path, "/dev/shm/");
    strcat(file_path, file_name);
    int fd = open(file_path, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    diary_entry_t *entry_ptr = calloc(1, sizeof(diary_entry_t));
    strcpy(entry_ptr->date, date);
    strcpy(entry_ptr->entry, entry);
    if (write(fd, entry_ptr, sizeof(diary_entry_t)) == -1) {
        perror("write");
        exit(1);
    }
    close(fd);
}

void read_diary(const char *date) {
    char *file_name = malloc(strlen(date) + 1);
    strcpy(file_name, date);
    file_name[strcspn(file_name, "-/")] = 0;
    char *file_path = malloc(strlen(file_name) + 1);
    strcpy(file_path, "/dev/shm/");
    strcat(file_path, file_name);
    int fd = open(file_path, O_RDONLY, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    diary_entry_t *entry_ptr = calloc(1, sizeof(diary_entry_t));
    if (read(fd, entry_ptr, sizeof(diary_entry_t)) == -1) {
        perror("read");
        exit(1);
    }
    close(fd);
    printf("%s: %s\n", entry_ptr->date, entry_ptr->entry);
}

int main(void) {
    init_diary();
    add_diary_entry("2022-01-01", "New year resolutions");
    add_diary_entry("2022-01-02", "Started learning C");
    add_diary_entry("2022-01-03", "Finished reading The C Programming Language");
    write_diary("2022-01-04", "Started working on this project");
    read_diary("2022-01-05");
    return 0;
}