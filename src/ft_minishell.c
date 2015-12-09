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

	directory = ft_strsplit(buf, ' ');
	if ((chdir(directory[1])) == -1)
		ft_putstr("problème de changement de répertoire\n");
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
	directory_path = ft_strsplit(path, ':');
	while (((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) != 0)
	&& directory_path[i])
		i++;
	if ((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) == 0)
	{
		if ((parent = fork()) == 0)
			execve(ft_strjoin(directory_path[i], binary), args, enviro);
		else
			waitpid(parent, &status, 0);
	}
	else
		ft_putstr("Binaire not found\n");
}

void		ft_minishell(char *buf)
{
	char	*path;
	char	**args;

	path = ft_strsub(enviro[0], 5, ft_strlen(enviro[0]));
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

	buf = (char*)malloc(sizeof(char));
	GREEN;
	while ((ret = (get_next_line(1, &buf))))
	{
		if (ft_isprint(buf))
		{
			tab = ft_strsplit(buf, ' ');
			if (ft_strcmp(buf, "exit\n") == 0)
				exit(0);
			if (tab[0][0] == 'c' && tab[0][1] == 'd')
				move_directory(buf);
			else
				ft_minishell(buf);
		}
		GREEN;
	}
	if (ret == 0)
		ft_putstr("exit\n");
}

int			main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	gestion_signaux();
	enviro = env;
	affiche_prompt();
	return (0);
}
