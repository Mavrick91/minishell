/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:11:41 by maducham          #+#    #+#             */
/*   Updated: 2015/12/09 16:51:35 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	prompt(int sig)
{
	(void)sig;
	ft_putstr("\n");
}

void	prompt_z(int sig)
{
	(void)sig;
	ft_putstr("\n");
}

void	prompt_a(int sig)
{
	(void)sig;
	ft_putstr("\nMinishell >> ");
}

void	gestion_signaux(void)
{
//	signal(SIGINT, prompt_a);
	signal(SIGTERM, prompt);
	signal(SIGHUP, prompt_a);
	signal(SIGCONT, prompt);
	signal(SIGSEGV, prompt);
	signal(SIGQUIT, prompt);
	signal(SIGILL, prompt);
	signal(SIGTRAP, prompt);
	signal(SIGABRT, prompt);
// 	signal(SIGEMT, prompt);
	signal(SIGFPE, prompt);
	signal(SIGKILL, prompt);
	signal(SIGBUS, prompt);
	signal(SIGSYS, prompt);
	signal(SIGPIPE, prompt);
	signal(SIGALRM, prompt);
	signal(SIGSTOP, prompt);
	signal(SIGTTIN, prompt);
	signal(SIGTTOU, prompt);
	signal(SIGXCPU, prompt);
	signal(SIGXFSZ, prompt);
	signal(SIGVTALRM, prompt);
	signal(SIGPROF, prompt);
	signal(SIGUSR1, prompt);
	signal(SIGUSR2, prompt);
}
