//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>

#define MIN_TEMPERATURE -40
#define MAX_TEMPERATURE 100

int read_temperature() {
    char buffer[10];
    int file_desc;
    struct termios old_tio;

    file_desc = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if (file_desc == -1) {
        perror("open");
        return -1;
    }

    tcgetattr(file_desc, &old_tio);
    cfmakeraw(&old_tio);
    old_tio.c_iflag = ISTRIP;
    old_tio.c_oflag = 0;
    old_tio.c_lflag = 0;

    tcsetattr(file_desc, TCSANOW, &old_tio);

    read(file_desc, buffer, sizeof(buffer));

    tcsetattr(file_desc, TCSANOW, &old_tio);
    close(file_desc);

    return atoi(buffer);
}

int main() {
    int temperature;
    int min_temp = MIN_TEMPERATURE;
    int max_temp = MAX_TEMPERATURE;

    while (1) {
        temperature = read_temperature();

        if (temperature < min_temp) {
            min_temp = temperature;
        }

        if (temperature > max_temp) {
            max_temp = temperature;
        }

        printf("Minimum temperature: %d\n", min_temp);
        printf("Maximum temperature: %d\n", max_temp);

        sleep(1);
    }

    return 0;
}