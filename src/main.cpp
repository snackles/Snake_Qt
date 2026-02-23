#include "../include/snake.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	GameData game;
	init_game(game);
	game.show();
	return app.exec();
}
