//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>
#include <openssl/err.h>
#include <openssl/evp.h>

#define BUF_SIZE (1024 * 1024)
#define ROUNDS 16

static void print_errors(void)
{
    unsigned long err;
    while ((err = ERR_get_error()) != 0) {
        char *msg = ERR_error_string(err, NULL);
        fprintf(stderr, "%s\n", msg);
    }
}

static int encrypt_file(const char *infile, const char *outfile)
{
    int infd, outfd, efd;
    struct epoll_event ev;
    EVP_CIPHER_CTX *ctx;
    unsigned char *buf, *outbuf;
    int outlen, buflen;
    size_t olen, ilen;
    int rv = -1;

    /* open input file */
    infd = open(infile, O_RDONLY);
    if (infd == -1) {
        perror("open");
        goto err_open;
    }

    /* open output file */
    outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfd == -1) {
        perror("open");
        goto err_open;
    }

    /* create eventfd */
    efd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK);
    if (efd == -1) {
        perror("eventfd");
        goto err_eventfd;
    }

    /* create EVP cipher context */
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        perror("EVP_CIPHER_CTX_new");
        goto err_EVP_CIPHER_CTX_new;
    }

    /* initialize EVP cipher context */
    if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL, 1) != 1) {
        print_errors();
        goto err_EVP_CipherInit_ex;
    }

    /* allocate buffers */
    buf = malloc(BUF_SIZE);
    if (buf == NULL) {
        perror("malloc");
        goto err_malloc;
    }
    outbuf = malloc(BUF_SIZE);
    if (outbuf == NULL) {
        perror("malloc");
        goto err_malloc;
    }

    /* create epoll event */
    ev.events = EPOLLIN;
    ev.data.fd = infd;

    /* add epoll event to epoll instance */
    if (epoll_ctl(efd, EPOLL_CTL_ADD, infd, &ev) == -1) {
        perror("epoll_ctl");
        goto err_epoll_ctl;
    }

    /* main loop */
    while (1) {
        /* wait for input file to be readable */
        if (epoll_wait(efd, &ev, 1, -1) == -1) {
            perror("epoll_wait");
            goto err;
        }

        /* read from input file */
        buflen = read(infd, buf, BUF_SIZE);
        if (buflen == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            goto err;
        }

        /* update input length */
        ilen += buflen;

        /* update output buffer */
        outlen = EVP_CipherUpdate(ctx, outbuf, &olen, buf, buflen);
        if (outlen != 1) {
            print_errors();
            goto err;
        }

        /* write to output file */
        if (write(outfd, outbuf, outlen) != outlen) {
            perror("write");
            goto err;
        }

        /* update output length */
        olen += outlen;

        /* check if input file is finished */
        if (buflen == 0) {
            break;
        }
    }

    /* write final */
    outlen = EVP_CipherFinal_ex(ctx, outbuf, &olen);
    if (outlen != 1) {
        print_errors();
        goto err;
    }

    /* write to output file */
    if (write(outfd, outbuf, outlen) != outlen) {
        perror("write");
        goto err;
    }

    /* close input file */
    if (close(infd) == -1) {
        perror("close");
        goto err;
    }

    /* close output file */
    if (close(outfd) == -1) {
        perror("close");
        goto err;
    }

    /* destroy EVP cipher context */
    EVP_CIPHER_CTX_free(ctx);

    /* free buffers */
    free(buf);
    free(outbuf);

    rv = 0;

err:
    /* close eventfd */
    close(efd);

err_epoll_ctl:
err_malloc:
err_EVP_CipherInit_ex:
err_EVP_CIPHER_CTX_new:
err_eventfd:
err_open:
    return rv;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <infile> <outfile>\n", argv[0]);
        return 1;
    }

    if (encrypt_file(argv[1], argv[2]) != 0) {
        fprintf(stderr, "error: encrypt_file failed\n");
        return 1;
    }

    return 0;
}