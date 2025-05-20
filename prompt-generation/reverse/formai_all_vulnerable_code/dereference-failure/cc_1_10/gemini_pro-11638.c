//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define CONVERT_UNITS 7
#define INPUT_BUFFER 256
#define INPUT_UNITS 64
#define UNITS_TABLE "in cm ft m yd mi km"

typedef enum {
    INCH,
    CM,
    FOOT,
    METER,
    YARD,
    MILE,
    KILOMETER
} unit_t;

typedef struct {
    char *name;
    double value;
} unit_entry_t;

typedef struct {
    char *input;
    size_t input_len;
    size_t input_pos;
    char *output;
    size_t output_pos;
} input_buffer_t;

typedef struct {
    char *input;
    size_t input_len;
    size_t input_pos;
    unit_t from_unit;
    unit_t to_unit;
    double value;
    char *output;
    size_t output_pos;
} unit_conversion_t;

static unit_entry_t units_table[] = {
    { "in", 2.54 },
    { "cm", 1.0 },
    { "ft", 30.48 },
    { "m", 100.0 },
    { "yd", 91.44 },
    { "mi", 160934.4 },
    { "km", 100000.0 }
};

static void input_buffer_init(input_buffer_t *buf) {
    buf->input = malloc(INPUT_BUFFER);
    buf->input_len = 0;
    buf->input_pos = 0;
    buf->output = malloc(INPUT_BUFFER);
    buf->output_pos = 0;
}

static void input_buffer_free(input_buffer_t *buf) {
    free(buf->input);
    free(buf->output);
}

static void input_buffer_append(input_buffer_t *buf, char *str) {
    size_t len = strlen(str);
    memcpy(buf->input + buf->input_len, str, len);
    buf->input_len += len;
}

static void input_buffer_append_char(input_buffer_t *buf, char c) {
    buf->input[buf->input_len++] = c;
}

static void input_buffer_reset(input_buffer_t *buf) {
    buf->input_len = 0;
    buf->input_pos = 0;
    buf->output_pos = 0;
}

static char input_buffer_peek(input_buffer_t *buf) {
    if (buf->input_pos < buf->input_len) {
        return buf->input[buf->input_pos];
    }
    return '\0';
}

static char input_buffer_get(input_buffer_t *buf) {
    if (buf->input_pos < buf->input_len) {
        return buf->input[buf->input_pos++];
    }
    return '\0';
}

static void input_buffer_put(input_buffer_t *buf, char c) {
    buf->output[buf->output_pos++] = c;
}

static void input_buffer_flush(input_buffer_t *buf) {
    buf->output[buf->output_pos] = '\0';
    buf->input_len = buf->output_pos;
    memcpy(buf->input, buf->output, buf->input_len);
    buf->input_pos = 0;
    buf->output_pos = 0;
}

static unit_t input_buffer_get_unit(input_buffer_t *buf) {
    char c;
    char units[INPUT_UNITS];
    size_t units_len = 0;

    while ((c = input_buffer_get(buf))) {
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            break;
        }
        if (units_len < INPUT_UNITS) {
            units[units_len++] = c;
        }
    }

    if (units_len == 0) {
        return -1;
    }

    units[units_len] = '\0';

    for (size_t i = 0; i < CONVERT_UNITS; i++) {
        if (strcmp(units, units_table[i].name) == 0) {
            return i;
        }
    }

    return -1;
}

static double input_buffer_get_value(input_buffer_t *buf) {
    char c;
    char value[INPUT_UNITS];
    size_t value_len = 0;

    while ((c = input_buffer_get(buf))) {
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            break;
        }
        if (value_len < INPUT_UNITS) {
            value[value_len++] = c;
        }
    }

    if (value_len == 0) {
        return -1;
    }

    value[value_len] = '\0';

    return atof(value);
}

static void unit_conversion_init(unit_conversion_t *conv, char *input) {
    conv->input = input;
    conv->input_len = strlen(input);
    conv->input_pos = 0;
    conv->from_unit = -1;
    conv->to_unit = -1;
    conv->value = -1;
    conv->output = malloc(INPUT_BUFFER);
    conv->output_pos = 0;
}

static void unit_conversion_free(unit_conversion_t *conv) {
    free(conv->output);
}

static void unit_conversion_parse(unit_conversion_t *conv) {
    char c;
    input_buffer_t buf;

    input_buffer_init(&buf);
    input_buffer_append(&buf, conv->input);

    while ((c = input_buffer_get(&buf))) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c) || c == '.') {
            input_buffer_put(&buf, c);
        } else if (isalpha(c)) {
            input_buffer_flush(&buf);
            if (conv->from_unit == -1) {
                conv->from_unit = input_buffer_get_unit(&buf);
            } else if (conv->to_unit == -1) {
                conv->to_unit = input_buffer_get_unit(&buf);
            } else {
                break;
            }
        } else {
            break;
        }
    }

    if (conv->from_unit == -1 || conv->to_unit == -1) {
        conv->value = -1;
        return;
    }

    input_buffer_reset(&buf);
    conv->value = input_buffer_get_value(&buf);
}

static void unit_conversion_convert(unit_conversion_t *conv) {
    if (conv->value == -1) {
        return;
    }

    double result = conv->value * units_table[conv->from_unit].value / units_table[conv->to_unit].value;

    snprintf(conv->output, INPUT_BUFFER, "%f %s", result, units_table[conv->to_unit].name);
}

static void unit_conversion_print(unit_conversion_t *conv) {
    if (conv->value == -1) {
        printf("Invalid input.\n");
    } else {
        printf("%s\n", conv->output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unit_conversion_t conv;
    unit_conversion_init(&conv, argv[1]);
    unit_conversion_parse(&conv);
    unit_conversion_convert(&conv);
    unit_conversion_print(&conv);
    unit_conversion_free(&conv);

    return EXIT_SUCCESS;
}