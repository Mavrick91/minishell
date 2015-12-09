/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:11:00 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 17:30:51 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int			check_env(char *find)
{
	int		i;
	char	**tab;

	i = 0;
	while (g_enviro[i])
	{
		tab = ft_strsplit(g_enviro[i], '=');
		if (!ft_strcmp(tab[0], find))
			return (0);
		i++;
	}
	return (1);
}

void		modify_env(char *key, char *value)
{
	int		i;
	char	**n_e;
	char	*variable_env;
	char	*tmp;
	char	**tab;

	i = 0;
	n_e = (char**)malloc(sizeof(char*) * 500);
	while (g_enviro[i])
	{
		tab = ft_strsplit(g_enviro[i], '=');
		n_e[i] = (char*)malloc(sizeof(char) * ft_strlen(g_enviro[i]) + 1);
		if (!ft_strcmp(tab[0], key))
		{
			variable_env = (char*)malloc(sizeof(char) + (ft_strlen(key) +
			ft_strlen(value) + 1));
			tmp = ft_strjoin(key, "=");
			variable_env = ft_strjoin(tmp, value);
			n_e[i] = variable_env;
		}
		else
			n_e[i] = g_enviro[i];
		i++;
	}
	g_enviro = n_e;
}

void		set_env(char **args)
{
	int		i;
	char	**n_e;
	char	*variable_env;
	char	*tmp;

	i = 0;
	if (check_env(args[1]))
	{
		n_e = (char**)malloc(sizeof(char*) * 500);
		variable_env = (char*)malloc(sizeof(char) + ft_strlen(args[1])
				+ ft_strlen(args[2]) + 1);
		tmp = ft_strjoin(args[1], "=");
		variable_env = ft_strjoin(tmp, args[2]);
		while (g_enviro[i] != NULL)
		{
			n_e[i] = (char*)malloc(sizeof(char) * ft_strlen(g_enviro[i]) + 1);
			n_e[i] = g_enviro[i];
			i++;
		}
		n_e[i] = (char*)malloc(sizeof(char) * ft_strlen(variable_env) + 1);
		n_e[i] = variable_env;
		g_enviro = n_e;
	}
	else
		modify_env(args[1], args[2]);
}

void		unset_env(char **args)
{
	int		i;
	int		j;
	char	**n_e;
	char	**tab;

	i = 0;
	j = 0;
	n_e = (char**)malloc(sizeof(char*) * 30);
	while (g_enviro[i] != NULL)
	{
		tab = ft_strsplit(g_enviro[i], '=');
		if (ft_strcmp(tab[0], args[1]))
		{
			n_e[j] = (char*)malloc(sizeof(char) * ft_strlen(g_enviro[i] + 1));
			n_e[j] = g_enviro[i];
			j++;
		}
		i++;
	}
	g_enviro = n_e;
}

void		print_env(void)
{
	int		i;

	i = 0;
	while (g_enviro[i])
	{
		ft_putstr(g_enviro[i]);
		ft_putstr("\n");
		i++;
	}
}
