//
// Created by chloe on 7/25/24.
//

#ifndef CONSOLE_H
#define CONSOLE_H


#include <flanterm.h>
#include <backends/fb.h>
#include <boot/limine.h>

namespace rhyme::core {

class console {
public:
    console(limine_framebuffer_request * fb) {
        this->fb = fb;
    }
    void init();
    void puts(const char *s);
    void puts(const char *s, size_t n);


private:
    flanterm_context *ctx;
    limine_framebuffer_request * fb;
};

}

#endif //CONSOLE_H
