#include "Repo.h"

Repo::Repo() { size = 0; }

void Repo::addProject(Project p) {
	projects[size++] = p;
}

int Repo::findProject(Project p) {
	int i = 0;

	while (i < size) {
		if (projects[i] == p) return i;
	}
	return -1;
}

void Repo::deleteProject(Project p) {
	int i = findProject(p);
	if (i != -1)
		projects[i] = projects[size - 1];
	size--;
}

void Repo::updateProject(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findProject(p);
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);

}

Project* Repo::getAll() {
	return projects;
}
int Repo::dim() {
	return size;
}
Repo::~Repo() {
}

Project Repo::getItemFromPos(int i) {
	return projects[i];
}