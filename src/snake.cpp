#include "../include/constants.hpp"
#include "../include/snake.hpp"

// Load font
void loadFontFamily() {
	QFontDatabase::addApplicationFont(":/assets/DS-DIGI.TTF");
	QFontDatabase::addApplicationFont(":/assets/DS-DIGIB.TTF");
}

// Constructor: Setup UI, timer-based game loop, and initial state
GameData::GameData(QWidget *parent)
	: QWidget(parent) {
	createWindow();
	gameTimer = new QTimer(this);
	connect(gameTimer, &QTimer::timeout, this, [this](){
        if(!isGameOver && !isPaused){
            moveSnake();     
            checkApple();     
            checkCollision(); 
            update();        
        }
    });
	initGame();
}

GameData::~GameData() {
	if(gameTimer){delete gameTimer;}
}

void GameData::initGame(){
	// Initial game state
	snake.clear();
	snake.append(QPoint(BOARD_WIDTH / 2, BOARD_HEIGHT / 2));
	snake.append(QPoint(BOARD_WIDTH / 2 - 1,  BOARD_HEIGHT / 2)); 
	direction = RIGHT;
	isGameOver = false;
	isPaused = false;
	score = 0;
	apples = 0;
	level = 1;

	// Font styling
	loadFontFamily();

	titleFont.setFamily("DS-Digital");
	titleFont.setBold(true);
	titleFont.setPointSize(50);

	textFont.setFamily("DS-Digital");
	textFont.setWeight(QFont::Normal);
	textFont.setPointSize(30);

	// Start game
	gameTimer->start(START_DELAY);
	createApple();
}

void GameData::pauseGame() {
    isPaused = !isPaused;
    if (isPaused) {
        gameTimer->stop();
    } else {
        gameTimer->start();
    }
	update();
}

void GameData::gameOver() {
	isGameOver = true;
	gameTimer->stop();
}

// Create apple in random block
void GameData::createApple() {
	int x = QRandomGenerator::global()->bounded(0, BOARD_WIDTH);
	int y = QRandomGenerator::global()->bounded(0, BOARD_HEIGHT);
    apple = QPoint(x, y);

	// Check the same position with snake
    while (snake.contains(apple)) {
		int x = QRandomGenerator::global()->bounded(0, BOARD_WIDTH);
		int y = QRandomGenerator::global()->bounded(0, BOARD_HEIGHT);
        apple = QPoint(x, y);
    }        
}

// Move logic
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

// Eating apple, calculate score and level
void GameData::checkApple() {
	QPoint head = snake.front();
	
	if(head == apple){
		score += POINTS_PER_APPLE;
		apples++;
		createApple();
		int newLevel = (score / (POINTS_PER_APPLE * APPLES_TO_LEVEL_UP)) + 1;

		if (newLevel > level) {
        level = newLevel;
        updateSpeed();
		}
	}else{
		snake.pop_back();
	}
}

// Acceleration
void GameData::updateSpeed() {
	int newInterval = START_DELAY - (level * 20);
	if (newInterval < 30) {newInterval = 30;}
	gameTimer->setInterval(newInterval);
}

// Check collision with wall and snake's body
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
bool GameData::event(QEvent *event) {
	if (event->type() == QEvent::WindowDeactivate) {
        if (!isPaused && !isGameOver) {
            pauseGame();
        }
    }
    return QWidget::event(event);
}

