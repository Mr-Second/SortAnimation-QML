#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP
#include <QGlobalStatic>
#include <QVector>
#include <QTime>


#include <time.h>
#include <random>
#include <chrono>

#define rg RandomGenerator::instance()

class RandomGenerator {
public:
    static RandomGenerator* instance();
    QVector<int> getData(int);
    QVector<int> getData(int, int, int);
    int getOneElement(int, int);
private:
    RandomGenerator(){}
    static std::default_random_engine e;
};

std::default_random_engine RandomGenerator::e;

RandomGenerator* RandomGenerator::instance() {
    static RandomGenerator _rg;
    return &_rg;
}

QVector<int> RandomGenerator::getData(int size, int min, int max) {
    assert( max >=  min);

    QVector<int> data(size);
    e.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> u{min, max};
    for(int i = 0; i < size; ++i) {
        data[i] = u(e);
    }
    return data;
}

int RandomGenerator::getOneElement(int min, int max)
{
    e.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> u{min, max};
    return u(e);
}

QVector<int> RandomGenerator::getData(int size) {
    return this->getData(INT_MIN, INT_MAX, size);
}


#endif // RANDOMGENERATOR_HPP
