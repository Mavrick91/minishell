/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:08:46 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 18:37:24 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int			nb_elem(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		set_unset(char **args)
{
	if (args[1] == NULL)
		ft_putstr("too fiew argument 2\n");
	else
	{
		if (!(ft_strcmp("unsetenv", args[0])) && args[1] != NULL
				&& args[2] == NULL)
			unset_env(args);
		else if (!(ft_strcmp("setenv", args[0])) && args[1] != NULL
				&& args[2] != NULL && args[3] == NULL)
			set_env(args);
		else
			ft_putstr("too many argument 3 \n");
	}
}

char		*get_home(void)
{
	char	**tab;
	int		i;

	i = 0;
	while (g_enviro[i])
	{
		tab = ft_strsplit(g_enviro[i], '=');
		if (!ft_strcmp(tab[0], "HOME"))
			return (tab[1]);
		i++;
	}
	return (NULL);
}

void		check_line(char *buf, char **tab)
{
	if (ft_isprint(buf))
	{
		tab = ft_strsplit(buf, ' ');
		if (!(ft_strcmp(tab[0], "exit")))
		{
			if (tab[1] == NULL)
				exit(0);
			else
			{
				ft_putstr("exit: too many arguments");
				exit(1);
			}
		}
		if (tab[0][0] == 'c' && tab[0][1] == 'd')
			move_directory(buf);
		else
			ft_minishell(buf);
	}
}
