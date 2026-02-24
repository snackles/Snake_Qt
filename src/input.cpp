#include "../include/constants.hpp"
#include "../include/snake.hpp"

#include <QKeyEvent>

void GameData::keyPressEvent(QKeyEvent *event) {
	Direction nextDirection;
	
    switch (event->key()) {
    case Qt::Key_W:
        nextDirection = UP;
        break;
    case Qt::Key_S:
        nextDirection = DOWN;
        break;
    case Qt::Key_A:
        nextDirection = LEFT;
        break;
    case Qt::Key_D:
        nextDirection = RIGHT;
        break;
    case Qt::Key_P:
        pauseGame();
        break;
    case Qt::Key_R:
        initGame();
        break;
    }

	if (inputQueue.size() >= 3) {return;}

	Direction lastInQueue = inputQueue.isEmpty() ? direction : inputQueue.last();
	if ((nextDirection== UP && lastInQueue != DOWN) ||
        (nextDirection == DOWN && lastInQueue != UP) ||
        (nextDirection == LEFT && lastInQueue != RIGHT) ||
        (nextDirection == RIGHT && lastInQueue != LEFT)) {
        
		if (nextDirection != lastInQueue) {
            inputQueue.enqueue(nextDirection);
        }
    }
}
