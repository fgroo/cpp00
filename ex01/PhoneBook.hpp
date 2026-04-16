/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:57:49 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/07 18:51:26 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class	PhoneBook {
	public:
		PhoneBook(void);
		void		MENU(void);

	private:
		Contact	contacts[8];
		int		count;

		void		ADD(void);
		void		SEARCH(void);
		void		stream_trunc(const std::string &s);
		std::string	get_input(const std::string &prompt);
};

#endif
