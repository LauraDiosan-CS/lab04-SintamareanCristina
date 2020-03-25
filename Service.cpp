#include "Service.h"
#include "Project.h"
#include <iostream>
using namespace std;

//constructor fara param
Service::Service() {
	this->r;
}

//destructor
Service::~Service() {
}

//adauga un element de tip Project
void Service::addProject(Project& p) {
	r.addProject(p);
}

//returneaza toate elementele de tip Project
Project* Service::getAll() {
	return r.getAll();
}

//sterge un element de tip Project 
void Service::deleteProject(Project p) {
	r.deleteProject(p);
}

//modifica un element de tip Project 
void Service::updateProject(Project& p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	r.updateProject(p, gitPath, noOfBranches, totalNoOfCommits);
}

//returneaza elementul de tip Project de pe o anumita pozitie
Project Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}

int Service::dim() {
	return r.dim();
}

//filtreaza elementele de tip Project dupa proprietatea: noOfBranches >= k si totalNoOfCommits >= l
void Service::filterProjects(Service& s, int n, int k, int l, Project result[], int& resultLen){
	resultLen = 0;
	Project* projects = s.getAll();
	for (int i = 0; i < n; i++)
	{
		if (projects[i].getNoOfBranches() >= k && projects[i].getTotalNoOfCommits() >= l)
		{
			result[resultLen++] = projects[i];
		}
	}
}

//sterge elementele de tip Project care au noOfBranches * totalNoOfCommits = 0
void Service::eliminateProjects(Service& s, int& n) {
	Project* projects = s.getAll();
	int i = 0;
	while(i < n)
	{
		if (projects[i].getNoOfBranches() * projects[i].getTotalNoOfCommits() == 0)
		{
			s.deleteProject(projects[i]);
			n--;
		}
		else i++;
	}
}
