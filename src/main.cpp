#include "../include/snake.hpp"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	GameData game;
	game.show();
	return app.exec();
}
