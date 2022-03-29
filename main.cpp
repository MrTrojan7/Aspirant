#include "AllLibraries.h"
#include "Aspirant.h"

int main()
{
	Student k("Ivan", "Ivanov");
	Aspirant a(k, "development");
	Aspirant b("Olexandr", "Makedonskiy", "building");
	a.Print();
	b.Print();
	return 0;
}