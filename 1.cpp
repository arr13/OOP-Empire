#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


class Slave{
public:
    Slave();
    Slave(char*, int);
    virtual void Work() {cout << "Slave working\n";}
private:
    char* name;
    int age;
};

Slave::Slave(){
    name = "No name";
    age = 0;
}

Slave::Slave(char* name, int age = 0){
    name = name;
    age = age;
}


class Trader: public Slave{
public:
    Trader(char* name, int age = 0): Slave(name, age) {;}
    virtual void Work() {cout << "Trading\n";}

};

class Soldier: public Slave{
public:
    Soldier(char* name, int age = 0): Slave(name, age) {;}
    virtual void Work() {cout << "Fighting against enemy\n";}
};

class Scholar: public Slave{
public:
    Scholar(char* name, int age = 0): Slave(name, age) {;}
    virtual void Work() {cout << "Researching science\n";}
};

class Priest: public Slave{
public:
    Priest(char* name, int age = 0): Slave(name, age) {;}
    virtual void Work() {cout << "Performing ritual\n";}
};

class Archer: public Soldier{
public:
    Archer(char* name, int age = 0): Soldier(name, age){;}
    virtual void Work() {cout << "Archer fighting\n";}
};

class Swordsman: public Soldier{
public:
    Swordsman(char* name, int age = 0): Soldier(name, age){;}
    virtual void Work() {cout << "Swordsman fighting\n";}
};

class Emperor: public Swordsman{
public:
    Emperor(char* name, int age): Swordsman(name, age){;}
    virtual void Work() {cout << "Ruling the empire\n";}
};

enum Citizens{
    slave,
    soldier,
    scholar,
    priest,
    archer,
    swordsman,
    emperor,
    trader
};

class Empire{
public:
    Empire();
    Empire(char*);
    Empire(Citizens, int);
    int get_emp_population() {return emp_population;}
    Slave* set_new_citizen(Citizens);
private:
    char* name;
    int emp_population;
    Slave** population;
};

Empire::Empire(char* n){
    name = n;
    emp_population = 0;
}

Slave* Empire::set_new_citizen(Citizens citizen){
    switch (citizen){
        case slave:{
            Slave slave_();
            break;
        }
        case soldier:{
            Soldier soldier_();
            break;
        }
        case scholar:{
            Scholar scholar_();
            break;
        }

        case priest:{
            Priest priest_();
            break;
        }

        case archer:{
            Archer archer_();
            break;
        }

        case swordsman:{
            Swordsman swordsman_();
            break;
        }

        case emperor:{
            Emperor emperor_();
            break;
        }
        case trader:{
            Trader trader_();
            break;
        }
    }
}

Empire::Empire(Citizens citizen, int amount){
    for (int i = 0; i < amount; i++){
        population[i] = set_new_citizen(citizen);
    }
    emp_population += amount;
}

void menu(Empire emp){
    string comand;
    string citizen_char;
    int amount;
    cin >> comand;
    while (comand != "exit"){
        if (comand == "add"){
            cin >> citizen_char >> amount;
            Citizens citizen;
            if (citizen_char == "slave") citizen = slave;
            if (citizen_char == "trader") citizen = trader;
            if (citizen_char == "soldier") citizen = soldier;
            emp = Empire(citizen, amount);
            cout << amount << " citizens added to the empire" << endl;
        }
        if (comand == "list"){
            cin >> comand;
            cout << "the empire has " << emp.get_emp_population() << " citizens";
        }
        cin >> comand;

    }
}

int main(){
    Slave* s = new Soldier("Achilles", 20);
    s->Work();
    Slave* s1 = new Trader("Adam", 24);
    s1->Work();
    Slave* s2 = new Emperor("Julius Caesar", 50);
    s2->Work();

    delete s;
    delete s1;
    delete s2;

    Empire RomanEmpire("Roman Empire");
    menu(RomanEmpire);
    return 0;
}
