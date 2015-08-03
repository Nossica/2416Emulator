#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include<exception>

class eNotAnInstruction : public std::exception {
public:
  virtual const char* what() const throw()
  {
    return "Attempt to execute a constant";
  }
};

enum FLAGSTATES {
    FLAGSTATES_BEGIN,
    NO_CHANGE,
    SET_CARRY_UNSET_ZERO,
    SET_CARRY_SET_ZERO,
    UNSET_CARRY_UNSET_ZERO,
    UNSET_CARRY_SET_ZERO,
    SET_CARRY,
    UNSET_CARRY,
    SET_ZERO,
    UNSET_ZERO,
    FLAGSTATES_END
};


#endif // CONSTANTS_HPP
