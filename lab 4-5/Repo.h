#pragma once
#include "Project.h"

class Repo
{
private:
	Project projects[20];
	int size;

public:
	Repo();
	void addProject(Project);
	int findProject(Project);
	Project getItemFromPos(int);
	void deleteProject(Project);
	void updateProject(Project, char*, int, int);
	Project* getAll();
	int dim();
	~Repo();
};
