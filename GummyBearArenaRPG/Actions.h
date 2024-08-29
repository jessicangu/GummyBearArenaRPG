#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>

class Actions {
private:
    int id;
    std::string name;
    int damage;

public:
    // constructor
    Actions(int id, const std::string& name, int damage);

    // default constructor
    Actions() : id(0), name(""), damage(0) {}

    // getters and setters
    int getID() const;
    void setID(int id);
    const std::string& getName() const;
    void setName(const std::string& name);
    int getDamage() const;
    void setDamage(int damage);
};

#endif // ACTIONS_H
