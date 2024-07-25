//
// Created by chloe on 7/25/24.
//

#include <cstdint>
#include <cstddef>
#include <kernel.h>
#include <flanterm.h>
#include <backends/fb.h>
#include <x86_64/common.h>
#include <boot/limine.h>

using namespace rhyme;

namespace {

    __attribute__((used, section(".requests")))
    volatile LIMINE_BASE_REVISION(2);

}

namespace {

    __attribute__((used, section(".requests")))
    volatile limine_framebuffer_request framebuffer_request = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0,
        .response = nullptr
    };

}

namespace {

    __attribute__((used, section(".requests_start_marker")))
    volatile LIMINE_REQUESTS_START_MARKER;

    __attribute__((used, section(".requests_end_marker")))
    volatile LIMINE_REQUESTS_END_MARKER;

}

extern "C" {
    int __cxa_atexit(void (*)(void *), void *, void *) { return 0; }
    void __cxa_pure_virtual() { halt(); }
    void *__dso_handle;
}

extern "C" void _start()
{
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        halt();
    }

    if (framebuffer_request.response == nullptr
        || framebuffer_request.response->framebuffer_count < 1) {
           halt();
    }
    limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    core::kernel ke(framebuffer);

    ke.init();

    halt();
}