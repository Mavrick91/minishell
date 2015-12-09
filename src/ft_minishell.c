/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:57:32 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 19:30:11 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

#define CANCEL ft_putstr("\033[00m")
#define RED ft_putstr("\033[31m")
#define BLUE ft_putstr("\033[34m"); ft_putstr("Minishell >> "); CANCEL;
#define CYAN ft_putstr("\033[36m")
#define GREEN ft_putstr("\033[32m"); ft_putstr("Minishell >> "); CANCEL;
#define YELLOW ft_putstr("\033[33m")

void		move_directory(char *buf)
{
	char	**directory;
	char	*str;

	str = NULL;
	modify_env("OLDPWD", getcwd(str, 255));
	directory = ft_strsplit(buf, ' ');
	if (directory[1] == NULL || (!(ft_strcmp(directory[1], "~"))))
		chdir(get_home());
	else if ((ft_strstr(directory[1], "~/")))
	{
		chdir(get_home());
		chdir(ft_strsub(directory[1], 2, ft_strlen(directory[1])));
	}
	else if ((chdir(directory[1])) == -1)
		ft_putstr("problème de changement de répertoire\n");
	modify_env("PWD", getcwd(str, 255));
	free(directory);
}

void		process(char *path, char *args[])
{
	pid_t	parent;
	int		status;
	char	**directory_path;
	int		i;
	char	*binary;

	i = 0;
	binary = ft_strjoin("/", args[0]);
	if (g_enviro == NULL)
		directory_path = get_path();
	else
		directory_path = ft_strsplit(path, ':');
	while (((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) != 0)
			&& directory_path[i])
		i++;
	if ((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) == 0)
	{
		if ((parent = fork()) == 0)
			execve(ft_strjoin(directory_path[i], binary), args, g_enviro);
		else
			wait(&status);
	}
	else
		ft_putstr("Binaire not found\n");
}

void		ft_minishell(char *buf)
{
	char	*path;
	char	**args;

	if (g_enviro != NULL)
		path = ft_strsub(g_enviro[0], 5, ft_strlen(g_enviro[0]));
	args = ft_strsplit(buf, ' ');
	if (ft_strstr(args[0], "set"))
		set_unset(args);
	else if (!ft_strcmp(args[0], "env"))
		print_env();
	else
		process(path, args);
}

void		affiche_prompt(void)
{
	char	*buf;
	char	**tab;
	int		ret;

	tab = NULL;
	buf = (char*)malloc(sizeof(char));
	GREEN;
	while ((ret = (get_next_line(1, &buf))))
	{
		check_line(buf, tab);
		GREEN;
	}
	if (ret == 0)
		ft_putstr("exit\n");
}

int			main(int ac, char **av, char **env)
{
	char	*buf;

	(void)ac;
	(void)av;
	buf = NULL;
	g_way_absolute = getcwd(buf, 255);
	gestion_signaux();
	if (env != NULL)
		g_enviro = env;
	affiche_prompt();
	return (0);
}
