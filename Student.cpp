#include "Student.h"

/////////////////// Date /////////////////

Date::Date() : Date(12, 01, 2001)
{
}

Date::Date(int day, int month, int year)
{
    SetDay(day);
    SetMonth(month);
    SetYear(year);
}

const int Date::GetDay() const
{
    return this->day;
}

const int Date::GetMonth() const
{
    return this->month;
}

const int Date::GetYear() const
{
    return this->year;
}

void Date::SetDay(const int day)
{
    this->day = day;
}

void Date::SetMonth(const int month)
{
    this->month = month;
}

void Date::SetYear(const int year)
{
    this->year = year;
}

/////////////////// Phone /////////////////

PHONE::PHONE() : PHONE(1232123, 7777, 333) {}

PHONE::PHONE(int mob, int home, int work)
{
    SetMobNum(mob);
    SetHomeNum(home);
    SetWorkNum(work);
}

const int PHONE::GetMobNum() const
{
    return this->mob;
}

const int PHONE::GetHomeNum() const
{
    return this->home;
}

const int PHONE::GetWorkNum() const
{
    return this->work;
}

void PHONE::SetMobNum(const int mob)
{
    this->mob = mob;
}

void PHONE::SetHomeNum(const int home)
{
    this->home = home;
}

void PHONE::SetWorkNum(const int work)
{
    this->work = work;
}

/////// Student /////////////////

