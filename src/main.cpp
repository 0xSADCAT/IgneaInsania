#include "Application.hpp"
#include "ui/Window.hpp"
#include "game/Game.hpp"


int main(int argc, char** argv)
{
    Application app(argc, argv);
    Window window ("Ignea Insania");
    Game game;

    app.setWindow(&window);
    app.setGameModel(&game);

    return app.execute();
}
