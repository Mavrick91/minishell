#include "../ft_minishell.h"

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

	binary = ft_strjoin("/", args[0]);
	i = 0;
	directory_path = ft_strsplit(path, ':');
	printf("path = %s\n", path);
	printf("directory_path[0] = %s\n", directory_path[0]);
	printf("directory_path[1] = %s\n", directory_path[1]);
	printf("directory_path[2] = %s\n", directory_path[2]);
	printf("directory_path[3] = %s\n", directory_path[3]);
	while ((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) != 0)
	{
		printf("binaire = %s\n",ft_strjoin(directory_path[i], binary));
		if ((access(ft_strjoin(directory_path[i], binary), F_OK | X_OK)) == 0)
		{
			printf("test\n");
		/*
		 * printf("str = %s\n", ft_strjoin(directory_path[1], binary));
			if ((parent = fork()) == 0)
				execve((ft_strjoin(directory_path[i], args[0])), args, enviro);
			else
				waitpid(parent, &status, 0);
		*/
		}
		i++;
	}
}

void		ft_minishell(char *buf)
{
	char	*path;
	char	*env_args[2];
	char	**args;

	path = ft_strsub(enviro[0], 5, ft_strlen(enviro[0]));
	env_args[0] = path;
	env_args[1] = NULL;
	args = ft_strsplit(buf, ' ');
	if (ft_strstr(args[0], "set"))
		set_unset(args);
	else
		process(path, args);
}

void		affiche_prompt(void)
{
	char	*buf;
	char	**tab;
	int		ret;

	buf = (char*)malloc(sizeof(char));
	ft_putstr("Minishell >> ");
	while ((ret = (get_next_line(1, &buf))))
	{
		if (ft_isprint(buf))
		{
			tab = ft_strsplit(buf, ' ');
			if (ft_strcmp(buf, "exit") == 0)
				exit(0);
			if (tab[0][0] == 'c' && tab[0][1] == 'd')
				move_directory(buf);
			else
				ft_minishell(buf);
		}
		ft_putstr("Minishell >> ");
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
