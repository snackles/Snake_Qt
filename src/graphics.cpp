#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QPainter>
#include <iostream>

void GameData::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	drawBoard(&painter);
}

void GameData::drawBoard(QPainter *painter) {
	QRect boardRect(BOARD_OFFSET_X,
					BOARD_OFFSET_Y,
					BLOCK_SIZE * BOARD_WIDTH,
					BLOCK_SIZE * BOARD_HEIGHT);
	QColor wallColor = Qt::black;
	painter->setPen(QPen(wallColor, 1));
	painter-> setBrush(Qt::NoBrush);
	painter->drawRect(boardRect);
	
	for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
             drawBlock(painter, x, y, BOARD_COLOR);
        }
    }
}

void GameData::drawBlock(QPainter *painter, int x, int y, QColor color) {
	QRect blockRect(x * BLOCK_SIZE + BOARD_OFFSET_X,
					y * BLOCK_SIZE + BOARD_OFFSET_Y,
					BLOCK_SIZE,
					BLOCK_SIZE);
	QRect outlineRect = blockRect.adjusted(BLOCK_OUTLINE,
										   BLOCK_OUTLINE,
										   -BLOCK_OUTLINE,
										   -BLOCK_OUTLINE);
	painter->setPen(QPen(color, 1));
	painter-> setBrush(Qt::NoBrush);
	painter->drawRect(outlineRect);

	QRect inlineRect = outlineRect.adjusted(BLOCK_OUTLINE * 3,
											BLOCK_OUTLINE * 3,
											-(BLOCK_OUTLINE * 3),
											-(BLOCK_OUTLINE * 3));
	painter->fillRect(inlineRect, color);
}

