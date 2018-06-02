// Test
//  PackageTracking.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "PackageTracking.h"
#include <fstream>
#include <sstream>
/*!
this function is the constructor, anything that can have a value is given an initial value because in c++ 
just because you create a variable doesnt mean it has a meaningful initial value
*/
PackageTracking::PackageTracking(const string& strnum) {
	packageList;
	total_updates = 0;
	iter;
	location = "";
	status = "";
	pTime;
	currentStatus = 0;
	timeu = 0;
	
}

// add a new update
/*!
this function adds an update to a package tracking information which includes the status location and time updated
*/
void PackageTracking::m_addUpdate(const string& status, const string& location, const time_t& timeUpdated) {

	ShippingStatus update2(status, location, timeUpdated);
	shipList.push_back(update2);
	total_updates++;
	//std::cout << "All the things inside the list so far: " << std::endl;
	list<ShippingStatus>::iterator iter = shipList.begin();
	/*for (int i = 0; i < total_updates; i++)
	{	
		
		ShippingStatus &butts = *iter;
		cout << butts.m_getLocation() << " " <<  butts.m_getStatus() << " " << butts.m_getTime() << std::endl;
		iter++;
	}*/
	
}
/*!
Moves the point in the list one space forward in time. Does not use iterators but increase or decreases a value called currentStatus.
*/
bool PackageTracking::m_moveBackward()
{

	if (currentStatus == 1)
	{
		std::cout << "At the front of the list. Cannot move backward." << std::endl;
		return false;
	}
	else {
		currentStatus--;
		return true;

	}
	
	
}
/*!
m_moveforward will more the iterator to what the data we are viewing forward
this function also has a check to see if we are the end of the list and if so returns that the 
forward move was incomplete
*/
bool PackageTracking::m_moveForward()//move iterator one step forward in time
{
	if (currentStatus == total_updates) {
		std::cout << "At the end of the list. Cannot move forward." << std::endl;
		return false;
	}
	else 
	{
		currentStatus++;
		return true;
	}
}
/*!
Returns the location of the current update. Grabs the number that currentStatus holds and goes through the list using the number
that currentStatus holds. After it is done going through the list it returns the value at that location.
*/
string PackageTracking::m_getLocation()
{
	std::string location_;
	list<ShippingStatus>::iterator iter = shipList.begin();
	if (currentStatus == 0)
	{
		ShippingStatus &track = *iter;
		location_ = track.m_getLocation();
		//std::cout << "Location is: " << location_ << std::endl;

	}
	for (int i = 0; i < currentStatus; i++)
	{
		ShippingStatus &track = *iter;
		iter++;
		location_ = track.m_getLocation();
	}


	return location_;
}
/*!
Returns the time of the current update. Grabs the number that currentStatus holds and goes through the list using the number
that currentStatus holds. After it is done going through the list it returns the value for the time at that location.
*/

time_t PackageTracking::m_getTime()//return the time of the current update
{
	int timeu = 0;
	list<ShippingStatus>::iterator iter = shipList.begin();
	if (currentStatus == 0)
	{
		ShippingStatus &track = *iter;		
		timeu = track.m_getTime();
	}
	for (int i = 0; i < currentStatus; i++)
	{
		ShippingStatus &track = *iter;
		iter++;
		timeu = track.m_getTime();
	}


	return timeu;
}
/*!
Returns the status of the current update. Grabs the number that currentStatus holds and goes through the list using the number
that currentStatus holds. After it is done going through the list it returns the value for the status at that location.
*/
string PackageTracking::m_getStatus()
{
	std::string status;
	list<ShippingStatus>::iterator iter = shipList.begin();
	if (currentStatus == 0)
	{

		ShippingStatus &track = *iter;		
		status = track.m_getStatus();
	}
	for (int i = 0; i < currentStatus; i++)
	{
		ShippingStatus &track = *iter;
		iter++;
		status = track.m_getStatus();
	}


	return status;
}
/*!
m_getnumofupdate will only return the total number of shipping status updates
*/
int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status updates
{
	return total_updates;
}
/*!
Prints all previous updates in the shipping chain when the package was shipped, all the way up to (but not including) 
the current update you are viewing (may not be the most recent update)Grabs the number that currentStatus 
holds and goes through the list using the number that currentStatus holds, returning each value along the way until
it reaches the value of currentStatus.
*/

