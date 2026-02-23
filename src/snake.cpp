#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QWidget>
#include <QPainter>

bool init_game(GameData &game){
	
	game.resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	game.setWindowTitle("Snake_QT_OOP");
	
    game.setAutoFillBackground(true);
    QPalette background_color = game.palette();
    background_color.setColor(QPalette::Window, Qt::gray);
    game.setPalette(background_color);

	return true;
}