void Student::SetSurame(const char* surname)
{
    if (!surname || strlen(surname) == 0)
        return;
    if (this->surname != nullptr)
        delete[] this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Student::SetName(const char* name)
{
    if (!name || strlen(name) == 0)
        return;
    if (this->name != nullptr)
        delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}


void Student::SetPatronymic(const char* patronymic)
{
    if (!patronymic || strlen(patronymic) == 0)
        return;
    if (this->patronymic != nullptr)
        delete[] this->patronymic;
    this->patronymic = new char[strlen(patronymic) + 1];
    strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
}


void Student::SetBirthday(Date _birthday)
{
    GetCheckZero(_birthday.GetDay(), _birthday.GetMonth(), _birthday.GetYear());
    this->birthday.SetDay(_birthday.GetDay());
    this->birthday.SetMonth(_birthday.GetMonth());
    this->birthday.SetYear(_birthday.GetYear());
}

void Student::SetAdress(const char* adress)
{
    if (!adress || strlen(adress) == 0)
        return;
    if (this->adress != nullptr)
        delete[] this->adress;
    this->adress = new char[strlen(adress) + 1];
    strcpy_s(this->adress, strlen(adress) + 1, adress);
}

void Student::SetPhone(PHONE _phone)
{
    GetCheckZero(_phone.GetMobNum(), _phone.GetHomeNum(), _phone.GetWorkNum());
    this->phone.SetMobNum(_phone.GetMobNum());
    this->phone.SetHomeNum(_phone.GetHomeNum());
    this->phone.SetWorkNum(_phone.GetWorkNum());
}

const char* Student::GetSurname() const
{
    return this->surname;
}

const char* Student::GetName() const
{
    return this->name;
}

void Student::SetGrades(const int val1, const int val2, const int val3)
{
    GetCheckZero(val1, val2, val3);
    this->mas1.push_back(val1);
    this->mas2.push_back(val2);
    this->mas3.push_back(val3);
}

const char* Student::GetPatronymic() const
{
    return this->patronymic;
}

void Student::GetBirthday(const Date date) const
{
    cout << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear() << "\n";
}

char* Student::GetAdress() const
{
    return  adress;
}

void Student::GetGrades(const vector <int> mas) const
{
    for (size_t i = 0; i < mas.size(); i++)
        cout << mas[i] << " ";
}

int Student::GetAverageGrade()
{
    int result = 0;
    int amount = mas1.size() + mas2.size() + mas3.size();
    for (int i = 0; i < mas1.size(); i++)
        result += mas1[i];
    for (int i = 0; i < mas2.size(); i++)
        result += mas2[i];
    for (int i = 0; i < mas3.size(); i++)
        result += mas3[i];
    return (result / amount);
}

const int const Student::GetMinGrade(const vector<int> mas)
{
    int min = mas[0];
    for (size_t i = 0; i < mas.size(); i++)
    {
        if (mas[i] < min)
            min = mas[i];
    }
    return min;
}

int const Student::CheckGrades()
{
    unsigned int min = mas1[0];
    if (GetMinGrade(mas1) < min)
        min = GetMinGrade(mas1);
    if (GetMinGrade(mas2) < min)
        min = GetMinGrade(mas2);
    if (GetMinGrade(mas3) < min)
        min = GetMinGrade(mas3);
    return min;
}

bool Student::GetCheckZero(int val1, int val2, int val3) const
{
    if (val1 <= 0 || val2 <= 0 || val3 <= 0)
    {
        throw "Invalid value! It should not be equal to zero!";
    }
    return true;
}

void Student::EditingStudent()
{
    string tmp;
    cout << "Enter new surname: ";
    cin >> tmp;
    SetSurame(tmp.c_str());
    cout << "Enter new name: ";
    cin >> tmp;
    SetName(tmp.c_str());
    cout << "Enter new patronymic: ";
    cin >> tmp;
    SetPatronymic(tmp.c_str());
    cout << "Enter new adress: ";
    cin >> tmp;
    SetAdress(tmp.c_str());
}

bool Student::operator>(const Student& student) const 
{
    for (int i = 0; i < strlen(this->surname); i++)
    {
        if (this->surname[i] > student.surname[i])
            return true;
        else if (this->surname[i] == student.surname[i])
            continue;
        else if (this->surname[i] < student.surname[i])
            return false;
    }
    return false;
}

bool Student::operator<(const Student& student) const
{
    if (operator>(student))
        return false;
    else if (!operator>(student))
        return true;
}

bool Student::operator==(Student& student)
{
    return GetAverageGrade() == student.GetAverageGrade();
}

bool Student::operator!=(Student& student)
{
    return GetAverageGrade() != student.GetAverageGrade();
}

void Student::operator=(const Student& student)
{
    this->SetSurame(student.GetSurname());
    this->SetName(student.GetName());
    this->SetPatronymic(student.GetPatronymic());
    this->SetBirthday(student.birthday);
    this->SetAdress(student.GetAdress());
    this->SetPhone(student.phone);
    this->mas1.assign(student.mas1.begin(), student.mas1.end());
    this->mas2.assign(student.mas2.begin(), student.mas2.end());
    this->mas3.assign(student.mas3.begin(), student.mas3.end());
}

Student Student::operator()(const char* Surname, const char* Name, 
    const char* Patronymic, Date _Birthday, 
    const char* Adress, PHONE Phone, 
    const int val1, const int val2, const int val3)
{
    this->Student::Student(Surname, Name, Patronymic, _Birthday, Adress, Phone, val1, val2, val3);
    return Student();
}

Student Student::operator+=(int grade)
{
    if (grade < 0 || grade > 12)
        throw "invalid grade!";
    this->mas3.push_back(grade);
    return Student();
}

int Student::GetPhone(int phone) const
{
    return phone;
}

void Student::Show()
{
    cout << "Surname: " << GetSurname() << "\n";
    cout << "Name: " << GetName() << "\n";
    cout << "Patronymic: " << GetPatronymic() << "\n";
    cout << "Birthday date: ";
    GetBirthday(this->birthday);
    cout << "Home Adress: " << "str. " << GetAdress() << "\n";
    cout << "Telephone number:\n"
        << "Mobile number: " << GetPhone(this->phone.GetMobNum()) << "\n"
        << "Home number: " << GetPhone(this->phone.GetHomeNum()) << "\n"
        << "Job number: " << GetPhone(this->phone.GetWorkNum()) << "\n";
    cout << "Grades of subject 1: ";
    GetGrades(mas1);
    cout << "\nGrades of subject 2: ";
    GetGrades(mas2);
    cout << "\nGrades of subject 3: ";
    GetGrades(mas3);
    cout << endl;
}

Student::Student(const char* Surname, const char* Name,
    const char* Patronymic, Date _Birthday,
    const char* Adress, PHONE _Phone, const int val1, const int val2, const int val3)
{
    SetSurame(Surname);
    SetName(Name);
    SetPatronymic(Patronymic);
    SetBirthday(_Birthday);
    SetAdress(Adress);
    SetPhone(_Phone);
    SetGrades(val1, val2, val3);
}

Student::Student() : Student("Fedko", "Vasya", "Vasilievich",
    { 1, 1, 2000 }, "Chernyahovskogo 2", { 123456789 ,12345, 123 }, 12, 11, 10) {}

Student::Student(const char* Surname, const char* Name) : Student(Surname, Name, "Vasilievich",
    { 1, 1, 2000 }, "Chernyahovskogo 2", { 123456789 ,12345, 123 }, 12, 11, 10) {}

Student::Student(const Student& student)
{
    this->SetSurame(student.GetSurname());
    this->SetName(student.GetName());
    this->SetPatronymic(student.GetPatronymic());
    this->SetBirthday(student.birthday);
    this->SetAdress(student.GetAdress());
    this->SetPhone(student.phone);
    this->mas1.assign(student.mas1.begin(), student.mas1.end());
    this->mas2.assign(student.mas2.begin(), student.mas2.end());
    this->mas3.assign(student.mas3.begin(), student.mas3.end());
}

Student::~Student()
{
    if (name != nullptr)
    {
        delete[]name;
        name = nullptr;
    }
    if (surname != nullptr)
    {
        delete[]surname;
        surname = nullptr;
    }
    if (patronymic != nullptr)
    {
        delete[]patronymic;
        patronymic = nullptr;
    }
    if (adress != nullptr)
    {
        delete[]adress;
        adress = nullptr;
    }
}

ostream& operator<<(ostream& out, const Student& original)
{
    out << original.GetSurname() << " " << original.GetName() << " " << original.GetPatronymic() << "\n"
        << original.GetAdress() << "\n" << original.phone.GetMobNum();
    return out;
}

istream& operator>>(istream& in, Student& original)
{
    in >> original.surname >> original.name >> original.patronymic >> original.adress;
    return in;
}
