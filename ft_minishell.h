/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:54:08 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 19:26:22 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>

char		**g_enviro;
char		*g_way_absolute;
char		**g_path;

void		gestion_signaux();
void		affiche_prompt();
void		prompt(int sig);
void		set_unset(char **args);
void		print_env();
int			nb_elem(char **str);
void		set_unset(char **args);
void		set_env(char **args);
void		unset_env(char **args);
void		modify_env(char *key, char *value);
char		*get_home(void);
void		check_line(char *buf, char **tab);
void		ft_minishell(char *buf);
void		move_directory(char *buf);
char		**get_path();
void		process_no_env(char **args);

#endif
