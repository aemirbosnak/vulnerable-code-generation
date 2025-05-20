//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <err.h>

struct calc_args {
    double a;
    double b;
    char op;
    double result;
};

double calculate(struct calc_args *args)
{
    switch (args->op) {
        case '+':
            args->result = args->a + args->b;
            break;
        case '-':
            args->result = args->a - args->b;
            break;
        case '*':
            args->result = args->a * args->b;
            break;
        case '/':
            if (args->b == 0.0) {
                errx(1, "Division by zero");
            }
            args->result = args->a / args->b;
            break;
        case '^':
            args->result = pow(args->a, args->b);
            break;
        case 's': // sin
            args->result = sin(args->a);
            break;
        case 'c': // cos
            args->result = cos(args->a);
            break;
        case 't': // tan
            if (cos(args->a) == 0.0) {
                errx(1, "Tangent undefined at this angle");
            }
            args->result = sin(args->a) / cos(args->a);
            break;
        case 'l': // log
            if (args->a <= 0.0) {
                errx(1, "Logarithm undefined for non-positive numbers");
            }
            args->result = log(args->a);
            break;
        default:
            errx(1, "Invalid operator");
    }
    return args->result;
}

void *calc_thread(void *args)
{
    struct calc_args *calc_args = (struct calc_args *)args;
    calc_args->result = calculate(calc_args);
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        errx(1, "Usage: %s <num1> <op> <num2>", argv[0]);
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
    char op = argv[2][0];

    struct calc_args args = { .a = a, .b = b, .op = op };

    pthread_t tid;
    if (pthread_create(&tid, NULL, calc_thread, &args) != 0) {
        err(1, "pthread_create");
    }

    if (pthread_join(tid, NULL) != 0) {
        err(1, "pthread_join");
    }

    printf("Result: %f\n", args.result);
    return 0;
}