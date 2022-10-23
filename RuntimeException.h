//
// Created by jeanc on 17/10/2022.
//

#ifndef PROYECTO_2_RUNTIMEEXCEPTION_H
#define PROYECTO_2_RUNTIMEEXCEPTION_H

#include <iostream>
using namespace std;
class RuntimeException {
private:
    string msg;
public:
    RuntimeException(const string &msg);

    const string &getMsg() const;

    void setMsg(const string &msg);
};


#endif //PROYECTO_2_RUNTIMEEXCEPTION_H
