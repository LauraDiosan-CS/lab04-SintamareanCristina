#include "Operations.h"
#include "Repo.h"

//filtreaza elementele de tip Project dupa proprietatea: noOfBranches >= k si totalNoOfCommits >= l
void filterProjects(Project projects[], int n, int k, int l, Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (projects[i].getNoOfBranches() >= k && projects[i].getTotalNoOfCommits() >= l)
		{
			result[resultLen++] = projects[i];
		}
	}
}

void filterProjectsWithRepo(Repo repo, int n, int k, int l, Project result[], int& resultLen)
{
	resultLen = 0;
	Project* initialProjects = repo.getAll();
	return filterProjects(initialProjects, n, k, l, result, resultLen);
}

//sterge elementele de tip Project care au noOfBranches * totalNoOfCommits = 0
void eliminateProjects(Project projects[], int n, Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if(projects[i].getNoOfBranches() * projects[i].getTotalNoOfCommits() != 0)
		{
			result[resultLen++] = projects[i];
		}
	}
}

void eliminateProjectsWithRepo(Repo repo, int n, Project result[], int& resultLen)
{
	resultLen = 0;
	Project* initialProjects = repo.getAll();
	return eliminateProjects(initialProjects, n, result, resultLen);
}