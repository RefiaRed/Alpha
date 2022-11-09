#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <string>

#include <scene.hpp>
#include <spriteObject.hpp>
#include <sceneHandler.hpp>
#include <textObject.hpp>
#include <entity.hpp>
#include <button.hpp>


int main() {
    //Setup
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Alpha Project", sf::Style::Close);
    window.setPosition(sf::Vector2i(0,0));
    int defaultCharSize = 25;

    std::random_device rd;
    std::uniform_int_distribution<int> distLow(1,10);
    std::uniform_int_distribution<int> distHigh(30,40);
    //Start Main menu
    Scene scene1("scene01");

        Button playButton("playButton", "Play", &window, 200.0f, 100.0f, true);
        playButton.setPosition(sf::Vector2f(window.getSize().x / 2, (window.getSize().y - 200.0f) / 3 ));
        playButton.setText("Trial Button 2", defaultCharSize);
        scene1.addGameObject(playButton);

        Button eraseButton("eraseButton", "Erase Score", &window, 200.0f, 100.0f, true);
        eraseButton.setPosition(sf::Vector2f(window.getSize().x / 2, (window.getSize().y - 200.0f) / 3 * 2));
        eraseButton.setText("Trial Button 2", defaultCharSize);
        scene1.addGameObject(eraseButton);

        Button exitButton("exitButton", "Quit", &window, 200.0f, 100.0f, true);
        exitButton.setPosition(sf::Vector2f(window.getSize().x / 2, (window.getSize().y - 200.0f) / 3 * 3));
        exitButton.setText("Click Here", defaultCharSize);
        scene1.addGameObject(exitButton);





    //Start Battle scene (but it's useless)
    Scene scene2("scene02");

        SpriteObject sprite1("soldierSprite", "assets/head.png");
        sprite1.setPosition(sf::Vector2f(70.0f, ((window.getSize().y - 10.0f) / 4)));
        sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
        scene2.addGameObject(sprite1);

        SpriteObject sprite2("soldierSprite", "assets/head_hurt.png");
        sprite2.setPosition(sf::Vector2f(500.0f, ((window.getSize().y - 10.0f) / 4)));
        sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
        scene2.addGameObject(sprite2);


        Entity player("player",20,20,6,5);
        Entity enemy("enemy",20,10,6,5);
        scene2.addGameObject(player);
        scene2.addGameObject(enemy);

        TextObject playerHp("playerHp", "PLAYER HP:"+ std::to_string(player.getHp()));
        scene2.addGameObject(playerHp);

        TextObject infoBox("Infobox", "Lorem ipsum dolor sit amet.");
        infoBox.setPosition(sf::Vector2f(window.getSize().x / 4, (window.getSize().y -10.0f)/ 8 * 7));
        scene2.addGameObject(infoBox);





    //Adding scenes to stack
    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);

    //Utility
    int counter = 0;

    //Game loop
    while (window.isOpen()) {
        
        //check for Events
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == sf::Keyboard::Escape){
                    window.close();
                }

                if (event.key.code == sf::Keyboard::A){
                    enemy.attack(player, distLow(rd));
                    playerHp.setText("PLAYER HP:"+ std::to_string(player.getHp()),defaultCharSize);
                }
                if (event.key.code == sf::Keyboard::S){
                    player.getStats();
                }

                
            }

            if (playButton.isClicked()){
                    handler.stackScene("scene02");
            }
                
            if (exitButton.isClicked()){
                    window.close();
            }
            if (player.getHp() == 0) {
                window.close();
            }
            if (enemy.getHp() == 0) {

            }

        }
        
        

        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





