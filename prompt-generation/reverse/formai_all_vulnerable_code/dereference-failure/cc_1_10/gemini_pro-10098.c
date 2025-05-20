//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

struct token {
	enum {
		IDENT,
		INT,
		CHAR,
		STRING,
		SYMBOL,
		KEYWORD,
		COMMENT,
	} type;
	char *value;
};

struct node {
	struct token token;
	struct node *next;
};

struct parser {
	struct node *current;
	struct node *head;
	char *input;
};

struct parser *parser_new(char *input)
{
	struct parser *parser = malloc(sizeof(*parser));
	parser->input = input;
	parser->current = NULL;
	parser->head = NULL;
	return parser;
}

void parser_free(struct parser *parser)
{
	struct node *node = parser->head;
	while (node) {
		struct node *next = node->next;
		free(node->token.value);
		free(node);
		node = next;
	}
	free(parser);
}

struct token parser_next_token(struct parser *parser)
{
	struct token token = { .type = COMMENT };
	while (isspace(*parser->input))
		parser->input++;
	if (!*parser->input)
		return token;
	if (isalpha(*parser->input)) {
		token.type = IDENT;
		while (isalpha(*parser->input) || isdigit(*parser->input))
			parser->input++;
	} else if (isdigit(*parser->input)) {
		token.type = INT;
		while (isdigit(*parser->input))
			parser->input++;
	} else if (*parser->input == '\'') {
		token.type = CHAR;
		parser->input++;
		token.value = malloc(2);
		token.value[0] = *parser->input++;
		token.value[1] = '\0';
		if (*parser->input != '\'')
			token.type = COMMENT;
		parser->input++;
	} else if (*parser->input == '"') {
		token.type = STRING;
		parser->input++;
		int len = 0;
		while (*parser->input != '"') {
			len++;
			parser->input++;
		}
		token.value = malloc(len + 1);
		strncpy(token.value, parser->input - len, len);
		token.value[len] = '\0';
		parser->input++;
	} else if (strchr("+-*/()[]{};,.", *parser->input)) {
		token.type = SYMBOL;
		token.value = malloc(2);
		token.value[0] = *parser->input++;
		token.value[1] = '\0';
	} else if (strchr("elifelsewhileforifreturn", *parser->input)) {
		token.type = KEYWORD;
		while (isalpha(*parser->input) || isdigit(*parser->input))
			parser->input++;
	}
	return token;
}

struct node *parser_parse(struct parser *parser)
{
	struct node *node = malloc(sizeof(*node));
	node->next = NULL;
	node->token = parser_next_token(parser);
	if (parser->head)
		parser->current->next = node;
	else
		parser->head = node;
	parser->current = node;
	return node;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input>\n", argv[0]);
		return 1;
	}
	struct parser *parser = parser_new(argv[1]);
	while (parser_next_token(parser).type != COMMENT)
		parser_parse(parser);
	struct node *node = parser->head;
	while (node) {
		switch (node->token.type) {
		case IDENT:
			printf("Identifier: %s\n", node->token.value);
			break;
		case INT:
			printf("Integer: %s\n", node->token.value);
			break;
		case CHAR:
			printf("Character: %s\n", node->token.value);
			break;
		case STRING:
			printf("String: %s\n", node->token.value);
			break;
		case SYMBOL:
			printf("Symbol: %s\n", node->token.value);
			break;
		case KEYWORD:
			printf("Keyword: %s\n", node->token.value);
			break;
		case COMMENT:
			printf("Comment: %s\n", node->token.value);
			break;
		}
		node = node->next;
	}
	parser_free(parser);
	return 0;
}