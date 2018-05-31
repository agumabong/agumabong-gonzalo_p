//
//  ShippingStatus.cpp
//  Project2
//
//  Created by Han, Wenlin on 2/13/18.
//  Copyright © 2018 Han, Wenlin. All rights reserved.
//

#include "ShippingStatus.h"

ShippingStatus::ShippingStatus() {//default constructor. Will set values to zero on initialization. 
	status_ = "";
	location_ = "";
	time_ = 0;
}

ShippingStatus::ShippingStatus(const string& status, const string& location, const time_t& timeUpdated) {
	status_ = status;
	location_ = location;
	time_ = timeUpdated;
}

string ShippingStatus::m_getStatus() {
	return status_;
}

string ShippingStatus::m_getLocation() {
	return location_;
}

time_t ShippingStatus::m_getTime() {
	return time_;
}
