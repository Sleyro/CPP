#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook()
{
	count = 0;
	nextIndex = 0;
	text[0] = "first name";
	text[1] = "last name";
	text[2] = "nickname";
	text[3] = "phone number";
	text[4] = "darkest secret";
}
static std::string formatText(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

static bool isOnlyWhiteSpace(const std::string& s)
{
	for (std::size_t i = 0; i < s.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}
void	PhoneBook::AddCmd()
{
	std::string Infos[5];

	for (int i = 0; i < 5 ; i++)
	{
		std::cout << "Enter your " << text[i] << ": ";
		if (!std::getline(std::cin, Infos[i]))
			return ;
		while (Infos[i].empty() || isOnlyWhiteSpace(Infos[i]))
		{
			std::cout << "Cannot be empty or just spaces, try again!" << std::endl;
			std::cout << "Enter your " << text[i] << ": ";
			if (!std::getline(std::cin, Infos[i]))
				return;
		}
	}
	contacts[nextIndex].SetContact(Infos[0], Infos[1], Infos[2], Infos[3], Infos[4]);
	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;
}
void	PhoneBook::SearchCmd()
{
	std::string str;
	int index;

	Print();
	while (true)
	{
		std::cout << "Enter an index: ";
		if (!std::getline(std::cin, str))
			return;
		if (str.length() == 1 && std::isdigit(static_cast<unsigned char>(str[0])))
		{
			index = str[0] - '0';
			if (index >= 0 && index < count)
				break;
		}
		std::cout << "Error, enter a valid index (0-" << (count - 1) << ")" << std::endl;
	}
	std::cout << "First Name: " << contacts[index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].GetLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].GetNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].GetDarkestSecret() << std::endl;
}

void	PhoneBook::Print() const
{
	if (count == 0)
	{
		std::cout	<< "PhoneBook empty!" << std::endl;
		return ;
	}

	std::cout	<< std::setw(10) << "Index" << "|" 
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "NickName" << std::endl;
	
	for (int i = 0; i < count; i++)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << formatText(contacts[i].GetFirstName()) << "|"
					<< std::setw(10) << formatText(contacts[i].GetLastName()) << "|"
					<< std::setw(10) << formatText(contacts[i].GetNickName()) << std::endl;
	}
}
