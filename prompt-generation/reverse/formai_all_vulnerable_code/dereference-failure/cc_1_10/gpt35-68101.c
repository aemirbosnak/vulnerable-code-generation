//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <linux/videodev2.h>
#include <linux/input.h>
#include <pthread.h>
#include <errno.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))

struct buffer {
    void *start;
    size_t length;
};

static struct buffer *buffers;
static unsigned int n_buffers;

static int fd = -1;
static struct v4l2_buffer buf;

static pthread_t tid;
static bool capturing = false;

static void process_image(void *p, int size);
static int read_frame(void);

void* capture_video(void *arg) {
    while (capturing) {
        for (;;) {
            fd_set fds;
            struct timeval tv;
            int r;

            FD_ZERO(&fds);
            FD_SET(fd, &fds);

            tv.tv_sec = 2;
            tv.tv_usec = 0;

            r = select(fd + 1, &fds, NULL, NULL, &tv);
            if (r == -1) {
                if (errno == EINTR) continue;
                perror("select");
                return NULL;
            }
            if (r == 0) {
                fprintf(stderr, "select timeout\n");
                return NULL;
            }

            if (read_frame() == -1) {
                fprintf(stderr, "read_frame error\n");
                return NULL;
            }

            // You can do something with `buf` here.
        }
    }

    return NULL;
}

int v4l2_open(const char *device) {
    fd = open(device, O_RDWR | O_NONBLOCK, 0);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    struct v4l2_capability cap;
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1) {
        perror("VIDIOC_QUERYCAP");
        return -1;
    }
    if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
        fprintf(stderr, "%s is not a video capture device\n", device);
        return -1;
    }

    struct v4l2_cropcap cropcap;
    CLEAR(cropcap);

    cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_CROPCAP, &cropcap) == 0) {
        struct v4l2_crop crop;
        CLEAR(crop);

        crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        crop.c = cropcap.defrect;

        if (ioctl(fd, VIDIOC_S_CROP, &crop) == -1) {
            switch (errno) {
                case EINVAL:
                    // Cropping not supported.
                    break;
                default:
                    // Errors ignored.
                    break;
            }
        }
    }

    struct v4l2_format fmt;
    CLEAR(fmt);

    fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width       = 640;
    fmt.fmt.pix.height      = 480;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;

    if (ioctl(fd, VIDIOC_S_FMT, &fmt) == -1) {
        perror("VIDIOC_S_FMT");
        return -1;
    }

    struct v4l2_requestbuffers req;
    CLEAR(req);

    req.count  = 4;
    req.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;

    if (ioctl(fd, VIDIOC_REQBUFS, &req) == -1) {
        perror("VIDIOC_REQBUFS");
        return -1;
    }

    buffers = calloc(req.count, sizeof(*buffers));
    if (!buffers) {
        fprintf(stderr, "Out of memory\n");
        return -1;
    }

    for (n_buffers = 0; n_buffers < req.count; ++n_buffers) {
        struct v4l2_buffer buf;
        CLEAR(buf);

        buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index  = n_buffers;

        if (ioctl(fd, VIDIOC_QUERYBUF, &buf) == -1) {
            perror("VIDIOC_QUERYBUF");
            return -1;
        }

        buffers[n_buffers].length = buf.length;
        buffers[n_buffers].start  = mmap(NULL, buf.length, PROT_READ | PROT_WRITE,
                                         MAP_SHARED, fd, buf.m.offset);
        if (buffers[n_buffers].start == MAP_FAILED) {
            perror("mmap");
            return -1;
        }
    }

    for (unsigned int i = 0; i < n_buffers; ++i) {
        struct v4l2_buffer buf;
        CLEAR(buf);

        buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index  = i;

        if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
            perror("VIDIOC_QBUF");
            return -1;
        }
    }

    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMON, &type) == -1) {
        perror("VIDIOC_STREAMON");
        return -1;
    }

    return 0;
}

int v4l2_close() {
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMOFF, &type) == -1) perror("VIDIOC_STREAMOFF");

    for (unsigned int i = 0; i < n_buffers; ++i)
        munmap(buffers[i].start, buffers[i].length);

    free(buffers);

    return close(fd);
}

int read_frame() {
    CLEAR(buf);

    buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;

    if (ioctl(fd, VIDIOC_DQBUF, &buf) == -1) {
        switch (errno) {
            case EAGAIN:
                break;
            case EIO:
            default:
                perror("VIDIOC_DQBUF");
                return -1;
        }
    }

    process_image(buffers[buf.index].start, buf.bytesused);

    if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
        perror("VIDIOC_QBUF");
        return -1;
    }

    return 0;
}

static void process_image(void *p, int size) {
    // You can do something with the image buffer here.
    // In this example, we just print out the size of the buffer.
    printf("buffer size: %d\n", size);
}

int main() {
    if (v4l2_open("/dev/video0") == -1) {
        fprintf(stderr, "Failed to open device\n");
        return EXIT_FAILURE;
    }

    capturing = true;
    if (pthread_create(&tid, NULL, capture_video, NULL) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Wait for a key to be pressed to stop the video capture.
    getchar();
    capturing = false;
    pthread_join(tid, NULL);

    v4l2_close();

    return EXIT_SUCCESS;
}