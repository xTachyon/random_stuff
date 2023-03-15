#include <windows.h>
#include <cstdio>
#include <cstdint>

void die_if(bool b) {
    if (!b) {
        abort();
    }
}
constexpr uint64_t log2(uint64_t n) noexcept {
    return (n > 1) ? 1 + log2(n >> 1) : 0;
}
void leak() {
    auto current = 64ULL * 1024ULL * 1024ULL;
    while (true) {
        auto log = log2(current);
        auto ptr = VirtualAlloc(nullptr, current, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
        if (ptr) {
            memset(ptr, 0, current);
            printf("ok: %llu\n", log);
        } else {
            printf("nope: %llu\n", log);
            current >>= 1;
        }
        if (log == 0) {
            break;
        }
    }
    Sleep(3000);
}

int main() {
    unsigned size = 4096 * 16;
    auto ptr = (unsigned char*) VirtualAlloc(nullptr, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    die_if(ptr);

    ptr[0] = 255;
    memset(ptr, 255, size);

    die_if(VirtualAlloc(ptr, size, MEM_RESET, PAGE_READWRITE));
    leak();
    /*printf("trying the read o:\n");
    for (unsigned i = 0; i < size; ++i) {
        if (ptr[i] != 255) {
            abort();
        }
    }
    printf("the reads worked o:\n");*/
    if (VirtualAlloc(ptr, size, MEM_RESET_UNDO, PAGE_READWRITE)) {
        printf("recovered!\n");
    } else {
        printf("nope!\n");
    }
    for (unsigned i = 0; i < size; ++i) {
        if (ptr[i] != 0) {
            printf("byte %u is not 0!\n", i);
            return 1;
        }
    }
    printf("all zero!\n");

    die_if(VirtualFree(ptr, 0, MEM_RELEASE));
}
