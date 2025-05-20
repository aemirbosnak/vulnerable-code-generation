//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

enum unit_type {
    UNIT_INVALID,
    UNIT_LENGTH,
    UNIT_MASS,
    UNIT_TIME,
    UNIT_TEMPERATURE
};

struct unit {
    char *name;
    enum unit_type type;
    double value;
};

struct unit_conversion {
    struct unit from;
    struct unit to;
    double factor;
};

struct unit_conversions {
    size_t num_conversions;
    struct unit_conversion *conversions;
};

static struct unit_conversions conversions = {
    .num_conversions = 0,
    .conversions = NULL
};

static int add_conversion(const char *from, enum unit_type from_type,
                         const char *to, enum unit_type to_type,
                         double factor)
{
    struct unit_conversion *new_conversion;

    new_conversion = realloc(conversions.conversions,
                            (conversions.num_conversions + 1) *
                            sizeof(*new_conversion));
    if (!new_conversion)
        return -1;

    conversions.conversions = new_conversion;

    conversions.conversions[conversions.num_conversions].from.name = strdup(from);
    conversions.conversions[conversions.num_conversions].from.type = from_type;
    conversions.conversions[conversions.num_conversions].to.name = strdup(to);
    conversions.conversions[conversions.num_conversions].to.type = to_type;
    conversions.conversions[conversions.num_conversions].factor = factor;

    conversions.num_conversions++;

    return 0;
}

static int convert_unit(const char *from, const char *to, double value,
                        double *result)
{
    size_t i;

    for (i = 0; i < conversions.num_conversions; i++) {
        if (strcmp(conversions.conversions[i].from.name, from) == 0 &&
                strcmp(conversions.conversions[i].to.name, to) == 0) {
            *result = value * conversions.conversions[i].factor;
            return 0;
        }
    }

    return -1;
}

static void print_conversions(void)
{
    size_t i;

    for (i = 0; i < conversions.num_conversions; i++) {
        printf("%s -> %s: %f\n",
               conversions.conversions[i].from.name,
               conversions.conversions[i].to.name,
               conversions.conversions[i].factor);
    }
}

static void free_conversions(void)
{
    size_t i;

    for (i = 0; i < conversions.num_conversions; i++) {
        free(conversions.conversions[i].from.name);
        free(conversions.conversions[i].to.name);
    }

    free(conversions.conversions);
}

int main(int argc, char **argv)
{
    char buf[BUFSIZE];
    double value, result;
    int ret;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <from> <to> <value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (add_conversion("inches", UNIT_LENGTH, "centimeters", UNIT_LENGTH, 2.54) < 0) {
        fprintf(stderr, "Error adding conversion: inches -> centimeters\n");
        return EXIT_FAILURE;
    }

    if (add_conversion("pounds", UNIT_MASS, "kilograms", UNIT_MASS, 0.453592) < 0) {
        fprintf(stderr, "Error adding conversion: pounds -> kilograms\n");
        return EXIT_FAILURE;
    }

    if (add_conversion("seconds", UNIT_TIME, "minutes", UNIT_TIME, 1.0 / 60.0) < 0) {
        fprintf(stderr, "Error adding conversion: seconds -> minutes\n");
        return EXIT_FAILURE;
    }

    if (add_conversion("fahrenheit", UNIT_TEMPERATURE, "celsius", UNIT_TEMPERATURE, 5.0 / 9.0) < 0) {
        fprintf(stderr, "Error adding conversion: fahrenheit -> celsius\n");
        return EXIT_FAILURE;
    }

    value = strtod(argv[3], NULL);

    ret = convert_unit(argv[1], argv[2], value, &result);
    if (ret < 0) {
        fprintf(stderr, "Error converting %s to %s\n", argv[1], argv[2]);
        return EXIT_FAILURE;
    }

    printf("%f %s = %f %s\n", value, argv[1], result, argv[2]);

    print_conversions();

    free_conversions();

    return EXIT_SUCCESS;
}