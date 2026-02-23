#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QPainter>
#include <iostream>

void GameData::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	drawBoard(&painter);
	drawGrid(&painter);
}

void GameData::drawBoard(QPainter *painter) {
	painter-> setBrush(BOARD_COLOR);
    painter->drawRect(BOARD_OFFSET_X, BOARD_OFFSET_Y, BLOCK_SIZE * BOARD_WIDTH, BLOCK_SIZE * BOARD_HEIGHT);
}

void GameData::drawGrid(QPainter *painter) {
	painter->setOpacity(0.3);
	painter-> setBrush(GRID_COLOR);
	// Vertical lines
	for(int x = 0; x <= BOARD_WIDTH; ++x){
		painter->drawLine(BOARD_OFFSET_X + x * BLOCK_SIZE, BOARD_OFFSET_Y, BOARD_OFFSET_X + x * BLOCK_SIZE,  BOARD_OFFSET_Y + BLOCK_SIZE * BOARD_HEIGHT);
	}

	// Horizontal lines
	for(int y = 0; y <= BOARD_HEIGHT; ++y){
		painter->drawLine(BOARD_OFFSET_X, BOARD_OFFSET_Y + y * BLOCK_SIZE, BOARD_OFFSET_X + BLOCK_SIZE * BOARD_WIDTH , BOARD_OFFSET_Y + y * BLOCK_SIZE);
	}
}
