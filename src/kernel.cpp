//
// Created by chloe on 7/25/24.
//

#include "kernel.h"

namespace rhyme::core
{
void
kernel::init ()
{
  console console (this->fb);
  console.init ();
}
} // kernel
// rhyme
