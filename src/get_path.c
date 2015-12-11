/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:48:14 by maducham          #+#    #+#             */
/*   Updated: 2015/12/11 16:53:04 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

char		**modify_path(char **tab)
{
	char	**new_tab;
	int		i;
	int		z;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * 6);
	while (tab[i])
	{
		new_tab[i] = (char*)malloc(sizeof(char) * ft_strlen(tab[i]) + 1);
		z = 0;
		while (tab[i][z] != '\n')
		{
			new_tab[i][z] = tab[i][z];
			z++;
		}
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

char		**get_path(void)
{
	int			fd;
	char		*line;
	char		**tab;
	int			i;

	i = 0;
	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
	{
		ft_putstr("Erreur lors de l'ouverture");
		exit(1);
	}
	tab = (char **)malloc(sizeof(char *) * 6);
	while (get_next_line(fd, &line))
	{
		tab[i] = (char*)malloc(sizeof(char) * ft_strlen(line) + 1);
		tab[i] = line;
		i++;
	}
	tab[i] = NULL;
	return (modify_path(tab));
}
