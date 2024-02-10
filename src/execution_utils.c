/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:39:11 by aallou-v          #+#    #+#             */
/*   Updated: 2024/02/07 22:31:25 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins_no_exec(char *buf)
{
	if (ft_strncmp("env", buf, 3) == 0 || ft_strncmp("pwd", buf, 3) == 0
		|| ft_strncmp("cd", buf, 3) == 0 || ft_strncmp("echo", buf, 4) == 0)
		return (1);
	return (0);
}

int	is_token(char const *s)
{
	if (ft_strncmp(s, "PIPE", 4) == 0)
		return (1);
	if (ft_strncmp(s, "SEMICOLON", 9) == 0)
		return (1);
	if (ft_strncmp(s, "GREATGREAT", 10) == 0)
		return (1);
	if (ft_strncmp(s, "LESSLESS", 8) == 0)
		return (1);
	if (ft_strncmp(s, "GREAT", 5) == 0 && ft_strlen(s) <= 5)
		return (1);
	if (ft_strncmp(s, "LESS", 4) == 0 && ft_strlen(s) <= 4)
		return (1);
	return (0);
}

void	remove_hd(int id, t_core *core)
{
	char	**argv;
	pid_t	pid;

	(void) id;
	if (access("HEREDOC", F_OK) == -1)
		return ;
	argv = ft_calloc(3, sizeof(char *));
	if (!argv)
		return ;
	argv[0] = "rm";
	argv[1] = "HEREDOC";
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/rm", argv, core->envp);
		exit(1);
	}
	free(argv);
	wait(NULL);
}

int	check_exit(char const *s)
{
	if (ft_strncmp(s, "exit", ft_strlen(s)) == 0)
		return (1);
	return (0);
}
