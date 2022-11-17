// Jacob Martin
// 9/23/2022
// Post.hpp
// Project 2 - create post class that lets user create a post

#ifndef _POST_
#define _POST_

#include<iostream>
#include<time.h>
#include<string>

class Post
{
public:
	Post(const std::string& name, const std::string& body, const std::string& acct);
	void setTitle(const std::string& name);
	std::string getTitle() const;
	void setBody(const std::string& body);
	std::string getBody() const;
	void getTimeStamp() const;
	void displayPost() const;
	std::string getUsername() const;
	void setUsername(const std::string& name);
private:
	std::string post_name;
	std::string post_body;
	time_t time_stamp;
	std::string acct_username;
};

#endif