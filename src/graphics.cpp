#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QPainter>
#include <iostream>

void GameData::createWindow() {
	this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	this->setWindowTitle("Snake_QT_OOP");
	
    this->setAutoFillBackground(true);
    QPalette background_color = this->palette();
    background_color.setColor(QPalette::Window, BACKGROUND_COLOR);
    this->setPalette(background_color);
}

void GameData::paintEvent(QPaintEvent *event) {
	Q_UNUSED(event);
	
	QPainter painter(this);

	drawBoard(painter);
	drawApple(painter);
	drawSnake(painter);
}

void GameData::drawBoard(QPainter &painter) {
	QRect boardRect(BOARD_OFFSET_X,
					BOARD_OFFSET_Y,
					BLOCK_SIZE * BOARD_WIDTH,
					BLOCK_SIZE * BOARD_HEIGHT);
	painter.setPen(QPen(WALL_COLOR, 1));
	painter.setBrush(Qt::NoBrush);
	painter.drawRect(boardRect);
	
	for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
             drawBlock(painter, x, y, BOARD_COLOR);
        }
    }
}

void GameData::drawBlock(QPainter &painter, int x, int y, QColor color) {
	QRect blockRect(x * BLOCK_SIZE + BOARD_OFFSET_X,
					y * BLOCK_SIZE + BOARD_OFFSET_Y,
					BLOCK_SIZE,
					BLOCK_SIZE);
	QRect outlineRect = blockRect.adjusted(BLOCK_OUTLINE,
										   BLOCK_OUTLINE,
										   -BLOCK_OUTLINE,
										   -BLOCK_OUTLINE);
	painter.setPen(QPen(color, 1));
	painter.setBrush(Qt::NoBrush);
	painter.drawRect(outlineRect);

	QRect inlineRect = outlineRect.adjusted(BLOCK_OUTLINE * 3,
											BLOCK_OUTLINE * 3,
											-(BLOCK_OUTLINE * 3),
											-(BLOCK_OUTLINE * 3));
	painter.fillRect(inlineRect, color);
}

void GameData::drawApple(QPainter &painter) {
	drawBlock(painter, apple.x(), apple.y(), APPLE_COLOR);
}

void GameData::drawSnake(QPainter &painter) {
	QPoint head = snake.front();	
    drawBlock(painter, head.x(), head.y(), SNAKE_COLOR);
	
	for(int i = 1; i < snake.size() - 1; ++i){
		QPoint body = snake[i];
		drawBlock(painter, body.x(), body.y(), SNAKE_COLOR);
	}

	QPoint tail = snake.back();
	drawBlock(painter, tail.x(), tail.y(), SNAKE_COLOR);
}
