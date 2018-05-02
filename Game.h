#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    void roll(int pins);
    int score();
signals:

public slots:
private:
    int rolls[21];
    int currentRoll;
    int sumOfBallsInFrame(int frameIndex);
    int spareBonus(int frameIndex);
    int strikeBonus(int frameIndex);
    bool isSpare(int frameIndex);
    bool isStrike(int frameIndex);
};



#endif // GAME_H
