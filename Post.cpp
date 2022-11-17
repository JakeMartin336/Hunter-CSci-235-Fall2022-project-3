// Jacob Martin
// 9/23/2022
// Post.cpp
// Project 2 - create post class that lets user create a post

#include "Post.hpp"

Post::Post(const std::string& name, const std::string& body, const std::string& acct) //constructor with updated parameter
{
	post_name = name; //assigning private members to the parameter given
	post_body = body;
	acct_username = acct; //assigning new string private member to the parameter
	time(&time_stamp);
}

void Post::setTitle(const std::string& name)
{
	post_name = name; //setting data member to the parameter given
}

std::string Post::getTitle() const
{
	return post_name; //returning data member
}

void Post::setBody(const std::string& body)
{
	post_body = body; //setting data member to the parameter given
}

std::string Post::getBody() const
{
	return post_body; //returning data member
}

void Post::getTimeStamp() const //creating time variable
{
	struct tm* timeptr; //using tm struct so i can use the calendar date format 
	timeptr = localtime(&time_stamp); //reference to the time data member and putting in the calendar date format
	std::cout << asctime(timeptr); //printing time data member in the format that was assigned
}

void Post::displayPost() const //printing post class in the format that was assigned
{
	std::cout << getTitle() << " posted at ";
	getTimeStamp();
	std::cout << ":" << std::endl << getBody() << std::endl;
}

std::string Post::getUsername() const
{
	return acct_username; //returning data member
	//return Account::getUsername();
}

void Post::setUsername(const std::string& name)
{
	acct_username = name; //setting data member to the parameter given
	//Account::setUsername(name);
}