#include "game.h"

int main(int ac, char *av[])
{
	QApplication app(ac, av);
	Game game;
	game.run();
	return app.exec();
}
