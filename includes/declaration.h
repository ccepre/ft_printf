/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:55:39 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/07 15:19:33 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_attributs g_attr_tab[] =
{
	{'#', &ft_hashtag},
	{'+', &ft_plus},
	{' ', &ft_space},
};