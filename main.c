#include "run.h"


int shared_var = 10;

int main() {
    return add(shared_var, 5);
}
