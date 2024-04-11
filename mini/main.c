

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/10 17:34:26 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **get_command(char **words, char *command)
{
  int i;
  i = 0;
  while (words[i])
  {

    command = words[i];
    printf("command: %s\n", command);
    i++;
  }
  return (command);
}

char **get_params(char *input, char **params, char **words, char *command)
{

  int i;
  i = 0;
  int j;
  j = 0;
  params = ft_split(input, ' ');
  words = (char **)malloc(sizeof(char *) * 100);
  while (params[i])
  {
    if (ft_strchr(params[i], '|'))
      i++;
    else if (ft_strchr(params[i], '<'))
      i++;
    else if (ft_strchr(params[i], '>'))
      i++;
    words[j] = params[i];
    printf("words[%d]: %s\n", j, words[j]);
    i++;
    j++;
  }
  command = get_command(words, command);
  return (words);
}

int validate_path_with_command(char *path, char *command)
{
  int i;
  i = 0;
  while (path[i])
  {
    if (path[i] == command[0])
    {
      return (1);
    }
    i++;
  }
  return (0);
}

char **get_path(char **env)
{
  int x;
  int i;
  char *path;
  char **paths;
  x = 0;

  path = getenv("PATH");
  paths = ft_split(path, ':');

  x = 0;
  while (paths[x])
  {
    int i = 0;
    while (paths[x][i])
    {
      i++;
    }
    paths[x][i] = '/';
    paths[x][i + 1] = '\0';
    printf("%s\n", paths[x]);

    x++;
  }

  return (paths);
}

int main(int ac, char **av, char **env)
{
  char *input;
  char *path;
  char *command;
  char **paths;
  char **params;
  char **words;
  // type_prompt();
  while (1)
  {
    input = readline("minishell: ");
    get_path(env);
    get_params(input, params, words, command);
    int pid = fork();

    if (pid < 0)
      return 1;
    if (pid == 0)
    {
      if ((execve("/bin/ls", av, env)) == -1)
      {
        printf("Error\n");
        exit(1);
      }
    }
    // print_env(input, env);
    // pwd(input);
    // echo(input);
    // cd(input);
    // quantity_operator_pipe(input);
    // if (ft_exit(input) == 0)
    //     ; // vai dar leak
    // break;
    waitpid(pid, NULL, 0);
    free(input);
  }
}