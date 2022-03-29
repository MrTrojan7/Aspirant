#pragma once
#include "AllLibraries.h"
#include "Student.h"
class Aspirant : public Student
{
private:
	string theme;
	void SetTheme(string theme);
public:
	Aspirant();
	Aspirant(string theme);
	Aspirant(Student& student, string theme);
	Aspirant(const char* name, const char* surname, string theme);
	~Aspirant();
	void Print() const;
	string GetTheme() const;

};

