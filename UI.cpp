#include "UI.h"
#include "Service.h"
#include <iostream>
using namespace std;

//constructor
UI::UI()
{
	this->s;
}

//destructor
UI::~UI()
{
}

//afisare meniu
void UI::printMenu()
{
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. Afisare proiecte care au noOfBranches >= k si totalNoOfCommits >= l" << endl;
	cout << "6. Eliminare proiecte care au noOfBranches * totalNoOfCommits = 0" << endl;
	cout << "7. Iesire." << endl;
	cout << endl;
}

//adaugare element de tip Project
void UI::addProject(Service& s)
{
	char gitPath[100];
	int noOfBranches, totalNoOfCommits, n = 0;
	cout << "Git path: ";
	cin >> gitPath;
	cout << "noOfBranches: ";
	cin >> noOfBranches;
	cout << "totalNoOfCommits: ";
	cin >> totalNoOfCommits;
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	s.addProject(p); n++;
	cout << endl;
}

//afisare toate elementele de tip Project
void UI::getAll(Service& s)
{
	cout << endl << "Projects: " << endl;
	for (int i = 0; i < s.dim(); i++) {
		cout << s.getAll()[i] << " ";
		cout << endl;
		}

	cout << endl;
}

//stergere element de tip Project
void UI::deleteProject(Service& s)
{
	cout << "Sterge proiectul cu numarul: ";
	int i; cin >> i; int n = s.dim();
	s.deleteProject(s.getItemFromPos(i - 1)); n -= 1;
}

//modificare element de tip Project
void UI::updateProject(Service& s)
{
	cout << "Update la proiectul cu numarul: "; int i; cin >> i;
	Project p = s.getItemFromPos(i - 1);
	cout << "new gitPath: "; char  newGitPath[10];  cin >> newGitPath;
	cout << "new noOfBranches: "; int newNoOfBranches;  cin >> newNoOfBranches;
	cout << "new totalNoOfCommits: "; int newTotalNoOfCommits;  cin >> newTotalNoOfCommits;
	s.updateProject(p, newGitPath, newNoOfBranches, newTotalNoOfCommits);
}

//afisare elemente dupa filtrare
void UI::filterProjects(Service& s)
{
	int resultLen = 0; Project result[10]; int k, l;
	cout << "Dati k: ";
	cin >> k;
	cout << "Dati l: ";
	cin >> l;
	int n = s.dim();
	s.filterProjects(s, n, k, l, result, resultLen);
	cout << endl << "Proiectele sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}
	cout << endl;
}

//stergere elementele care au noOfBranches * totalNoOfCommits = 0
void UI::eliminateProjects(Service& s)
{
	int n = s.dim();
	s.eliminateProjects(s, n);
}