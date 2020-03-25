#pragma once
#include "Project.h"
#include "Repo.h"

class Service {
private:
	Repo r;
public:
	Service();
	~Service();
	void addProject(Project& p);
	Project* getAll();
	void deleteProject(Project p);
	void updateProject(Project& p, char* gitPath, int noOfBranches, int totalNoOfCommits);
	Project getItemFromPos(int i);
	int dim();
	void filterProjects(Service& s, int n, int k, int l, Project result[], int& resultLen);
	void eliminateProjects(Service& s, int& n);
};
