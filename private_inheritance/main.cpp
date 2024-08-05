#include <iostream>
using namespace std;


class Base{
    private:
        int a = 4;
    protected:
        int b = 6;
    public:
        int c = 55;
        Base(int x, int y, int z): a(x), b(y), c(z){}  //constructor is some kind of public setter method
        int getA(){   //a is private, that is why we need public method to get its value
            return a;
        }
        void setA(int value){
            a = value;
        }

        void printMembers(){
            cout << "Member a in Base class: " << a << endl;
            cout << "Member b in Base class: " << b << endl;
            cout << "Member c in Base class: " << c << endl;

        }

};

class Derived :  public Base{
    //in class Derived, b is protected, c is public(public inheritance)...BUT a is not accessible in Derived class because it is private
    protected:
        int d = 9;
    public:
        Derived(int a, int b, int c, int d): Base(a, b, c), d(d){}
        void printDerivedClassMmembers(){
            cout << "Member a in Derived class: " << getA() << endl;  //BECAUSE A IS PRIVATE IN BASE CLASS, WE MUST USE GET METHOD TO ACCESS IT IN DERIVED CLASS
            cout << "Member b in Derived class: " << b << endl;
            cout << "Member c in Derived class: " << c << endl;
            cout << "Member d in Derived class: " << d << endl;
        }

};

int main()
{
    Base b(21, 57, 4);
    Derived d(10, 20, 45, 1);
    b.printMembers();
    d.printDerivedClassMmembers();
    
    return 0;
}