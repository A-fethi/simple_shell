#include "main.h"

/**
 * free_all - frees all allocations
 * @line: line
 * @tokens_list: tokens list
 */

void free_all(char *line, char **tokens_list)
{
	int i;

	for (i = 0; tokens_list[i]; i++)
		free(tokens_list[i]);
	free(tokens_list);
	free(line);
}

/**
 * prompt_command - the prompt
 * @void: void
 * Return: line
 */

char *prompt_command(void)
{
	char *line = NULL;
	size_t n = 0;

	printf("#cisfun$ ");

	if (getline(&line, &n, stdin) == -1)
	{
		exit(-1);
	}
	return (line);
}

/**
 * split_str_to_arr - splits a string
 * @line: line
 * Return: array of each word of the string
 */

char **split_str_to_arr(char *line)
{
	char **tokens_list;
	char *token;
	int i, num;

	i = 0;
	num = 0;
	while (line[i])
	{
		if ((line[i] == ' ' && line[i + 1] != ' ') || line[i] == '\n')
			num++;
		i++;
	}

	tokens_list = malloc((num + 1) * sizeof(char *));
	token = strtok(line, " \n");

	i = 0;
	while (token)
	{
		tokens_list[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (!tokens_list)
		{
			exit(-1);
		}
		strcpy(tokens_list[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	tokens_list[i] = token;
	return (tokens_list);
}

int main(void)
{
	char *line;
	char **tokens_list;

	while (1)
	{
		line = prompt_command();
		tokens_list = split_str_to_arr(line);
		if (strcmp(tokens_list[0], "exit") == 0)
		{
			free_all(line, tokens_list);
			exit(EXIT_SUCCESS);
		}
		execute_command(tokens_list);
		free_all(line, tokens_list);
	}
	free_all(line, tokens_list);
       	return (0);
}
