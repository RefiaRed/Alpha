#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameObject.hpp"

class Scene {
    private:
        const std::string identifier;
        std::vector<GameObject*> listOfGameObjects;

    public:
        Scene(std::string identifier);
        ~Scene();
    public:
    virtual void addGameObject(GameObject& object);

    virtual void update();

    virtual void render(sf::RenderWindow& window);

    virtual std::string getIdentifier() const;
};

