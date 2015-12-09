/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:48:14 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 19:06:23 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

char		**get_path()
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
	return (tab);
}
