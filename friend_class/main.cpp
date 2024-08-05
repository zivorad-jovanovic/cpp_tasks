#include <iostream>
using namespace std;

class Derived;    //forward declaration

class Base{
    private:
        int a = 4;
    protected:
        int b = 6;
    public:
        int c = 55;
        Base(int x, int y, int z): a(x), b(y), c(z){}  //constructor is some kind of public setter method
        
        void printMembers(){
            cout << "Member a in Base class: " << a << endl;
            cout << "Member b in Base class: " << b << endl;
            cout << "Member c in Base class: " << c << endl;

        }

        friend class Derived;  //this is important, now Derived class can access even private members of the base class

};

class Derived :  public Base{

    protected:
        int d = 9;
    public:
        Derived(int a, int b, int c, int d): Base(a, b, c), d(d){}
        void printDerivedClassMmembers(){
            cout << "Member a in Derived class: " << a << endl;  //now we can access a member of the base class as usual, because derived is friend class
            cout << "Member b in Derived class: " << b << endl;
            cout << "Member c in Derived class: " << c << endl;
            cout << "Member d in Derived class: " << d << endl;
        }

        void displayPrivateMember(Base& obj){  //passing object by reference, avoiding copies and it is faster all changes inside function reflects outside function
            cout << "Private member a in Base class is: " << obj.a << endl;  //we don't need getter anymore because Derived class is a friend class of the base class
            obj.c = 0;
        }

};

int main()
{
    Base b(21, 57, 4);
    Derived d(10, 20, 45, 1);
    b.printMembers(); //c = 4
   // d.printDerivedClassMmembers();
    cout << "Displaying private member a from Base class: ************" << endl;
    d.displayPrivateMember(b);
    b.printMembers();  //c = 0

    
    return 0;
}