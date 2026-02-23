#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <QWidget>
#include <QPainter>

class GameData : public QWidget {
	Q_OBJECT
public:
	QWidget window;
	
	void paintEvent(QPaintEvent *event) override;
	void drawBoard(QPainter *painter);
	void drawGrid(QPainter *painter);
};

bool init_game(GameData &game);

#endif
