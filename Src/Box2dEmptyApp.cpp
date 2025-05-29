 #include "Game.h"
#include "Box2DHelper.h"

void Box2DEmptyApp::run() {
    Game game;
    game.start();
}
#include "Box2DHelper.h"

int main() {
    Box2DEmptyApp app;
    app.run();
    return 0;
}
