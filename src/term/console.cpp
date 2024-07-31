//
// Created by chloe on 7/25/24.
//

#include "console.h"

namespace rhyme::core
{

void
console::init ()
{
  ctx = flanterm_fb_init (
      NULL, NULL, reinterpret_cast<uint32_t *> (this->fb->address),
      this->fb->width, this->fb->height, this->fb->pitch,
      this->fb->red_mask_size, this->fb->red_mask_shift,
      this->fb->green_mask_size, this->fb->green_mask_shift,
      this->fb->blue_mask_size, this->fb->blue_mask_shift, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 12);
}

void
console::puts (const char *s)
{
  flanterm_write (this->ctx, s, internal::strlen (s));
}

}
