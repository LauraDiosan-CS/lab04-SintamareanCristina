#include "Project.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
#include "tests.h"
#include <cassert>
#include <string.h>
using namespace std;

void testEntity() {
    Project x;
    assert((x.getGitPath() == NULL) && (x.getNoOfBranches() == 0) && (x.getTotalNoOfCommits() == 0));
    Project p("abc", 2, 3);
    assert(p.getGitPath() == "abc");
    assert(p.getNoOfBranches() == 2);
    assert(p.getTotalNoOfCommits() == 3);
    p.setGitPath("aaa");
    assert(p.getGitPath() == "aaa");
    p.setTotalNoOfCommits(4);
    assert(p.getTotalNoOfCommits() == 4);
    Project q("abc", 2, 2);
    assert((p == q) == 0);
    Project p2(p);
    assert(p == p2);
    Project y("abb", 9, 2);
    Project z("oll", 1, 1);
    y = z;
    assert((y.getGitPath() == "oll") && (y.getNoOfBranches() == 1) && (y.getTotalNoOfCommits() == 1));
}


void testRepo() {
    Project p1("abb", 9, 2);
    Project p2("oll", 1, 1);
    Repo rep;
    assert(rep.dim() == 0);
    rep.addProject(p1);
    rep.addProject(p2);
    assert(rep.dim() == 2);
    assert(rep.getAll()[0] == p1);
    assert(rep.getAll()[1] == p2);
    rep.deleteProject(p1);
    assert(rep.dim() == 1);
    char b[4] = "oll";
    rep.updateProject(p2, b, 0, 0);
    assert((p2.getNoOfBranches() == 0) && (p2.getTotalNoOfCommits() == 0));
    assert(rep.getItemFromPos(0).getNoOfBranches() == 0);
    assert(rep.findProject(rep.getItemFromPos(0)) == 0);
}

void testService() {
    Service s;
    Project p1("ddd", 4, 0);
    s.addProject(p1); 
    assert(s.dim() == 1);
    Project p2("eee", 1, 1);
    s.addProject(p2);
    assert(s.dim() == 2);
    s.deleteProject(p1); 
    assert(s.dim() == 1);
    assert((strstr(p2.getGitPath(), "eee")) && (p2.getNoOfBranches() == 1) && (p2.getTotalNoOfCommits() == 1));
    char x[4] = "eee";
    s.updateProject(p2, x, 2, 2);
    assert((strstr(s.getItemFromPos(0).getGitPath(), "eee")) && (s.getItemFromPos(0).getNoOfBranches() == 2) && (s.getItemFromPos(0).getTotalNoOfCommits() == 2));
    Project p5("aaa", 2, 0);
    s.addProject(p1);
    Project p3("bbb", 4, 5);
    s.addProject(p3);
    Project p4("ccc", 4, 0);
    s.addProject(p4);

    Project result[10]; int lenResult = 0;
    s.filterProjects(s, s.dim(), 4, 5, result, lenResult); 
    assert(lenResult == 1);
    int n = s.dim();
    s.eliminateProjects(s, n); 
    assert(n == 2);
}

void tests() {
    void testEntity();
    void testRepo();
    void testService();
    cout << "Testele s-au rulat" << endl;
    cout << endl;
}