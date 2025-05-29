#include "SFMLRenderer.h"

void SFMLRenderer::run() {
    // Configurar la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulación de Pelota");

    // Crear la pelota
    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(400, 300);

    // Variables de movimiento
    sf::Vector2f velocity(500.f, 500.f); // Velocidades iniciales en X y Y
    const float elasticity = -0.8f;     // Factor de elasticidad (rebote)

    // Reloj para gestión del tiempo
    sf::Clock clock;

    while (window.isOpen()) {
        // Manejo de eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Actualizar posición de la pelota
        float deltaTime = clock.restart().asSeconds();
        sf::Vector2f position = ball.getPosition();
        position += velocity * deltaTime;

        // Colisión con los bordes y cálculo de rebote
        if (position.x <= 0 || position.x + ball.getRadius() * 2 >= window.getSize().x) {
            velocity.x *= elasticity; // Rebote horizontal
            position.x = std::max(0.f, position.x);
            position.x = std::min(window.getSize().x - ball.getRadius() * 2, position.x);
        }
        if (position.y <= 0 || position.y + ball.getRadius() * 2 >= window.getSize().y) {
            velocity.y *= elasticity; // Rebote vertical
            position.y = std::max(0.f, position.y);
            position.y = std::min(window.getSize().y - ball.getRadius() * 2, position.y);
        }

        ball.setPosition(position);

        // Dibujar elementos
        window.clear();
        window.draw(ball);
        window.display();
    }
}
