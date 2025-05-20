//FormAI DATASET v1.0 Category: QR code reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define DEVICE_NAME "/dev/video0"

#define QR_CODE_SIZE 21
#define QR_CODE_MARKER_COUNT 3

#define BUFFER_COUNT 3

struct buffer {
    void *start;
    size_t length;
};

struct buffer buffers[BUFFER_COUNT];
int fd = -1;

uint8_t qr_code[QR_CODE_SIZE*QR_CODE_SIZE] = {0};

const int marker_coordinates[QR_CODE_MARKER_COUNT][2] = {
    {3, 3},
    {3, 17},
    {17, 3},
};

bool init_camera();
void deinit_camera();
bool capture_image(uint8_t *image_data, size_t *image_size);
bool find_qr_code(uint8_t *image_data, size_t image_size);
bool decode_qr_code(uint8_t *qr_code_data);

int main(int argc, char **argv) {
    if (init_camera() == false) {
        printf("Failed to initialize camera.\n");
        return -1;
    }

    uint8_t *image_data = calloc(1, buffers[0].length);
    size_t image_size = 0;
    while (true) {
        if (capture_image(image_data, &image_size) == false) {
            printf("Failed to capture image.\n");
            break;
        }

        if (find_qr_code(image_data, image_size) == false) {
            printf("QR code not found.\n");
            continue;
        }

        if (decode_qr_code(qr_code) == false) {
            printf("Failed to decode QR code.\n");
            continue;
        }

        printf("QR code: %s\n", qr_code);
    }

    free(image_data);
    deinit_camera();
    return 0;
}

bool init_camera() {
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd == -1) {
        printf("Failed to open %s: %s.\n", DEVICE_NAME, strerror(errno));
        return false;
    }

    struct v4l2_capability cap;
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1) {
        printf("Failed to query video device capabilities: %s.\n", strerror(errno));
        return false;
    }

    if (cap.capabilities & ~(V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING)) {
        printf("%s is not a video capture device.\n", DEVICE_NAME);
        return false;
    }

    struct v4l2_format fmt = {
        .type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
        .fmt.pix.width = 640,
        .fmt.pix.height = 480,
        .fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV,
        .fmt.pix.field = V4L2_FIELD_NONE,
    };
    if (ioctl(fd, VIDIOC_S_FMT, &fmt) == -1) {
        printf("Failed to set video format: %s.\n", strerror(errno));
        return false;
    }

    struct v4l2_requestbuffers req = {
        .type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
        .count = BUFFER_COUNT,
        .memory = V4L2_MEMORY_MMAP,
    };
    if (ioctl(fd, VIDIOC_REQBUFS, &req) == -1) {
        printf("Failed to request buffers: %s.\n", strerror(errno));
        return false;
    }

    for (int i = 0; i < req.count; i++) {
        struct v4l2_buffer buf = {
            .type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
            .index = i,
        };
        if (ioctl(fd, VIDIOC_QUERYBUF, &buf) == -1) {
            printf("Failed to query buffer %d: %s.\n", i, strerror(errno));
            return false;
        }

        buffers[i].length = buf.length;
        buffers[i].start = mmap(NULL, buf.length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        if (buffers[i].start == MAP_FAILED) {
            printf("Failed to map buffer %d: %s.\n", i, strerror(errno));
            return false;
        }
    }

    for (int i = 0; i < req.count; i++) {
        struct v4l2_buffer buf = {
            .type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
            .index = i,
            .memory = V4L2_MEMORY_MMAP,
        };
        if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
            printf("Failed to enqueue buffer %d: %s.\n", i, strerror(errno));
            return false;
        }
    }

    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMON, &type) == -1) {
        printf("Failed to start streaming: %s.\n", strerror(errno));
        return false;
    }

    return true;
}

void deinit_camera() {
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_STREAMOFF, &type) == -1) {
        printf("Failed to stop streaming: %s.\n", strerror(errno));
    }

    for (int i = 0; i < BUFFER_COUNT; i++) {
        munmap(buffers[i].start, buffers[i].length);
    }

    close(fd);
    fd = -1;
}

bool capture_image(uint8_t *image_data, size_t *image_size) {
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    int ret = select(fd + 1, &fds, NULL, NULL, &tv);
    if (ret == -1) {
        printf("Failed to select: %s.\n", strerror(errno));
        return false;
    }

    if (ret == 0) {
        printf("Timeout while waiting for frame.\n");
        return false;
    }

    struct v4l2_buffer buf = {
        .type = V4L2_BUF_TYPE_VIDEO_CAPTURE,
        .memory = V4L2_MEMORY_MMAP,
    };
    if (ioctl(fd, VIDIOC_DQBUF, &buf) == -1) {
        printf("Failed to dequeue buffer: %s.\n", strerror(errno));
        return false;
    }

    *image_size = 0;
    size_t remaining_size = buf.bytesused;
    while (remaining_size > 0) {
        const ssize_t size = read(fd, image_data + (*image_size), remaining_size);
        if (size == -1) {
            if (errno == EINTR) {
                continue;
            }

            printf("Failed to read data: %s.\n", strerror(errno));
            return false;
        }

        if (size == 0) {
            printf("EOF.\n");
            return false;
        }

        *image_size += size;
        remaining_size -= size;
    }

    if (remaining_size != 0) {
        printf("Unexpected data read: %d.\n", (int)(buf.bytesused - remaining_size));
        return false;
    }

    if (ioctl(fd, VIDIOC_QBUF, &buf) == -1) {
        printf("Failed to enqueue buffer: %s.\n", strerror(errno));
        return false;
    }

    return true;
}

bool find_qr_code(uint8_t *image_data, size_t image_size) {
    const uint8_t marker[QR_CODE_MARKER_COUNT] = {0xff, 0x00, 0xff};
    size_t marker_index = 0;
    size_t marker_count = 0;
    for (size_t i = 0; i < image_size; i++) {
        if (image_data[i] == marker[marker_index]) {
            marker_index++;
            if (marker_index == QR_CODE_MARKER_COUNT) {
                if (marker_count == 0) {
                    // First marker found, copy the QR code into buffer.
                    for (size_t j = 0; j < QR_CODE_SIZE; j++) {
                        memcpy(qr_code + j*QR_CODE_SIZE, image_data + i - QR_CODE_SIZE + j*2, QR_CODE_SIZE);
                    }

                    marker_count++;
                    marker_index = 0;
                    i += 10;  // Skip next 10 bytes to avoid finding the same marker again.
                } else {
                    marker_count++;
                    marker_index = 0;
                    if (marker_count == QR_CODE_MARKER_COUNT) {
                        return true;
                    }
                }
            }
        } else {
            marker_index = 0;
            marker_count = 0;
        }
    }

    return false;
}

bool decode_qr_code(uint8_t *qr_code_data) {
    // TODO: Implement QR code decoder.
    return true;  // Dummy implementation - always return true.
}