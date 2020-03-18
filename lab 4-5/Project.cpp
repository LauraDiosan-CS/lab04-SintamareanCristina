#include "Project.h"
#include <string.h>
#include <iostream>

using namespace std;

// Constructor
// In: -
// Out: an empty object of type Student

Project::Project() {
	this->gitPath = NULL;
	this->noOfBranches = 0;
	this->totalNoOfCommits = 0;
}


// Constructor with parameters
// In: gitPath (string), noOfBranches (integer), age (integer)
// Out: an object of type Project that contains the given info

Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits)
{
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, 1 + strlen(gitPath), gitPath);
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;
}


// Copy constructor
// In: an object p of type Project
// Out: another object of type Project that contains the same info as p

Project::Project(const Project& p) 
{
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, sizeof this->gitPath, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}


// Desonstructor
// In: an object of type Project
// Out: -

Project::~Project() 
{
	if (this->gitPath) 
	{
		delete[] this->gitPath;
		this->gitPath = NULL;
	}
}


// getter
// In: an object of type Project
// Out: gitPath of the project
char* Project::getGitPath() {
	return this->gitPath;
}


// getter
// In: an object of type Project
// Out: noOfBranches of the project

int Project::getNoOfBranches() {
	return this->noOfBranches;
}


// getter
// In: an object of type Project
// Out: totalNoOfCommits of the project

int Project::getTotalNoOfCommits() {
	return this->totalNoOfCommits;
}


// setter
// In: an object of type Project and gitPath (string)
// Out: the same object with a new gitPath

void Project::setGitPath(const char* n) {
	if (gitPath) delete[]gitPath;
	gitPath = new char[strlen(n) + 1];
	strcpy_s(gitPath, strlen(n) + 1, n);
}


// setter
// In: an object of type Project and noOfBranches (integer)
// Out: the same object with a new noOfBranches

void Project::setNoOfBranches(int nr) {
	this->noOfBranches = nr;
}


// setter
// In: an object of type Project and totalNoOfCommits (integer)
// Out: the same object with a new totalNoOfCommits

void Project::setTotalNoOfCommits(int nr) {
	this->totalNoOfCommits = nr;
}


// assignment operator
// In: two objects of type Project (the current one, this, and p)
// Out: the new state of the current object (this)

Project& Project::operator=(const Project& p) {
	this->setGitPath(p.gitPath);
	this->setNoOfBranches(p.noOfBranches);
	this->setTotalNoOfCommits(p.totalNoOfCommits);
	return *this;
}


// comparator
// In: two objects of type Project (this and p)
// Out: true or false

bool Project::operator==(const Project& p) {
	return ((strcmp(this->gitPath, p.gitPath) == 0) && (this->noOfBranches == p.noOfBranches) && (this->totalNoOfCommits == p.totalNoOfCommits));
}