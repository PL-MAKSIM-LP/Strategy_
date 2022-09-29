#include <iostream>

using namespace std;

class QuackBehavior {
public:
    virtual void quack() = 0;
};

class SimpleQuack : public QuackBehavior { 
public:
    void quack() {
        cout << "quack\n";
    }
};

class PiskQuack : public QuackBehavior { 
public:
    void quack() {
        cout << "piskquack\n";
    }
};

class NoQuack : public QuackBehavior {
public:
    void quack() {
    }
};

class ToyDuck {
    QuackBehavior* behavior;
public:
    void quack(QuackBehavior* b) { 
        behavior = b;
        b->quack();
    }
};

class TreeDuck : public ToyDuck {};

class RubberDuck : public ToyDuck {};

class GlassDuck : public ToyDuck {};

int main()
{
    ToyDuck* td = new TreeDuck();    

    QuackBehavior* quack_view;  

    SimpleQuack simple_quack;   
    PiskQuack  pisk_quack;
    NoQuack  no_quack;

    cout << "TreeDuck do simple_quack: ";
    td->quack(&simple_quack);
    cout << "\n";
    cout << "TreeDuck do pisk_quack_quack: ";
    td->quack(&pisk_quack); 
    cout << "\n";
    cout << "RubberDuck do pisk_quack_quack: ";
    td->quack(&no_quack); 
    cout << "\n";

    delete td;
}