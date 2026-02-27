#include "../include/constants.hpp"
#include "../include/snake.hpp"

// Creating and setup window
void GameData::createWindow() {
	this->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	this->setWindowTitle("Snake_QT_OOP");
	
    this->setAutoFillBackground(true);
    QPalette background_color = this->palette();
    background_color.setColor(QPalette::Window, BACKGROUND_COLOR);
    this->setPalette(background_color);
}

// Rendering all objects
void GameData::paintEvent(QPaintEvent *event) {
	Q_UNUSED(event);
	
	QPainter painter(this);
	
	drawBoard(painter);
	drawApple(painter);
	drawSnake(painter);
	drawScore(painter);

	if (isGameOver){drawGameOver(painter);}
	if (isPaused){drawPause(painter);}
}

// Grid drawing
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

// Block drawing
void GameData::drawBlock(QPainter &painter, int x, int y, QColor color) {
	// First rectangle
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

	// Second rectangle
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

void GameData::drawScore(QPainter &painter) {
	painter.setFont(titleFont);
	painter.setPen(TEXT_COLOR);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y + 35,
					 "SCORE");

	painter.setFont(textFont);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y * 8,
					 QString::number(score));

	painter.setFont(titleFont);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y + 135,
					 "APPLES");

	painter.setFont(textFont);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y + 170,
					 QString::number(apples));

	painter.setFont(titleFont);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y + 235,
					 "LEVEL");

	painter.setFont(textFont);
	painter.drawText((BOARD_WIDTH * BLOCK_SIZE) + (BOARD_OFFSET_X * 2),
					 BOARD_OFFSET_Y + 275,
					 QString::number(level));
}

void GameData::drawGameOver(QPainter &painter) {
	int x = (WINDOW_WIDTH - BANNER_WIGTH) / 2;
	int y = (WINDOW_HEIGHT - BANNER_HEIGHT) / 2;
	QRect banner(x, y, BANNER_WIGTH, BANNER_HEIGHT);

	painter.setBrush(BACKGROUND_COLOR);
	painter.setPen(WALL_COLOR);
	painter.drawRect(banner);

	int marginTop = 10; 
    QRect textTitle = banner.adjusted(0, marginTop, 0, 0);
	
	painter.setFont(titleFont);
	painter.setPen(GAME_OVER_COLOR);
	painter.drawText(textTitle,
					 Qt::AlignHCenter | Qt::AlignTop,
					 "GAME OVER");

	int marginBottom = 10; 
    QRect textComment = banner.adjusted(0, 0, 0, -marginBottom);
	
	painter.setFont(textFont);
	painter.setPen(TEXT_COLOR);
	painter.drawText(textComment,
					 Qt::AlignHCenter | Qt::AlignBottom,
					 "Press R to restart");
}

void GameData::drawPause(QPainter &painter) {
	int x = (WINDOW_WIDTH - BANNER_WIGTH) / 2;
	int y = (WINDOW_HEIGHT - BANNER_HEIGHT) / 2;
	QRect banner(x, y, BANNER_WIGTH, BANNER_HEIGHT);

	painter.setBrush(BACKGROUND_COLOR);
	painter.setPen(WALL_COLOR);
	painter.drawRect(banner);

	int marginTop = 10; 
    QRect textTitle = banner.adjusted(0, marginTop, 0, 0);
	
	painter.setFont(titleFont);
	painter.setPen(TEXT_COLOR);
	painter.drawText(textTitle,
					 Qt::AlignHCenter | Qt::AlignTop,
					 "PAUSE");
	
	int marginBottom = 10; 
    QRect textComment = banner.adjusted(0, 0, 0, -marginBottom);
	
	painter.setFont(textFont);
	painter.setPen(TEXT_COLOR);
	painter.drawText(textComment,
					 Qt::AlignHCenter | Qt::AlignBottom,
					 "Press P to resume");
}
