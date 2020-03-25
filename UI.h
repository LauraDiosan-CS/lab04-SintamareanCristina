#pragma once
#include "Project.h"
#include "Repo.h"
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	~UI();
	void printMenu();
	void addProject(Service& s);
	void getAll(Service& s);
	void deleteProject(Service& s);
	void updateProject(Service& s);
	void filterProjects(Service& s);
	void eliminateProjects(Service& s);
};
