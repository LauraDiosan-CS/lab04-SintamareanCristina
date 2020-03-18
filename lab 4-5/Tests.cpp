#include "Tests.h"
#include "Operations.h"
#include "assert.h"
#include <iostream>
using namespace std;

void testFilterProjects() 
{
    Project p1("xyz", 2, 3);
    Project p2("abc/d", 2, 6);
    Project p3("fe/ds", 5, 8);
    Project p4("vv/ww", 1, 4);
    Project projects[4] = { p1, p2, p3, p4 };
    Project results[4];
    int m = 0;
    filterProjects(projects, 4, 2, 6, results, m);
    assert((m == 2) && (results[0] == p2) && (results[1] == p3));
}

void testFilterProjectsWithRepo() {
    Project p1("xyz", 2, 3);
    Project p2("abc/d", 2, 6);
    Project p3("fe/ds", 5, 8);
    Project p4("vv/ww", 1, 4);
    Repo rep;
    rep.addProject(p1);
    rep.addProject(p2);
    rep.addProject(p3);
    rep.addProject(p4);
    Project results[4];
    int m = 0;
    filterProjectsWithRepo(rep, 4, 2, 6, results, m);
    assert((m == 2) && (results[0] == p2) && (results[1] == p3));
}

void testEliminateProjects(){
    Project p1("aaa", 2, 0);
    Project p2("bbb", 4, 5);
    Project p3("ccc", 0, 0);
    Project p4("ddd", 4, 0);
    Project p5("eee", 1, 1);
    Project projects[5] = { p1, p2, p3, p4, p5 };
    Project results[5];
    int m = 0;
    eliminateProjects(projects, 5, results, m);
    assert((m == 2) && (results[0] == p2) && (results[1] == p5));
}

void testEliminateProjectsWithRepo() {
    Project p1("aaa", 2, 0);
    Project p2("bbb", 4, 5);
    Project p3("ccc", 0, 0);
    Project p4("ddd", 4, 0);
    Project p5("eee", 1, 1);
    Repo rep;
    rep.addProject(p1);
    rep.addProject(p2);
    rep.addProject(p3);
    rep.addProject(p4);
    rep.addProject(p5);
    Project results[5];
    int m = 0;
    eliminateProjectsWithRepo(rep, 5, results, m);
    assert((m == 2) && (results[0] == p2) && (results[1] == p5));
}

void testEntity() {
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
}