//
// Created by chloe on 7/24/24.
//

#include "common.h"

void halt() {
    __asm__ __volatile__("1: cli; hlt; jmp 1b");
}