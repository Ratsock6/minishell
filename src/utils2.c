/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:08:03 by aallou-v          #+#    #+#             */
/*   Updated: 2024/02/10 00:58:29 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ending(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '$' || c == '\''
		|| c == '\t' || c == '\v' || c == '\"');
}
