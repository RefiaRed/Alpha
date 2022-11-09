#include "entity.hpp"

Entity::Entity(std::string identifier, int maxHp, int maxTp, int atk, int def)
        : GameObject(identifier) {
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->tp = maxTp;
    this->atk = atk;
    this->def = def;

}

Entity::~Entity() = default;
void Entity::update() { }
void Entity::render(sf::RenderWindow& window) { }

void Entity::getStats() {
    std::printf ("MAX-HP: %d,HP: %d, TP: %d, ATK: %d,DEF: %d", maxHp, hp, tp, atk, def);
}

int Entity::getHp() {
    return hp;
}

int Entity::getMaxHp() const {
    return maxHp;
}

int Entity::getTp() {
    return tp;
}

int Entity::getAtk() const {
    return atk;
}

int Entity::getDef() const {
    return def;
}

void Entity::setHp(int newHp) {
    hp = newHp;
}

//actions

void Entity::waitTurn(Entity &target) {
    endTurn(target);
}

void Entity::attack(Entity& target, int rdLow) {
    int damage;
    damage =  (atk + rdLow) - target.getDef()  ;
    if (damage < target.getHp())
    target.setHp(target.getHp() - damage);
    else
        target.setHp(0);

    endTurn(target);

}

void Entity::heal(Entity &target, int rdHigh) {
    int newHp = getHp() + rdHigh;
    int newTp = getTp() - 3;
    if(getHp() < getMaxHp() && newHp < getMaxHp())
        setHp(newHp);

    else
        setHp(getMaxHp());

    tp = newTp;
    endTurn(target);
}

void Entity::randAct(Entity &target, int rdLow) {

    switch (action){
        case waits:
            waitTurn(target);
        break;

        case attacks:
            attack(target, rdLow);
        break;

        case heals:
            heal(target, rdLow + 5);
        break;

    }

}

void Entity::endTurn(Entity &next) {
    itsTurn = false;
    next.itsTurn = true;
}

bool Entity::getTurn() {
    return itsTurn;

}

int Entity::getAction() {
    return action;
}

void Entity::destroy() {
    this->~Entity();

}








