//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define RESUME_SIZE 1024

typedef struct {
    char name[100];
    int age;
    char education[100];
    char experience[5][100];
} Resume;

void parse_resume(char *resume_data) {
    Resume *r = (Resume *) resume_data;
    printf("Name: %s\n", r->name);
    printf("Age: %d\n", r->age);
    printf("Education: %s\n", r->education);

    int i;
    for (i = 0; i < 5; i++) {
        printf("Experience %d: %s\n", i + 1, r->experience[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t resume_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *resume_data = mmap(NULL, resume_size, PROT_READ, MAP_PRIVATE, fileno(fp), 0);
    if (resume_data == MAP_FAILED) {
        perror("Error mapping file");
        exit(1);
    }

    parse_resume(resume_data);

    munmap(resume_data, resume_size);
    fclose(fp);

    return 0;
}