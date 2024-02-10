/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:37:49 by cjouenne          #+#    #+#             */
/*   Updated: 2024/02/10 00:42:31 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_core *core, char **envp)
{
	core->envp = envp;
	core->execution_three = 0;
	core->son_pid = -1;
	core->lexer_out = NULL;
	core->folder = "";
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}

void	free_lexing(t_core *core)
{
	size_t	i;

	i = -1;
	if (core->get_d_quote != NULL)
	{
		while (core->get_d_quote[++i])
			free(core->get_d_quote[i]);
		free(core->get_d_quote);
	}
	i = -1;
	if (core->get_quote != NULL)
	{
		while (core->get_quote[++i])
			free(core->get_quote[i]);
		free(core->get_quote);
	}
}

void	start(char *buf, t_core *core)
{
	add_history(buf);
	pre_lexing(buf, core);
	free_lexing(core);
	core->execution_three = node_init(ft_strdup(""));
	fill_three(core);
	parse_io(core);
	rm_sep_three(core->execution_three);
}

void	end_main(t_core *core)
{
	free_three(core->execution_three);
	free(core->lexer_out);
	core->lexer_out = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*buf;
	t_core	*core;

	buf = NULL;
	(void) argc;
	(void) argv;
	core = ft_calloc(1, sizeof(t_core));
	if (!core)
		return (1);
	init(core, envp);
	while (1)
	{
		buf = readline("\e[35mminishell \e[33m ➤ \e[21m\e[0m ");
		if (buf == NULL)
		{
			printf("exit\n");
			ft_exit(0, NULL, NULL);
			break ;
		}
		start(buf, core);
		execution(core);
		end_main(core);
	}
}
