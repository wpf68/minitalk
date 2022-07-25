/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:06:14 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/21 11:30:55 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_test_argc(int argc)
{
	if (argc == 2)
		write(2, "Error Message\n", 14);
	else if (argc == 1)
		write(2, "Error PID & Message\n", 20);
	else
		return ;
	exit(1);
}

static pid_t	ft_test_argv2(char *argv)
{
	pid_t	pid;

	pid = (pid_t)ft_atoi(argv);
	if (pid < 2)
		write(2, "Error PID\n", 10);
	else
		return (pid);
	exit(1);
}

static void	ft_send_message(char *argv, pid_t pid)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (((int)argv[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(DELAY);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	ft_test_argc(argc);
	pid = ft_test_argv2(argv[1]);
	ft_send_message(argv[2], pid);
	return (0);
}

/*
 	 PID max : /proc/sys/kernel/pid_max
	ft_printf(" ---- i = %d  --  PID = %d  --  CHAR = %s\n", i, pid, argv);
	ft_printf("c = %c = %d -- i = %d  --  j = %d --- bit :: %d \n",argv[i], argv[i],
   			i, j, (((int)argv[i] >> j) & 1));
	write(1, "\n", 1); 
*/
