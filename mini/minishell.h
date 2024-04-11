/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/11 20:37:53 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <unistd.h>

// builtins
void echo(char *input);
void print_env(char *input, char **env);
int count_quotes(char *input);
char *strq(char *input, char *comand);
void pwd(char *input);
void cd(char *input);
int ft_exit(char *input);
int quantity_operator_pipe(char *input);
int exec_pipe(char *input);
void type_prompt();
#endif