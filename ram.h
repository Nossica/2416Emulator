#ifndef RAM_H
#define RAM_H

#include <map>

class RAM
{
    std::map<unsigned int, unsigned int> memory_;

public:
    unsigned int current_;

    RAM():current_(0) {
    }

    void writeToMemory(const unsigned int location, const unsigned int value) {
        memory_[location] = value;
    }

    const unsigned int readFromMemory(const unsigned int location) {
        return memory_[location];
    }

    unsigned int readNextMemory() {
        return memory_[current_];
    }

    void setNextMemory(const unsigned int location) {
        current_ = location;
    }
};

#endif // RAM_H
