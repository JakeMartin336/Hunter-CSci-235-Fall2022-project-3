// Jacob Martin
// 10/11/2022
// Network.cpp
// Project 3 - Define and implement the Network template class with a header and a source file. In this project you will design and implement the network as a "bag of accounts".

#include "Network.hpp" //include needed headers and libraries
#include "Post.hpp"
#include "Account.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

template<class ItemType>
Network<ItemType>::Network(): acct_count(0) //constructor and setting num of accounts in network to 0
{
}

template<class ItemType>
int Network<ItemType>::getSizeOfNetwork() const //getting size of accounts in network
{
	return acct_count;
}

template<class ItemType>
bool Network<ItemType>::isEmpty() const //seeing if num of accounts in network is 0
{
	return acct_count == 0;
}

template<class ItemType>
bool Network<ItemType>::addAccount(ItemType* entry) //adding account to network
{
	bool space = (acct_count < DEFAULT_CAPACITY);
	if (space && !containsAccount(entry)) //if there is enough space in the network for another account and it isnt already within the network
	{
		//if item doesnt already exist..
		items[acct_count] = entry; //add new account to array
		acct_count++; //up the num of accounts in network
		entry->setNetwork(this); //set the network that the account is apart of
		return true;
	}
	else
		return false;
}

template<class ItemType>
bool Network<ItemType>::removeAccount(const ItemType* entry)
{
	int found_index = getIndexOf(entry->getUsername()); //finding where the account is in the array
	bool can_remove = !isEmpty() && (found_index > -1); //making sure the account isnt empty and is in valid index in array
	if (can_remove) // if previous statement is true
	{
		acct_count--; //making num of accounts in network smaller
		items[found_index] = items[acct_count]; //removing the account from the found index in array
	}
	return can_remove;
}

template<class ItemType>
void Network<ItemType>::clear()
{
	acct_count = 0; //setting num of accounts in the network to 0
}

template<class ItemType>
bool Network<ItemType>::containsAccount(const ItemType* entry) const
{
	return getIndexOf(entry->getUsername()) > -1; // if index is valid index in array then return true
}

template<class ItemType>
int Network<ItemType>::getIndexOf(const std::string& usr) const
{
	bool found = false; 
	int result = -1;
	int search_index = 0;

	while (!found && (search_index < acct_count)) //cycling through array index until the index of the account looking for is found
	{
		if (items[search_index]->getUsername() == usr) //if username of index matches the string given
		{
			found = true; // end search
			result = search_index; //send the index of the account to result
		}
		else
			search_index++; //keep searching index of array
	}
	return result;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class ItemType>
void Network<ItemType>::populateNetwork(const std::string file)
{
    std::string line; //string to store each line of the file
	std::ifstream myfile(file); //creating fstream variable and opening

    while(std::getline(myfile, line)) //reading line by line from file and storing it in file 
    {
        std::istringstream filter(line); //creating an input string stream object and having the line from the file pass through this object, where it only takes characters as valid 
		std::string user; //string to store username
        std::string pass; //string to store password
        filter >> user >> pass; //streaming the line and storing it in the respective strings, having the space between the user and pass be the character that ends the user string
        if (user == "" || pass == "") //checking if user and pass are in the correct format
        {
            std::cout << "Improper Format\n"; //if not throw error
            break;
        }
        else if (line == ";") //if line read is the end of file mark, then end 
            break;
        else //if user and pass are in correct format
        {
            ItemType *temp = new ItemType(user, pass);
            if (addAccount(temp)) //once the new account is added
            {
                user = ""; //set the strings back to empty
                pass = "";
            }
            else
                break; 
        }
    }
    myfile.close();
}

template<class ItemType>
Network<ItemType> Network<ItemType>::operator-=(Network<ItemType>& entry)
{
	for (int i = 0; i < entry.acct_count; i++) //cycling through first network
		if (containsAccount(entry.items[i]))
			removeAccount(entry.items[i]);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class ItemType>
void Network<ItemType>::printFeedForAccount(ItemType& entry) const
{
	for (int i = 0; i < entry.following().size(); i++)
    {
        int acct_count  = getIndexOf(entry.viewFollowing()[i]);
        if (acct_count != -1)
            items[acct_count] -> viewPosts();
    } 
}
template<class ItemType>
bool Network<ItemType>::authenticateFollow(ItemType& entry, const std::string& name)
{
	if (containsAccount(&entry) && (getIndexOf(name) != -1))
    {
        entry.followAccount(name);
        return true;
    }
    return false;
}



template<class ItemType>
bool Network<ItemType>::addToFeed(const Post& entry)
{
	if (getIndexOf(entry.getUsername()))
    {
        net_posts.push_back(entry);
        return true;
    }
	else
    	return false;
}