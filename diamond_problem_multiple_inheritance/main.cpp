#include<iostream>
using namespace std;
//The diamond problem occurs when two superclasses of a class have a common base class. For example, 
//the TA class gets two copies of all attributes of Person class, this causes ambiguities.
//person constructor will be called twice
//this can be solved by adding virtual inheritance()

class Person {
   // Data members of person 
public:
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
};
 
class Faculty : /*virtual*/ public Person {
   // data members of Faculty
public:
    Faculty(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
};
 
class Student : /*virtual*/ public Person {
   // data members of Student
public:
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
};
 
class TA : public Faculty, public Student  {
public:
    TA(int x): Student(x), Faculty(x) /*,Person(x)*/{  //kada se koristi virtualno nasledjivanje, mora se eksplicitno pozvati i konstruktor bazne klase
        cout<<"TA::TA(int ) called"<< endl;
    }
};
 
int main()  {
    TA ta1(30);
}