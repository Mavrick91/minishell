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

char		**enviro;


void		gestion_signaux();
void		affiche_prompt();
void		prompt(int sig);
void		set_unset(char **args);
void		print_env();

#endif