void PackageTracking::m_printPreviousUpdates() 
{
	std::list<ShippingStatus>::iterator iter = shipList.begin();
	for (int i = 0; i < currentStatus; i++)
	{
		ShippingStatus &iter2 = *iter;
		std::cout << iter2.m_getStatus() << std::endl;
		iter++;
	}
}

//print all updates from the current update you are viewing to the last update in the tracking chain
void PackageTracking::m_printFollowingUpdates()
{
	int counter;
	std::list<ShippingStatus>::iterator iter = shipList.begin();
	for (int i = 0; i < currentStatus; i++)
	{		
		iter++;
	}
	for (int j = currentStatus; j < total_updates; j++)
	{
		ShippingStatus &iter2 = *iter;
		std::cout << iter2.m_getStatus() << std::endl;
		iter++;
	}
}

void PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
	std::list<ShippingStatus>::iterator iter = shipList.begin();
	for (int i = 0; i < total_updates; i++)
	{
		ShippingStatus &iter2 = *iter;
		std::cout << iter2.m_getStatus() << std::endl;
		iter++;
	}
}
/*!
Views an update. The function takes in a value and goes through the list until it sees that value. If it sees the value,
it sets the currentStatus to that value. If it doesn't, function returns false.
*/
bool PackageTracking::m_setCurrent(const time_t& timeUpdated) 
{
	std::list<ShippingStatus>::iterator iter = shipList.begin();
	//std::cout << "The time we are looking for is: " << timeUpdated << std::endl;
	for (int i = 0; i < total_updates; i++)
	{
		ShippingStatus &iter2 = *iter;
		//std::cout << "The current time is: " << iter2.m_getTime() << std::endl;
		if (iter2.m_getTime() == timeUpdated)
		{
			currentStatus = i+1;
			return true;
		}
		iter++;
	}
	//std::cout << "Couldnt find time." << std::endl;
	return false;
}


bool PackageTracking::m_readTrackingFile(string fileName) {
	ifstream pList(fileName);
	std::string data; // holds the whole line of the text file
	std::string prev; // used to see the prev item, only to check if the prev item is "new"
	
	std::string token;
	if (pList.is_open())
	{
		std::cout << "File is open." << std::endl;

	}
	else
	{
		std::cout << "Could not open file." << std::endl;
		return false;
	}
	while (!pList.eof())
	{
		getline(pList, data);
		std::istringstream parser(data); // used to parse the string that contains the shipping info.
		
		if (data == "new")
		{
			total_updates++;
		}
		if (prev == "new")
		{
			//std::cout << "Found a new update." << std::endl;
			std::getline(parser, token, ';');
			status = token;
			//std::cout << status << std::endl;
			std::getline(parser, token, ';');
			location = token;
			//std::cout << location << std::endl;
			std::getline(parser, token, ';');
			istringstream(token) >> pTime;
			//std::cout << pTime << std::endl;
			ShippingStatus update2(status, location, pTime);
			shipList.push_back(update2);
			currentStatus++;

		}
		if (data == "back")
		{
			m_moveBackward();
		}
		if (data == "forward")
		{
			m_moveForward();
		}

		packageList.push_back(data);
		prev = data;
	}
	/*
	list<std::string>::iterator iter = packageList.begin();
	for (int i = 0; i < 22; i++)
	{
		std::string& r = *iter;
		cout << r << std::endl;
		iter++;


	}*/
	return true;

}


