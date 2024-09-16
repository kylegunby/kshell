#include <stdlib.h>

#include "kshell.h"

int main() {

    kshell_init();

    kshell_loop();

    // Cleanup
    // kshell_cleanup();

    return EXIT_SUCCESS;
}
