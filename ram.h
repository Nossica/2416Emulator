#ifndef RAM_H
#define RAM_H

#include <map>

class RAM
{
    std::map<unsigned int, unsigned int> memory_;
    unsigned int current_;

public:

    RAM() : current_(0) {
    }

    void writeToMemory(const unsigned int location, const unsigned int value) {
        memory_[location] = value;
    }

    unsigned int readFromMemory(const unsigned int location) {
        return memory_[location];
    }

    unsigned int readNextMemory() {
        return memory_[current_];
    }

    void setRAR() {
        memory_[0xFFFF] = getNext();
    }

    unsigned int getRAR() {
        return readFromMemory(0xFFFF);
    }

    void setCurrent(const unsigned int location) {
        if (location == 0xFFFF)
            current_ = readFromMemory(0xFFFF);
        else
            current_ = location;
    }

    unsigned int getCurrent() { return current_; }
    unsigned int getNext() { return getCurrent() + 1; }
};
#endif // RAM_H
