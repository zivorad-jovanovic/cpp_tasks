#include <iostream>
using namespace std;

class GFG {
public:
    void call_Function() // function that call print
    {
        print();
    }
    virtual void print() // the display function
    {
        cout << "Printing the Base class Content" << endl;
    }
};
class GFG2 : public GFG // GFG2 inherit a publicly
{
public:
   virtual void print() // GFG2's display
    {
        cout << "Printing the Derived class Content"
             << endl;
    }
};
int main()
{
    GFG2 obj2;
    GFG* geeksforgeeks = &obj2; // Creating GFG's object
    geeksforgeeks->print(); // Calling call_Function
    
    return 0;
}