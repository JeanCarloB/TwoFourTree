//
// Created by jeanc on 17/10/2022.
//

#include "RuntimeException.h"

RuntimeException::RuntimeException(const string &msg) : msg(msg) {}

const string &RuntimeException::getMsg() const {
    return msg;
}

void RuntimeException::setMsg(const string &msg) {
    RuntimeException::msg = msg;
}
