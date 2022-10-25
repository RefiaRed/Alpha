#include <textObject.hpp>

TextObject::TextObject(std::string identifier) : GameObject(identifier)
{
    if(font.loadFromFile("assets/rainyhearts.ttf"))
        throw ("ERROR! Font didn't load\n");

    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Testing, testing, testing \n");
}


TextObject::~TextObject() { }

void TextObject::update() {

}

void TextObject::render(sf::RenderWindow& window) {
    window.draw(text);
}

void TextObject::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void TextObject::setCharSize(int size) {
    text.setCharacterSize(size);
}

void TextObject::setText(sf::String newtext) {
    text.setString(newtext);
}

