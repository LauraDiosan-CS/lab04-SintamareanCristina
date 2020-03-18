#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <string.h>
class Project {
private:
    char* gitPath;
    int noOfBranches;
    int totalNoOfCommits;
public:
    Project();
    Project(const char* gitPath, int noOfBranches, int totalNoOfCommits);
    Project(const Project& p);
    ~Project();
    char* getGitPath();
    int getNoOfBranches();
    int getTotalNoOfCommits();
    void setGitPath(const char* n);
    void setNoOfBranches(int nr);
    void setTotalNoOfCommits(int nr);
    Project& operator=(const Project& p);
    bool operator==(const Project& p);

};
#endif