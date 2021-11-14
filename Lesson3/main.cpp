#include<iostream>
using namespace std;
struct Position{    
    int x;
    int y;
};

class BaseObject{
    public:
        int id;
        char *name;
        Position position;
        BaseObject(){}
        char* getName(){
            return this->name;
        }
        int getId(){
            return this->id;
        }
        virtual void move(){}
        void printPosition(){
            cout << "(" << this->position.x << "," << this->position.y << ")" << endl;
        }
        virtual void display(){}
        ~BaseObject(){}
};

class StaticObject: public BaseObject
{
public:
    void move(){
        cout << "StaticObject khong the di chuyen!" << endl;
    }

};

class DynamicObject: public BaseObject
{  
};

class Tree: public StaticObject
{   
    void display(){
        cout << "Tree: " << endl;
        cout << "Name : " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Position: " ;
        this->printPosition();
        this->move();
        cout << "Position: " ;
        this->printPosition();
    }
};

class House: public StaticObject
{   
    void display(){
        cout << "House: " << endl;
        cout << "Name : " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Position: " ;
        this->printPosition();
        this->move();
        cout << "Position: " ;
        this->printPosition();
    }
};

class Motorbike: public DynamicObject
{
    void move(){
        this->position.x += 5;
        cout << "Position.x += 5" << endl;
    }
    void display(){
        cout << "Motorbike: " << endl;
        cout << "Name : " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Position: " ;
        this->printPosition();
        this->move();
        cout << "Position: " ;
        this->printPosition();
    }
};

class Car: public DynamicObject
{
    void move(){
        this->position.y += 5;
        cout << "Position.y += 5" << endl;
    }
    void display(){
        cout << "Car: " << endl;
        cout << "Name : " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Position: " ;
        this->printPosition();
        this->move();
        cout << "Position: " ;
        this->printPosition();
    }
};

int main()
{
    Position *pos = new Position[4];
    for(int i = 1; i <= 4; i++)
    {
        pos[i - 1].x = i;
        pos[i - 1].y = i;
    }

    // Create Object
    BaseObject *obj1 = new Tree();
    obj1->id = 1;
    obj1->name = (char *)"Tree 1";
    obj1->position = pos[0];

    BaseObject *obj2 = new House();
    obj2->id = 2;
    obj2->name = (char *)"House 1";
    obj2->position = pos[1];

    BaseObject *obj3 = new Motorbike();
    obj3->id = 3;
    obj3->name = (char *)"Motorbike 1";
    obj3->position = pos[2];

    BaseObject *obj4 = new Car();
    obj4->id = 4;
    obj4->name = (char *)"Car 1";
    obj4->position = pos[3];

    // Display Object
    obj1->display();
    obj2->display();
    obj3->display();
    obj4->display();

    // Remove
    delete obj1, obj2, obj3, obj4;
    delete[] pos;
    return 0;
}



