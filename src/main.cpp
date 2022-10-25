#include <SFML/Graphics.hpp>

#include <scene.hpp>
#include <spriteObject.hpp>
#include <sceneHandler.hpp>
#include <textObject.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Alpha Project", sf::Style::Close);

    Scene scene1("scene01");

    SpriteObject sprite1("soldierSprite", "assets/head.png");
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene1.addGameObject(sprite1);

    Scene scene2("scene02");

    SpriteObject sprite2("soldierSprite", "assets/head_hurt.png");
    sprite2.setPosition(sf::Vector2f(170.0f, 170.0f));
    sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite2);

    TextObject testingtext("testtext");
    //scene2.addGameObject(testingtext); <-insta closes window when uncommented

    


    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);
    


    int counter = 0;
    while (window.isOpen()) {
        
        //check for Events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::A) {
                    if(counter == 0) {
                        handler.stackScene("scene02");
                        counter++;
                    } else {
                        handler.popScene();
                        counter--;
                    }
                }
            }
        }
        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





