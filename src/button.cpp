#include "button.hpp"

Button::Button(std::string identifier,sf::String buttonString, sf::RenderWindow* window, float width, float height, bool active) : TextObject(identifier, buttonString)
{
    isActive = active;

    this->window = window;
    this->buttonString = buttonString;
    if(!font.loadFromFile("assets/rainyhearts.ttf"))
        std::printf("ERROR! Font didn't load\n");


    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);
    rect.setPosition(0,0);
    bounds =  rect.getGlobalBounds();

    
    //Button text
    text.setFont(font);
    text.setString(buttonString);
    text.setPosition(sf::Vector2f(0,0));
    text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
}

Button::Button(const Button& other) : 
    TextObject(other)
{   if(!font.loadFromFile("assets/rainyhearts.ttf"))
        std::printf("ERROR! Font didn't load\n");

    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);
    bounds =  rect.getGlobalBounds();

    //Button text
    text.setFont(font);
    text.setString("default button text");
    text.setPosition(sf::Vector2f(0,0));

}

Button::~Button() = default;

void Button::update(){
    if (isHovering()){
         text.setFillColor(sf::Color::Cyan);
         rect.setFillColor(boxColorHov);
    }
    else{
         text.setFillColor(sf::Color::White);
        rect.setFillColor(boxColor);   
    }

     text;

}

void Button::render(sf::RenderWindow& renderWindow) {
    renderWindow.draw(rect);
    renderWindow.draw(text);
}

void Button::setPosition(sf::Vector2f position) {
    rect.setPosition(position);
    bounds =  rect.getGlobalBounds();
    text.setPosition(position.x + (bounds.width) /1.5, position.y + bounds.height / 1.3);
}        




bool Button::isHovering() {
        return bounds.contains((sf::Vector2f) sf::Mouse::getPosition(*window));
}

bool Button::isClicked() {
    return isHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

