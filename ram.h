#ifndef RAM_H
#define RAM_H

#include <map>
#include <token.h>

// There are 0xFFFF memory addresses
// Each address has a top value of 0xFFFFFF
// The RAM stores instructions and data
class Instruction;

const unsigned int CAPACITY = 0xFFFF;       // this is also the RAR location
const unsigned int MAX_VALUE = 0xFFFFFF;

class RAM
{
    // TODO - switch this to use a smart pointer or a boost map
    std::map<unsigned int, Token*> memory_;
    unsigned int current_;

public:

    RAM() : current_(0) {
        for (int i=0; i <= 0xFFFF; i++) {
            memory_[i] = new Token(0, 0);
        }
    }

/*    ~RAM() {
        memory_.clear();
    }
*/
    void writeToMemory(unsigned int location, unsigned int value) {
        location = location % CAPACITY;
        value = value % MAX_VALUE;

        memory_[location] = new Token(value, 0);
    }

    void writeToMemory(unsigned int location, Token *value) {
        location = location%CAPACITY;

        memory_[location] = value;
    }

    Token* readFromMemory(const unsigned int location) {
        return memory_[location];
    }

    Token* readNextMemory() {
        return memory_[current_];
    }

    void setRAR() {
        writeToMemory(CAPACITY, getNext());
    }

    Token* getRAR() {
        return readFromMemory(0xFFFF);
    }

    void setCurrent(const unsigned int location) {
        if (location == 0xFFFF)
            current_ = readFromMemory(0xFFFF)->getValue();
        else
            current_ = location;
    }

    unsigned int getCurrent() { return current_; }
    unsigned int getNext() { return ((getCurrent() + 1) % CAPACITY); }
    unsigned int memoryLimit() { return CAPACITY; }
};
#endif // RAM_H
