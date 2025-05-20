//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 1024
#define ASYNC_GETDIR 1
#define ASYNC_ANALYZE 2
#define ASYNC_PRINT 3

typedef struct {
    DIR *dir;
    char *dirname;
    int subdirs_count;
    char **subdirs;
    int block_count;
    int file_count;
    off_t total_size;
    int pipefd[2];
    int pid;
    int async_op;
} AsyncContext;

void getdir_async(AsyncContext *ctx);
void analyze_async(AsyncContext *ctx);
void print_async(AsyncContext *ctx);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    AsyncContext ctx = {0};
    ctx.dirname = argv[1];
    pipe(ctx.pipefd);
    ctx.async_op = ASYNC_GETDIR;
    ctx.pid = fork();
    if (ctx.pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (ctx.pid == 0) {
        close(ctx.pipefd[0]);
        getdir_async(&ctx);
        close(ctx.pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(ctx.pipefd[1]);
        analyze_async(&ctx);
        wait(0);
        close(ctx.pipefd[0]);
        exit(EXIT_SUCCESS);
    }
}

void getdir_async(AsyncContext *ctx) {
    DIR *dir = opendir(ctx->dirname);
    if (dir == NULL) {
        fprintf(stderr, "Cannot open directory %s: %s\n", ctx->dirname, strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (1) {
        struct dirent *entry = readdir(dir);
        if (entry == NULL) {
            break;
        }
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0
                && strcmp(entry->d_name, "..") != 0) {
            ctx->subdirs_count++;
            ctx->subdirs = realloc(ctx->subdirs, sizeof(char *) * ctx->subdirs_count);
            ctx->subdirs[ctx->subdirs_count - 1] = malloc(strlen(ctx->dirname) + strlen(entry->d_name) + 2);
            sprintf(ctx->subdirs[ctx->subdirs_count - 1], "%s/%s", ctx->dirname, entry->d_name);
        }
    }
    closedir(dir);
    ctx->dir = opendir(ctx->dirname);
    ctx->async_op = ASYNC_ANALYZE;
    write(ctx->pipefd[1], &ctx->async_op, sizeof(ctx->async_op));
}

void analyze_async(AsyncContext *ctx) {
    int res;
    while (1) {
        res = read(ctx->pipefd[0], &ctx->async_op, sizeof(ctx->async_op));
        if (res == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (res == 0) {
            break;
        }
        if (ctx->async_op == ASYNC_GETDIR) {
            continue;
        }
        struct dirent *entry = readdir(ctx->dir);
        if (entry == NULL) {
            break;
        }
        if (entry->d_type == DT_REG) {
            char filename[strlen(ctx->dirname) + strlen(entry->d_name) + 2];
            sprintf(filename, "%s/%s", ctx->dirname, entry->d_name);
            struct stat st;
            if (stat(filename, &st) == -1) {
                fprintf(stderr, "Cannot stat file %s: %s\n", filename, strerror(errno));
                continue;
            }
            ctx->total_size += st.st_size;
            ctx->file_count++;
            ctx->block_count += (st.st_blocks - 1);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0
                && strcmp(entry->d_name, "..") != 0) {
            char subdir[strlen(ctx->dirname) + strlen(entry->d_name) + 2];
            sprintf(subdir, "%s/%s", ctx->dirname, entry->d_name);
            AsyncContext async_ctx = {0};
            async_ctx.dirname = subdir;
            pipe(async_ctx.pipefd);
            async_ctx.async_op = ASYNC_GETDIR;
            async_ctx.pid = fork();
            if (async_ctx.pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (async_ctx.pid == 0) {
                close(async_ctx.pipefd[0]);
                getdir_async(&async_ctx);
                close(async_ctx.pipefd[1]);
                exit(EXIT_SUCCESS);
            } else {
                close(async_ctx.pipefd[1]);
                analyze_async(&async_ctx);
                wait(0);
                close(async_ctx.pipefd[0]);
            }
        }
    }
    ctx->async_op = ASYNC_PRINT;
    write(ctx->pipefd[1], &ctx->async_op, sizeof(ctx->async_op));
}

void print_async(AsyncContext *ctx) {
    printf("%d blocks\n%d files\n%ld bytes\n", ctx->block_count, ctx->file_count, ctx->total_size);
    printf("%s: %d subdirectories\n", ctx->dirname, ctx->subdirs_count);
    for (int i = 0; i < ctx->subdirs_count; i++) {
        printf("\n");
        AsyncContext async_ctx = {0};
        async_ctx.dirname = ctx->subdirs[i];
        pipe(async_ctx.pipefd);
        async_ctx.async_op = ASYNC_GETDIR;
        async_ctx.pid = fork();
        if (async_ctx.pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (async_ctx.pid == 0) {
            close(async_ctx.pipefd[0]);
            getdir_async(&async_ctx);
            close(async_ctx.pipefd[1]);
            exit(EXIT_SUCCESS);
        } else {
            close(async_ctx.pipefd[1]);
            analyze_async(&async_ctx);
            wait(0);
            close(async_ctx.pipefd[0]);
            print_async(&async_ctx);
        }
    }
}