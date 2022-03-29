#pragma once
#include "AllLibraries.h"
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    const int GetDay() const;
    const int GetMonth() const;
    const int GetYear() const;
    void SetDay(const int day);
    void SetMonth(const int month);
    void SetYear(const int year);
};
class PHONE
{
private:
    int mob;
    int home;
    int work;
public:
    PHONE();
    PHONE(int mob, int home, int work);
    const int GetMobNum() const;
    const int GetHomeNum() const;
    const int GetWorkNum() const;
    void SetMobNum(const int mob);
    void SetHomeNum(const int home);
    void SetWorkNum(const int work);
};

class Student
{
private:
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    Date birthday;
    char* adress = nullptr;
    PHONE phone;
    vector<int> mas1;
    vector<int> mas2;
    vector<int> mas3;
    void SetBirthday(Date _birthday);
    void SetPatronymic(const char* patronymic);

public:

    void SetSurame(const char* surname);
    void SetName(const char* name);
    void SetAdress(const char* adress);
    void SetPhone(PHONE _phone);
    void SetGrades(const int val1, const int val2, const int val3);
    const char* GetSurname() const;
    const char* GetName() const;
    const char* GetPatronymic() const;
    void GetBirthday(const Date date) const;
    char* GetAdress() const;
    void GetGrades(const vector <int> mas) const;
    int GetAverageGrade();
    const int const GetMinGrade(const vector <int> mas);
    const int const CheckGrades();
    int GetPhone(const int phone) const;
    bool GetCheckZero(int val1, int val2, int val3) const;
    void EditingStudent();
    bool operator > (const Student& student) const;
    bool operator < (const Student& student) const;
    bool operator == (Student& student);
    bool operator != (Student& student);
    void operator = (const Student& student);
    Student operator()(const char* Surname, const char* Name,
        const char* Patronymic, Date _Birthday,
        const char* Adress, PHONE Phone,
        const int val1, const int val2, const int val3);
    friend ostream& operator << (ostream& out, const Student& original);
    friend istream& operator >> (istream& in, Student& original);
    Student operator+= (int grade);
    void Show();
    Student();
    Student(const char* Surname, const char* Name);
    Student(const char* Surname, const char* Name,
        const char* Patronymic, Date _Birthday,
        const char* Adress, PHONE Phone,
        const int val1, const int val2, const int val3);
    Student(const Student& student);
    ~Student();
};