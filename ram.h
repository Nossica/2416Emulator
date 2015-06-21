#ifndef RAM_H
#define RAM_H

#include <map>

class RAM
{
    std::map<unsigned int, unsigned int> memory_;
    unsigned int current_;

public:

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

    void setCurrent(const unsigned int location) {
        current_ = location;
    }

    unsigned int getCurrent() { return current_; }
};

#endif // RAM_H
