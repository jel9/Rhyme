#ifndef KERNEL_H
#define KERNEL_H

#include <backends/fb.h>
#include <boot/limine.h>
#include <flanterm.h>
#include <term/console.h>
#include <x86_64/common.h>

namespace rhyme::core {

class kernel
{
public:
  kernel(limine_framebuffer* fb) { this->fb = fb; }

  void init();

private:
  limine_framebuffer* fb;
};

} // kernel

// rhyme

#endif // KERNEL_H
