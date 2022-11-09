#pragma once
#include "gameObject.hpp"
#include "spriteObject.hpp"

class Entity : public GameObject {
private:
    int maxHp;
    int atk;
    int def;
    int hp;
    int tp;
    bool itsTurn = false;

    //Enemy extra
    enum Action {waits, attacks, heals};

public:
    Entity(std::string identifier, int maxHp, int maxTp, int atk, int def);
    ~Entity() override;
public:
    void render(sf::RenderWindow &window) override;
    void update() override;
    void getStats();
    int getHp();
    int getTp();
    int getAtk() const;
    int getDef() const;
    int getMaxHp() const;

    void setHp(int newHp);
    void attack(Entity &target, int rdLow);
    void heal(Entity &target, int rdHigh);
    void randAct(Entity &target,int a, int rdLow);
    void waitTurn(Entity &target);
    void endTurn(Entity &next);

};








