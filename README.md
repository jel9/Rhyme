# Rhyme

Neat kernel written in C++.

## Building

#### Requirements

You need:

* clang, gcc will work in the future
* meson & ninja
* lld/llvm's linker

Do note that this is the kernel only, no userspace or iso will be provided!

#### Building

First decide on what target arch you will compile for, only x86_64 is supported for now. Now you will use the meson cross-file in meta/targets, and run meson with it.

Next you will compile it with ninja, which should be straight forward.

## License

Rhyme is MPL-2.0 licensed, see the LICENSE file for more.
