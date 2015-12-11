/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:08:46 by maducham          #+#    #+#             */
/*   Updated: 2015/12/11 18:16:12 by maducham         ###   ########.fr       */
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

void		set_unset(char **args, char **env)
{
	if ((env[0] != NULL || g_enviro != NULL || !(ft_strcmp("setenv", args[0]))))
	{
		if (args[1] == NULL)
			ft_putstr("too fiew argument 2\n");
		else
		{
			if (!(ft_strcmp("setenv", args[0])) && args[1] != NULL
			&& args[2] != NULL && args[3] == NULL)
				set_env(args);
			else if (!(ft_strcmp("unsetenv", args[0])) && args[1] != NULL
					&& args[2] == NULL)
				unset_env(args);
			else
				ft_putstr("too many argument 3 \n");
		}
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

void		check_line(char *buf, char **tab, char **env)
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
				ft_putstr("exit: too many arguments\n");
				exit(1);
			}
		}
		if (tab[0][0] == 'c' && tab[0][1] == 'd')
			move_directory(buf);
		else
			ft_minishell(buf, env);
	}
}

void		process_no_env(char **args)
{
	pid_t		parent;
	int			status;
	char		**directory_path;
	int			i;
	char		*binary;

	i = 0;
	binary = ft_strjoin("/", args[0]);
	directory_path = get_path();
	while (((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) != 0)
			&& directory_path[i])
		i++;
	if ((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) == 0)
	{
		if ((parent = fork()) == 0)
			execve(ft_strjoin(directory_path[i], binary), args, NULL);
		else
			wait(&status);
	}
	else
		ft_putstr("Binaire not found\n");
}
