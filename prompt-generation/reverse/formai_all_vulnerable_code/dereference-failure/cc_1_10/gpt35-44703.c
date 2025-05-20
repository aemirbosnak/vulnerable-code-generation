//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program parses a simplified version of C syntax */

void program(void);
void declaration_list(void);
void declaration(void);
void var_declaration(void);
void func_declaration(void);
void type_specifier(void);
void identifier(void);
void params(void);
void param_list(void);
void param(void);
void compound_statement(void);
void statement_list(void);
void statement(void);
void expression_statement(void);
void selection_statement(void);
void iteration_statement(void);
void expression(void);
void variable(void);
void simple_expression(void);
void term(void);
void factor(void);
void actual_params(void);
void actual_param_list(void);
void actual_param(void);

char *token; // current token
char *prev_token; // previous token
char **next_ptr; // point to next character in input string

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s 'source code'\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    next_ptr = &input;

    program();

    printf("Successful parse!\n");

    return 0;
}

void program(void) {
    declaration_list(); // program starts with a list of declarations
}

void declaration_list(void) {
    declaration();
    while (*next_ptr) {
        declaration();
    }
}

void declaration(void) {
    type_specifier();
    if (strcmp(token, "ID") == 0) {
        identifier();
        if (strcmp(token, "(") == 0) {
            func_declaration();
        } else {
            var_declaration();
        }
    } else {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void var_declaration(void) {
    // skip variable name
    identifier();
    if (strcmp(token, ";") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    // move on to next declaration or end of input
    token = strtok_r(NULL, " ", next_ptr);
}

void func_declaration(void) {
    // skip parameter list
    params();
    compound_statement();
}

void type_specifier(void) {
    prev_token = token;
    token = strtok_r(NULL, " ", next_ptr);
    if (strcmp(token, "int") == 0 || strcmp(token, "void") == 0) {
        // valid type specifier
    } else {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void identifier(void) {
    prev_token = token;
    token = strtok_r(NULL, " ", next_ptr);
    if (strcmp(token, "ID") == 0) {
        // valid identifier
    } else {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void params(void) {
    if (strcmp(token, "(") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    param_list();
    if (strcmp(token, ")") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void param_list(void) {
    param();
    while (strcmp(token, ",") == 0) {
        param();
    }
}

void param(void) {
    type_specifier();
    identifier();
}

void compound_statement(void) {
    if (strcmp(token, "{") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    statement_list();
    if (strcmp(token, "}") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void statement_list(void) {
    while (strcmp(token, "}") != 0) {
        statement();
    }
}

void statement(void) {
    if (strcmp(token, "ID") == 0) {
        expression_statement();
    } else if (strcmp(token, "if") == 0) {
        selection_statement();
    } else if (strcmp(token, "while") == 0) {
        iteration_statement();
    } else if (strcmp(token, "{") == 0) {
        compound_statement();
    } else {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void expression_statement(void) {
    variable();
    if (strcmp(token, "=") == 0) {
        expression();
    }
    if (strcmp(token, ";") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    // move on to next statement or end of input
    token = strtok_r(NULL, " ", next_ptr);
}

void selection_statement(void) {
    if (strcmp(token, "if") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    expression();
    statement();
    if (strcmp(token, "else") == 0) {
        statement();
    }
}

void iteration_statement(void) {
    if (strcmp(token, "while") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    expression();
    statement();
}

void expression(void) {
    simple_expression(); // TODO: support relational operators
}

void variable(void) {
    identifier();
    // TODO: support arrays
}

void simple_expression(void) {
    term();
    while (strcmp(token, "+") == 0 || strcmp(token, "-") == 0) {
        term();
    }
}

void term(void) {
    factor();
    while (strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
        factor();
    }
}

void factor(void) {
    if (strcmp(token, "(") == 0) {
        expression();
        if (strcmp(token, ")") != 0) {
            printf("Syntax error at %s\n", token);
            exit(1);
        }
    } else if (strcmp(token, "ID") == 0) {
        variable();
    } else if (strcmp(token, "NUM") == 0) {
        // valid number
    } else {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    // move on to next factor or operator, if any
    token = strtok_r(NULL, " ", next_ptr);
}

void actual_params(void) {
    if (strcmp(token, "(") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
    actual_param_list();
    if (strcmp(token, ")") != 0) {
        printf("Syntax error at %s\n", token);
        exit(1);
    }
}

void actual_param_list(void) {
    actual_param();
    while (strcmp(token, ",") == 0) {
        actual_param();
    }
}

void actual_param(void) {
    expression();
}