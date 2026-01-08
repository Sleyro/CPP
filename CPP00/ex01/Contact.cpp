#include "Contact.hpp"

Contact::Contact() : full(false)
{
}

void	Contact::SetContact(const std::string& first,
							const std::string& last,
							const std::string& nick,
							const std::string& phone,
							const std::string& secret)
{
	FirstName = first;
	LastName = last;
	NickName = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
	full = true;
}

bool Contact::IsFull() const
{
	return full;
}
std::string Contact::GetFirstName() const
{
	return FirstName;
}
std::string Contact::GetLastName() const
{
	return LastName;
}
std::string Contact::GetNickName() const
{
	return NickName;
}
std::string Contact::GetPhoneNumber() const
{
	return PhoneNumber;
}
std::string Contact::GetDarkestSecret() const
{
	return DarkestSecret;
}



