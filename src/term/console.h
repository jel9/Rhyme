#ifndef CONSOLE_H
#define CONSOLE_H

#include <backends/fb.h>
#include <boot/limine.h>
#include <flanterm.h>

namespace rhyme::core {

namespace internal {
extern "C" size_t
strlen(const char* s);
}

class console
{
public:
  console(limine_framebuffer* fb) { this->fb = fb; }
  void init();
  void puts(const char* s);
  void puts(const char* s, size_t n);

private:
  flanterm_context* ctx;
  limine_framebuffer* fb;
};

}

#endif // CONSOLE_H
