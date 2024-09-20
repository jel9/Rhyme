#include "kernel.h"

namespace rhyme::core {
void
kernel::init()
{
  console console(this->fb);
  console.init();
}
} // kernel
// rhyme
