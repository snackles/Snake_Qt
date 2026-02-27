#ifndef SNAKE_CONSTANTS_HPP
#define SNAKE_CONSTANTS_HPP

#include <QPainter>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QQueue>
#include <QRandomGenerator>
#include <QFontDatabase>
#include <QFont>
#include <QApplication>
#include <QKeyEvent>
#include <QDebug>
#include <QEvent>
#include <iostream>

// Board settings
constexpr int BOARD_WIDTH    = 30;
constexpr int BOARD_HEIGHT   = 29;
constexpr int BOARD_OFFSET_X = 10;
constexpr int BOARD_OFFSET_Y = 10;

// Window settings
constexpr int WINDOW_WIDTH   = 800;
constexpr int WINDOW_HEIGHT = 600;

// UI settings
constexpr int BANNER_WIGTH = 250;
constexpr int BANNER_HEIGHT = 100;

// Block parameters
constexpr int BLOCK_SIZE     = 20;
constexpr int BLOCK_OUTLINE = 1;

// Gameplay parameters
constexpr int START_DELAY = 300;
constexpr int POINTS_PER_APPLE = 10;
constexpr int APPLES_TO_LEVEL_UP = 10;

// Colors
const QColor BACKGROUND_COLOR = QColor("#9DAD86");
const QColor BOARD_COLOR = QColor("#8E9D77");
const QColor WALL_COLOR = Qt::black;
const QColor APPLE_COLOR = QColor("#86362f");
const QColor SNAKE_COLOR = QColor("#282828");
const QColor TEXT_COLOR = Qt::black;
const QColor GAME_OVER_COLOR = QColor("#86362f");

// Font
const QString FONT_FAMILY = "DS-Digital";

enum Direction { UP, DOWN, LEFT, RIGHT };
#endif
