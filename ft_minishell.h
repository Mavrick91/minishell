/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:54:08 by maducham          #+#    #+#             */
/*   Updated: 2015/12/11 17:33:42 by maducham         ###   ########.fr       */
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

# define CANCEL ft_putstr("\033[00m")
# define RED ft_putstr("\033[31m")
# define BLUE ft_putstr("\033[34m"); ft_putstr("Minishell >> "); CANCEL;
# define CYAN ft_putstr("\033[36m")
# define GREEN ft_putstr("\033[32m"); ft_putstr("Minishell >> "); CANCEL;
# define YELLOW ft_putstr("\033[33m")

char		**g_enviro;
char		*g_way_absolute;
char		**g_path;

void		gestion_signaux();
void		affiche_prompt();
void		prompt(int sig);
void		set_unset(char **args, char **env);
void		print_env(char **env);
int			nb_elem(char **str);
void		set_env(char **args);
void		unset_env(char **args);
void		modify_env(char *key, char *value);
char		*get_home(void);
void		check_line(char *buf, char **tab, char **env);
void		ft_minishell(char *buf, char **env);
void		move_directory(char *buf);
char		**get_path();
void		process_no_env(char **args);

#endif
