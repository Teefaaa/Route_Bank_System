//parser .h
#pragma once
#include<vector>
#include<string>
#include<Client.h>
#include<Employee.h>
#include<Admin.h>
using namespace std;
class Parser {
public:
	static vector<string>split(string line);
	
	static Client parsetoclient(string line);
	
	static Employee parsetoEmployee(string line);
	
	static Admin parsetoAdmin(string line);
	
};
