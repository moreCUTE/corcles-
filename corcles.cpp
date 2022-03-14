#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
int screenW = 800;
int screenH = 800;
void areareturn(int radius) {
    
    cout<< "Area of the circle is: " << 3.14159 * (radius * radius) << endl;

}
void totalarea(int purple, int orange) {
    cout << "area of game screen is " << screenW * screenH << endl;
    cout << " black area is " << screenW * screenH - 64 * purple * purple * 3.14 << endl;
    //add depression grey area
    cout <<  "'purple' area is: " << (64 * purple * purple * 3.14) - (64 * orange * orange * 3.14159) << endl;
    //add pimple pink area here
    cout<< "'orange' area is: "<< 64 * orange * orange * 3.14 << endl;
}
int main()
{
    
    sf::RenderWindow window(sf::VideoMode(screenW, screenH), "Circles");
    sf::CircleShape circle;

    double xpos = 0;
    double ypos = 0;
    double size = 50;
    double size2 = 30;
    double purparea = 0;
    double orarea = 0;
    areareturn(size);
    areareturn(size2);
    totalarea(size, size2);
    while (window.isOpen())//GAME LOOP--------------------------------
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        //modify these arguments so each is a different slot of the vectors above
        for (double i = 0; i < 8; i++) {
            for (double j = 0; j < 8; j++) {
                circle.setRadius(size);
                circle.setFillColor((sf::Color(250, 20, 250, 80)));
                circle.setPosition(xpos + i * 100, ypos + j * 100);
                window.draw(circle);
                purparea += 3.14159 * size * size;
                circle.setRadius(size2);
                circle.setFillColor((sf::Color(250, 130, 50, 80)));
                circle.setPosition(xpos + i * 100 + size2-10, ypos + j * 100 + size2-10);
                window.draw(circle);
                orarea += 3.14159 * size2 * size2;
                purparea -= orarea;
            }
        }
        
        
        window.display();

    }//end game loop-------------------------------------------------
    
    
    return 0;
} //end main
