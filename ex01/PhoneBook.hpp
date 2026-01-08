#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		nextIndex;
		int		count;
		std::string text[5];
	public:

		PhoneBook();

		void	AddCmd();
		void	SearchCmd();
		void	Print() const;
};

#endif
		

