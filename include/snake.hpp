#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "constants.hpp"

class GameData : public QWidget {
	Q_OBJECT
	
public:
	GameData(QWidget *parent = nullptr);
	~GameData();
	
protected:	
	void paintEvent(QPaintEvent *event) override;
	void keyPressEvent(QKeyEvent *) override;
	
private:
	bool isGameOver;
	bool isPaused;
	int score;

	QTimer *gameTimer;
	QVector<QPoint> snake;
	QPoint apple;
	Direction direction;
	QFont titleFont;
	QFont textFont;

	void createWindow();
	void initGame();
	void pauseGame();
	void gameOver();
	void moveSnake();
	void createApple();
	void checkApple();
	void checkCollision();
	
	void drawBoard(QPainter &painter);
	void drawBlock(QPainter &painter, int x, int y, QColor color);
	void drawApple(QPainter &painter);
	void drawSnake(QPainter &painter);
	void drawScore(QPainter &painter);
	void drawGameOver(QPainter &painter);
	void drawPause(QPainter &painter);

	QQueue<Direction> inputQueue;
};

void loadFontFamily();

#endif
