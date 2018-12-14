/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdontos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:17:35 by tdontos-          #+#    #+#             */
/*   Updated: 2018/11/26 17:17:37 by tdontos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	cp = NULL;
	i = 0;
	while (s1[i] != '\0')
		i++;
	cp = (char *)malloc(sizeof(char) * i + 1);
	if (cp == 0)
		return (NULL);
	i++;
	cp[i] = '\0';
	while (i >= 0)
	{
		i--;
		cp[i] = s1[i];
	}
	return (cp);
}
