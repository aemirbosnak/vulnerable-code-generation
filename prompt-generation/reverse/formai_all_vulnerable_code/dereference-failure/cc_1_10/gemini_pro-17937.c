//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

typedef int32_t temp_t;

static temp_t read_temp(const char *path) {
    int32_t temp;

    FILE *fp = fopen(path, "rb");
    if (!fp) return -1;

    if (fscanf(fp, "%*s %d", &temp) != 1) temp = -1;

    fclose(fp);

    return temp;
}

static char *humanize_temp(temp_t temp) {
    static char buf[20];

    int32_t int_temp = temp / 1000;
    int32_t frac_temp = (temp % 1000) / 10;

    if (int_temp >= 0) sprintf(buf, "+%d.%01d", int_temp, frac_temp);
    else sprintf(buf, "%d.%01d", int_temp, frac_temp);

    return buf;
}

static void dump_table(void) {
    FILE *fp = fopen("temp.dat", "w");
    if (!fp) return;

    for (int i = 0; i < 30; i++) {
        temp_t temp = read_temp("/sys/class/thermal/thermal_zone0/temp");
        if (temp < 0) break;

        fprintf(fp, "%d %s\n", i, humanize_temp(temp));
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (!strcmp("dump", argv[1])) {
        dump_table();
        return 0;
    }

    temp_t temp = read_temp("/sys/class/thermal/thermal_zone0/temp");

    if (temp < 0) {
        fprintf(stderr, "Could not read temperature\n");
        return -1;
    }

    printf("%s\n", humanize_temp(temp));

    return 0;
}