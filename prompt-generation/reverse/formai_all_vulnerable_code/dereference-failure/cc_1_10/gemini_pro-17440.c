//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A very primitive XML parser. */

struct xml_node {
        char *name;
        char *value;
        struct xml_node *next;
        struct xml_node *child;
};

struct xml_document {
        struct xml_node *root;
};

struct xml_parser {
        char *input;
        int offset;
};

struct xml_parser *
xml_parser_new(char *input)
{
        struct xml_parser *parser;

        parser = malloc(sizeof(*parser));
        if (!parser)
                return NULL;

        parser->input = input;
        parser->offset = 0;

        return parser;
}

void
xml_parser_free(struct xml_parser *parser)
{
        if (!parser)
                return;

        free(parser);
}

int
xml_parser_has_next(struct xml_parser *parser)
{
        return parser->offset < strlen(parser->input);
}

char
xml_parser_peek(struct xml_parser *parser)
{
        if (!xml_parser_has_next(parser))
                return '\0';

        return parser->input[parser->offset];
}

char
xml_parser_next(struct xml_parser *parser)
{
        if (!xml_parser_has_next(parser))
                return '\0';

        return parser->input[parser->offset++];
}

void
xml_parser_skip_whitespace(struct xml_parser *parser)
{
        while (isspace(xml_parser_peek(parser)))
                xml_parser_next(parser);
}

struct xml_node *
xml_parser_parse_node(struct xml_parser *parser)
{
        struct xml_node *node;
        char *name, *value;
        int i;

        xml_parser_skip_whitespace(parser);

        if (xml_parser_peek(parser) != '<')
                return NULL;

        xml_parser_next(parser);

        name = malloc(1);
        if (!name)
                return NULL;

        i = 0;
        while (xml_parser_peek(parser) != '>') {
                name = realloc(name, i + 2);
                if (!name)
                        return NULL;

                name[i] = xml_parser_next(parser);
                i++;
        }
        name[i] = '\0';

        xml_parser_next(parser);

        value = malloc(1);
        if (!value)
                return NULL;

        i = 0;
        while (xml_parser_peek(parser) != '<') {
                value = realloc(value, i + 2);
                if (!value)
                        return NULL;

                value[i] = xml_parser_next(parser);
                i++;
        }
        value[i] = '\0';

        node = malloc(sizeof(*node));
        if (!node)
                return NULL;

        node->name = name;
        node->value = value;
        node->next = NULL;
        node->child = NULL;

        return node;
}

struct xml_document *
xml_parser_parse(struct xml_parser *parser)
{
        struct xml_document *document;
        struct xml_node *node;

        document = malloc(sizeof(*document));
        if (!document)
                return NULL;

        document->root = NULL;

        while (xml_parser_has_next(parser)) {
                node = xml_parser_parse_node(parser);
                if (!node)
                        return NULL;

                if (!document->root)
                        document->root = node;
                else {
                        struct xml_node *last;

                        last = document->root;
                        while (last->next)
                                last = last->next;

                        last->next = node;
                }
        }

        return document;
}

void
xml_document_free(struct xml_document *document)
{
        struct xml_node *node, *next;

        if (!document)
                return;

        node = document->root;
        while (node) {
                next = node->next;

                free(node->name);
                free(node->value);
                free(node);

                node = next;
        }

        free(document);
}

void
xml_document_print(struct xml_document *document)
{
        struct xml_node *node;

        if (!document)
                return;

        node = document->root;
        while (node) {
                printf("<%s>%s</%s>\n", node->name, node->value, node->name);

                node = node->next;
        }
}

int
main(int argc, char **argv)
{
        struct xml_parser *parser;
        struct xml_document *document;

        if (argc < 2) {
                fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
                return 1;
        }

        parser = xml_parser_new(argv[1]);
        if (!parser) {
                fprintf(stderr, "Error: failed to create XML parser.\n");
                return 1;
        }

        document = xml_parser_parse(parser);
        if (!document) {
                fprintf(stderr, "Error: failed to parse XML document.\n");
                return 1;
        }

        xml_document_print(document);

        xml_document_free(document);
        xml_parser_free(parser);

        return 0;
}