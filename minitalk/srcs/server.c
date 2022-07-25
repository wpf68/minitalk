/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:10:19 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/16 09:11:33 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bit_to_int(int sig)
{
	static int	signal;
	static int	count;

	if (sig == SIGUSR1)
		signal = signal | (1 << (7 - count));
	if (count == 7)
	{
		ft_printf("%c", signal);
		count = -1;
		signal = 0;
	}
	count++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s1;

	pid = getpid();
	s1.sa_flags = 0;
	s1.sa_handler = &ft_bit_to_int;
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

/*
	signal(SIGUSR1, ft_bit1);
	signal(SIGUSR2, ft_bit0);
	

	ft_printf("signal = %d  :  %c\n", signal, signal);

*/
/*  --  tres lent , demande un DELAY eleve
 *
static void	ft_bit(int sig)
{
	static int	count;
	static char	*c;     //  static char  c[9]; c[8] = '\n';
	char		*temp;
	char		result;
	int		i;
	int		power;

	if (sig == SIGUSR1)
	{
		if (c == NULL)
			c = ft_strjoin("", "1");
		else
		{
			temp = c;	
			c = ft_strjoin(temp, "1");
			free(temp);
		}
	}
	else
	{
		if (c == NULL)
			c = ft_strjoin("", "0");
		else
		{
			temp = c;
			c = ft_strjoin(c, "0");
			free(temp);
		}
	}
	if (count < 7)
		count++;
	else
	{
		count = 0;
		i = 7;
		result = 0;
		power = 1;
		while (i >= 0)
		{
			if (c[i] == '1')
			{
				result = result + power;
			}
			ft_printf("c = %c  | i = %d  power = %d  result = %d\n", 
				c[i], i, power, result);
			if (i == 7)
				power = 2;
			else
				power = power * 2;
			i--;
		}
		ft_printf("bin : %s   dec = %d   c = %c\n", c, result, result);
		c = NULL;
	}
}
*/
