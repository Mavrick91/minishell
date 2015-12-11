/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maducham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:11:41 by maducham          #+#    #+#             */
/*   Updated: 2015/12/11 16:50:41 by maducham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

void	prompt(int sig)
{
	(void)sig;
	ft_putstr("\n");
	GREEN;
}

void	gestion_signaux(void)
{
	/*
	signal(SIGINT, prompt);
	signal(SIGTERM, prompt);
	signal(SIGHUP, prompt);
	signal(SIGCONT, prompt);
	signal(SIGSEGV, prompt);
	signal(SIGQUIT, prompt);
	signal(SIGILL, prompt);
	signal(SIGTRAP, prompt);
	signal(SIGABRT, prompt);
	signal(SIGEMT, prompt);
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
	*/
}
