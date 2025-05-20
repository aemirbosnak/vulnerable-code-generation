//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LEN 1024
#define MAX_VARS 10

typedef struct {
    char *name;
    char *value;
} var_t;

static void parse_expr(const char *expr, var_t *vars, int max_vars) {
    char *token, *next_token;
    int i = 0;

    while ((token = strtok_r(expr, " ", &next_token)) != NULL) {
        if (i >= max_vars) {
            break;
        }

        if (strcmp(token, " ") == 0) {
            continue;
        }

        if (strcmp(token, "=") == 0) {
            var_t *var = &vars[i];
            char *value = strtok_r(NULL, " ", &next_token);
            var->name = token;
            var->value = value;
            i++;
        } else {
            vars[i].name = token;
        }
    }
}

int main() {
    char expr[] = "a = 5; b = 10; c = a + b;";
    var_t vars[MAX_VARS];
    int i = 0;

    parse_expr(expr, vars, MAX_VARS);

    printf("vars: ");
    for (i = 0; i < MAX_VARS; i++) {
        printf("%s = %s\n", vars[i].name, vars[i].value);
    }

    return 0;
}