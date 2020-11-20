#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP
#include <QGlobalStatic>
#include <QVector>
#include <QTime>

#include <time.h>
#include <random>
#include <chrono>


class RandomGenerator {
public:
    RandomGenerator* getInstance();

    decltype (auto) getData(int);
    decltype (auto) getData(int, int, int);
private:
    static std::default_random_engine e;
};

Q_GLOBAL_STATIC(RandomGenerator, rg)

RandomGenerator* RandomGenerator::getInstance() { return rg(); }

decltype (auto) RandomGenerator::getData(int min, int max, int size) {
    QVector<int> data(size);
    e.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> u(min, max);
    for(int i = 0; i < size; ++i) {
        data[i] = u(e);
    }
    return data;
}

decltype (auto) RandomGenerator::getData(int size) {
    return this->getData(INT_MIN, INT_MAX, size);
}



#endif // RANDOMGENERATOR_HPP
