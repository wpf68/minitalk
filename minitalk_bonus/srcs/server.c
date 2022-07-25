/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:18:45 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/16 09:19:31 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_answer(pid_t pid)
{
	char	*c_pid;
	char	*answer;

	c_pid = ft_itoa((int)pid);
	answer = ft_strjoin(c_pid, " OK@");
	free(c_pid);
	return (answer);
}

static void	ft_bit_to_int(int sig, siginfo_t *info, void *ucontext)
{
	static int	signal;
	static int	count;
	char		*answer;

	(void)ucontext;
	if (sig == SIGUSR1)
		signal = signal | (1 << (31 - count));
	if (count == 31)
	{
		count = -1;
		if (signal == '@')
		{
			sleep(1);
			answer = ft_answer(info->si_pid);
			ft_printf("\n\n-> (%s) to %d\n", answer, info->si_pid);
			ft_send_message(answer, info->si_pid);
			free(answer);
		}
		else
			ft_printf("%c", signal);
		signal = 0;
	}
	count++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s1;

	pid = getpid();
	s1.sa_flags = SA_SIGINFO;
	s1.sa_sigaction = &ft_bit_to_int;
	system("clear");
	ft_printf("PID = %d\n\n", pid);
	if (sigaction(SIGUSR1, &s1, NULL) == -1)
		write(2, "Error SIGUSR1\n", 14);
	if (sigaction(SIGUSR2, &s1, NULL) == -1)
		write(2, "Error SIGUSR2\n", 14);
	while (1)
		pause();
	return (0);
}
