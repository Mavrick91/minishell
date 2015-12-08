/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:11:00 by maducham          #+#    #+#             */
/*   Updated: 2015/12/08 16:11:24 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	set_env(char **args)
{
	int		i;
	char	**new_env;
	char	*variable_env;
	char	*tmp;

	i = 0;
	new_env = (char**)malloc(sizeof(char*) * 30);
	variable_env = (char*)malloc(sizeof(char) + ft_strlen(args[1])
			+ ft_strlen(args[2]) + 1);
	tmp = ft_strjoin(args[1], "=");
	variable_env = ft_strjoin(tmp, args[2]);
	while (enviro[i] != NULL)
	{
		new_env[i] = (char*)malloc(sizeof(char) * ft_strlen(enviro[i]) + 1);
		new_env[i] = enviro[i];
		i++;
	}
	new_env[i] = (char*)malloc(sizeof(char) * ft_strlen(variable_env) + 1);
	new_env[i] = variable_env;
	enviro = new_env;
}

void	unset_env(char **args)
{
	int		i;
	int		j;
	char	**new_env;
	char	**tab;

	i = 0;
	j = 0;
	new_env = (char**)malloc(sizeof(char*) * 30);
	while (enviro[i] != NULL)
	{
		tab = ft_strsplit(enviro[i], '=');
		if (ft_strcmp(tab[0], args[1]))
		{
			new_env[j] = (char*)malloc(sizeof(char) * ft_strlen(enviro[i]) + 1);
			new_env[j] = enviro[i];
			j++;
		}
		i++;
	}
	enviro = new_env;
}

void	print_env(void)
{
	int		i;

	i = 0;
	while (enviro[i])
	{
		ft_putstr(enviro[i]);
		ft_putstr("\n");
		i++;
	}
}

void	set_unset(char **args)
{
	if (!ft_strcmp("unsetenv", args[0]))
		unset_env(args);
	else if (!ft_strcmp("setenv", args[0]))
		set_env(args);
}
