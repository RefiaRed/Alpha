#include <textObject.hpp>

TextObject::TextObject(std::string identifier, sf::String textString) : GameObject(identifier)
{
    if(!textFont.loadFromFile("assets/rainyhearts.ttf"))
        std::printf("ERROR! Font didn't load\n");

    text.setFont(textFont);
    text.setCharacterSize(25);
    text.setString(textString);
}

TextObject::TextObject(const TextObject& other) : 
    GameObject(other.getIdentifier()) 
{
     if(!textFont.loadFromFile("assets/rainyhearts.ttf"))
        std::printf("ERROR! Font didn't load\n");

    text.setFont(textFont);
    text.setCharacterSize(25);
}


TextObject::~TextObject() = default;

void TextObject::update() {

}

void TextObject::render(sf::RenderWindow& window) {
    window.draw(text);
}

void TextObject::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}




void TextObject::setText(sf::String newText, int size) {
    text.setString(newText);
    text.setCharacterSize(size);
}

void TextObject::setColor(sf::Color color){
    text.setFillColor(color);
}

sf::String TextObject::getText() const {
    return text.getString();
}

const sf::Vector2f TextObject::getPosition() {
    return sf::Vector2f(text.getPosition());
}


