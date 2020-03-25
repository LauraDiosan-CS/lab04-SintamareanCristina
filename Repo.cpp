#include "Repo.h"

Repo::Repo() { size = 0; }

//adaugarea unui element de tip Project
void Repo::addProject(Project p) {
	projects[size++] = p;
}

//returneaza pozitia unui element de tip Project
int Repo::findProject(Project p) {
	int i = 0;

	while (i < size) {
		if (projects[i] == p) return i;
	}
	return -1;
}

//sterge un element de tip Project
void Repo::deleteProject(Project p) {
	int i = findProject(p);
	if (i != -1)
		projects[i] = projects[size - 1];
	size--;
}

//modifica un element de tip Project
void Repo::updateProject(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findProject(p);
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);

}

////returneaza toate elementele de tip Project
Project* Repo::getAll() {
	return projects;
}

//returneaza dimensiunea repo-ului
int Repo::dim() {
	return size;
}

//destructor
Repo::~Repo() {
}

//returneaza elementul de tip Project de pe o anumita pozitie
Project Repo::getItemFromPos(int i) {
	return projects[i];
}