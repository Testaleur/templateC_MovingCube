#include <SFML/Graphics.hpp>

using namespace sf; // Utiliser le namespace SFML

int main()
{
    // Cr�er une fen�tre
    RenderWindow window(VideoMode(800, 600), "Moving cube");

    // Cr�er un cube noir (rectangle)
    RectangleShape cube(Vector2f(50.f, 50.f)); // Taille du cube
    cube.setFillColor(Color::Black); // Couleur noire
    cube.setPosition((window.getSize().x - cube.getSize().x) / 2, (window.getSize().y - cube.getSize().y) / 2); // Centrer le cube

    // Vitesse de d�placement
    float speed = 0.1;

    // Boucle principale
    while (window.isOpen())
    {
        // Traiter les �v�nements
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // D�placer le cube avec les fl�ches du clavier
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            cube.move(0, -speed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            cube.move(0, speed);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            cube.move(-speed, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            cube.move(speed, 0);
        }

        // Effacer la fen�tre avec une couleur
        window.clear(Color(100, 100, 100)); // Couleur de fond

        // Dessiner le cube
        window.draw(cube);

        // Afficher le contenu de la fen�tre
        window.display();
    }

    return 0;
}
