#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

static void toUpperStr(std::string& str)
{
	for (std::size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(str[i])));
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT); ";
		if (!std::getline(std::cin, cmd))
			break ;
		toUpperStr(cmd);
		if (cmd == "ADD")
			phonebook.AddCmd();
		else if (cmd == "SEARCH")
			phonebook.SearchCmd();
		else if (cmd == "EXIT")
			break ;
		else if (cmd.empty())
			continue ;
		else
			std::cout << "Enter a valid command!" << std::endl;
	}
	return 0;
}