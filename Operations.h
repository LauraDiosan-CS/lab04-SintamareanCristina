#pragma once
#include "Project.h"
#include "Repo.h"

void filterProjects(Project projects[], int n, int k, int l, Project result[], int& resultLen);
void filterProjectsWithRepo(Repo repo, int n, int k, int l, Project result[], int& resultLen);
void eliminateProjects(Project projects[], int n, Project result[], int& resultLen);
void eliminateProjectsWithRepo(Repo repo, int n, Project result[], int& resultLen);