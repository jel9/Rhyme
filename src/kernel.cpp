//
// Created by chloe on 7/25/24.
//

#include "kernel.h"

namespace rhyme::core {
    void kernel::init() {

        struct flanterm_context *ctx = flanterm_fb_init(
                NULL,
                NULL,
                reinterpret_cast<uint32_t *>(this->fb->address), this->fb->width, this->fb->height, this->fb->pitch,
                this->fb->red_mask_size, this->fb->red_mask_shift,
                this->fb->green_mask_size, this->fb->green_mask_shift,
                this->fb->blue_mask_size, this->fb->blue_mask_shift,
                NULL,
                NULL, NULL,
                NULL, NULL,
                NULL, NULL,
                NULL, 0, 0, 1,
                0, 0,
                12
            );

        const char msg[] = "Hello world\n";

        flanterm_write(ctx, msg, sizeof(msg));
    }
} // kernel
// rhyme