//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/obj_mac.h>
#include <sys/epoll.h>

#define MAX_EVENTS 64

struct encrypt_ctx {
    EVP_CIPHER_CTX *ctx;
    int fd;
    unsigned char *buf;
    int buflen;
};

static int encrypt_init(struct encrypt_ctx *ctx, const char *key,
                       const char *iv)
{
    EVP_CIPHER *cipher;
    int ret;

    cipher = EVP_get_cipherbyname("aes-256-cbc");
    if (!cipher) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ctx->ctx = EVP_CIPHER_CTX_new();
    if (!ctx->ctx) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ret = EVP_CipherInit_ex(ctx->ctx, cipher, NULL, NULL, NULL, 1);
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ret = EVP_CIPHER_CTX_set_key_length(ctx->ctx, EVP_CIPHER_key_length(cipher));
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ret = EVP_CipherInit_ex(ctx->ctx, NULL, NULL, (unsigned char *)key, (unsigned char *)iv, 1);
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    return 0;
}

static int encrypt_update(struct encrypt_ctx *ctx, const char *buf, int buflen)
{
    int outlen = 0;
    int ret;

    ret = EVP_CipherUpdate(ctx->ctx, ctx->buf, &outlen, (unsigned char *)buf, buflen);
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    return outlen;
}

static int encrypt_final(struct encrypt_ctx *ctx)
{
    int outlen = 0;
    int ret;

    ret = EVP_CipherFinal_ex(ctx->ctx, ctx->buf, &outlen);
    if (ret != 1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    return outlen;
}

static int encrypt_file(const char *file, const char *key, const char *iv)
{
    struct encrypt_ctx ctx;
    int fd;
    int ret;
    struct stat st;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    fstat(fd, &st);

    ret = encrypt_init(&ctx, key, iv);
    if (ret != 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ctx.buf = malloc(st.st_size);
    if (!ctx.buf) {
        perror("malloc");
        return -1;
    }

    ctx.buflen = st.st_size;

    ret = read(fd, ctx.buf, ctx.buflen);
    if (ret != ctx.buflen) {
        perror("read");
        return -1;
    }

    ret = encrypt_update(&ctx, (char *)ctx.buf, ctx.buflen);
    if (ret < 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ret = encrypt_final(&ctx);
    if (ret < 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ret = write(fd, ctx.buf, ctx.buflen + ret);
    if (ret != ctx.buflen + ret) {
        perror("write");
        return -1;
    }

    close(fd);

    return 0;
}

static void event_loop(int epollfd)
{
    struct epoll_event events[MAX_EVENTS];
    int nfds;
    int i;

    while (1) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            break;
        }

        for (i = 0; i < nfds; i++) {
            if (events[i].events & EPOLLIN) {
                struct encrypt_ctx *ctx = events[i].data.ptr;
                int ret;

                ret = encrypt_update(ctx, (char *)ctx->buf, ctx->buflen);
                if (ret < 0) {
                    ERR_print_errors_fp(stderr);
                }

                if (ret == 0) {
                    ret = encrypt_final(ctx);
                    if (ret < 0) {
                        ERR_print_errors_fp(stderr);
                    }

                    epoll_ctl(epollfd, EPOLL_CTL_DEL, ctx->fd, NULL);
                    close(ctx->fd);
                    free(ctx->buf);
                    free(ctx);
                }
            }
        }
    }
}

static int async_encrypt_file(const char *file, const char *key, const char *iv)
{
    struct encrypt_ctx *ctx;
    int fd;
    int ret;
    struct stat st;
    int epollfd;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    fstat(fd, &st);

    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return -1;
    }

    ctx = malloc(sizeof(*ctx));
    if (!ctx) {
        perror("malloc");
        return -1;
    }

    ret = encrypt_init(ctx, key, iv);
    if (ret != 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    ctx->fd = fd;
    ctx->buf = malloc(st.st_size);
    if (!ctx->buf) {
        perror("malloc");
        return -1;
    }

    ctx->buflen = st.st_size;

    ret = read(fd, ctx->buf, ctx->buflen);
    if (ret != ctx->buflen) {
        perror("read");
        return -1;
    }

    struct epoll_event event = {
        .events = EPOLLIN,
        .data.ptr = ctx,
    };

    ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    if (ret != 0) {
        perror("epoll_ctl");
        return -1;
    }

    event_loop(epollfd);

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 5) {
        fprintf(stderr, "Usage: %s file key iv sync/async\n", argv[0]);
        return -1;
    }

    const char *sync = argv[4];

    if (strcmp(sync, "sync") == 0) {
        return encrypt_file(argv[1], argv[2], argv[3]);
    } else if (strcmp(sync, "async") == 0) {
        return async_encrypt_file(argv[1], argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid sync option\n");
    }
}