#include "Aspirant.h"

void Aspirant::SetTheme(string theme)
{
	this->theme = theme;
}

Aspirant::Aspirant() : Aspirant("programming"){}

Aspirant::Aspirant(string theme) : Student()
{
	SetTheme(theme);
}

Aspirant::Aspirant(Student& student, string theme) : Student(student)
{
	SetTheme(theme);
}

Aspirant::Aspirant(const char* name, const char* surname, string theme) : Student(surname, name)
{
	SetTheme(theme);
}

Aspirant::~Aspirant()
{
	Student::~Student();
}

void Aspirant::Print() const
{
	cout << "Aspirant " << GetName() << " " << GetSurname();
	cout << "\nTheme: " << GetTheme() << "\n";
}

string Aspirant::GetTheme() const
{
	return theme;
}
