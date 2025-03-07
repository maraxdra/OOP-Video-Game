//methods, main console, constructors, setters and getters for derived classes
#include <iostream>
#include <cstring>
#include "vector"

using namespace std;

class Character {
private:
    string name;
    int hp;
    int mana;
    int stamina;
public:

    //constructor
    Character() {}

    Character(const string &name, int hp, int mana, int stamina) {
        this->name = name;
        this->hp = hp;
        this->mana = mana;
        this->stamina = stamina;
    }

    //destructor

    // ???

    //getters

    const string &getName() const {
        return name;
    }

    int getHp() const {
        return hp;
    }

    int getMana() const {
        return mana;
    }

    int getStamina() const {
        return stamina;
    }

    //setters

    void setName(const string &name) {
        Character::name = name;
    }

    void setHp(int hp) {
        Character::hp = hp;
    }

    void setMana(int mana) {
        Character::mana = mana;
    }

    void setStamina(int stamina) {
        Character::stamina = stamina;
    }

    //methods

    virtual void printInfo() const {
        cout << "Name: " << name << endl
             << "HP: " << hp << endl
             << "Mana: " << mana << endl
             << "Stamina: " << stamina << endl;
    }
};


class Player : public Character {
private:
    string classtype;
public:
    Player(const string &name, int hp, int mana, int stamina, const string &classtype) : Character(name, hp, mana,
                                                                                                   stamina) {
        this->classtype = classtype;
    }

    void printInfo() const override {
        cout << "<----------------Player---------------" << endl;
        Character::printInfo();
        cout << "Class: " << classtype << endl;
    }
};


class NPC : public Character {
private:
    bool isAgressive;
public:
    NPC(const string &name, int hp, int mana, int stamina, bool isAgressive) : Character(name, hp, mana, stamina) {
        this->isAgressive = isAgressive;
    }


    void printInfo() const override {
        cout << "<----------------NPC---------------" << endl;
        Character::printInfo();
        cout << "Is agressive: " << isAgressive << endl;
    }
};

class Enemy : public Character {
public:
    int damage;

    Enemy(const string &name, int hp, int mana, int stamina, int damage) : Character(name, hp, mana, stamina) {
        this->damage = damage;
    }

    void printInfo() const override {
        cout << "<----------------Enemy---------------" << endl;
        Character::printInfo();
        cout << "Damage: " << damage << endl;
    }
};

int main() {
    Character *character;

    int currentPos = 0;
    bool quit = false;
    while (!quit) {
        cout << "1. Create a player character" << endl;
        cout << "2. Create an NPC" << endl;
        cout << "3. Create an enemy" << endl;
        cout << "4. Delete character" << endl;
        cout << "5. Set HP of character" << endl;
        cout << "6. Set Mana of character" << endl;
        cout << "7. Set Stamina of character" << endl;
        cout << "8. Print info of character" << endl;
        cout << "9. Quit" << endl;

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int hp, mana, stamina;
                string classtype;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter HP: ";
                cin >> hp;
                cout << "Enter Mana: ";
                cin >> mana;
                cout << "Enter Stamina: ";
                cin >> stamina;
                cout << "Enter class type:";
                cin >> classtype;

                character = new Player(name, hp, mana, stamina, classtype);
                cout << "Created a new Player!" << endl;
                break;
            }
            case 2: {
                string name;
                int hp, mana, stamina;
                bool agression;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter HP: ";
                cin >> hp;
                cout << "Enter Mana: ";
                cin >> mana;
                cout << "Enter Stamina: ";
                cin >> stamina;
                cout << "Is the character agressive?" << endl;
                cout << "1. True" << endl;
                cout << "2. False" << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        agression = true;
                        break;
                    case 2:
                        agression = false;
                        break;
                }
                character = new NPC(name, hp, mana, stamina, agression);
                cout << "Created a new NPC!" << endl;
            }
            case 3: {
                string name;
                int hp, mana, stamina, damage;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter HP: ";
                cin >> hp;
                cout << "Enter Mana: ";
                cin >> mana;
                cout << "Enter Stamina: ";
                cin >> stamina;
                cout << "Enter Damage: ";
                cin >> damage;

                character = new Enemy(name, hp, mana, stamina, damage);
                cout << "Created a new Enemy!" << endl;
                break;
            }

            case 4: {
                //??
                break;
            }

            case 5: {
                int hp;
                cout << "Enter HP: ";
                cin >> hp;
                character->setHp(hp);
                cout << "Set HP to " << character->getHp() << endl;
                break;
            }
            case 6: {
                int mana;
                cout << "Enter Mana: ";
                cin >> mana;
                character->setMana(mana);
                cout << "Set Mana to " << character->getMana() << endl;
                break;
            }
            case 7: {
                int stamina;
                cout << "Enter HP: ";
                cin >> stamina;
                character->setStamina(stamina);
                cout << "Set Stamina to " << character->getStamina() << endl;
                break;
            }

            case 8: {
                character->printInfo();
                break;
            }

            case 9:
                quit = true;
                break;
        }
        cout << "===================================" << endl << endl;
    }
}