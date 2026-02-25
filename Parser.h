#pragma once
#include<vector>
#include<string>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;


class Parser
{
public:
	static vector<string>split(string line);

	static Client parse_to_client(string line);

	static Employee parse_to_Employee(string line);

	static Admin parse_to_Admin(string line);

};
