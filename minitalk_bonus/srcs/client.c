/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:15:22 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/21 11:32:42 by pwolff           ###   ########.fr       */
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

static void	ft_bit_to_int(int sig)
{
	static int	signal;
	static int	count;

	if (sig == SIGUSR1)
		signal |= (1 << (31 - count));
	if (count == 31)
	{
		if (signal == '@')
		{
			write(1, "\n====== END ========\n\n", 22);
			exit(0);
		}
		ft_printf("%c", signal);
		count = -1;
		signal = 0;
	}
	count++;
}

static void	ft_test_no_end(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '@')
		{
			write(2, "Error '@' for end message\n", 26);
			exit (1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	ft_test_argc(argc);
	pid = ft_test_argv2(argv[1]);
	ft_test_no_end(argv[2]);
	system("clear");
	printf("PID server :: %d  --> Message :: %s\n", pid, argv[2]);
	message = ft_strjoin(argv[2], "@");
	ft_send_message(message, pid);
	free(message);
	pid = getpid();
	printf("PID client :: %d\n\n", pid);
	if (signal(SIGUSR1, ft_bit_to_int) == SIG_ERR)
		write(2, "Error SIGUSR1\n", 14);
	if (signal(SIGUSR2, ft_bit_to_int) == SIG_ERR)
		write(2, "Error SIGUSR2\n", 14);
	while (1)
		pause();
	return (0);
}

/*
 * PID max : /proc/sys/kernel/pid_max
	ft_printf(" ---- i = %d  --  PID = %d  --  CHAR = %s\n", i, pid, argv);
	ft_printf("c = %c = %d -- i = %d  --  j = %d --- bit :: %d \n",argv[i], 
			argv[i], i, j, (((int)argv[i] >> j) & 1));
	write(1, "\n", 1); 
*/
