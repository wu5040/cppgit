#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
    string Name;
    double GPA;
public:
    Student(string name,double gpa) : Name(name),GPA(gpa) {} //√∞∫≈”Ô∑®ππ‘Ï
    friend ostream & operator<<(ostream &out,const Student &s)
    {
        out<<left<<setw(7)<<s.Name<<s.GPA;
        return out;
    }
};
