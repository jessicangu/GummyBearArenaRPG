#include "Actions.h"

Actions::Actions(int id, const std::string& name, int damage)
    : id(id), name(name), damage(damage) {}

int Actions::getID() const {
    return id;
}

void Actions::setID(int id) {
    this->id = id;
}

const std::string& Actions::getName() const {
    return name;
}

void Actions::setName(const std::string& name) {
    this->name = name;
}

int Actions::getDamage() const {
    return damage;
}

void Actions::setDamage(int damage) {
    this->damage = damage;
}
