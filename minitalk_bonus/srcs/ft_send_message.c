/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:17:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/16 09:17:34 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(char *argv, pid_t pid)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 31;
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
