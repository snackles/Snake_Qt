#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QWidget>
#include <QPainter>
#include <QRandomGenerator>

GameData::GameData(QWidget *parent)
	: QWidget(parent) {
	createWindow();
	gameTimer = new QTimer(this);
	connect(gameTimer, &QTimer::timeout, this, [this](){
        if(!isGameOver){
            moveSnake();      // Сначала двигаем
            checkApple();     // Проверяем яблоко
            checkCollision(); // Проверяем стены
            update();         // Перерисовываем
        }
    });
	initGame();
}

GameData::~GameData() {
	if(gameTimer){delete gameTimer;}
}

void GameData::initGame(){
	snake.clear();
	snake.append(QPoint(BOARD_WIDTH / 2, BOARD_HEIGHT / 2));
	snake.append(QPoint(BOARD_WIDTH / 2 - 1,  BOARD_HEIGHT / 2)); 
	direction = RIGHT;
	isGameOver = false;
	isPaused = false;
	score = 0;

	gameTimer->start(DELAY);
	createApple();
}

void GameData::pauseGame() {
    isPaused = !isPaused;
    if (isPaused) {
        gameTimer->stop();
    } else {
        gameTimer->start(DELAY);
    }
}

void GameData::gameOver() {
	isGameOver = true;
	gameTimer->stop();
}

void GameData::createApple() {
	int x = QRandomGenerator::global()->bounded(0, BOARD_WIDTH);
	int y = QRandomGenerator::global()->bounded(0, BOARD_HEIGHT);
    apple = QPoint(x, y);

    while (snake.contains(apple)) {
		int x = QRandomGenerator::global()->bounded(0, BOARD_WIDTH);
		int y = QRandomGenerator::global()->bounded(0, BOARD_HEIGHT);
        apple = QPoint(x, y);
    }        
}

void GameData::moveSnake() {
	if(isGameOver){return;}

	if (!inputQueue.isEmpty()) {
        direction = inputQueue.dequeue();
    }
	
	QPoint head = snake.front();
	
	switch(direction){
	case UP:{
		head.ry() -= 1;
	}break;
	case DOWN:{
		head.ry() += 1;
	}break;
	case LEFT:{
		head.rx() -= 1;
	}break;
	case RIGHT:{
		head.rx() += 1;
	}break;
	}

	snake.push_front(head);

}
void GameData::checkApple() {
	QPoint head = snake.front();
	
	if(head == apple){
		score++;
		createApple();
	}else{
		snake.pop_back();
	}
}

void GameData::checkCollision() {
	QPoint head = snake.front();
    if (head.x() < 0 ||
		head.x() >= BOARD_WIDTH ||
		head.y() < 0 ||
		head.y() >= BOARD_HEIGHT) {
        gameOver();
    }
	for (int i = 1; i < snake.size(); ++i) {
        if (head == snake[i]) {
            gameOver();
            break;
        }
    }
}
