// lab 4-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tests.h"
#include "Service.h"
#include "UI.h"
using namespace std;

int main(){
	tests();
	bool k = true;
	Service s; UI ui;
	ui.printMenu();
	Project p1("abcd", 1, 2); Project p2("xyz/aa", 4, 0); Project p3("c", 3, 4); Project p4("def", 3, 5);
	s.addProject(p1); s.addProject(p2); s.addProject(p3);
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			ui.addProject(s);
			ui.printMenu();
			continue;
		}
		if (option == 2)
		{
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 3)
		{
			ui.updateProject(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 4)
		{
			ui.deleteProject(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 5)
		{
			ui.filterProjects(s);
			ui.printMenu();
			continue;
		}
		if (option == 6)
		{
			ui.eliminateProjects(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 7)
			k = false;
	}
return 0;
}