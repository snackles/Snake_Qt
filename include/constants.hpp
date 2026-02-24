#ifndef SNAKE_CONSTANTS_HPP
#define SNAKE_CONSTANTS_HPP

#include <QPainter>

constexpr int BOARD_WIDTH    = 30;
constexpr int BOARD_HEIGHT   = 29;
constexpr int BOARD_OFFSET_X = 10;
constexpr int BOARD_OFFSET_Y = 10;

constexpr int WINDOW_WIDTH   = 800;
constexpr int WINDOW_HEIGHT  = 600;

constexpr int BLOCK_SIZE     = 20;
constexpr int BLOCK_OUTLINE = 1;

constexpr int DELAY = 300;

const QColor BACKGROUND_COLOR = QColor("#9DAD86");
const QColor BOARD_COLOR = QColor("#8E9D77");
const QColor WALL_COLOR = Qt::black;
const QColor APPLE_COLOR = QColor("#86362f");
const QColor SNAKE_COLOR = QColor("#282828");


enum Direction { UP, DOWN, LEFT, RIGHT };
#endif
