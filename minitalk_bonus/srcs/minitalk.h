/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:40:16 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/16 09:18:27 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# include <signal.h>		for signal - sigemptyset - sigaddset 
							- sigaction - kill
# include <sys/types.h>		for kill - getpid (unistd.h)
*/

#ifndef MINITALK_H
# define MINITALK_H
# define DELAY 200

# include "../libft_total/libft.h"
# include <signal.h>
# include <sys/types.h>

void	ft_send_message(char *argv, pid_t pid);

#endif
