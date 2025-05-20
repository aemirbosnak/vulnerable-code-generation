//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <light_name>\n", argv[0]);
        return 1;
    }

    char* light_name = argv[1];
    char* light_file = "/sys/class/gpio/gpio<num>";
    char* pin_dir = "/sys/class/gpio/gpio<num>/direction";
    char* pin_write = "/sys/class/gpio/gpio<num>/value";

    int light_num = atoi(light_name + 4);

    if (access(light_file, F_OK) == -1) {
        printf("Light not found.\n");
        return 1;
    }

    if (access(pin_dir, F_OK) == -1) {
        printf("GPIO not found.\n");
        return 1;
    }

    if (access(pin_write, F_OK) == -1) {
        printf("GPIO not found.\n");
        return 1;
    }

    int fd_file = open(light_file, O_RDWR);
    int fd_dir = open(pin_dir, O_WRONLY);
    int fd_write = open(pin_write, O_WRONLY);

    if (fd_file == -1 || fd_dir == -1 || fd_write == -1) {
        printf("Error opening file.\n");
        return 1;
    }

    char* mode = "out";
    char* value = "1";

    write(fd_dir, mode, strlen(mode));
    write(fd_write, value, strlen(value));

    printf("Light '%s' turned on.\n", light_name);

    sleep(5);

    char* off_value = "0";
    write(fd_write, off_value, strlen(off_value));

    printf("Light '%s' turned off.\n", light_name);

    close(fd_file);
    close(fd_dir);
    close(fd_write);

    return 0;
}