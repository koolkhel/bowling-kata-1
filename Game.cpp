#include "Game.h"

Game::Game(QObject *parent) : QObject(parent), currentRoll(0)
{
    memset(rolls, 0, sizeof(rolls));
}

void Game::roll(int pins) {
    rolls[currentRoll++] = pins;
}

int Game::score() {
    int calcScore = 0;
    int frameIndex = 0;
    for (int frame = 0; frame < 10; frame++) {
        if (isStrike(frameIndex)) { // strike
            calcScore += 10 + strikeBonus(frameIndex);
            frameIndex += 1;
        } else if (isSpare(frameIndex)) {
            calcScore += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        } else {
            calcScore += sumOfBallsInFrame(frameIndex);
            frameIndex += 2;
        }
    }
    return calcScore;
}

bool Game::isSpare(int frameIndex) {
    return (rolls[frameIndex] + rolls[frameIndex + 1] == 10);
}

bool Game::isStrike(int frameIndex) {
    return rolls[frameIndex] == 10;
}

int Game::sumOfBallsInFrame(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex+1];
}

int Game::spareBonus(int frameIndex) {
    return rolls[frameIndex + 2];
}

int Game::strikeBonus(int frameIndex) {
    return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}
