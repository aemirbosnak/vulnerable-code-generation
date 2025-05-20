//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define GPIO_PATH "/sys/class/gpio"
#define GPIO_EXPORT_FILE "export"
#define GPIO_UNEXPORT_FILE "unexport"
#define GPIO_VALUE_FILE "value"

int main(int argc, char *argv[])
{
    int fd, value;
    char buf[256];

    // Check if the user provided a GPIO number
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <GPIO number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the GPIO number from the user
    int gpio_number = atoi(argv[1]);

    // Export the GPIO
    fd = open(GPIO_PATH "/" GPIO_EXPORT_FILE, O_WRONLY);
    if (fd < 0)
    {
        perror("Unable to open GPIO export file");
        exit(EXIT_FAILURE);
    }
    snprintf(buf, sizeof(buf), "%d", gpio_number);
    write(fd, buf, strlen(buf));
    close(fd);

    // Set the GPIO to output mode
    snprintf(buf, sizeof(buf), GPIO_PATH "/gpio%d/" "direction", gpio_number);
    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("Unable to open GPIO direction file");
        exit(EXIT_FAILURE);
    }
    write(fd, "out", 3);
    close(fd);

    // Set the initial GPIO value to low
    snprintf(buf, sizeof(buf), GPIO_PATH "/gpio%d/" GPIO_VALUE_FILE, gpio_number);
    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("Unable to open GPIO value file");
        exit(EXIT_FAILURE);
    }
    write(fd, "0", 1);
    close(fd);

    // Loop forever, waiting for the user to press a key
    while (1)
    {
        // Get the current GPIO value
        snprintf(buf, sizeof(buf), GPIO_PATH "/gpio%d/" GPIO_VALUE_FILE, gpio_number);
        fd = open(buf, O_RDONLY);
        if (fd < 0)
        {
            perror("Unable to open GPIO value file");
            exit(EXIT_FAILURE);
        }
        read(fd, buf, sizeof(buf));
        close(fd);

        // Convert the GPIO value to an integer
        value = atoi(buf);

        // Toggle the GPIO value
        value = !value;

        // Set the GPIO value
        snprintf(buf, sizeof(buf), GPIO_PATH "/gpio%d/" GPIO_VALUE_FILE, gpio_number);
        fd = open(buf, O_WRONLY);
        if (fd < 0)
        {
            perror("Unable to open GPIO value file");
            exit(EXIT_FAILURE);
        }
        snprintf(buf, sizeof(buf), "%d", value);
        write(fd, buf, strlen(buf));
        close(fd);

        // Sleep for 1 second
        sleep(1);
    }

    // Unexport the GPIO
    snprintf(buf, sizeof(buf), GPIO_PATH "/" GPIO_UNEXPORT_FILE, gpio_number);
    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        perror("Unable to open GPIO unexport file");
        exit(EXIT_FAILURE);
    }
    snprintf(buf, sizeof(buf), "%d", gpio_number);
    write(fd, buf, strlen(buf));
    close(fd);

    return EXIT_SUCCESS;
}